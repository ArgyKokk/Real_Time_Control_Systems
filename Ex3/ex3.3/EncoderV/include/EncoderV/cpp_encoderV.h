/**
 * Header file for the cpp_encoderV model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace EncoderV { namespace cpp_encoderV { 

class cpp_encoderV : public CodeBlock
{

public:
  // Define constructor and destructor
  cpp_encoderV(int &input, double &output);
  virtual ~cpp_encoderV();

  void execute();

private:

  // Class variables
  int &input;
  double &output;

  // protected region additional class members or functions on begin

  // protected region additional class members or functions end
};

// Close namespace(s)
} } 
