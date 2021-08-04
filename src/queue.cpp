#include "queue.hpp"

template <class T>
Queue<T>::Queue()
{
};

template <class T>
Queue<T>::Queue(int size):
                        queueSize(size)
{
    queue_vector.reserve(queueSize);
};

/**
 * Include new element in the last position of the queue.
 * If the queue is full, the thread should blocks until
 * an element is removed from the queue. 
**/
template <class T>
void Queue<T>::Push(T element)
{
    std::unique_lock<std::mutex> ul(m);

    cv.wait(ul,[&] { return (Count() != Size() )? true : false;}); //lock the thread in case the queue is full
        queue_vector.push_back(element);
    cv.notify_one();
};

/**
 * Remove the first element of the queue.
 * If the queue is empty, the thread should blocks until
 * a new element is added to the queue. 
**/
template <class T>
T Queue<T>::Pop()
{
    std::unique_lock<std::mutex> ul(m);
    
    cv.wait(ul,[&] { return (Count()!= 0 )? true : false;}); //lock the thread in case the queue is empty
        T popped_value = queue_vector[0];
        queue_vector.erase(queue_vector.begin(),queue_vector.begin()+1);
    cv.notify_one();
    
    return popped_value;
};

/**
 * Returns the current amount of elements stored on the queue.
**/
template <class T>
int Queue<T>::Count()
{
    return queue_vector.size();
};

/**
 * Returns the max number of elements allowed on the queue,
 * defined on the constructor.
**/
template <class T>
int Queue<T>::Size()
{
    return queueSize;
};