#include <iostream>
#include <thread>
#include "queue.hpp"


int main()
{
    Queue<int> *myQueue = new Queue<int> (2);
    // std::cout << "Size() : " << myQueue->Size() << std::endl;
    // std::cout << "Count(): " << myQueue->Count() << std::endl;

    std::thread write_1(&Queue<int>::Push, myQueue, 1); //Push(1)
    std::thread read_1(&Queue<int>::Pop, myQueue);  //Pop()->1
    std::thread write_2(&Queue<int>::Push, myQueue, 2); //Push(2)
    std::thread write_3(&Queue<int>::Push, myQueue, 3); //Push(3)
    std::thread write_4(&Queue<int>::Push, myQueue, 4); //Push(4)
    std::thread read_2(&Queue<int>::Pop, myQueue);  //Pop()->2
    std::thread read_3(&Queue<int>::Pop, myQueue);  //Pop()->3
    std::thread read_4(&Queue<int>::Pop, myQueue);  //Pop()->4
    std::thread read_5(&Queue<int>::Pop, myQueue);  //Pop()->5
    std::thread write_5(&Queue<int>::Push, myQueue, 5); //Push(5)
    write_1.join();
    read_1.join();
    write_2.join();
    write_3.join();
    write_4.join();
    read_2.join();
    read_3.join();
    read_4.join();
    read_5.join();
    write_5.join();
    delete myQueue;
    return 0;
}