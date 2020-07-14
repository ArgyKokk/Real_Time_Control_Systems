# build.mk file for Model3_5.cspm, provide information to 'project MakeFile' 
# Generated by the TERRA CSPm2LUNA generator version 1.1.3
#
# protected region document description on begin

# protected region document description end

TARGETS+=bin/Model3_5

Model3_5/Model3_5:
	@echo
	@echo "Building $@"
	@make -C Model3_5 --no-print-directory

bin/Model3_5: Model3_5/Model3_5 | bin
	@cp $^ $@
	@echo "Build $@"

# Additional dependencies to ensure that bin/Model3_5 gets properly rebuild
Model3_5/Model3_5: Model3_5/src/main.cpp
Model3_5/Model3_5: Model3_5/src/MainModel.cpp Model3_5/include/MainModel.h
Model3_5/Model3_5: Model3_5/src/Producer.cpp Model3_5/include/Producer.h
Model3_5/Model3_5: Model3_5/src/Producer/CPP_pr.cpp Model3_5/include/Producer/CPP_pr.h
Model3_5/Model3_5: Model3_5/src/Producer/CPP_check.cpp Model3_5/include/Producer/CPP_check.h
Model3_5/Model3_5: Model3_5/src/Consumer.cpp Model3_5/include/Consumer.h
Model3_5/Model3_5: Model3_5/src/Consumer/CPP_r1.cpp Model3_5/include/Consumer/CPP_r1.h
Model3_5/Model3_5: Model3_5/src/Consumer/CPP_r2.cpp Model3_5/include/Consumer/CPP_r2.h
Model3_5/Model3_5: Model3_5/src/Consumer/CPP_r3.cpp Model3_5/include/Consumer/CPP_r3.h

# protected region additional dependencies on begin

# protected region additional dependencies end