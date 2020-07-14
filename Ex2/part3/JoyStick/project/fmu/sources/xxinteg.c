/**********************************************************
 * This file is generated by 20-sim ANSI-C Code Generator
 *
 *  file:  src\xxinteg.c
 *  subm:  JoyStick
 *  model: JIWY-co-sim
 *  expmt: JIWY-co-sim
 *  date:  May 31, 2019
 *  time:  7:02:08 PM
 *  user:  Universiteit Twente
 *  from:  20-sim 4.7 Campus License
 *  build: 4.7.0.8692
 **********************************************************/

/* This file describes the integration methods
   that are supplied for computation.

   Currently the following methods are supported:
   * Euler
   * RungeKutta2
   * RungeKutta4
   * Vode Adams
   but it is easy for the user to add their own
   integration methods with these two as an example.
*/

/* the system include files */
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* our own include files */
#include "xxinteg.h"
#include "xxmodel.h"

#define FMI_LOG_ERROR(mi,message)	if (mi->fmiCallbackFunctions != NULL && mi->fmiCallbackFunctions->logger != NULL)\
	{\
		mi->fmiCallbackFunctions->logger(NULL, "JoyStick", fmi2Error, "error",\
			message);\
	}


/*********************************************************************
 * Discrete integration method
 *********************************************************************/

/* the initialization of the Discrete integration method */
XXBoolean XXDiscreteInitialize (xx_ModelInstance* model_instance)
{
	/* The internal time is set to the start time
	 * so set our discrete time to this value as well
	 */
	model_instance->m_discrete_time = model_instance->time;
	model_instance->major = XXTRUE;

	return XXTRUE;
}

/* the termination of the Discrete integration method */
XXBoolean XXDiscreteTerminate (xx_ModelInstance* model_instance)
{
	/* nothing to be done */
	return XXTRUE;
}

/* the Discrete integration method itself */
XXBoolean XXDiscreteStep (xx_ModelInstance* model_instance, XXDouble outputTime)
{
	/* no states in the model */
	/* increment the simulation discrete time */
	model_instance->m_discrete_time += model_instance->step_size;

	/* and set the continious time to the discrete time */
	model_instance->time = model_instance->m_discrete_time;

	model_instance->major = XXTRUE;

	/* evaluate the dynamic part to calculate the new rates */
	XXCalculateDynamic (model_instance);

	return XXTRUE;
}
