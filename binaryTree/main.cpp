#include "binarytree.h"
#include "../unitTest/test.h"
#include <iostream>

void insert_test(test_result &r){
  auto tree=BinaryTree<int>();
  tree.insert(10);
  tree.insert(5);
  tree.insert(14);
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
  tree.insert(10);
  tree.insert(5);
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
  tree.insert(10);
  tree.insert(5);
  tree.insert(4);
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
  tree.insert(10);
  tree.insert(15);
  tree.insert(20);
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
  tree.insert(10);
  tree.insert(15);
  tree.insert(12);
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
  tree.insert(10);
  tree.insert(3);
  tree.insert(5);
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

int main(){
  auto tester=Test("Binary Tree Tests");
  tester.add_test("Insert Test", insert_test);
  tester.add_test("Height Test", height_test);
  tester.add_test("Rotate left Test", rotate_left_test);
  tester.add_test("Rotate right Test", rotate_right_test);
  tester.add_test("Left Right Rotate Test", left_right_rotate_test);
  tester.add_test("Right Left Rotate Test", right_left_rotate_test);

  // auto tree=BinaryTree<int>();
  // tree.insert(10);
  // tree.insert(11);
  // tree.insert(20);
  // tree.insert(5);
  // tree.insert(4);
  // tree.insert(2);
  // tree.print();
  // std::cout << std::endl;
  // tree.root=tree.rotate_left(tree.root);
  // tree.print();
  tester.run();
  return 0;
}
