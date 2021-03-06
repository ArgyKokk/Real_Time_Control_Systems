# build.mk file for ControllerTilt.cspm, provide information to 'project MakeFile' 
# Generated by the TERRA CSPm2LUNA generator version 1.1.3
#
# protected region document description on begin
# protected region document description end

TARGETS+=lib/libControllerTilt.a

ControllerTilt/lib/libControllerTilt.a:
	@echo
	@echo "Building $@"
	@make -C ControllerTilt --no-print-directory

lib/libControllerTilt.a: ControllerTilt/lib/libControllerTilt.a | lib
	@cp $^ $@
	@echo "Build $@"

# Additional dependencies to ensure that lib/libControllerTilt.a gets properly rebuild
ControllerTilt/lib/libControllerTilt.a: ControllerTilt/src/ControllerTilt.cpp ControllerTilt/include/ControllerTilt/ControllerTilt.h
ControllerTilt/lib/libControllerTilt.a: ControllerTilt/src/FMI_ControllerTilt.cpp ControllerTilt/include/ControllerTilt/FMI_ControllerTilt.h ControllerTilt/include/ControllerTilt/fmi2Functions.h ControllerTilt/include/ControllerTilt/logger.h

# protected region additional dependencies on begin
# protected region additional dependencies end