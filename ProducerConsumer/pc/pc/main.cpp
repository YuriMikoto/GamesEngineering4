using namespace std;

#include <iostream>
#include <chrono>
#include <thread>

int p;
int c;
const int n = 5;
int buf;

void producer()
{
	int a[n] = { 10, 20, 30, 40, 50 };
	bool run = true;
	while (run)
	{
		while (p < n)
		{
			cout << "ID: " << this_thread::get_id() << endl;
			this_thread::sleep_for(chrono::seconds(2));
			while (p != c)
			{
				cout << "Producer is spinning." << endl;
			}
			buf = a[p];
			cout << a[p] << " deposited in buffer." << endl;
			p++;
		}
		cout << "Production finished." << endl;
		run = false;
	}
}

void consumer()
{
	int b[n];
	bool run = true;
	while (run)
	{
		while (c < n)
		{
			cout << "ID: " << this_thread::get_id() << endl;
			this_thread::sleep_for(chrono::seconds(1));
			while (p <= c)
			{
				cout << "Consumer spinning." << endl;
			}
			b[c] = buf;
			cout << buf << " deposited in b[]." << endl;
			c++;
		}
		cout << "Consumption finished." << endl;
		run = false;
	}
}

int main()
{
	thread pro(producer);
	thread con(consumer);

	pro.join();
	con.join();

	cin.get();
}