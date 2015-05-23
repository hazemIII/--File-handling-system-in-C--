/*
 * bst.h
 *
 *  Created on: May 23, 2015
 *      Author: hazem
 */

#ifndef BST_H_
#define BST_H_
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;
template<typename bt>
class bst {
public:
	bst() {
		Empty = true;
		leftbst = rightbst = 0;
	}
	bool isEmpty() {
		return Empty;
	}
	bt getData() {
		if (!isEmpty())
			return data;
		else
			return 0;
	}
	void insert(const bt &d) {
		if (Empty) {
			Empty = false;
			leftbst = new bst;
			rightbst = new bst;
			data = d;
			root = this;

		}
		//else if (d==data);//don't do shit
		else if (d <= data)
			leftbst->insert(d); // insert in leftbst subbst
		else
			rightbst->insert(d); // insert in rightbst subbst
	}
	void insert2(const bt &d) {
		if (Empty) {
			Empty = false;
			leftbst = new bst;
			rightbst = new bst;
			data = d;
		} else if (d == getData())
			; //don't do shit
		else if (d < data)
			leftbst->insert2(d); // insert in leftbst subbst
		else if (d > data)
			rightbst->insert2(d); // insert in rightbst subbst
	}

	bst<bt>* retrieve(const bt &d) {
		if (Empty || d == data)
// return pointer to bst for which retrieve was called
			return this;
		else if (d < data)
			return leftbst->retrieve(d); // recurse leftbst
		else
			return rightbst->retrieve(d); // recurse rightbst
	}
	bst<bt>* left() {
		if (!isEmpty())
			return leftbst;
		else
			return 0;
	}
	bst<bt>* right() {
		if (!isEmpty())
			return rightbst;
		else
			return 0;
	}
	int noe() {
		if (!isEmpty()) {
			return 1 + leftbst->noe() + rightbst->noe();
		} else {
			return 0;
		}
	}
	int pn() {
		return (noe());
	}
	int search(string word) {
		if (!isEmpty()) {
			if (word == this->data) {
				if (leftbst != 0)
					return 1 + leftbst->search(word);
				else
					return 1;
			} else if (word < this->data) {
				if (leftbst != 0)
					return leftbst->search(word);
				else
					return 0;
			} else {
				if (rightbst != 0)
					return rightbst->search(word);
				else
					return 0;
			}
		} else
			return 0;
	}
	bst<bt>* getRoot() {
		return root;
	}

	void preorder(bst *b) {
		if (!isEmpty()) { // if not empty
			// visit bst
			cout << getData() << ' ';
			cout << b->search(getData()) << ' ';
			// traverse left child
			//preorder(b->left());
			leftbst->preorder(b);
			// traverse right child
			//preorder(b->right());
			rightbst->preorder(b);
		}
	}
	void inorder(bst *b) {
		if (!isEmpty()) {
			// traverse left child
			//inorder(b->left());
			leftbst->inorder(b);
			// visit bst
			cout <<getData() << ' ';
			cout << b->search(getData()) << ' ';
			// traverse right child
			rightbst->inorder(b);
		}
	}
	void postorder(bst *b) {
		if (!isEmpty()) {
			// traverse left child
			leftbst->postorder(b);
			// traverse right child
			rightbst->postorder(b);
			// visit bst
			cout << getData() << ' ';
			cout << b->search(getData()) << ' ';

		}
	}
	void mostFreq(bst *t, int max){
		if(! isEmpty()){
			int num = 0 ;
			string u;
			num = t->search(getData());
			leftbst->mostFreq(t,max);
			if(max == num){
				u = getData();
				cout << u<<' ';
			}
			rightbst->mostFreq(t,max );

		}

	}

private:
	bool Empty;
	bt data;
	bst* root;
	bst* leftbst;
	bst* rightbst;

};



#endif /* BST_H_ */
