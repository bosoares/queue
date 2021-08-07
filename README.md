# Queue
Implements a queue of a finite amount of elements to be used for multi-threaded communication.

# How to use
1 - The development process was done on a Linux distribuition. Be sure to have installed g++ and cmake.
<br />
* sudo apt-get install cmake
* sudo apt-get install g++

2 - Download the repositories.<br />
<br />
3 - In the root directorie (queue), enter the following commands:
<br />
* mkdir build
* cd build
* cmake ..
* make 
* make install
* cd ../dist
* ./myQueue
* ./testmyQueue (Unit test)

# NOTES
1 - To activate a verbose mode, uncomment the following lines before Step 3:
* src/include/queue.hpp - Line  81
* src/include/queue.hpp - Line 118
* src/main.cpp - Line 9
* src/main.cpp - Line 10
