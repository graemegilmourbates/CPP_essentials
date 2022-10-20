/*
  Author: Graeme Bates
*/
#include <iostream>
// #define NULL 0

#ifndef binaryTree_h
#define binartTree_h

template <class T>
class BinaryTree{
  public:
    struct bNode{
      T package;
      bNode *left;
      bNode *right;
    };
    bNode *root;
    BinaryTree(){
      root=NULL;
    }
    ~BinaryTree(){
      bNode *current=root;
      destroyTree(current);
    }
    void print(){
      print("", root, false);
    }
    void print(const std::string &prefix, const bNode *node, bool isLeft){
      if(node!=NULL){
        std::cout << prefix;
        std::cout << (isLeft ? "├──" : "└──");
        std::cout << node->package << std::endl;
        print(prefix+(isLeft? "|  " : "   "), node->left, true);
        print(prefix+(isLeft? "|  " : "   "), node->right, false);
      }
    }
    void insert(T value){
      root=insert(root, value);
    }
    bNode* insert(bNode *node, T value){
      if(node==NULL){
        node=new bNode;
        node->left=NULL;
        node->right=NULL;
        node->package=value;
        return node;
      } else{
        if(value < node->package){
          node->right=insert(node->right, value);
        } else if(value > node->package){
          node->left=insert(node->left, value);
        }
        return node;
      }
    }
    int height(){
      return height(root);
    }
    int height(bNode *node){
      if(node==NULL){
        return 0;
      }
      return(std::max(height(node->left), height(node->right)) + 1);
    }
    bNode *rotate_left(bNode *node){
      //take node to the right make it root
      //with current node on new roots left
      //with contents of target nodes left on the right of this node
      bNode *temp=node->right->left;
      bNode *target=node->right;
      target->left=node;
      node->right=temp;
      return target;
    }
    bNode *rotate_right(bNode *node){
      bNode *temp=node->left->right;
      bNode *target=node->left;
      target->right=node;
      node->left=temp;
      return target;
    }
    bNode *left_right_rotate(bNode *node){
      node->left=rotate_left(node->left);
      node=rotate_right(node);
      return node;
    }
    bNode *right_left_rotate(bNode *node){
      node->right=rotate_right(node->right);
      node=rotate_left(node);
      return node;
    }
  private:
    void destroyTree(bNode *node){
      if(node!=NULL){
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
      }
    }
};

#endif
