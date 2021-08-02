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
 * Include new element in the last position of the queue
**/
template <class T>
void Queue<T>::Push(T element)
{
    if(Count() != Size())
    {
        queue_vector.push_back(element);
    }
    else
    {
        std::cout << "Queue full... waiting for Pop" << std::endl;
    }
};

/**
 * Remove the first element of the queue
**/
template <class T>
T Queue<T>::Pop()
{
    if (queue_vector.begin() == queue_vector.end())
    {
        return (T)NULL;
    }
    else
    {
        T popped;
        popped = queue_vector[0];
        queue_vector.erase(queue_vector.begin(),queue_vector.begin()+1);
        return popped;
    }
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