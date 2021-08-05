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
    Queue(int size)
    {
        queueSize = size;
        queue_vector.reserve(queueSize);
    };
    void Push(T element)//Insert elements in the last position of the queue.
    {
        std::cout << "PUSH (" << element << ") - Try to aquire the mutex" << std::endl; //to be removed
        std::unique_lock<std::mutex> ul(m);
        cv.wait(ul,[&] { return (Count() != Size() )? true : false;}); //lock the thread in case the queue is full
        std::cout << "Push mutex aquired" << std::endl; //to be removed
        queue_vector.push_back(element);
        cv.notify_one();
    };

    T Pop() //Remove the first element of the queue.
    {
            std::unique_lock<std::mutex> ul(m);
    std::cout << "POP - Try to aquire the mutex" << std::endl; //to be removed
    cv.wait(ul,[&] { return (Count()!= 0 )? true : false;}); //lock the thread in case the queue is empty
    std::cout << "Pop Mutex aquired (" << queue_vector[0] << ")" << std::endl; //to be removed
        T popped_value = queue_vector[0];
        queue_vector.erase(queue_vector.begin(),queue_vector.begin()+1);
    cv.notify_one();
    
    return popped_value;
    };
    int Count()
    {
            return queue_vector.size();
    }; //Return the number of elements in the queue.
    int Size()
    {
        return queueSize;
    }; //Return the max number of elements allowed in the queue.
};

//#include "queue.cpp" //Necessary to compile/linking due to use of templates.

#endif //QUEUE_HPP