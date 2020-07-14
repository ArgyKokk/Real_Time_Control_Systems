/**
 * Source file for the XXStepModel model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * 20-sim C++ glue code to connect to StepModel
 * Modifying this file is absolutely not recommended!
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "XXStepModel.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace Step { namespace XXStepModel { 

XXStepModel::XXStepModel(double &output) :
    CodeBlock(), output(output){
  SETNAME(this, "XXStepModel");

  using namespace LUNA::xxsim;

  m_model = new StepModel;


  m_model->addOutput(&output, XXVARIABLE, 0, 1, 1);


  m_model->start();
}

XXStepModel::~XXStepModel()
{
    m_model->stop();

	//@todo Clean up adapters

    delete m_model;
}

void XXStepModel::execute()
{
    m_model->step();

}

// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 
