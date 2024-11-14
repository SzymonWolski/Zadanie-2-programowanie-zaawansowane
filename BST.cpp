#include "BST.h"

BST::BST() : root(nullptr) {}

BST::~BST() {
    clear();
}

void BST::addNode(Node*& node, int value) {
    if (!node) {
        node = new Node(value);
    }
    else if (value < node->data) {
        addNode(node->left, value);
    }
    else if (value > node->data) {
        addNode(node->right, value);
    }
}

void BST::add(int value) {
    addNode(root, value);
}

BST::Node* BST::deleteNode(Node* node, int value) {
    if (!node) return nullptr;
    if (value < node->data) {
        node->left = deleteNode(node->left, value);
    }
    else if (value > node->data) {
        node->right = deleteNode(node->right, value);
    }
    else {
        if (!node->left) {
            Node* temp = node->right;
            delete node;
            return temp;
        }
        else if (!node->right) {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = node->right;
        while (temp->left) temp = temp->left;
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

void BST::remove(int value) {
    root = deleteNode(root, value);
}

void BST::deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

void BST::clear() {
    deleteTree(root);
    root = nullptr;
}

bool BST::find(int value) const {
    return findNode(root, value) != nullptr;
}

BST::Node* BST::findNode(Node* node, int value) const {
    if (!node) return nullptr;
    if (value == node->data) return node;
    if (value < node->data) return findNode(node->left, value);
    return findNode(node->right, value);
}

void BST::preorder(Node* node) const {
    if (!node) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

void BST::inorder(Node* node) const {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

void BST::postorder(Node* node) const {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

void BST::printPreorder() const {
    preorder(root);
    std::cout << std::endl;
}

void BST::printInorder() const {
    inorder(root);
    std::cout << std::endl;
}

void BST::printPostorder() const {
    postorder(root);
    std::cout << std::endl;
}

void BST::writeToTextFile(Node* node, std::ofstream& file) const {
    if (!node) return;
    file << node->data << " ";
    writeToTextFile(node->left, file);
    writeToTextFile(node->right, file);
}

void BST::saveToTextFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        writeToTextFile(root, file);
        file.close();
    }
}
