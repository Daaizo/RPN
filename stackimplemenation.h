#ifndef STACKIMPLEMENTATION_H
#define STACKIMPLEMENTATION_H
#include <iostream>
//#include <cstdbool>
template <typename T> class MyStack
{
private:
    MyStack<T> *next;
    T data;

public:

    MyStack();
    MyStack(T var):data(var){;};
    ~MyStack<T>(){};
    void PrintStack(MyStack *c) const;
    void Pop(MyStack *&);
    void Push(MyStack *&,T value);
    T Top() const;
    bool IsEmpty(MyStack *) const;
    void DeleteWholeStack(MyStack *&);



};

template <typename T> void MyStack<T>::Push(MyStack *& current_stack,T value)
{
    MyStack *temp = new MyStack<T>;
    temp->data = value;
    temp->next =current_stack;

    current_stack = temp;
}

template <typename T> MyStack<T>::MyStack(){}
template <typename T> bool MyStack<T>::IsEmpty(MyStack *current_stack) const
{
    return !current_stack;
}

template <typename T> void MyStack<T>::PrintStack(MyStack *current_stack) const
{
    MyStack<T> *temp = current_stack;
    if(current_stack->IsEmpty(current_stack) == false)
    {
        std::cout << "\nStack: \n";
        while(!temp->IsEmpty(temp))
        {
            std::cout << temp->Top() << " ";
            temp->Pop(temp);
        }
    }
    else std::cout << "\nStack is empty and cannot be printed";

}

template <typename T> void MyStack<T>::Pop(MyStack *&current_stack)
{
    if(current_stack->IsEmpty(current_stack) == false)
    {
        current_stack = current_stack->next;
    }
    else std::cout << "\nStack is empty and there is no value to pop";
}

template <typename T> T MyStack<T>::Top() const
{
        return this->data;
}
template <typename T> void MyStack<T>::DeleteWholeStack(MyStack *&current_stack)
{
    if(current_stack->IsEmpty(current_stack) == false)
    {
        while(!current_stack->IsEmpty(current_stack))
        {
            current_stack->Pop(current_stack);
        }
        std::cout << "\nStack delation succed";
    }
    else std::cout << "\nStack is already empty!";


}
#endif // STACKIMPLEMENTATION_H
