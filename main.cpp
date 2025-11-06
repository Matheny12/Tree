#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* left;
	Node* right;
	Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

void printTree(const std::string& prefix, const Node* node, bool isLeft) {
	if (node != nullptr) {
		std::cout << prefix;
        	std::cout << (isLeft ? "├── " : "└── ");
        	std::cout << node->data << std::endl;
        	printTree(prefix + (isLeft ? "│   " : "    "), node->left, true);
    		printTree(prefix + (isLeft ? "│   " : "    "), node->right, false);
    	}
}

void displayTree(const Node* node) {
	printTree("", node, false);
}


int main() {
	Node* root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->right->left = new Node(17);
	root->right->right = new  Node(25);
	root->left->right = new Node(12);
	root->left->left = new Node(8);

	displayTree(root);
	delete root->left;
	delete root->right;
	delete root->right->left;
	delete root->right->right;
	delete root->left->right;
	delete root->left->left;
	delete root;
	return 0;
}
