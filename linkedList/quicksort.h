#include "linkedList.h"
#ifndef quicksort_h
#define quicksort_h

template <typename T>
int partition(LinkedList<T> &list, int left, int right){
  int pivot=list[right];
  int i=left-1;
  int j=left;
  while(j<right){
    if(list[j] <= pivot){
      i++;
      T temp=list[i];
      list[i]=list[j];
      list[j]=temp;
    }
    j++;
  }
  T temp=list[right];
  list[right]=list[i+1];
  list[i+1]=temp;
  return i+1;
}

template <typename T>
void quickSort(LinkedList<T> &unsorted){
  int left=0;
  int right=unsorted.length()-1;
  quickSort(unsorted, left, right);
}

template <typename T>
void quickSort(LinkedList<T> &unsorted, int left, int right){
  if(right-left<=0){
    return;
  } else {
    int pivot=partition(unsorted, left, right);
    quickSort(unsorted, left, pivot-1);
    quickSort(unsorted, pivot+1, right);
  }
}

#endif
