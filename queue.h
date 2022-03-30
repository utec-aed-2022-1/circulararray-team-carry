#include "circulararray.h"
//Estructura LIFO (First-In, First-Out)
template <typename T>
class QueueArray : public CircularArray<T> {
private:
    T *array;
    int size ;
    int eachSize;
    int front ,  back ;

public:
    QueueArray(int _size);

    bool isempty();
    void resize();
    void enqueue(int _value);
    void dequeue();
    void showfront();
    void showback();
    void Size();
    void displayQueue();
    ~QueueArray();
};



template <class T>
QueueArray<T>::QueueArray(int _size){
    CircularArray<T>::capacity = _size;
    this->eachSize=0;
    this->array = new T[_size];
    this->size = _size;
    this->front = this->back = -1;
}

template <class T>
QueueArray<T>::~QueueArray(){delete[] array;}

template <class T>
bool QueueArray<T>::isempty(){ bool verificar;
    return (front ==-1 and back == -1) ?  verificar=true: verificar= false;
}

template<class T>
void QueueArray<T>::resize(){
    int* arr_aux=new T[size*2];
    int i=0;
    int j=front;
    do {arr_aux[i++]=array[j];
        j=(j+1)%size;
    }while(j!=front);
    front=0;
    back=size-1;
    array=arr_aux;
    cout<<"Se ha redimensionado el QueueArray"<<endl;
};

template <class T>
void QueueArray<T>::enqueue(int _value){
    if (back == size-1) {
        cout<<"QueueArray esta lleno\n";
        resize();
    }
    if (front == -1) front = 0;
        back++;
        array[back] = _value;
        eachSize++;
}

template <class T>
void QueueArray<T>::dequeue(){
    if (isempty()) cout<<"QueueArray esta vacio\n";
    else if (front == back){
        front = back = -1;
    }
    else {front++ ;eachSize--;};
}

template <class T>
void QueueArray<T>::showfront(){
    if (isempty()) cout<<"QueueArray esta vacio\n";
    else cout<<"Front: "<<array[front]<<endl;}

template <class T>
void QueueArray<T>::showback(){
    if (isempty()) cout<<"QueueArray esta vacio\n";
    else cout<<"Back: "<<array[back]<<endl;
};

template <class T>
void QueueArray<T>::Size(){
    cout<<"Tamanio QueueArray: "<<eachSize<<endl;
};

template <class T>
void QueueArray<T>::displayQueue(){
    if (isempty()) cout<<"QueueArray esta vacio\n";
    else{
        for (int i = front; i <=back; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
};