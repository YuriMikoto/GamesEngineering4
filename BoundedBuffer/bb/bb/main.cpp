#include <iostream>
#include <chrono>
#include <thread>
#include <mutex>
//#include <condition_variable>

int p = 0;
int c = 0;
const int n = 5;
int buf;
std::mutex mtx;
//std::condition_variable cv;

int front = 0; //Index showing the next slot to consume from.
int rear = 0; //Index showing the next slot to produce to.
int empty = n;
int full = 0;

void P(int &i)
{
	//Waits until there's room to decrement.
	while (i <= 0)
	{

	}
	i--;
}

void V(int &i)
{
	i++;
}

void producer()
{
	int a[n] = { 10, 20, 30, 40, 50 };

	bool run = true;
	while (run)
	{
		while (p < n)
		{
			std::cout << "ID: " << std::this_thread::get_id() << std::endl;

			while (p != c)
			{
				//Uncomment this to see when this occurs. Commented because it makes it impossible to see what else is going on.
				//std::cout << "Producer is spinning." << std::endl;
			}
			//Entering critical section.
			mtx.lock();
			P(empty);
			//Adds data to the buffer, then moves the rear point.
			buf = a[rear];
			rear = (rear + 1) % n;
			V(full);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			//Exiting critical section.
			mtx.unlock();

			std::cout << a[p] << " deposited in buffer." << std::endl;
			p++;
		}
		std::cout << "Production finished." << std::endl;
		run = false;
	}
}

void consumer()
{
	int b[n];
	bool run = true;
	while (run == true)
	{
		while (c < n)
		{
			std::cout << "ID: " << std::this_thread::get_id() << std::endl;

			while (p <= c)
			{
				//Uncomment this to see when this occurs. Commented because it makes it impossible to see what else is going on.
				//std::cout << "Consumer spinning." << std::endl; 
			}
			//Entering critical section.
			mtx.lock();
			P(full);
			//Takes data from the buffer, then moves the front point.
			b[front] = buf;
			front = (front + 1) % n;
			V(empty);
			std::this_thread::sleep_for(std::chrono::seconds(1));
			//Exiting critical section.
			mtx.unlock();

			std::cout << b[c] << " deposited in b[]." << std::endl;
			c++; //I hate that I find this funny.
		}
		std::cout << "Consumption finished." << std::endl;
		run = false;

	}
}

int main()
{
	std::thread pro(producer);
	std::thread con(consumer);

	pro.join();
	con.join();

	std::cin.get();
}