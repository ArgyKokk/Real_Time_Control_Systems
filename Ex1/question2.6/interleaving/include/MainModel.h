/**
 * Header file for the MainModel model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"

// Models
#include "A.h"
#include "B.h"
#include "C.h"
#include "D.h"

// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace MainModel { 

class MainModel : public Recursion<CSProcess>
{

public:
  // Define constructor and destructor
  MainModel();
  virtual ~MainModel();

private:

  // Model objects
  A::A *myA;
  B::B *myB;
  C::C *myC;
  D::D *myD;

  // Model groups
  Parallel *myPARALLEL;



  // protected region additional class members or functions on begin

  // protected region additional class members or functions end
};

// Close namespace(s)
} 
