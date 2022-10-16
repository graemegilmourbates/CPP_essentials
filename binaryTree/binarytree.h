/*
  Author: Graeme Bates
*/
#include <iostream>
// #define NULL 0

#ifndef binaryTree_h
#define binartTree_h

template <class T>
class BinaryNode{
  public:
    BinaryNode(T);
    void destroy_node();

    void add_left(BinaryNode<T>);
    void add_right(BinaryNode<T>);

    void push(T, std::string);

    void insert(T);
    T recursive_search(std::string);

    T package;
    BinaryNode<T> *left;
    BinaryNode<T> *right;
};

template <class T>
BinaryNode<T>::BinaryNode(T val){
  package=val;
  left=NULL;
  right=NULL;
}

template <class T>
void BinaryNode<T>::destroy_node(){
  if(left!=NULL){
    left->destroy_node();
  }
  if(right!=NULL){
    right->destroy_node();
  }
  delete this;
}

template <class T>
void BinaryNode<T>::insert(T i_value){
  if(i_value>package){
    if(left==NULL){
      left=new BinaryNode(i_value);
    } else {
      // if(i_value<left->package){
      //   auto temp=new BinaryNode(i_value);
      //   temp->left=left;
      //   left=temp;
      // } else {
      //   left->insert(i_value);
      // }
      left->insert(i_value);
    }
  }
  else{
    if(right==NULL){
      right=new BinaryNode(i_value);
    } else {
      // if(i_value>right->package){
      //   auto temp=new BinaryNode(i_value);
      //   temp->right=right;
      //   right=temp;
      // } else {
      //   right->insert(i_value);
      // }
      right->insert(i_value);
    }
  }
}

template <class T>
void BinaryNode<T>::push(T value, std::string location){
  if(location.length()>1){
    if(location[0]=='0'){
      if(right!=NULL){
        right->push(value, location.substr(1));
      } else {
        //This will just go as far as it can if search is out of bounds
        right=new BinaryNode(value);
      }
    } else {
      if(left!=NULL){
        left->push(value, location.substr(1));
      } else {
        //This will just go as far as it can if search is out of bounds
        left=new BinaryNode(value);
      }
    }
  } else {
    auto temp=new BinaryNode(value);
    if(location[0]=='0'){
      temp->right=right;
      right=temp;
    } else {
      temp->left=left;
      left=temp;
    }
  }
}

template <class T>
T BinaryNode<T>::recursive_search(std::string binary){
  if(binary.length()!=0){
    if(binary[0]=='0'){
      return right->recursive_search(binary.substr(1));
    }
    else{
      return left->recursive_search(binary.substr(1));
    }
  } else {
    return package;
  }
}


template <class T>
class BinaryTree{
  public:
    BinaryTree(T);
    ~BinaryTree();
    void insert(T);
    void push(T, std::string);
    void print_tree();
    T search(std::string);
    BinaryNode<T> *root;
  private:
    void destroy_tree();
};

template <class T>
BinaryTree<T>::BinaryTree(T r_value){
  root=new BinaryNode(r_value);
}

template <class T>
void BinaryTree<T>::destroy_tree(){}

template <class T>
BinaryTree<T>::~BinaryTree(){
  root->destroy_node();
}

template <class T>
void BinaryTree<T>::insert(T i_value){
  root->insert(i_value);
}

template <class T>
void BinaryTree<T>::push(T value, std::string location){
  root->push(value, location);
}

template <class T>
T BinaryTree<T>::search(std::string search){
  return root->recursive_search(search);
}

template <class T>
void BinaryTree<T>::print_tree(){
  int indentation=0;

}

#endif
