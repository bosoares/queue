#include <iostream>
#include "queue.hpp"


int main()
{
    Queue<int> myQueue(5);
    std::cout << "Size() : " << myQueue.Size() << std::endl;
    std::cout << "Count(): " <<myQueue.Count() << std::endl
    ;
    myQueue.Push(12);
    std::cout << "Add 12" << std::endl;
    std::cout << "Count (): "<< myQueue.Count() << std::endl;
    
    myQueue.Push(99);
    std::cout << "Add 99" << std::endl;
    std::cout << "Count (): "<< myQueue.Count() << std::endl;

    myQueue.Push(45);
    std::cout << "Add 45" << std::endl;
    std::cout << "Count (): "<< myQueue.Count() << std::endl;
    
    std::cout << "Pop()   : " << myQueue.Pop() << std::endl;
    std::cout << "Count() : " << myQueue.Count() << std::endl;
    
    std::cout << "Pop()   : " << myQueue.Pop() << std::endl;
    std::cout << "Count() : " << myQueue.Count() << std::endl;

    std::cout << "Pop()   : " << myQueue.Pop() << std::endl;
    std::cout << "Count() : " << myQueue.Count() << std::endl;

    std::cout << "Pop()   : " << myQueue.Pop() << std::endl;
    std::cout << "Count() : " << myQueue.Count() << std::endl;


    std::cout << "Fulfil queue"<< std::endl;
    myQueue.Push(1);
    myQueue.Push(2);
    myQueue.Push(3);
    myQueue.Push(3);
    myQueue.Push(5);
    std::cout << "Exceed queue capacity"<< std::endl;
    myQueue.Push(6);
    return 0;
}