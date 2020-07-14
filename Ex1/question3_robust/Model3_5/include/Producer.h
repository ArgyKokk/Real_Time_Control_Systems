/**
 * Header file for the Producer model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "Producer/CPP_check.h"
#include "Producer/CPP_pr.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace MainModel { namespace Producer { 

class Producer : public Sequential
{

public:
  // Define constructor and destructor
  Producer(ChannelIn<int> *pr_ch1, ChannelIn<int> *pr_ch2, ChannelIn<int> *pr_ch3);
  virtual ~Producer();

private:

  // Class variables
  int var;

  // Model objects
  CPP_check::CPP_check *myCPP_check;
  CPP_pr::CPP_pr *myCPP_pr;
  Writer<int> *mywriter1;
  Writer<int> *mywriter2;
  Writer<int> *mywriter3;

  // Model groups
  Alternative *myALTERNATIVE;


  // Guard evaluation functions
  bool writer1GuardEvaluate();
  bool writer2GuardEvaluate();
  bool writer3GuardEvaluate();

  // protected region additional class members or functions on begin

  // protected region additional class members or functions end
};

// Close namespace(s)
} } 
