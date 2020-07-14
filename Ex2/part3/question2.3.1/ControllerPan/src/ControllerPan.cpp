/**
 * Source file for the ControllerPan model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "ControllerPan.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace ControllerPan { 

ControllerPan::ControllerPan(ChannelOut<double> *SetPointPan, ChannelOut<double> *measIO, ChannelIn<double> *steerIO) :
    Sequential(NULL)
{
  SETNAME(this, "ControllerPan");

  // Initialize model objects
  myFMI_ControllerPan = new FMI_ControllerPan::FMI_ControllerPan(v_SetPointPan, v_measIO, v_steerIO);
  SETNAME(myFMI_ControllerPan, "FMI_ControllerPan");
  myr_SetPointPan = new Reader<double>(&v_SetPointPan, SetPointPan);
  SETNAME(myr_SetPointPan, "r_SetPointPan");
  myr_measIO = new Reader<double>(&v_measIO, measIO);
  SETNAME(myr_measIO, "r_measIO");
  myw_steerIO = new Writer<double>(&v_steerIO, steerIO);
  SETNAME(myw_steerIO, "w_steerIO");

  // Create IO group
  myIO = new Parallel(
    (CSPConstruct *) myw_steerIO,
    (CSPConstruct *) myr_measIO,
    (CSPConstruct *) myr_SetPointPan,
    NULL
  );
  SETNAME(myIO, "IO");


  // Register model objects
  this->append_child(myIO);
  this->append_child(myFMI_ControllerPan);

  // protected region constructor on begin
  // protected region constructor end
}

ControllerPan::~ControllerPan()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model groups
  delete myIO;

  // Destroy model objects
  delete myw_steerIO;
  delete myr_measIO;
  delete myr_SetPointPan;
  delete myFMI_ControllerPan;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} 
