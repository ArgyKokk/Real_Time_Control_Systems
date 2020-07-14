/**
 * Header file for the Model32 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "cpp_produce.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace Model32 { 

class Model32 : public Sequential
{

public:
  // Define constructor and destructor
  Model32(ChannelIn<double> *pt_out, ChannelIn<LUNA::Clock::period_t> *pt_timer);
  virtual ~Model32();

private:

  // Class variables
  double output;
  LUNA::Clock::period_t timeDummy;

  // Model objects
  cpp_produce::cpp_produce *mycpp_produce;
  Writer<double> *mywrOut;
  Writer<LUNA::Clock::period_t> *mywriter_time;

  // Model groups
  Sequential *mySEQUENTIAL;



  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} 