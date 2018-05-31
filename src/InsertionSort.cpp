/*
CSCI 700: Proj.1 InsertionSort(C++)
Prof. Tsaiyun Phillips
Author: Shawn Yang
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class listNode {
	public:
		string data;
		listNode* next;
		listNode() {
			data = "dummy";
			next = NULL;
		}
		listNode(string str) {
			data = str;
			next = NULL;
		}
};

class linkedList {
	public:
		listNode* listHead;
		linkedList() {
			listHead = (new listNode());
		}
		bool isEmpty() {
			return ((*listHead).next == NULL);
		};
		void listInsert(string str) {
			//step 1
			listNode * walker = listHead;
			//step 2
			while (((*walker).next != NULL) && (str > ((*(*walker).next).data))) {
				walker = (*walker).next;
			}
			//step 3
			//step 4
			listNode *NN = new listNode(str);
			//step 5
			(*NN).next = (*walker).next;
			(*walker).next = NN;
		};
		void printList(ofstream &os) {
			listNode *walker = listHead;
			os << "listHead -->"<<"("+(*listHead).data+", ";
			while ((*walker).next != NULL) {
				walker = (*walker).next;
				os << (*walker).data + ") --> ("<< (*walker).data +", ";
			}
			os << "null)"<<endl;
		};
};

int main(int argc, char * argv[]){
	ifstream inFile;
	ofstream outFile;
	string word;
	if (argc < 3) {
		cout << "Please supply the locations of both input file and output file.";
		return 0;
	}
	try {
		inFile.open(argv[1]);
		outFile.open(argv[2]);
		cout <<"Files"<< argv[1] <<", "<< argv[2]<<" :openned successfully."<<endl;
		linkedList myList;
		while (inFile >> word) {
			myList.listInsert(word);
			myList.printList(outFile);
		}
		cout << "output to file successfully." << endl;
		inFile.close();
		outFile.close();
	}
	catch (const fstream* e) {
		cout << "Unable to open files." << e;
	}
	return 0;
}