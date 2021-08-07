#include "gtest/gtest.h"
#include "queue.hpp"

/**
 *  Test: Invalid Instantiation
 *  Description: Test the instantiation of a new object of class::Queue
 *               with invalid parameter.
 *  TEST 1
 *  Input: 0
 *  Expected output: Error message "Invalid initializer value"
 *  
 *  TEST 2
 *  Input: -1
 *  Expected output: Error message "Invalid initializer value"
 * 
 *  TEST 3
 *  Input: 1
 *  Expected output: Not equal to "Invalid initializer value"
 * 
**/

TEST(Queue_Test, Invalid_Instatiation)
{
    //TEST 1   
    try{
        Queue<int> *myQueue = new Queue<int> (0);
    }catch(const char* msg){
        EXPECT_EQ(msg, "Invalid initializer value");
    }

    //TEST 2
    try{
        Queue<int> *myQueue = new Queue<int> (-1);
    }catch(const char* msg){
        EXPECT_EQ(msg, "Invalid initializer value");
    }
    
    //TEST 3
    try{
        Queue<int> *myQueue = new Queue<int> (1);
    }catch(const char* msg){
        EXPECT_NE(msg, "Invalid initializer value");
    }
}

/**
 *  Test: Valid Instantiation
 *  Description: Test the instantiation of a new object of class::Queue
 *               with valid parameter for different types of variables
 *  TEST 1
 *  Input: Int
 *  Expected output: Now Error Throw
 *  
 *  TEST 2
 *  Input: bool
 *  Expected output: Now Error Throw
 * 
 *  TEST 3
 *  Input: double
 *  Expected output: Now Error Throw
 * 
 *  TEST 4
 *  Input: char
 *  Expected output: Now Error Throw
 * 
 *  TEST 5
 *  Input: string
 *  Expected output: Now Error Throw
 * 
**/
TEST(Queue_Test,Valid_Instatiation)
{
    //TEST 1
    EXPECT_NO_THROW(Queue<int> *myQueue_int = new Queue<int> (1));
    //TEST 2
    EXPECT_NO_THROW(Queue<bool> *myQueue_bool = new Queue<bool> (1));
    //TEST 3
    EXPECT_NO_THROW(Queue<double> *myQueue_double = new Queue<double> (1));
    //TEST 4
    EXPECT_NO_THROW(Queue<char> *myQueue_char = new Queue<char> (1));
    //TEST 5
    EXPECT_NO_THROW(Queue<std::string> *myQueue_string = new Queue<std::string> (1));
}

/**
 *  Test: Queue::Size()
 *  Description: Test if the method the Queue::Size() returns the same
 *               same value informed on the instantiation.
 * 
 *  Input: 1 to 10.000
 *  Expected output: 1 to 10.000
 *  
**/
TEST(Queue_Test, Queue_Size)
{
    for(int i=1;i<10000; i++)
    {
        Queue<int> *myQueue_int = new Queue<int> (i);
        EXPECT_EQ(myQueue_int->Size(),i);
        delete(myQueue_int);
    }
}

/**
 *  Test: Queue::Push() and Queue::Count()
 *  Description: Test if the method the Queue::Push() increases the
 *               number of elements in the Queue. Method Queue::Count()
 *               should returns the correct number of elements in the
 *               Queue.
 * 
 *  Input: 1 to 1000
 *  Expected output: 1 to 1000
 *  
**/
TEST(Queue_Test, Queue_Count)
{
    Queue<int> *myQueue_int = new Queue<int> (1000);
    for(int i=1;i<1000; i++)
    {
        myQueue_int->Push(i);
        EXPECT_EQ(myQueue_int->Count(),i);
    }
    delete(myQueue_int);
}

/**
 *  Test: Queue::Push() and Queue::Pop()
 *  Description: Test if the method the Queue::Push() increases the
 *               number of elements in the Queue and Method Queue::Pop()
 *               removes elements in the correct order.
 *               Queue.
 * 
 *  Input: 1 to 1000
 *  Expected output: 1000 to 1
 *  
**/
TEST(Queue_Test, Queue_Pop)
{
    Queue<int> *myQueue_int = new Queue<int> (1000);
    for(int i=1;i<=1000; i++)
    {
        myQueue_int->Push(i);
        EXPECT_EQ(myQueue_int->Count(),i);
    }
    int num_elements = myQueue_int->Count();
    for(int i=1;i<=1000; i++)
    {
        EXPECT_EQ(myQueue_int->Pop(),i);
        EXPECT_EQ(myQueue_int->Count(),num_elements-i);
    }
    delete(myQueue_int);
}