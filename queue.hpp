#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <vector>
#include <mutex>
#include <condition_variable>
template <class T>
class Queue{
private:
    int queueSize;
    std::vector<T> queue_vector;
    Queue(); //not possible to create a queue without size.
    std::mutex m;
    std::condition_variable cv;
public:
    Queue(int size);
    void Push(T element); //Insert elements in the last position of the queue.
    T Pop(); //Remove the first element of the queue.               
    int Count(); //Return the number of elements in the queue.
    int Size(); //Return the max number of elements allowed in the queue.
};

#include "queue.cpp" //Necessary to compile/linking due to use of templates.

#endif //QUEUE_HPP