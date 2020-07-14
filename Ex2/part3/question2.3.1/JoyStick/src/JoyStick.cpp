/**
 * Source file for the JoyStick model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "JoyStick.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace JoyStick { 

JoyStick::JoyStick(ChannelIn<double> *JoyStickPan, ChannelIn<double> *JoyStickTilt) :
    Sequential(NULL)
{
  SETNAME(this, "JoyStick");

  // Initialize model objects
  myFMI_JoyStick = new FMI_JoyStick::FMI_JoyStick(v_JoyStickPan, v_JoyStickTilt);
  SETNAME(myFMI_JoyStick, "FMI_JoyStick");
  myw_JoyStickPan = new Writer<double>(&v_JoyStickPan, JoyStickPan);
  SETNAME(myw_JoyStickPan, "w_JoyStickPan");
  myw_JoyStickTilt = new Writer<double>(&v_JoyStickTilt, JoyStickTilt);
  SETNAME(myw_JoyStickTilt, "w_JoyStickTilt");

  // Create IO group
  myIO = new Parallel(
    (CSPConstruct *) myw_JoyStickPan,
    (CSPConstruct *) myw_JoyStickTilt,
    NULL
  );
  SETNAME(myIO, "IO");


  // Register model objects
  this->append_child(myIO);
  this->append_child(myFMI_JoyStick);

  // protected region constructor on begin
  // protected region constructor end
}

JoyStick::~JoyStick()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model groups
  delete myIO;

  // Destroy model objects
  delete myw_JoyStickTilt;
  delete myw_JoyStickPan;
  delete myFMI_JoyStick;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} 