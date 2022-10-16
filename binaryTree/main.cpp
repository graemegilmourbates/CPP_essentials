#include "binarytree.h"
#include "../unitTest/test.h"
#include <iostream>

void test_simple_insert_value(test_result &r){
  auto test_tree=BinaryTree(5);
  test_tree.insert(2);
  test_tree.insert(3);
  try{
    if(test_tree.root->right->left->package==3){
      //woo leaf expected;
      r.passed=true;
    } else {
      r.passed=false;
      r.log="Expected 2, Got: "+std::to_string(
        test_tree.root->right->right->package
      );
    }
  }
  catch(std::exception &e){
    r.passed=false;
    r.log="Error: ";
  }
}

void test_insert_greater(test_result &r){
  auto test_tree=BinaryTree(5);
  test_tree.insert(6);
  if(test_tree.root->left->package==6){
    r.passed=true;
  } else {
    r.passed=false;
    r.log="something went wrong";
  }
}

void test_insert_lesser(test_result &r){
  auto test_tree=BinaryTree(5);
  test_tree.insert(2);
  if(test_tree.root->right->package==2){
    r.passed=true;
  } else {
    r.passed=false;
    r.log="something went wrong";
  }
}

void test_insert_many(test_result &r){
  auto test_tree=BinaryTree(5);
  int i=0;
  while(i<11){
    if(i!=5){
      test_tree.insert(i);
    }
    i++;
  }
  if(test_tree.root->left->package==6){
    if(test_tree.root->right->package==0){
      r.passed=true;
    } else {
      r.passed=false;
      r.log="Expected to get 0 on the first right Got "+std::to_string(
        test_tree.root->right->package
      );
    }
  } else {
    r.passed=false;
    r.log="Expected to get 6 on the first left";
  }
}

int main(){
  auto tester=Test("Binary Tree Tests");
  tester.add_test("Insert", test_simple_insert_value);
  tester.add_test("Insert Greater", test_insert_greater);
  tester.add_test("Insert Lesser", test_insert_lesser);
  tester.add_test("Insert Many", test_insert_many);
  tester.add_test("Binary Search", [](test_result &r)->void{
    auto test_tree=BinaryTree(5);
    int i=0;
    while(i<11){
      if(i!=5){
        test_tree.insert(i);
      }
      i++;
    }
    if(test_tree.root->recursive_search("011")==2){
      r.passed=true;
    } else {
      r.passed=false;
      r.log="Should have gotten 2 got: "+std::to_string(
        test_tree.root->recursive_search("011")
      );
    }
  });
  tester.add_test("Binary recursive search", [](test_result &r)->void{
    auto test_tree=BinaryTree(10);
    test_tree.insert(5);
    test_tree.insert(2);
    test_tree.insert(6);
    test_tree.insert(20);
    test_tree.insert(15);
    if(test_tree.search("0")==5){
      if(test_tree.search("01")==6){
        if(test_tree.search("10")==15){
          r.passed=true;
        } else {
          r.passed=false;
          r.log="Should have gotten 15 got: "+std::to_string(
            test_tree.search("10")
          );
        }
      } else {
        r.passed=false;
        r.log="Should have gotten 6 got: "+std::to_string(
          test_tree.search("01")
        );
      }
    } else {
      r.passed=false;
      r.log="Should have gotten 5 got: "+std::to_string(
        test_tree.search("0")
      );
    }
  });
  tester.add_test("Testing binary push", [](test_result &r)->void{
    auto test_tree=BinaryTree(10);
    test_tree.push(5, "0");
    test_tree.push(20, "00");
    test_tree.push(20, "00");
    test_tree.push(5, "01");
    if(test_tree.search("000")!=20){
      r.passed=false;
    } else {
      r.passed=true;
    }
  });
  tester.run();
  return 0;
}
