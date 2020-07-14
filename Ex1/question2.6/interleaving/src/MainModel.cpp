/**
 * Source file for the MainModel model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "MainModel.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { 

MainModel::MainModel() :
    Recursion<CSProcess>()
{
  SETNAME(this, "MainModel");

  // Initialize model objects
  myA = new A::A();
  SETNAME(myA, "A");
  myB = new B::B();
  SETNAME(myB, "B");
  myC = new C::C();
  SETNAME(myC, "C");
  myD = new D::D();
  SETNAME(myD, "D");

  // Create PARALLEL group
  myPARALLEL = new Parallel(
    (CSPConstruct *) myA,
    (CSPConstruct *) myB,
    (CSPConstruct *) myC,
    (CSPConstruct *) myD,
    NULL
  );
  SETNAME(myPARALLEL, "PARALLEL");

  // Register PARALLEL as top-level recursive object
  setToActivate(myPARALLEL);
  setEvaluateCondition(true);


  // protected region constructor on begin

  // protected region constructor end
}

MainModel::~MainModel()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin

  // protected region destructor end

  // Destroy model groups
  delete myPARALLEL;

  // Destroy model objects
  delete myD;
  delete myC;
  delete myB;
  delete myA;
}



// protected region additional functions on begin

// protected region additional functions end

// Close namespace(s)
} 
