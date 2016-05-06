#include <iostream>

#include <impala_udf/udf-test-harness.h>
#include "udf-helloworld.h"

using namespace impala;
using namespace impala_udf;
using namespace std;

int main(int argc, char** argv) {
    bool passed = true;

    passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
          Hello, StringVal("Tom"), StringVal("hello_Tom"));
    passed &= UdfTestHarness::ValidateUdf<StringVal, StringVal>(
          Hello, StringVal::null(), StringVal::null());

//    passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal, IntVal>(
//          Hello, IntVal(8), StringVal("hello_8"));
//    passed &= UdfTestHarness::ValidateUdf<IntVal, IntVal, IntVal>(
//          Hello, IntVal::null(), StringVal("Tom"), StringVal::null());


    cout << "Tests " << (passed ? "Passed." : "Failed.") << endl;
    return !passed;
}