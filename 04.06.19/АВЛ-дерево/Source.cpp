#define _CRT_SECURE_NO_WARNINGS
#define ll long long
#define null NULL

#include <stdio.h>
#include <limits.h>

#include <algorithm>
#include <stdexcept>
#include <iterator>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <string>
#include <vector>
#include <cstdio>
#include <random>
#include <deque>
#include <queue>
#include <stack>
#include <ctime>
#include <cmath>
#include <regex>
#include <tuple>
#include <map>
#include <set>

using namespace std;

struct Node
{
	int value;
	int height;

	Node* left;
	Node* right;

	Node(int value, Node* left = null, Node* right = null, int height = 1) {
		this->value = value;
		this->left = left;
		this->right = right;
		this->height = height;
	}

	int UpdateHeight() {
		height = max((right != null ? right->height : 0), (left != null ? left->height : 0)) + 1;
		return height;
	}
};

struct AVLTree {
	Node* head;
	int count;

	AVLTree() {
		head = null;
		count = 0;
	}

	void Add(int value) {
		if (head == null) {
			head = new Node(value);
			count++;
		}

		Add(value, head);
	}

	Node* Add(int value, Node* t) {
		Node* temp;
		if (t->value < value) {
			if (t->right == null) {
				t->right = new Node(value);
				count++;
			}
			else {
				temp = Add(value, t->right);
				if (temp != null)
					t->right = temp;
			}
		}
		else if (t->value > value) {
			if (t->left == null) {
				t->left = new Node(value);
				count++;
			}
			else {
				temp = Add(value, t->left);
				if (temp != null)
					t->left = temp;
			}
		}
		else {
			return null;
		}

		return Balance(t);
	}

	int GetBalance(Node* node) {
		return node == null ? 0 : ((node->right != null ? node->right->height : 0) - (node->left != null ? node->left->height : 0));
	}

	Node* Balance(Node* node, int i = 0) {
		int bal = GetBalance(node);

		if (bal == 2) {
			bal = GetBalance(node->right);

			if (bal >= 0) {
				return LRotate(node, node->right);
			}
			else if (bal == -1) {
				return RLRotate(node, node->right, node->right->left);
			}
		}
		else if (bal == -2) {
			bal = GetBalance(node->right);

			if (bal <= 0) {
				return RRotate(node, node->left);
			}
			else if (bal == 1) {
				return LRRotate(node, node->left, node->left->right);
			}
		}

		node->UpdateHeight();
		return null;
	}

	Node* LRotate(Node* a, Node* b) {
		Node* c;

		a->right = b->left;
		b->left = a;

		a->UpdateHeight();
		b->UpdateHeight();

		if (a == head) {
			head = b;
		}

		return b;
	}

	Node* RRotate(Node* a, Node* b) {
		Node* c;

		a->left = b->right;
		b->right = a;

		a->UpdateHeight();
		b->UpdateHeight();

		if (a == head) {
			head = b;
		}

		return b;
	}

	Node* LRRotate(Node* x, Node* a, Node* c) {
		LRotate(a, c);

		x->left = c;

		RRotate(c, x);

		x->UpdateHeight();
		a->UpdateHeight();
		c->UpdateHeight();

		return c;
	}

	Node* RLRotate(Node* x, Node* b, Node* d) {
		RRotate(b, d);

		x->right = d;

		LRotate(x, d);

		x->UpdateHeight();
		b->UpdateHeight();
		d->UpdateHeight();

		return d;
	}

	Node* Min(Node* n) {
		if (n == null || n->left == null)
			return n;

		return Min(n->left);
	}

	Node* Max(Node* n) {
		if (n == null || n->right == null)
			return n;

		return Max(n->right);
	}

	void Remove(int value) {
		Remove(head, value);
	}

	Node* Remove(Node* t, int value) {
		if (t == null)
			return null;

		Node* tmp;

		if (t->value == value) {
			count--;
			if (t->left == null) {
				tmp = t->right;
				delete t;
				return tmp;
			}
			if (t->right == null) {
				tmp = t->left;
				delete t;
				return tmp;
			}
			if (t->left->height > t->right->height) {
				tmp = Max(t->left);

				t->value = tmp->value;

				tmp = Remove(t->left, tmp->value);

				if (tmp != null) {
					t->left = tmp;
				}
			}
			else {
				tmp = Min(t->right);

				t->value = tmp->value;

				tmp = Remove(t->right, tmp->value);

				if (tmp != null) {
					t->right = tmp;
				}
			}
			tmp = Balance(t);
			return tmp == null ? t : tmp;
		}
		else {
			if (t->value > value)
				t->left = Remove(t->left, value);
			else
				t->right = Remove(t->right, value);

			tmp = Balance(t);
			return tmp == null ? t : tmp;
		}
	}

	void PrintTree(Node* temp, int p = 0)
	{
		int i;
		if (temp != NULL)
		{
			PrintTree(temp->right, p + 3);

			for (i = 0; i < p; i++)
			{
				cout << " ";
			}

			cout << "  " << temp->value << "\n";

			PrintTree(temp->left, p + 3);
		}
	}
};

int main()
{
	int n;
	int temp;
	AVLTree t;
	t.Add(20);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(25);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(15);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(10);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(30);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(5);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(35);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";

	t.Add(67);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(43);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(21);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(10);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(89);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(38);
	//cout << "\n------------------------------------------------\n";
	//t.PrintTree(t.head);
	//cout << "\n------------------------------------------------\n";

	t.Add(69);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";

	t.Remove(5);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";
	t.Remove(35);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";
	t.Remove(65);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";
	t.Remove(89);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";
	t.Remove(43);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";
	t.Remove(88);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";
	t.Remove(20);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";
	t.Remove(38);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";
	t.Remove(30);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";
	t.Remove(25);
	cout << "\n------------------------------------------------\n";
	t.PrintTree(t.head);
	cout << "\n------------------------------------------------\n";

	return 0;
}
