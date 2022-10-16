#include "linkedList.h"
#ifndef mergesort_h
#define mergesort_h

template <typename T>
LinkedList<T> mergeSort(LinkedList<T> unsorted){
  int len=unsorted.length();
  LinkedList<T> out=LinkedList<T>();
  if(len>2){
    int split=len/2;
    auto left_unsorted=unsorted.sub_list(0,split);
    auto right_unsorted=unsorted.sub_list(split+1);

    auto left=mergeSort(left_unsorted);
    auto right=mergeSort(right_unsorted);

    int i=0;
    int j=0;

    while(i<left.length() || j<right.length()){
      if(!(i<left.length())){
        out.push(right.get(j));
        j++;
      } else if(!(j<right.length())){
        out.push(left.get(i));
        i++;
      } else {
        if(left.get(i) < right.get(j)){
          out.push(left.get(i));
          i++;
        } else {
          out.push(right.get(j));
          j++;
        }
      }
    }
    return out;
  } else {
    if(len==1){
      out.push(unsorted.get(0));
    } else {
      if(unsorted.get(0)>unsorted.get(1)){
        out.push(unsorted.get(1));
        out.push(unsorted.get(0));
      } else {
        out.push(unsorted.get(0));
        out.push(unsorted.get(1));
      }
    }
    return out;
  }
}

#endif
