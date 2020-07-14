/**
 * Source file for the Consumer model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Consumer.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Consumer { 

Consumer::Consumer(GuardedChannelOut<int> *cons1, GuardedChannelOut<int> *cons2, GuardedChannelOut<int> *cons3) :
    Alternative()
{
  SETNAME(this, "Consumer");

  // Initialize model objects
  myCPP_r1 = new CPP_r1::CPP_r1(var1);
  SETNAME(myCPP_r1, "CPP_r1");
  myCPP_r2 = new CPP_r2::CPP_r2(var2);
  SETNAME(myCPP_r2, "CPP_r2");
  myCPP_r3 = new CPP_r3::CPP_r3(var3);
  SETNAME(myCPP_r3, "CPP_r3");
  myreader1 = new GuardedReader<int>(&var1, cons1);
  SETNAME(myreader1, "reader1");
  myreader2 = new GuardedReader<int>(&var2, cons2);
  SETNAME(myreader2, "reader2");
  myvar3 = new GuardedReader<int>(&var3, cons3);
  SETNAME(myvar3, "var3");

  // Create SEQUENTIAL1 group
  mySEQUENTIAL1 = new Sequential(
    (CSPConstruct *) myCPP_r1,
    NULL
  );
  SETNAME(mySEQUENTIAL1, "SEQUENTIAL1");

  // Create SEQUENTIAL2 group
  mySEQUENTIAL2 = new Sequential(
    (CSPConstruct *) myCPP_r2,
    NULL
  );
  SETNAME(mySEQUENTIAL2, "SEQUENTIAL2");

  // Create SEQUENTIAL3 group
  mySEQUENTIAL3 = new Sequential(
    (CSPConstruct *) myCPP_r3,
    NULL
  );
  SETNAME(mySEQUENTIAL3, "SEQUENTIAL3");

  // Register sequential groups to Channel Guarded Processes
  myreader1->setToActivate(mySEQUENTIAL1);
  myreader2->setToActivate(mySEQUENTIAL2);
  myvar3->setToActivate(mySEQUENTIAL3);

  // Register model objects
  this->append_child(myreader2);
  this->append_child(myvar3);
  this->append_child(myreader1);

  // protected region constructor on begin

  // protected region constructor end
}

Consumer::~Consumer()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin

  // protected region destructor end

  // Destroy model groups
  delete mySEQUENTIAL1;
  delete mySEQUENTIAL2;
  delete mySEQUENTIAL3;

  // Destroy model objects
  delete myvar3;
  delete myreader2;
  delete myreader1;
  delete myCPP_r3;
  delete myCPP_r2;
  delete myCPP_r1;
}



// protected region additional functions on begin

// protected region additional functions end

// Close namespace(s)
} } 
