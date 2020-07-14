# build.mk file for Model32.cspm, provide information to 'project MakeFile' 
# Generated by the TERRA CSPm2LUNA generator version 1.1.3
#
# protected region document description on begin
# protected region document description end

TARGETS+=lib/libModel32.a

Model32/lib/libModel32.a:
	@echo
	@echo "Building $@"
	@make -C Model32 --no-print-directory

lib/libModel32.a: Model32/lib/libModel32.a | lib
	@cp $^ $@
	@echo "Build $@"

# Additional dependencies to ensure that lib/libModel32.a gets properly rebuild
Model32/lib/libModel32.a: Model32/src/Model32.cpp Model32/include/Model32/Model32.h
Model32/lib/libModel32.a: Model32/src/cpp_produce.cpp Model32/include/Model32/cpp_produce.h

# protected region additional dependencies on begin
# protected region additional dependencies end