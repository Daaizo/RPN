#include "stackimplementation.h"
#include <iostream>
using namespace std;

template <typename T>
MyStack<T>::MyStack()
{
    //this = nullptr;
    cout << "\nkonstruktor\n";
}

template <typename T>
void MyStack<T>::Push(MyStack *& stack, T value)
{
    MyStack *temp = new MyStack;
    temp->data = value;
    temp->next = stack;
    stack = temp;

}

template <typename T>
bool MyStack<T>::IsEmpty(MyStack* stack) const
{
    return stack;
}




//template <typename T>
//void MyStack<T>::DeleteWholeStack(MyStack *&stack)
//{
//    for


//}


//template <typename T>
//MyStack<T>::~MyStack()
//{

//}
