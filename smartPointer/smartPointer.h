#ifndef NULL
#define NULL 0
#endif

#ifndef linkedList_h
#define linkedList_h

template <class T>
class smrtp{
  private:

  public:
    T *ptr;
    explicit smrtp(){
      ptr=NULL;
    }
    explicit smrtp(T* p){
      ptr=p;
    }
    ~smrtp(){
      delete ptr;
    }

    T& operator*(){
      return *ptr;
    }

    T* operator->(){
      return ptr;
    }
};

#endif
