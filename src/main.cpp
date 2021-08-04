#include <iostream>
#include <thread>
#include "queue.hpp"


int main()
{
    Queue<int> *myQueue = new Queue<int> (3);
    std::cout << "Size() : " << myQueue->Size() << std::endl;
    std::cout << "Count(): " << myQueue->Count() << std::endl;

    std::thread read_1(&Queue<int>::Pop, myQueue);
    std::thread read_2(&Queue<int>::Pop, myQueue);
    std::thread read_3(&Queue<int>::Pop, myQueue);
    std::thread read_4(&Queue<int>::Pop, myQueue);
    std::thread read_5(&Queue<int>::Pop, myQueue);
    std::thread write_1(&Queue<int>::Push, myQueue, 11);
    std::thread write_2(&Queue<int>::Push, myQueue, 22);
    std::thread write_3(&Queue<int>::Push, myQueue, 33);
    std::thread write_4(&Queue<int>::Push, myQueue, 44);
    std::thread write_5(&Queue<int>::Push, myQueue, 55);
    write_1.join();
    write_2.join();
    write_3.join();
    write_4.join();
    read_1.join();
    read_2.join();
    read_3.join();
    read_4.join();
    read_5.join();
    write_5.join();
    

    // myQueue.Push(12);
    // std::cout << "Add 12" << std::endl;
    // std::cout << "Count (): "<< myQueue.Count() << std::endl;
    
    // myQueue.Push(99);
    // std::cout << "Add 99" << std::endl;
    // std::cout << "Count (): "<< myQueue.Count() << std::endl;

    // myQueue.Push(45);
    // std::cout << "Add 45" << std::endl;
    // std::cout << "Count (): "<< myQueue.Count() << std::endl;
    
    // std::cout << "Pop()   : " << myQueue.Pop() << std::endl;
    // std::cout << "Count() : " << myQueue.Count() << std::endl;
    
    // std::cout << "Pop()   : " << myQueue.Pop() << std::endl;
    // std::cout << "Count() : " << myQueue.Count() << std::endl;

    // std::cout << "Pop()   : " << myQueue.Pop() << std::endl;
    // std::cout << "Count() : " << myQueue.Count() << std::endl;

    // std::cout << "Pop()   : " << myQueue.Pop() << std::endl;
    // std::cout << "Count() : " << myQueue.Count() << std::endl;


    // std::cout << "Fulfil queue"<< std::endl;
    // myQueue.Push(1);
    // myQueue.Push(2);
    // myQueue.Push(3);
    // myQueue.Push(3);
    // myQueue.Push(5);
    // std::cout << "Exceed queue capacity"<< std::endl;
    delete myQueue;
    return 0;
}