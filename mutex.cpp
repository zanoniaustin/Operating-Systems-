#include<thread>
#include<mutex>
#include<iostream>
using namespace std;

int counter = 2;
mutex mute;

void safe(int num);

int main()
{
  //int counter = 0;
  // Learned that you cannot do pass by reference when creating new threads
  // seems to me this is a easy, simple thing for the language to implement
  // to help with not passing a value to a function that all threads can 
  // manipulate, hence why my use a global variable
  thread t1(safe, 3);
  thread t2(safe, 5);
  thread t3(safe, 7);
  thread t4(safe, 2);
  t1.join();
  t2.join();
  t3.join();
  t4.join();
  return 0;
}

void safe(int num)
{
  lock_guard<mutex> lock(mute);  
  cout << "Counter before inc: " << counter << endl;
  counter = counter * num;
  cout << "Counter after inc: " << counter << endl;
}
