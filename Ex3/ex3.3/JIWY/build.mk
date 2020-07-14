# build.mk file for JIWY.cspm, provide information to 'project MakeFile' 
# Generated by the TERRA CSPm2LUNA generator version 1.1.3
#
# protected region document description on begin
# protected region document description end

TARGETS+=lib/libJIWY.a

JIWY/lib/libJIWY.a:
	@echo
	@echo "Building $@"
	@make -C JIWY --no-print-directory

lib/libJIWY.a: JIWY/lib/libJIWY.a | lib
	@cp $^ $@
	@echo "Build $@"

# Additional dependencies to ensure that lib/libJIWY.a gets properly rebuild
JIWY/lib/libJIWY.a: JIWY/src/JIWY.cpp JIWY/include/JIWY/JIWY.h ControllerPan/include/ControllerPan/ControllerPan.h ControllerTilt/include/ControllerTilt/ControllerTilt.h
JIWY/lib/libJIWY.a: JIWY/src/Check.cpp JIWY/include/JIWY/Check.h
JIWY/lib/libJIWY.a: JIWY/src/Check/cpp_horizontal_check.cpp JIWY/include/JIWY/Check/cpp_horizontal_check.h
JIWY/lib/libJIWY.a: JIWY/src/Check/cpp_vertical.cpp JIWY/include/JIWY/Check/cpp_vertical.h

# protected region additional dependencies on begin
# protected region additional dependencies end