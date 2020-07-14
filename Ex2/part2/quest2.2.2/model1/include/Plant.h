/**
 * Header file for the Plant model
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

namespace MainModel { namespace Plant { 

class Plant : public Sequential
{

public:
  // Define constructor and destructor
  Plant(ChannelOut<int> *IN, ChannelIn<int> *Y);
  virtual ~Plant();

private:

  // Class variables
  int C_IN;
  int Y_OUT;

  // Model objects
  Reader<int> *myC_READER;
  Writer<int> *myY_WRITER;



  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} } 