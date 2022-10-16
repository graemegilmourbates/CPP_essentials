#include <iostream>

#ifndef linkedList_h
#define linkedList_h

template <class T>
class LinkedList{
  private:
    struct ListNode{
      T package;
      ListNode *next=NULL;
      ListNode *previous;
    };

    ListNode *root;
    void push(T, ListNode*);
    T pop(ListNode*);
    void destroy_list();

  public:
    LinkedList();

    LinkedList(const LinkedList&);
    LinkedList& operator=(const LinkedList&);
    LinkedList(LinkedList&&);
    LinkedList& operator=(LinkedList&&);

    ~LinkedList();

    void push(T);
    T pop();
    int length();

    T get(int);
    void print();

    LinkedList<T> sub_list(int);
    LinkedList<T> sub_list(int, int);

    void operator+=(T);
    T& operator[](int);
};

template <class T>
LinkedList<T>::LinkedList(){
  root=NULL;
}
//Copy constructor
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &other){
  root=NULL;
  ListNode* n=other.root;
  while(n!=NULL){
    push(n->package);
    n=n->next;
  }
}
//Copy assignment
template <class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &rhs){
  if(this!=rhs){
    root=rhs.root;
  }
  return *this;
}
//Move constructor
template <class T>
LinkedList<T>::LinkedList(LinkedList<T> &&other){
  root=other.root;
  other.root=NULL;
}
//Move assignment
template <class T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> &&rhs){
  if(this!=&rhs){
    root=rhs.root;
  }
  return *this;
}

template <class T>
void LinkedList<T>::destroy_list(){
  if(root!=NULL || length()!=0){
    ListNode *current=root;
    ListNode *next;
    while(current){
      next=current->next;
      delete current;
      current=next;
    }
  }
}

template <class T>
LinkedList<T>::~LinkedList(){
  destroy_list();
}

template <class T>
void LinkedList<T>::push(T key){
  if(root!=NULL){
    push(key, root);
  } else {
    root=new ListNode;
    root->package=key;
    root->previous=NULL;
  }
}

template <class T>
void LinkedList<T>::push(T key, ListNode *node){
  if(node->next!=NULL){
    push(key, node->next);
  } else {
    node->next=new ListNode;
    node->next->previous=node;
    node->next->package=key;
  }
}

template <class T>
T LinkedList<T>::pop(){
  if(root!=NULL){
    if(root->next!=NULL){
      return pop(root->next);
    } else {
      T out=root->package;
      delete root;
      root=NULL;
      return out;
    }
  } else {
    throw std::invalid_argument("Index out of range.");
  }
}

template <class T>
T LinkedList<T>::pop(ListNode *node){
  if(node->next!=NULL){
    return pop(node->next);
  } else {
    T out=node->package;
    node->previous->next=NULL;
    delete node;
    return out;
  }
}

template <class T>
int LinkedList<T>::length(){
  if(root!=NULL){
    auto current=root;
    int i=1;
    while(current->next!=NULL){
      current=current->next;
      i++;
    }
    return i;
  } else {
    return 0;
  }
}

template <class T>
T LinkedList<T>::get(int index){
  if(index<length()){
    auto current=root;
    int i=0;
    while(i < index){
      current=current->next;
      i++;
    }
    return current->package;
  } else {
    throw std::invalid_argument("Index out of range.");
  }
}

template <class T>
void LinkedList<T>::print(){
  if(root!=NULL){
    auto current=root;
    std::cout << current->package << std::endl;
    while(current->next!=NULL){
      current=current->next;
      std::cout << current->package << std::endl;
    }
  }
}

template <class T>
LinkedList<T> LinkedList<T>::sub_list(int index){
  auto out=LinkedList<T>();
  if(index<length()){
    int i=0;
    auto current=root;
    while(i < index){
      current=current->next;
      i++;
    }
    out.push(current->package);
    while(current->next!=NULL){
      current=current->next;
      out.push(current->package);
    }
  }
  return out;
}

template <class T>
LinkedList<T> LinkedList<T>::sub_list(int start, int end){
  LinkedList<T> out=LinkedList<T>();
  if(start<end && end<length()){
    int i=0;
    auto current=root;
    while(i < start){
      current=current->next;
      i++;
    }
    while(i < end+1){
      out.push(current->package);
      current=current->next;
      i++;
    }
  }
  return out;
}

template <class T>
void LinkedList<T>::operator+=(T key){
  push(key);
}

template <class T>
T& LinkedList<T>::operator[](int index){
  if(index < length() && index > -1){
    int i=0;
    auto current=root;
    while(i < index){
      current=current->next;
      i++;
    }
    return current->package;
  } else {
    throw std::invalid_argument("Index out of range.");
  }
}

#endif
