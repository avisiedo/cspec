/*
 *  cspec_output.h   :  ???
 */
#ifndef CSPEC_OUTPUT_H
#define CSPEC_OUTPUT_H

typedef void ( * CSpecOutputStartDescribeFun ) ( const char *descr);
typedef void ( * CSpecOutputEndDescribeFun ) ( );

typedef void ( * CSpecOutputStartItFun ) ( const char *descr);
typedef void ( * CSpecOutputEndItFun ) ( );

typedef void ( * CSpecOutputEvalFun ) (const char*filename, int line_number, const char*assertion, int assertionResult);

typedef struct
{

	CSpecOutputStartDescribeFun		startDescribeFun;
	CSpecOutputEndDescribeFun		endDescribeFun;

	CSpecOutputStartItFun			startItFun;
	CSpecOutputEndItFun				endItFun;

	CSpecOutputEvalFun				evalFun;

} CSpecOutputStruct;

void CSpec_SetOutput(CSpecOutputStruct* output);

#endif