#include "udf-helloworld.h"

#include <cctype>
#include <cmath>
#include <string>
#include <sstream>



StringVal Hello(FunctionContext* context, const StringVal& arg1){
    if (arg1.is_null) return StringVal::null();

    int index;
    std::string original((const char *)arg1.ptr,arg1.len);
    std::string shorter("hello_");

    int length;
    length = original.length();
    for (index = 0; index < length; index++){
        uint8_t c = original[index];

        shorter.append(1, (char)c);
    }

    StringVal result(context, shorter.size());
    memcpy(result.ptr, shorter.c_str(), shorter.size());

    return result;
}


//StringVal Hello(FunctionContext* context, const IntVal& arg1){
//    if (arg1.is_null) return IntVal::null();
//    stringstream stream;
//    string *stemp="";
//    stream << arg1;
//    stemp = stream.str();
//
//    std::string shorter("hello_");
//
//    shorter.append(*stemp);
//
//    StringVal result(context, shorter.size());
//    memcpy(result.ptr, shorter.c_str(), shorter.size());
//    return result;
//
//}


