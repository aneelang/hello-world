#include<iostream>
#include<stdlib.h>
#include<sstream>
#include<fstream>

using namespace std;

int arr[100], n;

void heapify(int arr[], int n, int i)
{
	int smallest = i;
	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < n && arr[l] < arr[smallest])
		smallest = l;

	if (r < n && arr[r] < arr[smallest])
		smallest = r;

	if (smallest != i) {
		swap(arr[i], arr[smallest]);

		heapify(arr, n, smallest);
	}
}

void insert(int num, int loc)
{
	int des;
	while (loc > 0)
	{
		des = (loc - 1) / 2;
		if (num >= arr[des])
		{
			arr[loc] = num;
			return;
		}
		arr[loc] = arr[des];
		loc = des;
	}
	arr[0] = num;
}


void deleteroot() {
	int lele = arr[n - 1];
	arr[0] = lele;
	n = n - 1;
	heapify(arr, n, 0);
}

void display()
{
	for (int i = 0; i < n; i++) {
		cout << arr[i] << endl
	}

	cout << endl;
}

int main()
{
	fstream myfile;
	myfile.open("data.txt");

	for (int i = 0; i < 100; i++)
	{
		int random = rand() % 500 + 50;
		myfile << random << endl;
	}

	int data = 0;
	ifstream infile("data.txt");
	if (infile.is_open())
	{
		string line;
		while (getline(infile, line))
		{
			stringstream geek(line);
			geek >> data;
			insert(data, n);
			n++;
		}
		display();
		for (int j = 0; j < 10; j++) {
			deleteroot();
		}
		display();
		infile.close();
	}

	return 0;
}