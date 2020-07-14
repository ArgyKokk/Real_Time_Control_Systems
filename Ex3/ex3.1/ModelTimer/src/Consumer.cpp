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

namespace ModelTimer { namespace Consumer { 

Consumer::Consumer(ChannelOut<int> *cons_in_ch1, ChannelOut<int> *cons_in_ch2) :
    Sequential(NULL)
{
  SETNAME(this, "Consumer");

  // Initialize model objects
  mycpp_consumer = new cpp_consumer::cpp_consumer(varC1, varC2);
  SETNAME(mycpp_consumer, "cpp_consumer");
  myreader_cons_ch1 = new Reader<int>(&varC1, cons_in_ch1);
  SETNAME(myreader_cons_ch1, "reader_cons_ch1");
  myreader_cons_ch2 = new Reader<int>(&varC2, cons_in_ch2);
  SETNAME(myreader_cons_ch2, "reader_cons_ch2");

  // Create SEQUENTIAL1 group
  mySEQUENTIAL1 = new Sequential(
    (CSPConstruct *) myreader_cons_ch1,
    (CSPConstruct *) myreader_cons_ch2,
    NULL
  );
  SETNAME(mySEQUENTIAL1, "SEQUENTIAL1");


  // Register model objects
  this->append_child(mySEQUENTIAL1);
  this->append_child(mycpp_consumer);

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

  // Destroy model objects
  delete myreader_cons_ch2;
  delete myreader_cons_ch1;
  delete mycpp_consumer;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 