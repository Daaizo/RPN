#ifndef STACKIMPLEMENTATION_H
#define STACKIMPLEMENTATION_H

template <typename T>
class MyStack
{
private:
    MyStack *next;
    T data;

public:
    MyStack();
    ~MyStack();
    void Pop(MyStack *&);
    void Push(MyStack *&, T value);
    void Top(MyStack*) const;
    bool IsEmpty(MyStack*) const;
    void DeleteWholeStack(MyStack *&);
    void PrintStack(MyStack *) const;


};

#endif // STACKIMPLEMENTATION_H
