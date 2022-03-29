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
<<<<<<< HEAD


    void push_front(T data);
    void push_back(T data);

    void insert(T data, int pos);

    T pop_front();
    T pop_back();
    bool is_full();
    bool is_empty();

    int size();
    void clear();


    T &operator[](int);
    void sort();


    bool is_sorted();
    void reverse();
=======
    void push_front(T data); // check
    void push_back(T data); // check
    void insert(T data, int pos); //
    T pop_front(); //
    T pop_back(); //
    bool is_full(); // check
    bool is_empty(); // check
    int size(); 
    void clear(); 
    T &operator[](int); 
    void sort(); // check
    bool is_sorted(); // check
    void reverse(); // check
>>>>>>> 23eb75529894ef011e31df2a130d50b9e1cf8716
    string to_string(string sep=" ");
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
    if (back = capacity-1) return true;
    else return false;
}

template <class T>
void CircularArray<T>::push_front(T data){
    for (int i = capacity; i > 0 ; i--) array[i] = array[i-1];
    array[0] = data;
    back++;
}

template <class T>
void CircularArray<T>::push_back(T data){
    if ( front == -1) front = 0;
    back++;
    array[back]= data;
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
    bool salida = false;
    for (int i = 0; i < capacity-1; i++)
    {
        if (array[i+1] > array[i]) salida = true;
        else salida = false;
    }
    return salida;
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


