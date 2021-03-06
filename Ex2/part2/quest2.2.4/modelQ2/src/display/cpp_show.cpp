/**
 * Source file for the cpp_show model
 * Generated by the TERRA CSPm2LUNA generator version 1.1.3
 *
 * protected region document description on begin
 *
 * protected region document description end
 */

#include "display/cpp_show.h"
// protected region additional headers on begin
// Each additional header should get a corresponding dependency in the Makefile
// protected region additional headers end

namespace MainModel { namespace display { namespace cpp_show { 

cpp_show::cpp_show(double &varcon, double &varout, double &varpulse) :
    CodeBlock(), varcon(varcon), varout(varout), varpulse(varpulse){
  SETNAME(this, "cpp_show");

  // protected region constructor on begin
  // protected region constructor end
}

cpp_show::~cpp_show()
{
  // protected region destructor on begin
  // protected region destructor end
}

void cpp_show::execute()
{
  // protected region execute code on begin
	printf("out %f \n",varout);
	printf("control %f \n",varcon);
	printf("pulse %f \n",varpulse);
	struct timespec myTime;
	   double showtime;
	    clock_gettime(CLOCK_REALTIME,&myTime);
	    showtime = (double) myTime.tv_nsec;
	    printf(" time : %f \n",showtime);

  // protected region execute code end
}

// protected region additional functions on begin
// protected region additional functions end

// Close namespace(s)
} } } 
