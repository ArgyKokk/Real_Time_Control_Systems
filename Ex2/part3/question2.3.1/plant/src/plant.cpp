/**
 * Source file for the plant model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "plant.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace plant { 

plant::plant(ChannelOut<double> *PanIn, ChannelIn<double> *PanOut, ChannelOut<double> *TiltIn, ChannelIn<double> *TiltOut) :
    Sequential(NULL)
{
  SETNAME(this, "plant");

  // Initialize model objects
  myplant_compute = new plant_compute::plant_compute(v_ControlPan, v_ControlTilt, v_Pan, v_Tilt);
  SETNAME(myplant_compute, "plant_compute");
  myreaderPan = new Reader<double>(&v_ControlPan, PanIn);
  SETNAME(myreaderPan, "readerPan");
  myreaderTilt = new Reader<double>(&v_ControlTilt, TiltIn);
  SETNAME(myreaderTilt, "readerTilt");
  mywriterPan = new Writer<double>(&v_Pan, PanOut);
  SETNAME(mywriterPan, "writerPan");
  mywriterTilt = new Writer<double>(&v_Tilt, TiltOut);
  SETNAME(mywriterTilt, "writerTilt");

  // Create PARALLELP group
  myPARALLELP = new Parallel(
    (CSPConstruct *) myreaderPan,
    (CSPConstruct *) mywriterPan,
    NULL
  );
  SETNAME(myPARALLELP, "PARALLELP");

  // Create PARALLELT group
  myPARALLELT = new Parallel(
    (CSPConstruct *) myreaderTilt,
    (CSPConstruct *) mywriterTilt,
    NULL
  );
  SETNAME(myPARALLELT, "PARALLELT");

  // Create PARALLEL group
  myPARALLEL = new Parallel(
    (CSPConstruct *) myPARALLELP,
    (CSPConstruct *) myPARALLELT,
    NULL
  );
  SETNAME(myPARALLEL, "PARALLEL");


  // Register model objects
  this->append_child(myPARALLEL);
  this->append_child(myplant_compute);

  // protected region constructor on begin
  // protected region constructor end
}

plant::~plant()
{
  // TODO Properly destroy all additional objects that got defined in the constructor

  // protected region destructor on begin
  // protected region destructor end

  // Destroy model groups
  delete myPARALLEL;
  delete myPARALLELP;
  delete myPARALLELT;

  // Destroy model objects
  delete mywriterTilt;
  delete mywriterPan;
  delete myreaderTilt;
  delete myreaderPan;
  delete myplant_compute;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} 
