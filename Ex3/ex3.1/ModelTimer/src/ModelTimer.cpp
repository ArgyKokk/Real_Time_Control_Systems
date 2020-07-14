/**
 * Source file for the ModelTimer model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "ModelTimer.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace ModelTimer { 

ModelTimer::ModelTimer(ChannelIn<int> *oscillator, ChannelIn<LUNA::Clock::period_t> *pt_time) :
    Sequential(NULL)
{
  SETNAME(this, "ModelTimer");

  // Initialize channels
  myProducerpro_out_ch2_to_Consumercons_in_ch2Channel = new UnbufferedChannel<int, One2In, Out2One>();
  myProducerprod_out_ch1_to_Consumercons_in_ch1Channel = new UnbufferedChannel<int, One2In, Out2One>();

  // Initialize model objects
  myConsumer = new Consumer::Consumer(myProducerprod_out_ch1_to_Consumercons_in_ch1Channel, myProducerpro_out_ch2_to_Consumercons_in_ch2Channel);
  SETNAME(myConsumer, "Consumer");
  myProducer = new Producer::Producer(oscillator, myProducerpro_out_ch2_to_Consumercons_in_ch2Channel, myProducerprod_out_ch1_to_Consumercons_in_ch1Channel);
  SETNAME(myProducer, "Producer");
  mytime_wr = new Writer<LUNA::Clock::period_t>(&timeDummy, pt_time);
  SETNAME(mytime_wr, "time_wr");

  // Create PARALLEL group
  myPARALLEL = new Parallel(
    (CSPConstruct *) myProducer,
    (CSPConstruct *) myConsumer,
    NULL
  );
  SETNAME(myPARALLEL, "PARALLEL");


  // Register model objects
  this->append_child(myPARALLEL);
  this->append_child(mytime_wr);

  // protected region constructor on begin
  // protected region constructor end
}

ModelTimer::~ModelTimer()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model groups
  delete myPARALLEL;

  // Destroy model objects
  delete mytime_wr;
  delete myProducer;
  delete myConsumer;

  // Destroy channels
  delete myProducerpro_out_ch2_to_Consumercons_in_ch2Channel;
  delete myProducerprod_out_ch1_to_Consumercons_in_ch1Channel;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} 
