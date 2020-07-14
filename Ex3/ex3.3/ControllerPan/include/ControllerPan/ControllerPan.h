/**
 * Header file for the ControllerPan model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "XXControllerPanModel.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace ControllerPan { 

class ControllerPan : public Sequential
{

public:
  // Define constructor and destructor
  ControllerPan(ChannelOut<double> *SetPointPan, ChannelOut<double> *measIO, ChannelIn<double> *steerIO);
  virtual ~ControllerPan();

private:

  // Class variables
  double v_SetPointPan;
  double v_measIO;
  double v_steerIO;

  // Model objects
  XXControllerPanModel::XXControllerPanModel *myXXControllerPanModel;
  Reader<double> *myr_SetPointPan;
  Reader<double> *myr_measIO;
  Writer<double> *myw_steerIO;

  // Model groups
  Parallel *myINS;



  // protected region additional class members or functions on begin

  // protected region additional class members or functions end
};

// Close namespace(s)
} 