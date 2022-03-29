#include "circulararray.h"

#include "circulararray.h"

using namespace std;
//Estructura LIFO (Last-In, First-Out)
template <typename T>
class StackArray: public CircularArray<T>{
private:
    T* array;
    //int capacity; //valor cambiable
    int size;

public:
    StackArray();
    StackArray(int max);//capacity=max;
    void push(int );
    void resize(T *&array, int &longitud, int newlongitud);
    void pop();
    void top();

    int _size();
    void printSize();
    void displayStack();
    ~StackArray();

};

template<class T>
void StackArray<T>::printSize() {
    cout<<"Size: "<<_size()<<endl;
}

template <class T>
StackArray<T>::StackArray(int max){//capacity=max;
    size=0;
    CircularArray<T>:: capacity=max;
    array=new T[max];
};


template <class T>
void StackArray<T>::resize(T* &array,int &longitud, int newlongitud){
    int* arr_aux=new T[newlongitud];
    for (int i = 0; i <longitud ; ++i) {
        arr_aux[i]=array[i];
    }
    longitud=newlongitud;
    array=arr_aux;
    cout<<"Se ha redimensionado el StackArray"<<endl;
}

template <class T>
void StackArray<T>::push(int data){
    if(size == CircularArray<T>::capacity){
        cout<<"Esta lleno"<<endl;
        resize(array,CircularArray<T>::capacity,CircularArray<T>::capacity*2); //O(n)
    }
    array[size]=data;//O(1)
    size+=1;
};

template<class T>
void StackArray<T>:: pop(){
    int data=array[size-1];
    size--;
    cout<<"Se elimino el elemento: "<<data<<endl;
};//O(1)


template<class T>
void StackArray<T>::top(){
    int indexTop=size-1;
    cout<<"Elemento top: "<<array[indexTop]<<endl;
};


template<class T>
int StackArray<T>::_size(){
    return size;
}

template<class T>
void StackArray<T>::displayStack(){
    for (int i = 0; i <size ; ++i) {
        cout<<array[i]<<" ";
    }cout<<endl;
};
template <class T>
StackArray<T>::~StackArray(){
    delete [] array;
};