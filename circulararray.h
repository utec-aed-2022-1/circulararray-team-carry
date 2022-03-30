#include <iostream>
using namespace std;

template <class T>
class CircularArray
{
protected:
    T *array;
    int capacity;
    int back, front;
    
public:
    CircularArray();
    CircularArray(int _capacity);
    virtual ~CircularArray();
    void push_front(T data); // check
    void push_back(T data); // check
    void insert(T data, int pos); // check
    T pop_front(); // check
    T pop_back(); // check
    bool is_full(); // check
    bool is_empty(); // check
    int size();  // check
    void clear(); // check
    T &operator[](int salida){
        return array[salida];
    }; // 
    void sort(); // check
    bool is_sorted(); // check
    void reverse(); // check
    string to_string(string sep=" "); // check
private:
    int next(int);
    int prev(int);
};

template <class T>
CircularArray<T>::CircularArray()
{
    CircularArray(0);
}

template <class T>
CircularArray<T>::CircularArray(int _capacity)
{
    this->array = new T[_capacity];
    this->capacity = _capacity;
    this->front = this->back = -1;
}

template <class T>
CircularArray<T>::~CircularArray()
{
    delete[] array;
}

template <class T>
int CircularArray<T>::prev(int index)
{
    return (index == 0) ? capacity - 1 : index - 1;
}

template <class T>
int CircularArray<T>::next(int index)
{
    return (index + 1) % capacity;
}

template <class T>
string CircularArray<T>::to_string(string sep)
{
    string result = ""; 
    for (int i = 0; i < size(); i++)
        result += std::to_string((*this)[i]) + sep;
    return result;    
}

template <class T>
bool CircularArray<T>::is_empty(){
    if (front == -1 and back==-1) return true;
    else return false;
}

template <class T>
bool CircularArray<T>::is_full(){
    if (front == capacity-1) return true;
    else return false;
}

template <class T>
void CircularArray<T>::push_front(T data){
    for (int i = capacity; i > 0 ; i--) array[i] = array[i-1];
    array[0] = data;
    front++;
}

template <class T>
void CircularArray<T>::push_back(T data){
    if ( back == -1) back = 0;
    front++;
    array[front]= data;
}

template <class T>
void CircularArray<T>::sort(){
    int aux;
    for(int i = 0; i < capacity; i++){
        for(int x = 0; x < capacity; x++){
            if(array[i] < array[x]){
                aux = array[i];
                array[i] = array[x];
                array[x] = aux;
            }
        }
    }
}

template <class T>
bool CircularArray<T>::is_sorted(){
    for (int i = 0; i < size()-1; i++)
    {
        if (array[i] > array[i+1]) return false;
    }
    return true;
}

template <class T>
void CircularArray<T>::reverse(){
    int restador = 1;
    for (int i = 0; i < capacity/2; i++){   
        int aux=array[i];
        array[i]= array[i+capacity-restador];
        array[i+capacity-restador] = aux;
        restador = restador+2;
    }
}

template <class T>
T CircularArray<T>::pop_front(){
    int value = array[front];
    this->array[front] = 0;
    front--;
    return value;
}

template <class T>
T CircularArray<T>::pop_back(){
    int value = array[back];
    for (int i = 0; i < size(); i++)
    {
        array[i] = array[i+1];
    }
    front--;
    return value;
}

template <class T>
int CircularArray<T>::size(){
    int contador = 0;
    for (int i = back; i < front+1; i++)
    {
        contador++;
    }
}

template <class T>
void CircularArray<T>::clear(){
    for (int i = 0; i < capacity; i++)
    {
        this->array[i] = 0;
    }
    front = back = -1;
}