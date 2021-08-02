#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <vector>

template <class T>
class Queue{
private:
    int queueSize;
    std::vector<T> queue_vector;
    Queue(); //not possible to create a queue without size
public:
    Queue(int size);
    void Push(T element);
    T Pop();
    int Count();
    int Size();
};
#include "queue.cpp" //Necessary to compile/linking due to use of templates

#endif //QUEUE_HPP