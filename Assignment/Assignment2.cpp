#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<string.h>

using namespace std;

struct LIST {
	string name;
};

struct NODE {
	LIST name;
	NODE* next = NULL;
};

NODE* head = NULL;
NODE* tail = NULL;

void insertnode(string cd_no) {
	NODE* newnode = new NODE;
	if (newnode) {
		newnode->name.name = cd_no;
		newnode->next = NULL;
		if (head == NULL) {
			head = newnode;
			tail = newnode;
			newnode = NULL;
		}
		else {
			tail->next = newnode;
			tail = newnode;
		}
	}
}

void removeElement(string srchno) {
	NODE* prev = head;
	NODE* current = head->next;
	while (current != NULL) {
		if (current->name.name == srchno || prev->name.name == srchno) {
			break;
		}
		else {
			prev = current;
			current = current->next;
		}
	}
	if (current == NULL && prev == NULL) {
		cout << "Can't remove value: no match found.\n";
	}
	else {
		NODE* deleteptr;
		if (prev->name.name == srchno) {
			deleteptr = prev;
			prev = prev->next;
			head = prev;
			delete deleteptr;
		}
		else {
			if (current) {
				prev->next = current->next;
				delete current;
			}
		}
	}
}


void display() {
	int count = 1;
	NODE* temp = new NODE;
	temp = head;
	while (temp != NULL) {
		cout << "CD Name" << count << ": " << temp->name.name << endl;
		temp = temp->next;
		count++;
	}
}

int main() {
	ofstream myfile;
	myfile.open("data1.txt");
	myfile << "PostMalone" << endl << "Bison" << endl << "Eminem";
	myfile.close();

	ifstream infile;
	string filename = "data1.txt";
	string line;
	string cd_no;
	string cd_in;
	string cd_out;
	infile.open(filename.c_str());
	if (!infile) {
		cout << "Unable to open file" << endl;
		exit(0);
	}
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile >> cd_no;
			insertnode(cd_no);
		}
	}
	infile.close();
	int choice;
	while (1) {
		cout << "-----------MENU----------\n (1) Insert new number\n (2) Remove existing number\n (3) Print list\n (4) Quit\n--------------------\nChoice: ";
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Please enter a CD Name ";
			cin >> cd_in;
			myfile.open("data.txt");
			myfile << cd_in;
			myfile.close();

			infile.open(filename.c_str());
			if (!infile) {
				cout << "Unable to open file" << endl;
				exit(0);
			}
			if (infile.is_open()) {
				while (!infile.eof()) {
					infile >> cd_no;
					insertnode(cd_no);
				}
			}
			infile.close();
			break;
		case 2:
			cout << "Enter a the name to remove: ";
			cin >> cd_out;
			removeElement(cd_out);
			break;
		case 3:
			cout << "_____ CD NAME _______" << endl;
			display();
			break;
		case 4:
			exit(0);
			break;
		default:
			cout << "Invalid option" << endl;
			break;
		}
	}
	return 0;
}
