//============================================================================
// Name        : A4.cpp
// Author      : Hazem Safwat
// Version     :
// Copyrightbst   : Your copyrightbst notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "bst.h"
using namespace std;
string lower(string sent) {
	for (string::iterator i = sent.begin(); i != sent.end(); i++) {
		*i = tolower(*i);
	}
	return sent;
}

int main(int argc, char ** argv) {
	if (argc < 3) {
		cout << "Incorrect number of arguments";
		return 0;
	}
	ifstream f;
	bst<string> T , s;
	string filename, word, command;
	filename = argv[1];
	command = argv[2];
	f.open(filename.c_str());
	if (!f.is_open()) {
		cout << "File not found";
		return 0;
	}
	if (command == "wordCount") {
		int w = 0;
		while (f >> word) {
			w++;
		}
		cout << w << " words";
	} else if (command == "distWords") {
//		int w = 0, total = 0;
		while (f >> word) {
//			T.insert(lower(word));
			s.insert2(lower(word));
//			total++;
//			w = (T.search(lower(word))) ;
		}
		cout <<  s.noe() << " distinct words" ;

	} else if (command == "countWord") {
		if (argc < 4 ){
			cout << "Incorrect number of arguments";
			return 0;
		}
		while (f >> word)
			T.insert(lower(word));
		cout << argv[3] << " is repeated " << T.search(argv[3]) << " times";


	} else if (command == "frequentWord") {
		int max = 0, num = 0;
		while (f >> word){
			T.insert(lower(word));
			s.insert2(lower(word));
			num = T.search(lower(word));
			if(max < num)
				max = num;
		}
		cout<< "Most frequent word is ";
		s.mostFreq(T.getRoot(), max);


	} else if (command == "printPreorder") {
		while (f >> word) {
			T.insert2(lower(word));
			s.insert(lower(word));
		}
		T.preorder(s.getRoot());
	} else if (command == "printInorder") {
		while (f >> word){
			T.insert2(lower(word));
					s.insert(lower(word));
				}
				T.inorder(s.getRoot());
	} else if (command == "printPostorder") {
		while (f >> word){
			T.insert2(lower(word));
					s.insert(lower(word));
				}
				T.postorder(s.getRoot());
	}

	else
		cout << "Undefined command";
	f.close();
	return 0;
}
