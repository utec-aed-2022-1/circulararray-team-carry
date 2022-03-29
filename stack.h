#include "circulararray.h"

template <typename T>
class StackArray: public CircularArray<T>{
private:
    T* array;
    //int capacity; //valor cambiable
    int size;
public:
    StackArray();
    StackArray(int max);//capacity=max;
    void resize(T *&array, int &longitud, int newlongitud);
    void push(int );
    void pop();
    void top();
    int _size();
    void printSize();
    void displayStack();
    ~StackArray();
};


template <class T>
StackArray<T>::StackArray(int max){//capacity=max;
    size=0;
    CircularArray<T>:: capacity=max;
    array=new T[max];
};
