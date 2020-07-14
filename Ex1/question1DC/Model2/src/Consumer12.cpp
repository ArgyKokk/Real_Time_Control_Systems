/**
 * Source file for the Consumer12 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Consumer12.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Consumer12 { 

Consumer12::Consumer12(ChannelOut<int> *consumer_ch1_in, ChannelOut<int> *consumer_ch2_in) :
    Sequential(NULL)
{
  SETNAME(this, "Consumer12");

  // Initialize model objects
  myCPP_cons21 = new CPP_cons21::CPP_cons21(varC1, varC2);
  SETNAME(myCPP_cons21, "CPP_cons21");
  myconsumer_reader_ch1 = new Reader<int>(&varC1, consumer_ch1_in);
  SETNAME(myconsumer_reader_ch1, "consumer_reader_ch1");
  myconsumer_reader_ch2 = new Reader<int>(&varC2, consumer_ch2_in);
  SETNAME(myconsumer_reader_ch2, "consumer_reader_ch2");

  // Create SEQUENTIAL group
  mySEQUENTIAL = new Sequential(
    (CSPConstruct *) myconsumer_reader_ch2,
    (CSPConstruct *) myconsumer_reader_ch1,
    NULL
  );
  SETNAME(mySEQUENTIAL, "SEQUENTIAL");


  // Register model objects
  this->append_child(mySEQUENTIAL);
  this->append_child(myCPP_cons21);

  // protected region constructor on begin
  // protected region constructor end
}

Consumer12::~Consumer12()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model groups
  delete mySEQUENTIAL;

  // Destroy model objects
  delete myconsumer_reader_ch2;
  delete myconsumer_reader_ch1;
  delete myCPP_cons21;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 
