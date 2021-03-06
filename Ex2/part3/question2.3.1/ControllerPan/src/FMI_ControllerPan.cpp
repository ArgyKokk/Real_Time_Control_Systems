/**
 * Source file for the FMI_ControllerPan model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * FMI C++ glue code to connect to ControllerPan
 * Modifying this file is absolutely not recommended!
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "FMI_ControllerPan.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end
#include "timer/GlobalTime.h"
namespace ControllerPan { namespace FMI_ControllerPan { 

FMI_ControllerPan::FMI_ControllerPan(double &SetPointPan, double &measIO, double &steerIO) :
    CodeBlock(), SetPointPan(SetPointPan), measIO(measIO), steerIO(steerIO){
  SETNAME(this, "FMI_ControllerPan");

// Create the text for the header of the measurement log
std::string measurementNames = "Time,SetPointPan,measIO,steerIO";
  
// Initialization of the log functions
logger->initLogger("measurement_ControllerPan.csv","log.txt",measurementNames);

// Load shared lib
handle = dlopen("/usr/local/lib/libSOControllerPan.so",RTLD_LAZY);

// Instantiation of the FMU
f_instantiate = (fp_instantiate)dlsym(handle,"fmi2Instantiate");
s1 = f_instantiate("ControllerPan", fmi2CoSimulation,"{dcca97bd-14bb-4b74-a62c-9203e2f1173b}", "", &cbf, fmi2True, fmi2False);
if(s1 == NULL)
{
   logger->fmiLog(NULL, "ControllerPan", fmi2Error, "error", "fmi2Instatiate is not created.");
}  
else
{
   logger->fmiLog(NULL, "ControllerPan", fmi2OK, "info","fmi2Instatiate is created correctly.");
}

// Set variables for simulation
timeStep = 0.01;
currentTime = 0.0;
status = fmi2OK;
simulationFinished = false;

f_setup = (fp_setup)dlsym(handle,"fmi2SetupExperiment");
f_setup(s1,fmi2False, 0.0, 0.0, fmi2True, 20.0);

fmi2EnterInitializationMode(s1);

fmi2ValueReference parameterRealRef[10] = {0,1,2,3,4,5,6,7,8,9};
fmi2Real parameterRealVal[10] = {10.0,5.0,0.1,1000.0,0.003141592,1.0,-1.0,0.0,0.0,0.0};
fmi2SetReal(s1,parameterRealRef,10,parameterRealVal);
  
  

fmi2ValueReference outputRealRef[1] = {16};
fmi2Real outputRealVal[1] = {0};
fmi2GetReal(s1,outputRealRef,1,outputRealVal);
steerIO = outputRealVal[0]; 
  
  

f_exit = (fp_exit)dlsym(handle,"fmi2ExitInitializationMode"); 
f_exit(s1);

g_time = currentTime;
g_stepsize = timeStep;
}

FMI_ControllerPan::~FMI_ControllerPan()
{
fmi2Terminate(s1);
fmi2FreeInstance(s1);
}

void FMI_ControllerPan::execute()
{

if(simulationFinished == false && status == fmi2OK)
{
  fmi2ValueReference inputRealRef[2] = {18,17};
  fmi2Real inputRealVal[2] = {SetPointPan,measIO};
  fmi2SetReal(s1,inputRealRef,2,inputRealVal);
  
  
  
  
  // Save the values of the input and output to a file
  logger->saveMeasurementPoint(std::to_string(currentTime) + "," + std::to_string(SetPointPan) + "," + std::to_string(measIO) + "," + std::to_string(steerIO));
  
  if(g_time < 20.0)
  {  
  	f_doStep = (fp_doStep)dlsym(handle,"fmi2DoStep");
    if(f_doStep(s1,g_time,g_stepsize,fmi2True) != fmi2OK)
    {
      printf("FMI: Error no simulation\n");
    }
    //currentTime = currentTime + timeStep;
  
    fmi2ValueReference outputRealRef[1] = {16};
    fmi2Real outputRealVal[1] = {0};
    fmi2GetReal(s1,outputRealRef,1,outputRealVal);
    steerIO = outputRealVal[0]; 
  
  
  }
  else
  {
    simulationFinished = true;
  }
}
else if(status != fmi2OK)
{
  printf("FMU: The simulation is stopped because of an error\n");
  std::_Exit(0);
}
else
{
  printf("FMU: Simulation is done\n");
  std::_Exit(0);
}
}

// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } 
