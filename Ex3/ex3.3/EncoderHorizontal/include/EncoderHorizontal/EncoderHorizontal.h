/**
 * Header file for the EncoderHorizontal model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "encoder_cpp.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace EncoderHorizontal { 

class EncoderHorizontal : public Sequential
{

public:
  // Define constructor and destructor
  EncoderHorizontal(ChannelOut<int> *encoder_pt, ChannelIn<double> *pt_encoderH_out);
  virtual ~EncoderHorizontal();

private:

  // Class variables
  int in;
  double out;

  // Model objects
  encoder_cpp::encoder_cpp *myencoder_cpp;
  Reader<int> *myreader_encoder_h;
  Writer<double> *mywriter_encoder_h;



  // protected region additional class members or functions on begin

  // protected region additional class members or functions end
};

// Close namespace(s)
} 
