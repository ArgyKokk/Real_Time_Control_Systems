/**
 * Source file for the CPP_r1 model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "Consumer/CPP_r1.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace Consumer { namespace CPP_r1 { 

CPP_r1::CPP_r1(int &var1) :
    CodeBlock(), var1(var1){
  SETNAME(this, "CPP_r1");

  // protected region constructor on begin
  // protected region constructor end
}

CPP_r1::~CPP_r1()
{
  // protected region destructor on begin
  // protected region destructor end
}

void CPP_r1::execute()
{
  // protected region execute code on begin
  printf("Channel 1 received: %d \n",var1);
  // protected region execute code end
}

// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } } 
