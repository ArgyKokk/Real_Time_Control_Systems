/**
 * Source file for the cpp_encoderV model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "cpp_encoderV.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace EncoderV { namespace cpp_encoderV { 

cpp_encoderV::cpp_encoderV(int &input, double &output) :
    CodeBlock(), input(input), output(output){
  SETNAME(this, "cpp_encoderV");

  // protected region constructor on begin

  // protected region constructor end
}

cpp_encoderV::~cpp_encoderV()
{
  // protected region destructor on begin

  // protected region destructor end
}

void cpp_encoderV::execute()
{
  // protected region execute code on begin
   this->output = (int32_t) input;
  // protected region execute code end
}

// protected region additional functions on begin

// protected region additional functions end

// Close namespace(s)
} } 