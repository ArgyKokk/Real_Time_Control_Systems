# build.mk file for PWM32.archm, provide information to 'project MakeFile' 
# Generated by the TERRA Arch2LUNA generator version 1.0.1
#
# protected region document description on begin
# protected region document description end

TARGETS+=bin/PWM32

PWM32/PWM32:
	@echo
	@echo "Building $@"
	@make -C PWM32 --no-print-directory

bin/PWM32: PWM32/PWM32 | bin
	@cp $^ $@
	@echo "Build $@"

# Additional dependencies to ensure that bin/PWM32 gets properly rebuild
PWM32/PWM32: PWM32/src/main.cpp Model32/lib/libModel32.a
PWM32/PWM32: PWM32/src/MainModel.cpp PWM32/include/MainModel.h Model32/include/Model32/Model32.h

# protected region additional dependencies on begin
# protected region additional dependencies end