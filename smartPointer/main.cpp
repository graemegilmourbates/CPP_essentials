#include "smartPointer.h"
#include <iostream>

int main(){
  smrtp<int> test(new int());
  *test = 20;
  std::cout << *test << std::endl;
  return 0;
}
