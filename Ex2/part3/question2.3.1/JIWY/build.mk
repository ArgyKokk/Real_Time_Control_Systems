# build.mk file for JIWY.archm, provide information to 'project MakeFile' 
# Generated by the TERRA Arch2LUNA generator version 1.0.1
#
# protected region document description on begin
# protected region document description end

TARGETS+=bin/JIWY

JIWY/JIWY:
	@echo
	@echo "Building $@"
	@make -C JIWY --no-print-directory

bin/JIWY: JIWY/JIWY | bin
	@cp $^ $@
	@echo "Build $@"

# Additional dependencies to ensure that bin/JIWY gets properly rebuild
JIWY/JIWY: JIWY/src/main.cpp JoyStick/lib/libJoyStick.a ControllerPan/lib/libControllerPan.a ControllerTilt/lib/libControllerTilt.a plant/lib/libplant.a
JIWY/JIWY: JIWY/src/MainModel.cpp JIWY/include/MainModel.h ControllerPan/include/ControllerPan/ControllerPan.h ControllerTilt/include/ControllerTilt/ControllerTilt.h JoyStick/include/JoyStick/JoyStick.h plant/include/plant/plant.h

# protected region additional dependencies on begin
# protected region additional dependencies end