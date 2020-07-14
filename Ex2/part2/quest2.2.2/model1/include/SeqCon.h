/**
 * Header file for the SeqCon model
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

namespace MainModel { namespace SeqCon { 

class SeqCon : public Sequential
{

public:
  // Define constructor and destructor
  SeqCon(ChannelIn<int> *out);
  virtual ~SeqCon();

private:

  // Class variables
  int VAR1;

  // Model objects
  Writer<int> *myPULSE_WRITER;



  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} } 
