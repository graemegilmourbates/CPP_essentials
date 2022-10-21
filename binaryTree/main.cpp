#include "binarytree.h"
#include "../unitTest/test.h"
#include <iostream>

void insert_test(test_result &r){
  auto tree=BinaryTree<int>();
  tree.binary_insert(10);
  tree.binary_insert(5);
  tree.binary_insert(14);
  if(tree.root->package==10){
    if(tree.root->right->package==5 && tree.root->left->package==14){
      r.passed=true;
    } else{
      r.passed=false;
      r.log="Leafs not correct";
    }
  } else{
    r.passed=false;
    r.log="Root not correct";
  }
}

void height_test(test_result &r){
  auto tree=BinaryTree<int>();
  tree.binary_insert(10);
  tree.binary_insert(5);
  if(tree.height()!=2){
    r.passed=false;
    return;
  }
  tree.insert(14);
  if(tree.height()!=2){
    r.passed=false;
    return;
  }
  tree.insert(15);
  if(tree.height()!=3){
    r.passed=false;
    return;
  }
  r.passed=true;
}

void rotate_left_test(test_result &r){
  auto tree=BinaryTree<int>();
  tree.binary_insert(10);
  tree.binary_insert(5);
  tree.binary_insert(4);
  tree.root=tree.rotate_left(tree.root);
  if(tree.root->package==5){
    if(tree.root->left->package==10){
      r.passed=true;
    } else{
      r.passed=false;
    }
  } else{
    r.passed=false;
  }
}

void rotate_right_test(test_result &r){
  auto tree=BinaryTree<int>();
  tree.binary_insert(10);
  tree.binary_insert(15);
  tree.binary_insert(20);
  tree.root=tree.rotate_right(tree.root);
  if(tree.root->package==15){
    if(tree.root->left->package==20){
      r.passed=true;
    } else{
      r.passed=false;
    }
  } else{
    r.passed=false;
  }
}

void left_right_rotate_test(test_result &r){
  auto tree=BinaryTree<int>();
  tree.binary_insert(10);
  tree.binary_insert(15);
  tree.binary_insert(12);
  tree.root=tree.left_right_rotate(tree.root);
  r.passed=false;
  if(tree.root->package==12){
    if(tree.root->right->package==10){
      if(tree.root->left->package==15){
        r.passed=true;
      }
    }
  }
}

void right_left_rotate_test(test_result &r){
  auto tree=BinaryTree<int>();
  tree.binary_insert(10);
  tree.binary_insert(3);
  tree.binary_insert(5);
  tree.root=tree.right_left_rotate(tree.root);
  r.passed=false;
  if(tree.root->package==5){
    if(tree.root->right->package==3){
      if(tree.root->left->package==10){
        r.passed=true;
      }
    }
  }
}

void balance_test(test_result &r){
  auto tree=BinaryTree<int>();
  tree.binary_insert(10);
  tree.binary_insert(11);
  tree.binary_insert(12);
  tree.binary_insert(13);
  tree.binary_insert(9);
  tree.binary_insert(8);
  tree.binary_insert(7);
  r.passed=false;
  if(tree.get_balance(tree.root)==0){
    tree.binary_insert(4);
    if(tree.get_balance(tree.root)==1){
      tree.binary_insert(5);
      if(tree.get_balance(tree.root)==2){
        tree.binary_insert(70);
        tree.binary_insert(60);
        tree.binary_insert(50);
        tree.binary_insert(40);
        tree.binary_insert(30);
        if(tree.get_balance(tree.root)==-3){
          r.passed=true;
          return;
        } else { r.log="Balance should have been -3"; }
      } else { r.log="Balance should have been 2"; }
    } else { r.log="Balance should have been 1"; }
  } else { r.log="Balance should have been 0"; }
}

int main(){
  auto tester=Test("Binary Tree Tests");
  tester.add_test("Insert Test", insert_test);
  tester.add_test("Height Test", height_test);
  tester.add_test("Rotate left Test", rotate_left_test);
  tester.add_test("Rotate right Test", rotate_right_test);
  tester.add_test("Left Right Rotate Test", left_right_rotate_test);
  tester.add_test("Right Left Rotate Test", right_left_rotate_test);
  tester.add_test("Balance Test", balance_test);
  tester.run();
  std::cout << "Pretty Print example" << std::endl;
  srand((unsigned) time(NULL));
  auto tree=BinaryTree<int>();
  int i=0;
  while(i < 20){
    tree.insert(rand()%100);
    i++;
  }
  tree.print();
  return 0;
}
