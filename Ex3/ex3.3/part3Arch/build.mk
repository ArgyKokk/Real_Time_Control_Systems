# build.mk file for part3Arch.archm, provide information to 'project MakeFile' 
# Generated by the TERRA Arch2LUNA generator version 1.0.1
#
# protected region document description on begin
# protected region document description end

TARGETS+=bin/part3Arch

part3Arch/part3Arch:
	@echo
	@echo "Building $@"
	@make -C part3Arch --no-print-directory

bin/part3Arch: part3Arch/part3Arch | bin
	@cp $^ $@
	@echo "Build $@"

# Additional dependencies to ensure that bin/part3Arch gets properly rebuild
part3Arch/part3Arch: part3Arch/src/main.cpp EncoderHorizontal/lib/libEncoderHorizontal.a EncoderV/lib/libEncoderV.a JIWY/lib/libJIWY.a ControllerPan/lib/libControllerPan.a ControllerTilt/lib/libControllerTilt.a PWM/lib/libPWM.a joystick/lib/libjoystick.a
part3Arch/part3Arch: part3Arch/src/MainModel.cpp part3Arch/include/MainModel.h EncoderHorizontal/include/EncoderHorizontal/EncoderHorizontal.h EncoderV/include/EncoderV/EncoderV.h JIWY/include/JIWY/JIWY.h ControllerPan/include/ControllerPan/ControllerPan.h ControllerTilt/include/ControllerTilt/ControllerTilt.h joystick/include/joystick/joystick.h PWM/include/PWM/PWM.h

# protected region additional dependencies on begin
# protected region additional dependencies end