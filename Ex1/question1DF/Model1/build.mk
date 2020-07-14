# build.mk file for Model1.cspm, provide information to 'project MakeFile' 
# Generated by the TERRA CSPm2LUNA generator version 1.1.3
#
# protected region document description on begin
# protected region document description end

TARGETS+=bin/Model1

Model1/Model1:
	@echo
	@echo "Building $@"
	@make -C Model1 --no-print-directory

bin/Model1: Model1/Model1 | bin
	@cp $^ $@
	@echo "Build $@"

# Additional dependencies to ensure that bin/Model1 gets properly rebuild
Model1/Model1: Model1/src/main.cpp
Model1/Model1: Model1/src/MainModel.cpp Model1/include/MainModel.h
Model1/Model1: Model1/src/Producer12.cpp Model1/include/Producer12.h
Model1/Model1: Model1/src/Producer12/CPP_pr.cpp Model1/include/Producer12/CPP_pr.h
Model1/Model1: Model1/src/Consumer12.cpp Model1/include/Consumer12.h
Model1/Model1: Model1/src/Consumer12/CPP_cons.cpp Model1/include/Consumer12/CPP_cons.h

# protected region additional dependencies on begin
# protected region additional dependencies end