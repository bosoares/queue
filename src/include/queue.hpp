#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>
#include <mutex>
#include <condition_variable>

template <class T>
class Queue{
private:
    //methods
    Queue(); //not possible to create a queue without pre-defined size.
    
    //data structures
    struct node
    {
        T value;
        node *next;
        node(T initializer)
        {
            value = initializer;
            next = NULL;
        };
    };
 
    //properties
    int queueSize;      // max defined size of the Queue.
    int queueNumElemen; // cureent size of the Queue.

    node* head;
    node* tail;

    std::mutex m;
    std::mutex m_numelemen;
    std::condition_variable cv;

public:
    Queue(int size)
    {
        if(size <= 0)   //Prevents Queue criation with size = 0
        {
            throw ("Invalid initializer value");
        }
        head = NULL;
        tail = NULL;
        queueNumElemen = 0;
        queueSize = size;        
    };
    
    /**
     * Method: void Push(T element)
     * Description: Include new element in the last position of the queue.
     *              If the queue is full, the thread should blocks until
     *              an element is removed from the queue.
     * 
     * Arguments: An element of the same type as defined at the instatiation of
     *            the class (template).
     * 
     * Return: void.
    **/
    void Push(T element)
    {
        std::unique_lock<std::mutex> ul(m);
        cv.wait(ul,[&] { return (Count() != Size() )? true : false;}); //lock the thread in case the queue is full.
            m_numelemen.lock(); //Block the Count() method to avoid it to return a wrong value.

                node *newNode = new node(element);
                
                if(tail == NULL)    //if Queue is empty, head and tail point to the same element.
                {
                    tail = newNode;
                    head = newNode;
                }
                else  //if Queue is not empty, connect last element to the new one and change tail to it.              
                {
                    tail->next = newNode;
                    tail = newNode;
                }
                
                queueNumElemen++;
                //std::cout << "PUSH(" << element << ") - " << "Count(): " << queueNumElemen << std::endl;

            m_numelemen.unlock();
        cv.notify_one();
    };

    /**
     * Method: T Pop()
     * Description: Remove the first element of the queue.
     *              If the queue is empty, the thread should blocks until
     *              a new element is added to the queue.
     * 
     * Arguments:
     * 
     * Return:  The first element of the queue, of the same type as defined
     *          at the instatiation of the class (template).
    **/
    T Pop()
    {
        std::unique_lock<std::mutex> ul(m);
        cv.wait(ul,[&] { return (Count()!= 0 )? true : false;}); //lock the thread in case the queue is empty
            m_numelemen.lock();
            
                T popped_value = head->value;   //Temp store of the popped value.

                node* temp = head;
                head = head->next;  // Change head to the next element

                if(head == NULL)    //If Queue becomes empty, clear the tail.
                {
                    tail = NULL;
                }
                
                delete(temp);   // Free the memory allocated on Push() operation.

                queueNumElemen--;

                //std::cout << " POP(" << popped_value << ") - " << "Count(): " << queueNumElemen << std::endl;

            m_numelemen.unlock();
        cv.notify_one();
    
        return popped_value;
    };

    /**
     * Method: int Count()
     * Description: Return the current amount of elements stored on the queue.
     *              If an operation of Push() or Pop() is under execution, the 
     *              thread should blocks until the current operation is finished.
     * 
     * Arguments:
     * 
     * Return:  Integer.
    **/
    int Count()
    {
        m_numelemen.lock();
        m_numelemen.unlock();
        return queueNumElemen;
    }; 
    
    /**
     * Method: int Size()
     * Description: Return the max number of elements allowed in the queue.
     *              This value never changes during the lifetime of the object.
     * 
     * Arguments:
     * 
     * Return:  Integer.
    **/
    int Size()
    {
        return queueSize;
    };
};

#endif //QUEUE_HPP