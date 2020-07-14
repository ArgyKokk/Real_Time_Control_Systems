/**
 * Header file for the CPP_pr model
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

namespace MainModel { namespace Producer12 { namespace CPP_pr { 

class CPP_pr : public CodeBlock
{

public:
  // Define constructor and destructor
  CPP_pr(int &var1, int &var2);
  virtual ~CPP_pr();

  void execute();

private:

  // Class variables
  int &var1;
  int &var2;

  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} } } 
