/**
 * Header file for the ModelEn model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "cpp_encoder.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace ModelEn { 

class ModelEn : public Sequential
{

public:
  // Define constructor and destructor
  ModelEn(ChannelOut<int> *pt_out, ChannelIn<LUNA::Clock::period_t> *pt_timer);
  virtual ~ModelEn();

private:

  // Class variables
  int encoder;
  LUNA::Clock::period_t timeDummy;

  // Model objects
  cpp_encoder::cpp_encoder *mycpp_encoder;
  Reader<int> *myreader_encoder;
  Writer<LUNA::Clock::period_t> *mywr_timer;

  // Model groups
  Sequential *mySEQUENTIAL;



  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} 
