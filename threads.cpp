#include<iostream>
#include<pthread.h>
#include<thread>

using namespace std;

void inc(int counter);

int main()
{
	int counter = 0;
	thread first(inc, counter);
	thread second(inc, counter);
																																																																																																																						
	cout << counter << endl;
	first.join();
	second.join();
	return 0;
}

void inc(int counter)
{
	counter++;
	cout << counter << endl;
}																											
