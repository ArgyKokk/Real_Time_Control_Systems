/**
 * Source file for the PWM model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "PWM.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace PWM { 

PWM::PWM(ChannelOut<double> *pwm_in_horizontal, ChannelOut<double> *pwm_in_vertical, ChannelIn<double> *pwm_out_horizontal, ChannelIn<double> *pwm_out_vertical) :
    Parallel(NULL)
{
  SETNAME(this, "PWM");

  // Initialize model objects
  mycpp_pwm_h = new cpp_pwm_h::cpp_pwm_h(inputH, outputH);
  SETNAME(mycpp_pwm_h, "cpp_pwm_h");
  mycpp_pwm_v = new cpp_pwm_v::cpp_pwm_v(inputV, outputV);
  SETNAME(mycpp_pwm_v, "cpp_pwm_v");
  myreaderPWM_h = new Reader<double>(&inputH, pwm_in_horizontal);
  SETNAME(myreaderPWM_h, "readerPWM_h");
  myreader_pwm_vertical = new Reader<double>(&inputV, pwm_in_vertical);
  SETNAME(myreader_pwm_vertical, "reader_pwm_vertical");
  mywriterPWM_h = new Writer<double>(&outputH, pwm_out_horizontal);
  SETNAME(mywriterPWM_h, "writerPWM_h");
  mywriterPWM_v = new Writer<double>(&outputV, pwm_out_vertical);
  SETNAME(mywriterPWM_v, "writerPWM_v");

  // Create SEQUENTIALH group
  mySEQUENTIALH = new Sequential(
    (CSPConstruct *) myreaderPWM_h,
    (CSPConstruct *) mycpp_pwm_h,
    (CSPConstruct *) mywriterPWM_h,
    NULL
  );
  SETNAME(mySEQUENTIALH, "SEQUENTIALH");

  // Create SEQUENTIALV group
  mySEQUENTIALV = new Sequential(
    (CSPConstruct *) myreader_pwm_vertical,
    (CSPConstruct *) mycpp_pwm_v,
    (CSPConstruct *) mywriterPWM_v,
    NULL
  );
  SETNAME(mySEQUENTIALV, "SEQUENTIALV");


  // Register model objects
  this->append_child(mySEQUENTIALH);
  this->append_child(mySEQUENTIALV);

  // protected region constructor on begin

  // protected region constructor end
}

PWM::~PWM()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin

  // protected region destructor end

  // Destroy model groups
  delete mySEQUENTIALH;
  delete mySEQUENTIALV;

  // Destroy model objects
  delete mywriterPWM_v;
  delete mywriterPWM_h;
  delete myreader_pwm_vertical;
  delete myreaderPWM_h;
  delete mycpp_pwm_v;
  delete mycpp_pwm_h;
}



// protected region additional functions on begin

// protected region additional functions end

// Close namespace(s)
} 