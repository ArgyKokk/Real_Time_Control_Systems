/**
 * Header file for the plant_compute model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#pragma once

#include "csp/CSP.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

using namespace LUNA::CSP;

namespace plant { namespace plant_compute { 

class plant_compute : public CodeBlock
{

public:
  // Define constructor and destructor
  plant_compute(double &controlPan, double &controlTilt, double &pan, double &tilt);
  virtual ~plant_compute();

  void execute();
  void *context = NULL;
    void *zmqsocket = NULL;

private:

  // Class variables
  double &controlPan;
  double &controlTilt;
  double &pan;
  double &tilt;

  // protected region additional class members or functions on begin
  // protected region additional class members or functions end
};

// Close namespace(s)
} } 