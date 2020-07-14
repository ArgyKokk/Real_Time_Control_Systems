/**
 * Header file for the MainModel model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "Controller/Controller.h"
#include "LinearSystem/LinearSystem.h"
#include "Step/Step.h"
#include "display.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace MainModel { 

class MainModel : public Recursion<CSPConstruct>
{

public:
  // Define constructor and destructor
  MainModel();
  virtual ~MainModel();

private:

  // Channel definitions
  BufferedChannel<double, One2In, Out2One> *myLoopConcontrol_out_to_displaycontrolChannel;
  UnbufferedChannel<double, One2In, Out2One> *myLoopConoutput_to_PlantuChannel;
  BufferedChannel<double, One2In, Out2One> *myPlanty_out_to_displayy_outChannel;
  UnbufferedChannel<double, One2In, Out2One> *myPlanty_to_LoopConMVChannel;
  UnbufferedChannel<double, One2In, Out2One> *mySeqConoutput_to_LoopConSPChannel;
  BufferedChannel<double, One2In, Out2One> *mySeqConpulse_out_to_displaypulseChannel;

  // Model objects
  Controller::Controller *myLoopCon;
  LinearSystem::LinearSystem *myPlant;
  Step::Step *mySeqCon;
  display::display *mydisplay;

  // Model groups
  Parallel *myPARALLEL;
  PriParallel *myPRI_PARALLEL;



  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} 
