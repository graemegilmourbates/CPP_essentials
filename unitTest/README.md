# CPP Unit Test Framework


### All test functions must share a signature
Function signature is void type with a single reference to a test_result parameter
### Can be either defined functions or lambdas
```
void test_function(test_result& r){
	r.passed=true; //woo it passed
}

[](test_result& r)->void{
	r.passed=false; //ah man, it failed lets log it
	r.log="Test failed because...";
}
```


### Features:
- Generate Test Suite
- Log Test Data
- Store Test Data to a File
- More To come soon!

## Useage Example
```
/*
  Author: Graeme Bates
*/
#include "test.h"
#include <iostream>

int sum(int a, int b){
  int i=0;
  int out=a;
  while(i < abs(b)){
    if(b<0){
      out--;
    } else{
      out++;
    }
    i++;
  }
  return out;
}

void test_simple_case(test_result& r){
  if(sum(1,2)==3){
    r.passed=true;
  } else {
    r.log="Expected:3 Got:"+std::to_string(sum(1,2));
    r.passed=false;
  }
}

void test_negative_inputs(test_result& r){
  if(sum(1,-2)==-1){
    r.passed=true;
  } else {
    r.log="Expected:-1 Got:"+std::to_string(sum(1,-2));
    r.passed=false;
  }
}

void test_will_fail(test_result& r){
  r.log="Intentional fail";
  r.passed=false;
}

void test_random_cases(test_result& r){
  int a = rand()%100;
  int b = rand()%100;
  int result=sum(a,b);
  int expected=a+b;
  if(result==expected){
    r.passed=true;
  } else {
    r.passed=false;
  }
}

int main(){
  srand((unsigned) time(NULL));
  Test tester=Test("Sum function tests");
  tester.add_test("Simple Addition Tests", test_simple_case);
  tester.add_test("Negative Number Test", test_negative_inputs);
  tester.add_test("Will Fail", test_will_fail);
  tester.add_test("Random inputs", test_random_cases, 10);
  tester.add_test("Lambda test", [](test_result& r)->void{
    r.passed=true;
  });
  tester.run();
  tester.run("test.txt");
  return 0;
}
```

## Outputs
```
Running: Sum function tests
	#### Test 1 : 5 PASS
	#### Test 2 : 5 PASS
	#### Test 3 : 5 FAILED
		Intentional fail on Test: Will Fail
	#### Test 4 : 5 PASS
	#### Test 5 : 5 PASS
Passed 4 out of 5
```
