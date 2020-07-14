/**
 * Source file for the example model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "example.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace example { 

example::example(ChannelIn<LUNA::Clock::period_t> *pt_time) :
    Sequential(NULL)
{
  SETNAME(this, "example");

  // Initialize channels
  myProducer12producer_ch1_out_to_Consumer12consumer_ch1_inChannel = new UnbufferedChannel<int, One2In, Out2One>();
  myProducer12producer_ch2_out_to_Consumer12consumer_ch2_inChannel = new UnbufferedChannel<int, One2In, Out2One>();

  // Initialize model objects
  myConsumer12 = new Consumer12::Consumer12(myProducer12producer_ch1_out_to_Consumer12consumer_ch1_inChannel, myProducer12producer_ch2_out_to_Consumer12consumer_ch2_inChannel);
  SETNAME(myConsumer12, "Consumer12");
  myProducer12 = new Producer12::Producer12(myProducer12producer_ch1_out_to_Consumer12consumer_ch1_inChannel, myProducer12producer_ch2_out_to_Consumer12consumer_ch2_inChannel);
  SETNAME(myProducer12, "Producer12");
  mywr1 = new Writer<LUNA::Clock::period_t>(&timeDummy, pt_time);
  SETNAME(mywr1, "wr1");

  // Create PARALLEL group
  myPARALLEL = new Parallel(
    (CSPConstruct *) myProducer12,
    (CSPConstruct *) myConsumer12,
    NULL
  );
  SETNAME(myPARALLEL, "PARALLEL");


  // Register model objects
  this->append_child(myPARALLEL);
  this->append_child(mywr1);

  // protected region constructor on begin
  // protected region constructor end
}

example::~example()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model groups
  delete myPARALLEL;

  // Destroy model objects
  delete mywr1;
  delete myProducer12;
  delete myConsumer12;

  // Destroy channels
  delete myProducer12producer_ch1_out_to_Consumer12consumer_ch1_inChannel;
  delete myProducer12producer_ch2_out_to_Consumer12consumer_ch2_inChannel;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} 
