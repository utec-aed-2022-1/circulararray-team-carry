#include "circulararray.h"

template <typename T>
class QueueArray : public CircularArray<T> { 
    private:
    T *array= getarray();
    int size = getcapacity();
    int front = getfront(); int back = getback();

    public:
    QueueArray(int _size);
    ~QueueArray();
    bool isempty();
    void enqueue(int _value);
    void dequeue();
    void showfront();
    void showback();
    void displayQueue();
};

template <class T>
QueueArray<T>::QueueArray(int _size){
    CircularArray<T>::capacity = _size;

    this->array = new int[_size];
    this->size = _size;
    this->front = this->back = -1;
}

template <class T>
QueueArray<T>::~QueueArray(){delete[] array;}

template <class T>
bool QueueArray<T>::isempty(){
    if (front ==-1 and back == -1)return true;
    else return false;
}

template <class T>
void QueueArray<T>::enqueue(int _value){
    if (back == size-1) cout<<"Queue esta lleno\n";
    else{
        if (front == -1) front = 0;
        back++;
        array[back] = _value;
    }
}

template <class T>
void QueueArray<T>::dequeue(){
    if (isempty()) cout<<"Queue esta vacio\n";
    else if (front == back){ front = back = -1;}
    else front++;
}

template <class T>
void QueueArray<T>::showfront(){
    if (isempty()) cout<<"Queue esta vacio\n";
    else cout<<"el elemento front es: "<<array[front]<<endl;
}

template <class T>
void QueueArray<T>::showback(){
    if (isempty()) cout<<"Queue esta vacio\n";
    else cout<<"el elemento back es: "<<array[back]<<endl;
}

template <class T>
void QueueArray<T>::displayQueue(){
    if (isempty()) cout<<"Queue esta vacio\n";
    else
    {
        for (int i = front; i <=back; i++){
            cout<<array[i]<<" ";
        }
        cout<<endl;
    }
}
