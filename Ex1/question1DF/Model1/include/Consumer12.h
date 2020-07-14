/**
 * Header file for the Consumer12 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "Consumer12/CPP_cons.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace MainModel { namespace Consumer12 { 

class Consumer12 : public Sequential
{

public:
  // Define constructor and destructor
  Consumer12(ChannelOut<int> *consumer_ch1_in, ChannelOut<int> *consumer_ch2_in);
  virtual ~Consumer12();

private:

  // Class variables
  int varC1;
  int varC2;

  // Model objects
  CPP_cons::CPP_cons *myCPP_cons;
  Reader<int> *myconsumer_reader_ch1;
  Reader<int> *myconsumer_reader_ch2;

  // Model groups
  Sequential *mySEQUENTIAL;



  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} } 
