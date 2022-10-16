#include "linkedList.h"
#include "mergesort.h"
#include "quicksort.h"
#include "../unitTest/test.h"

const int LIST_LENGTH=10;
const int LIST_COMPARE[LIST_LENGTH]={1,4,6,10,35,153,2,10,1,10};
const int SORTED_COMPARE[LIST_LENGTH]={1,1,2,4,6,10,10,10,35,153};

void populate_list(LinkedList<int> &list){
  int i=0;
  while(i < LIST_LENGTH){
    list.push(LIST_COMPARE[i]);
    i++;
  }
}

void test_list_push(test_result &r){
  auto test_list=LinkedList<int>();
  test_list.push(1);
  if(test_list[0]==1){
    r.passed=true;
  } else {
    r.passed=false;
  }
}

void test_list_pop(test_result &r){
  auto test_list=LinkedList<int>();
  test_list.push(1);
  test_list.push(2);
  if(test_list.pop()==2 && test_list.length()==1){
    if(test_list.pop()==1 && test_list.length()==0){
      r.passed=true;
    } else {
      r.passed=false;
    }
  } else {
    r.passed=false;
  }
}

void test_list_get(test_result &r){
  auto test_list=LinkedList<int>();
  test_list.push(1);
  if(test_list[0]==1){
    r.passed=true;
  } else {
    r.passed=false;
    r.log="Expected 1 Got: "+std::to_string(test_list[0]);
  }
}

void test_list_gets(test_result &r){
  auto test_list=LinkedList<int>();
  int i=0;
  populate_list(test_list);
  r.passed=true;
  while(i < LIST_LENGTH){
    if(test_list[i]!=LIST_COMPARE[i]){
      r.passed=false;
      break;
    }
    i++;
  }
}

void test_list_rewrite(test_result &r){
  auto test_list=LinkedList<int>();
  test_list.push(1);
  test_list.push(2);
  test_list.push(4);
  test_list[1]=10;
  if(test_list[1]==10){
    r.passed=true;
  } else {
    r.passed=false;
  }
}

void test_sub_list(test_result &r){
  auto test_list=LinkedList<int>();
  int i=5;
  populate_list(test_list);
  auto sub_list=test_list.sub_list(7);
  //expected 10,1,10
  if(sub_list[0]==10 && sub_list[1]==1 && sub_list[2]==10){
    r.passed=true;
  } else {
    r.passed=false;
  }
}

void test_sub_list_range(test_result &r){
  auto test_list=LinkedList<int>();
  int i=0;
  populate_list(test_list);
  auto sub_list=test_list.sub_list(5,7);
  //Expected list 153, 2, 10
  if(sub_list[0]==153 && sub_list[1]==2 && sub_list[2]==10){
    r.passed=true;
  } else {
    r.passed=false;
  }
}

void test_merge_sort(test_result &r){
  auto test_list=LinkedList<int>();
  test_list.push(10);
  test_list.push(5);
  test_list.push(1);
  LinkedList<int> sorted=mergeSort(test_list);
  if(sorted[0]==1 && sorted[1]==5 && sorted[2]==10){
    r.passed=true;
  } else {
    r.passed=false;
  }
}

void test_merge_sort_larger(test_result &r){
  auto test_list=LinkedList<int>();
  int i=0;
  populate_list(test_list);
  auto sorted=mergeSort(test_list);
  r.passed=true;
  while(i<LIST_LENGTH){
    if(sorted[i]!=SORTED_COMPARE[i]){
      r.passed=false;
      break;
    }
    i++;
  }
}

void test_quick_sort(test_result &r){
  auto test_list=LinkedList<int>();
  test_list.push(10);
  test_list.push(5);
  test_list.push(1);
  quickSort(test_list);
  if(test_list[0]==1 && test_list[1]==5 && test_list[2]==10){
    r.passed=true;
  } else {
    r.passed=false;
  }
}

void test_quick_sort_larger(test_result &r){
  auto test_list=LinkedList<int>();
  int i=0;
  populate_list(test_list);
  quickSort(test_list);
  r.passed=true;
  while(i<LIST_LENGTH){
    if(test_list[i]!=SORTED_COMPARE[i]){
      r.passed=false;
      break;
    }
    i++;
  }
}

int main(){
  auto list_test=Test("Linked List Tests");
  list_test.add_test("push test", test_list_push);
  list_test.add_test("pop test", test_list_pop);
  list_test.add_test("get test", test_list_get);
  list_test.add_test("get test multiple", test_list_gets);
  list_test.add_test("Rewrite test", test_list_rewrite);
  list_test.add_test("sub list test", test_sub_list);
  list_test.add_test("sub list range test", test_sub_list_range);

  list_test.run();

  auto merge_test=Test("Merge Sort Tests");
  merge_test.add_test("Merge Sort Test", test_merge_sort);
  merge_test.add_test("Merge Sort Large", test_merge_sort_larger);

  merge_test.run();

  auto quick_test=Test("Quick sort tests");
  quick_test.add_test("quick sort test", test_quick_sort);
  quick_test.add_test("Quick Sort Large", test_quick_sort_larger);

  quick_test.run();

  return 0;
}
