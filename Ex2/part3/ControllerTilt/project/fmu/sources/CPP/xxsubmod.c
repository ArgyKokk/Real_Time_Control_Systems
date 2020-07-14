/**********************************************************
 * This file is generated by 20-sim ANSI-C Code Generator
 *
 *  file:  src\xxsubmod.c
 *  subm:  ControllerTilt
 *  model: JIWY-co-sim
 *  expmt: JIWY-co-sim
 *  date:  May 31, 2019
 *  time:  7:03:02 PM
 *  user:  Universiteit Twente
 *  from:  20-sim 4.7 Campus License
 *  build: 4.7.0.8692
 **********************************************************/

/* Standard include files */
#include <stdlib.h>

/* 20-sim include files */
#include "xxmodel.h"
#include "xxinteg.h"
#include "xxfuncs.h"
#include "xxsubmod.h"
#include "MotionProfiles.h"
#include "EulerAngles.h"


/* The initialization function for submodel */
XXBoolean XXInitializeSubmodel (xx_ModelInstance* model_instance)
{
	/* Initialization phase (allocating memory) */
	model_instance->initialize = XXTRUE;
	model_instance->steps = 0;
	XXDiscreteInitialize (model_instance);

	/* initialize the integration method */
	if (XXDiscreteInitialize (model_instance) == XXFALSE)
	{
		return XXFALSE;
	}

	/* Calculate the model for the first time */
	XXCalculateInitial (model_instance);
	XXCalculateStatic (model_instance);
	XXCalculateInput (model_instance);
	XXCalculateDynamic (model_instance);
	XXCalculateOutput (model_instance);

	/* End of initialization phase */
	model_instance->initialize = XXFALSE;

	return XXTRUE;
}

/* The function that calculates the submodel */
XXBoolean XXCalculateSubmodel (xx_ModelInstance* model_instance, XXDouble t, XXDouble outputTime)
{
	/* Copy the time */
	model_instance->time = t;

	/* Calculate the model */
	XXCalculateInput (model_instance);
	if (XXDiscreteStep (model_instance, outputTime) == XXFALSE)
		return XXFALSE;
	XXCalculateOutput (model_instance);
	return XXTRUE;
}

/* The termination function for submodel */
XXBoolean XXTerminateSubmodel (xx_ModelInstance* model_instance, XXDouble t)
{
	/* Copy the time */
	model_instance->time = t;

	/* Calculate the final model equations */
	XXCalculateFinal (model_instance);

	/* and terminate the model itself (releasing memory) */
	XXModelTerminate (model_instance);
	if( XXDiscreteTerminate (model_instance) == XXFALSE)
		return XXFALSE;

	return XXTRUE;
}

