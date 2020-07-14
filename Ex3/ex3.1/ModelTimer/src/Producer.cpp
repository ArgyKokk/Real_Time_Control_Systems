/**
 * Source file for the Producer model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Producer.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace ModelTimer { namespace Producer { 

Producer::Producer(ChannelIn<int> *osci_port, ChannelIn<int> *pro_out_ch2, ChannelIn<int> *prod_out_ch1) :
    Sequential(NULL)
{
  SETNAME(this, "Producer");

  // Initialize model objects
  mycpp_producer = new cpp_producer::cpp_producer(oscSignal, var1, var2);
  SETNAME(mycpp_producer, "cpp_producer");
  mysignalWriter = new Writer<int>(&oscSignal, osci_port);
  SETNAME(mysignalWriter, "signalWriter");
  mywriter_ch1 = new Writer<int>(&var1, prod_out_ch1);
  SETNAME(mywriter_ch1, "writer_ch1");
  mywriter_ch2 = new Writer<int>(&var2, pro_out_ch2);
  SETNAME(mywriter_ch2, "writer_ch2");

  // Create SEQUENTIAL group
  mySEQUENTIAL = new Sequential(
    (CSPConstruct *) mywriter_ch1,
    (CSPConstruct *) mywriter_ch2,
    NULL
  );
  SETNAME(mySEQUENTIAL, "SEQUENTIAL");


  // Register model objects
  this->append_child(mycpp_producer);
  this->append_child(mysignalWriter);
  this->append_child(mySEQUENTIAL);

  // protected region constructor on begin
  // protected region constructor end
}

Producer::~Producer()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model groups
  delete mySEQUENTIAL;

  // Destroy model objects
  delete mywriter_ch2;
  delete mywriter_ch1;
  delete mysignalWriter;
  delete mycpp_producer;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 
