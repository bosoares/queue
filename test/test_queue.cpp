#include "gtest/gtest.h"
#include "queue.hpp"


TEST(GTestSuite_Queue, Instatiation)
{
    Queue<int> *myQueue = new Queue<int> (2);
}