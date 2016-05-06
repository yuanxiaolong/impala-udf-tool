//
// Created by xiaolong.yuanxl on 16-5-6.
//

#include "udf-urltool.h"
//#include "url-coding.h"

#include <cctype>
#include <cmath>
#include <string>
#include <sstream>
//#include <assert.h>

//using namespace my_impala;
//using namespace impala_udf;
using namespace std;


/**
 * 转换url
 *
 * 输入: http%3A%2F%2Fwww.mafengwo.cn%2Fentry.php%2Fdaka_list%2Findex
 * 输出: http://www.mafengwo.cn/entry.php/daka_list/index
 */
StringVal UrlDecoder(FunctionContext* context, const StringVal& arg1){
    if (arg1.is_null) return StringVal::null();

    try {
        std::string original((const char *)arg1.ptr,arg1.len);
        std::string decoded = UrlDecode(original);

        StringVal result(context, decoded.size());
        memcpy(result.ptr, decoded.c_str(), decoded.size());

        return result;
    }catch(...){
        return StringVal::null();
    }

}

/**
 * 转换url
 *
 * 输入: http://www.mafengwo.cn/entry.php/daka_list/index
 * 输出: http%3A%2F%2Fwww.mafengwo.cn%2Fentry.php%2Fdaka_list%2Findex
 */
StringVal UrlEncoder(FunctionContext* context, const StringVal& arg1){
    if (arg1.is_null) return StringVal::null();

    try {
        std::string original((const char *)arg1.ptr,arg1.len);
        std::string encoded = UrlEncode(original);

        StringVal result(context, encoded.size());
        memcpy(result.ptr, encoded.c_str(), encoded.size());

        return result;
    }catch(...){
        return StringVal::null();
    }
}




inline unsigned char ToHex(unsigned char x) {
    return  x > 9 ? x + 55 : x + 48;
}

inline unsigned char FromHex(unsigned char x) {
    unsigned char y;
    if (x >= 'A' && x <= 'Z') y = x - 'A' + 10;
    else if (x >= 'a' && x <= 'z') y = x - 'a' + 10;
    else if (x >= '0' && x <= '9') y = x - '0';
    else y = ' ';
    return y;
}

inline std::string UrlEncode(const std::string& str) {
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (isalnum((unsigned char)str[i]) ||
            (str[i] == '-') ||
            (str[i] == '_') ||
            (str[i] == '.') ||
            (str[i] == '~'))
            strTemp += str[i];
        else if (str[i] == ' ')
            strTemp += "+";
        else
        {
            strTemp += '%';
            strTemp += ToHex((unsigned char)str[i] >> 4);
            strTemp += ToHex((unsigned char)str[i] % 16);
        }
    }
    return strTemp;
}

inline std::string UrlDecode(const std::string& str) {
    std::string strTemp = "";
    size_t length = str.length();
    for (size_t i = 0; i < length; i++)
    {
        if (str[i] == '+') strTemp += ' ';
        else if (str[i] == '%')
        {
//            assert(i + 2 < length);
            unsigned char high = FromHex((unsigned char)str[++i]);
            unsigned char low = FromHex((unsigned char)str[++i]);
            strTemp += high*16 + low;
        }
        else strTemp += str[i];
    }
    return strTemp;
}