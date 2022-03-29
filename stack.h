#include "circulararray.h"

void resize(int* &array,int &longitud, int newlongitud){
    int* arr_aux=new int[newlongitud];
    for (int i = 0; i <longitud ; ++i) {
        arr_aux[i]=array[i];
    }
    longitud=newlongitud;
    array=arr_aux;
}


template <typename T>
//Estructura LIFO (Last-In, First-Out)
class StackArray:public CircularArray<T>{
private:
    T* array;
    int capacity; //valor cambiable
    int size;

public:
    StackArray(int max){//capacity=max;
        size=0;
        capacity=max;
        array=new T[capacity];
    };


    void push_front(T data){
        if(size == capacity){
            resize(array,capacity,capacity*2); //O(n)
        }
        array[size]=data;//O(1)
        size+=1;
    };
    int pop_back(){
        int data=array[size-1];
        size--;
        return data;
    };//O(1)
    int top(){
        int indexTop=size-1;
        return array[indexTop];
    };


    int _size(){
        return size;
    }

    void display(){
        for (int i = 0; i <size ; ++i) {
            cout<<array[i]<<" ";
        }cout<<endl;
    };

    ~StackArray(){
        delete [] array;
    }
};

