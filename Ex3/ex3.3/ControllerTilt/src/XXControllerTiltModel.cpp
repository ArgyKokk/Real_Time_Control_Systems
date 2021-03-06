/**
 * Source file for the XXControllerTiltModel model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * 20-sim C++ glue code to connect to ControllerTiltModel
 * Modifying this file is absolutely not recommended!
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "XXControllerTiltModel.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace ControllerTilt { namespace XXControllerTiltModel { 

XXControllerTiltModel::XXControllerTiltModel(double &SetPointTilt, double &measIO, double &steerIO) :
    CodeBlock(), SetPointTilt(SetPointTilt), measIO(measIO), steerIO(steerIO){
  SETNAME(this, "XXControllerTiltModel");

  using namespace LUNA::xxsim;

  m_model = new ControllerTiltModel;


  m_model->addOutput(&steerIO, XXVARIABLE, 6, 1, 1);


  m_model->addInput(&measIO, XXVARIABLE, 7, 1, 1);


  m_model->addInput(&SetPointTilt, XXVARIABLE, 8, 1, 1);


  m_model->start();
}

XXControllerTiltModel::~XXControllerTiltModel()
{
    m_model->stop();

	//@todo Clean up adapters

    delete m_model;
}

void XXControllerTiltModel::execute()
{
    m_model->step();
}

// protected region additional functions on begin

// protected region additional functions end

// Close namespace(s)
} } 
