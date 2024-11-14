#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>

class BST {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void addNode(Node*& node, int value);
    Node* deleteNode(Node* node, int value);
    void deleteTree(Node* node);
    Node* findNode(Node* node, int value) const;
    void preorder(Node* node) const;
    void inorder(Node* node) const;
    void postorder(Node* node) const;
    void writeToTextFile(Node* node, std::ofstream& file) const;

public:
    BST();
    ~BST();
    void add(int value);
    void remove(int value);
    void clear();
    bool find(int value) const;
    void printPreorder() const;
    void printInorder() const;
    void printPostorder() const;
    void saveToTextFile(const std::string& filename) const;
};

#endif // BST_H
