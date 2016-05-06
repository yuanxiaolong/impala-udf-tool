#ifndef HELLOWORLD_UDF_H
#define HELLOWORLD_UDF_H

#include <impala_udf/udf.h>

using namespace impala_udf;


StringVal Hello(FunctionContext* context, const StringVal& arg1);


//StringVal Hello(FunctionContext* context, const IntVal& arg1);

#endif