# Makefile for 20-sim FMU 2.0 export

FMU_NAME=ControllerTilt
FMU=$(FMU_NAME).fmu

FMU_DIR=project/fmu
FMU_SRC_DIR   = $(FMU_DIR)/sources
FMU_DOC_DIR   = $(FMU_DIR)/documentation
TERRA_DIR     = $(FMU_NAME)

BUILD = project/gcc
SRC   = src

XXSIM_SOURCES = EulerAngles.c \
	MotionProfiles.c \
	xxfuncs.c \
	xxinteg.c \
	xxinverse.c \
	xxmatrix.c \
	xxmodel.c \
	xxsubmod.c \
	xxTable2D.c

FMU_SOURCES = fmi2Functions.c $(XXSIM_SOURCES)

INCLUDES=
OBJS = $(addprefix $(BUILD)/, $(addsuffix .o, $(basename $(FMU_SOURCES))))
DEPS = $(addprefix $(BUILD)/, $(addsuffix .d, $(basename $(FMU_SOURCES))))

CXX?=g++
CC?=gcc

current_dir = $(shell pwd)
DEFINES=-DNO_FUNCTION_PREFIX

# OS detection
ifeq ($(OS),Windows_NT)
	# Windows
	WINDOWS=1
	DEFINES+= -DWIN32
	# For now, assume 32-bit
	# TODO detect MinGW 64
	OS_BITS=32
	DLL_EXT=dll
	# -shared to build a DLL, -static to prevent a dependency on libgcc_s_*.dll (gcc runtime library)
	BUILD_DLL=-shared -static
else
	# Other OS (Linux/MacOSX)
	ifeq ($(shell uname), Linux)
		LINUX=1
		DEFINES+= -DLINUX
		DLL_EXT=so
		BUILD_DLL=-shared
	endif
	ifeq ($(shell uname), Darwin)
		MACOSX=1
		DEFINES+= -DMACOSX
		DLL_EXT=dylib
		BUILD_DLL=-dynamiclib
	endif
	# Detect 32-bit / 64-bit OS
	OS_BITS=$(shell getconf LONG_BIT)
endif

# Set the OS specific settings
ifeq ($(WINDOWS),1)
	FMU_BIN32_DIR = $(FMU_DIR)/binaries/win32
	FMU_BIN64_DIR = $(FMU_DIR)/binaries/win64
	TEMPLATE_DIR=$(subst :,,$(subst \,/,/C:\Program Files (x86)\20-sim 4.7\Ccode\TERRA20FMU))
	ZIP_COMMAND="$(TEMPLATE_DIR)/bin/7z.exe" a -tzip -xr!.svn "$(FMU)" *
	POS_INDEP_CODE=
	STRIP=strip
endif
ifeq ($(LINUX),1)
	FMU_BIN32_DIR = $(FMU_DIR)/binaries/linux32
	FMU_BIN64_DIR = $(FMU_DIR)/binaries/linux64
	ZIP_COMMAND=zip -r $(FMU) *
	POS_INDEP_CODE=-fPIC -Wl,-Bsymbolic
	STRIP=strip
endif
ifeq ($(MACOSX),1)
	FMU_BIN32_DIR = $(FMU_DIR)/binaries/darwin32
	FMU_BIN64_DIR = $(FMU_DIR)/binaries/darwin64
	ZIP_COMMAND=zip -r $(FMU) *
	POS_INDEP_CODE=-fPIC
	STRIP=strip -x
endif

ifeq ($(MAKECMDGOALS),debug)
  CFLAGS=-g -DDEBUG $(INCLUDES) $(DEFINES) $(POS_INDEP_CODE)
  DEBUG=1
else
  CFLAGS=-O2 -Wall $(INCLUDES) $(DEFINES) $(POS_INDEP_CODE)
  DEBUG=0
endif

debug: fmu

default: fmu

.PHONY: clean

clean:
	@rm -rf $(BUILD)
	@rm -f $(FMU)
	@rm -rf $(FMU_BIN32_DIR)
	@rm -rf $(FMU_BIN64_DIR)
	@rm -rf $(FMU_SRC_DIR)
	@rm -f $(FMU_DOC_DIR)/*
	@rm -rf $(TERRA_DIR)
	@sudo rm -r /usr/local/lib/libSO$(FMU_NAME).$(DLL_EXT)

welcome:
	@echo ------------------------------------------------------------
	@echo 20-sim standalone co-simulation FMU export for:
	@echo '$(FMU_NAME)'
	@echo ------------------------------------------------------------

$(BUILD):
	@mkdir -p $(BUILD)

$(BUILD)/%.o: $(SRC)/%.c Makefile $(BUILD)
	@echo "[$(CC)] $<"
	@$(CC) -MD -MF $(patsubst %.o,%.d,$@) -c $(CFLAGS) $< -o $@

dll: welcome $(OBJS)
	@$(CC) $(CFLAGS) -o $(BUILD)/$(FMU_NAME).$(DLL_EXT) $(BUILD_DLL) $(OBJS) -lm
	@[ $(DEBUG)==0 ] && $(STRIP) $(BUILD)/$(FMU_NAME).$(DLL_EXT)

createfmudir:
	@echo Creating an empty FMU
	@mkdir -p $(FMU_DIR)
	@mkdir -p $(FMU_SRC_DIR)
fmu: dll createfmudir
	@if [ $(OS_BITS) -eq 32 ]; then \
		mkdir -p $(FMU_BIN32_DIR); \
		echo Copy the compiled 32-bit $(DLL_EXT) $(BUILD)/$(FMU_NAME).$(DLL_EXT) to $(FMU_BIN32_DIR); \
		cp $(BUILD)/$(FMU_NAME).$(DLL_EXT) $(FMU_BIN32_DIR); \
	else \
		mkdir -p $(FMU_BIN64_DIR); \
		echo Copy the compiled 64-bit $(DLL_EXT) $(BUILD)/$(FMU_NAME).$(DLL_EXT) to $(FMU_BIN64_DIR); \
		cp $(BUILD)/$(FMU_NAME).$(DLL_EXT) $(FMU_BIN64_DIR); \
	fi

	@echo Copy the generated sources to $(FMU_SRC_DIR)
	@cp $(SRC)/*.c $(FMU_SRC_DIR)
	@cp $(SRC)/*.h $(FMU_SRC_DIR)

	@echo Copy the generated sources to $(FMU_SRC_DIR)/CPP
	@mkdir -p $(FMU_SRC_DIR)/CPP && cp $(SRC)/*.c $(FMU_SRC_DIR)/CPP

	#@echo Renaming .c files to .cpp files, need to install dos2unix package
	#@chmod u+x rename.sh && dos2unix rename.sh && ./rename.sh

	@echo Create structured $(FMU_NAME) folders for TERRA project
	@mkdir -p $(TERRA_DIR) && mkdir -p $(TERRA_DIR)/include && mkdir -p $(TERRA_DIR)/model && mkdir -p $(TERRA_DIR)/src
	@mkdir -p $(TERRA_DIR)/include/$(FMU_NAME)
	@mkdir -p $(TERRA_DIR)/sharedLibs

	@echo Copy the sources and xml to $(TERRA_DIR)
	@cp $(SRC)/fmi2*.h $(TERRA_DIR)/include/$(FMU_NAME)
	@cp $(FMU_DIR)/$(FMU_NAME).xml $(TERRA_DIR)/model
	@cp logger.cpp $(TERRA_DIR)/src && cp logger.h $(TERRA_DIR)/include/$(FMU_NAME)

	@echo Copy and rename the shared lib to $(TERRA_DIR)
	@cp $(BUILD)/$(FMU_NAME).$(DLL_EXT) $(TERRA_DIR)/sharedLibs && mv $(TERRA_DIR)/sharedLibs/$(FMU_NAME).$(DLL_EXT) $(TERRA_DIR)/sharedLibs/libSO$(FMU_NAME).$(DLL_EXT)

	@echo Copy the renamed libSO$(FMU_NAME).$(DLL_EXT) to /usr/local/lib
	@sudo cp $(FMU_NAME)/sharedLibs/libSO$(FMU_NAME).$(DLL_EXT) /usr/local/lib	

	@cp $(SRC)/defines.def $(FMU_SRC_DIR)

	@echo Create the FMU: $(FMU)
	@cd $(FMU_DIR) && $(ZIP_COMMAND) && mv $(FMU) $(current_dir) && echo Ready!

