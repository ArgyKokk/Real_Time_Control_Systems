# Makefile for model1.cspm for Default target platform
# Generated by the TERRA CSPm2LUNA generator version 1.1.3
#
# protected region document description on begin
# protected region document description end

SOURCE_FILES=src/main.cpp src/MainModel.cpp src/SeqCon.cpp src/LoopCon.cpp src/LoopCon/CPP_first.cpp src/Plant.cpp

# Targets are expanded a second time, just before the rule is used
.SECONDEXPANSION:

# Contains the compiler commands that were used to build LUNA
-include /home/rtsd/RTSD/LUNA/luna-linux-x64/lib64/../tools.mk

# Additional commands
RM=rm -rf
MKDIR=mkdir -p

# Compiler/Linker flags
LDFLAGS+=-L/home/rtsd/RTSD/LUNA/luna-linux-x64/lib64
CPPFLAGS+=-Iinclude -I/home/rtsd/RTSD/LUNA/luna-linux-x64/include
LIBS+=-lLUNA


LIBS+=-lpthread



## protected region to add additional statements on begin
# For example, use this region to add additional files that are required:
#SOURCE_FILES+=xxsim/PID/PID.cpp $(wildcard xxsim/common/*.cpp)
#CPPFLAGS+=-Ixxsim/PID -Ixxsim/common 

## protected region to add additional statements end

OBJECT_FILES=$(patsubst src/%.cpp,obj/%.o,$(SOURCE_FILES))

all: model1

model1: $(OBJECT_FILES)
	$(CXX) $(LDFLAGS) $^ $(LIBS) -o $@

obj/%.o: src/%.cpp | $$(@D)
	$(CXX) -c $(CPPFLAGS) -o $@ $<

clean:
	$(RM) obj lib model1

# Targets for creating directories
uniq = $(strip $(if $1,$(firstword $1) $(call uniq,$(filter-out $(firstword $1),$1))))
DIRS:=$(call uniq,$(patsubst %/,%,lib/ $(dir $(OBJECT_FILES))))

define DirectoryTarget
  $(foreach directory, $(DIRS),
    $(directory):
	$(MKDIR) $(directory)
  )
endef
$(eval $(call DirectoryTarget))

# Dependencies
obj/main.o: include/MainModel.h
obj/MainModel.o: include/MainModel.h include/LoopCon.h include/Plant.h include/SeqCon.h
obj/SeqCon.o: include/SeqCon.h
obj/LoopCon.o: include/LoopCon.h include/LoopCon/CPP_first.h
obj/LoopCon/CPP_first.o: include/LoopCon/CPP_first.h
obj/Plant.o: include/Plant.h

# protected region additional targets on begin
# protected region additional targets end