#include <iostream>

#include <impala_udf/udf-test-harness.h>
#include "udf-urltool.h"

using namespace my_impala;
using namespace impala_udf;
using namespace std;

int main(int argc, char** argv) {
    bool passed = true;

    passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
          UrlDecoder, StringVal("http%3a%2f%2fwww.taobao.com"), StringVal("http://www.taobao.com"));
    passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
            UrlDecoder, StringVal::null(), StringVal::null());

//    passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal, IntVal>(
//          Hello, IntVal(8), StringVal("hello_8"));
//    passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal, IntVal>(
//          Hello, IntVal::null(), StringVal("Tom"), StringVal::null());


    cout << "Tests " << (passed ? "Passed." : "Failed.") << endl;
    return !passed;
}