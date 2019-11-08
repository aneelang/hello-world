#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<string.h>

using namespace std;


struct SCORE {
	float score1;
	float score2;
	float score3;
	float score4;
};
struct NODE {
	string name;
	SCORE score;
	NODE* next = NULL;
};

NODE* head = NULL;
NODE* tail = NULL;

void insertnode(string sname, SCORE sscore) {
	NODE* newnode = new NODE;
	if (newnode) {
		newnode->name = sname;
		newnode->score = sscore;
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

void display() {
	int count = 1;
	NODE* temp = new NODE;
	temp = head;
	while (temp != NULL) {
		cout << "Student" << count << ": " << temp->name << endl;
		cout << "	Score1: " << temp->score.score1 << endl;
		cout << "	Score2: " << temp->score.score2 << endl;
		cout << "	Score3: " << temp->score.score3 << endl;
		cout << "	Score4: " << temp->score.score4 << endl;
		temp = temp->next;
		count++;
	}
}

int main() {
	SCORE student;
	fstream myfile, infile;
	myfile.open("data2.txt");
	myfile << "Mark Zuckeberg 98 100 90 99.4\nJay Shetty 100.0 95 19.0 77.2\nJatin 100 99 84.0 99.7\n";
	myfile.close();

	string filename = "data2.txt";
	string name;
	float num1;
	float num2;
	float num3;
	float num4;
	infile.open(filename.c_str());
	if (!infile) {
		cout << "Unable to open file" << endl;
		exit(0);
	}
	if (infile.is_open()) {
		while (!infile.eof()) {
			infile >> name >> num1 >> num2 >> num3 >> num4;
			student.score1 = num1;
			student.score2 = num2;
			student.score3 = num3;
			student.score4 = num4;
			insertnode(name, student);
		}
	}
	infile.close();

	display();


	return 0;
}
