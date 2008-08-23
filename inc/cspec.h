/*
 *  cspec.h   :   the main header file
 */
#ifndef CSPEC_H
#define CSPEC_H

/* Include private macros and function definitions */
#include "cspec_config.h"
#include "cspec_private.h"
#include "cspec_output.h"

/* Public macros */
#define DEFINE_DESCRIPTION(x)				  void x ## _describe();
#define DESCRIPTION(x)						  x ## _describe

#define DESCRIBE(x, y)                        void x ## _describe () { CSpec_StartDescribe(y);
#define END_DESCRIBE                          CSpec_EndDescribe(); }

#define IT(x)                                 CSpec_StartIt(x);
#define END_IT                                CSpec_EndIt() ;

#define SHOULD_BE_TRUE(x)					  CSPEC_EVAL(x) 
#define SHOULD_EQUAL(x, y)                    CSPEC_EVAL(x == y) 
#define SHOULD_EQUAL_DOUBLE(x, y, delta)      CSPEC_EVAL( cspec_fabs(x - y) <= delta )
#define SHOULD_MATCH(x, y)                    SHOULD_EQUAL( cspec_strcmp(x, y)  , 0   )

#define SHOULD_BE_FALSE(x)					  CSPEC_EVAL( !(x) )
#define SHOULD_NOT_EQUAL(x, y)                CSPEC_EVAL(x != y) 
#define SHOULD_NOT_EQUAL_DOUBLE(x, y, delta)  CSPEC_EVAL( cspec_fabs(x - y) > delta )
#define SHOULD_NOT_MATCH(x, y)                SHOULD_NOT_EQUAL( cspec_strcmp(x, y)  , 0   )

typedef void ( * CSpecDescriptionFun ) ( );
void CSpec_Run( CSpecDescriptionFun fun, CSpecOutputStruct* output);

#endif