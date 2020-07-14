/**
 * Source file for the ControllerTilt model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "ControllerTilt.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace ControllerTilt { 

ControllerTilt::ControllerTilt(ChannelOut<double> *SetPointTilt, ChannelOut<double> *measIO, ChannelIn<double> *steerIO) :
    Sequential(NULL)
{
  SETNAME(this, "ControllerTilt");

  // Initialize model objects
  myFMI_ControllerTilt = new FMI_ControllerTilt::FMI_ControllerTilt(v_SetPointTilt, v_measIO, v_steerIO);
  SETNAME(myFMI_ControllerTilt, "FMI_ControllerTilt");
  myr_SetPointTilt = new Reader<double>(&v_SetPointTilt, SetPointTilt);
  SETNAME(myr_SetPointTilt, "r_SetPointTilt");
  myr_measIO = new Reader<double>(&v_measIO, measIO);
  SETNAME(myr_measIO, "r_measIO");
  myw_steerIO = new Writer<double>(&v_steerIO, steerIO);
  SETNAME(myw_steerIO, "w_steerIO");

  // Create IO group
  myIO = new Parallel(
    (CSPConstruct *) myw_steerIO,
    (CSPConstruct *) myr_measIO,
    (CSPConstruct *) myr_SetPointTilt,
    NULL
  );
  SETNAME(myIO, "IO");


  // Register model objects
  this->append_child(myIO);
  this->append_child(myFMI_ControllerTilt);

  // protected region constructor on begin
  // protected region constructor end
}

ControllerTilt::~ControllerTilt()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model groups
  delete myIO;

  // Destroy model objects
  delete myw_steerIO;
  delete myr_measIO;
  delete myr_SetPointTilt;
  delete myFMI_ControllerTilt;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} 
