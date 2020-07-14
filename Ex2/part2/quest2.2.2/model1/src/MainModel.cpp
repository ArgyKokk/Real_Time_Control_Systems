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

  // Initialize channels
  myLoopConCOUT_to_PlantINChannel = new UnbufferedChannel<int, One2In, Out2One>();
  myPlantY_to_LoopConMVChannel = new UnbufferedChannel<int, One2In, Out2One>();
  mySeqConout_to_LoopConSPChannel = new UnbufferedChannel<int, One2In, Out2One>();

  // Initialize model objects
  myLoopCon = new LoopCon::LoopCon(myLoopConCOUT_to_PlantINChannel, myPlantY_to_LoopConMVChannel, mySeqConout_to_LoopConSPChannel);
  SETNAME(myLoopCon, "LoopCon");
  myPlant = new Plant::Plant(myLoopConCOUT_to_PlantINChannel, myPlantY_to_LoopConMVChannel);
  SETNAME(myPlant, "Plant");
  mySeqCon = new SeqCon::SeqCon(mySeqConout_to_LoopConSPChannel);
  SETNAME(mySeqCon, "SeqCon");

  // Create PARALLEL group
  myPARALLEL = new Parallel(
    (CSPConstruct *) mySeqCon,
    (CSPConstruct *) myLoopCon,
    (CSPConstruct *) myPlant,
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
  delete mySeqCon;
  delete myPlant;
  delete myLoopCon;

  // Destroy channels
  delete myLoopConCOUT_to_PlantINChannel;
  delete myPlantY_to_LoopConMVChannel;
  delete mySeqConout_to_LoopConSPChannel;
}



// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} 
