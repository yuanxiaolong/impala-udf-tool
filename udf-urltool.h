//
// Created by xiaolong.yuanxl on 16-5-6.
//

#ifndef URLTOOL_UDF_H
#define URLTOOL_UDF_H

#include <impala_udf/udf.h>
#include <string>

using namespace impala_udf;
using namespace std;


StringVal UrlDecoder(FunctionContext* context, const StringVal& arg1);

StringVal UrlEncoder(FunctionContext* context, const StringVal& arg1);

std::string UrlEncode(const std::string& str);

std::string UrlDecode(const std::string& str);

unsigned char FromHex(unsigned char x);

unsigned char ToHex(unsigned char x);

#endif