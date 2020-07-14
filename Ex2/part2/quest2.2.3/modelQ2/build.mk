# build.mk file for modelQ2.cspm, provide information to 'project MakeFile' 
# Generated by the TERRA CSPm2LUNA generator version 1.1.3
#
# protected region document description on begin
# protected region document description end

TARGETS+=bin/modelQ2

modelQ2/modelQ2:
	@echo
	@echo "Building $@"
	@make -C modelQ2 --no-print-directory

bin/modelQ2: modelQ2/modelQ2 | bin
	@cp $^ $@
	@echo "Build $@"

# Additional dependencies to ensure that bin/modelQ2 gets properly rebuild
modelQ2/modelQ2: modelQ2/src/main.cpp Step/lib/libStep.a Controller/lib/libController.a LinearSystem/lib/libLinearSystem.a
modelQ2/modelQ2: modelQ2/src/MainModel.cpp modelQ2/include/MainModel.h Controller/include/Controller/Controller.h LinearSystem/include/LinearSystem/LinearSystem.h Step/include/Step/Step.h

# protected region additional dependencies on begin
# protected region additional dependencies end