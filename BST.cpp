#include "BST.h"

// Konstruktor - inicjuje pusty korze�
BST::BST() : root(nullptr) {}

// Destruktor - usuwa ca�e drzewo przy zako�czeniu
BST::~BST() {
    clear();
}

// Prywatna metoda dodaj�ca w�ze� do drzewa BST
void BST::addNode(Node*& node, int value) {
    if (!node) {
        node = new Node(value); // Tworzy nowy w�ze�, je�li aktualny jest pusty
    }
    else if (value < node->data) {
        addNode(node->left, value); // Przechodzi do lewego poddrzewa
    }
    else if (value > node->data) {
        addNode(node->right, value); // Przechodzi do prawego poddrzewa
    }
}

// Publiczna metoda do dodawania warto�ci do drzewa
void BST::add(int value) {
    addNode(root, value);
}

// Prywatna metoda usuwaj�ca w�ze� o okre�lonej warto�ci
BST::Node* BST::deleteNode(Node* node, int value) {
    if (!node) return nullptr; // Je�li w�ze� jest pusty, zako�cz
    if (value < node->data) {
        node->left = deleteNode(node->left, value); // Szuka w�z�a w lewym poddrzewie
    }
    else if (value > node->data) {
        node->right = deleteNode(node->right, value); // Szuka w�z�a w prawym poddrzewie
    }
    else {
        // Usuwa w�ze� i reorganizuje drzewo
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

        // Znajduje najmniejszy w�ze� w prawym poddrzewie
        Node* temp = node->right;
        while (temp->left) temp = temp->left;
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

// Publiczna metoda usuwaj�ca warto�� z drzewa
void BST::remove(int value) {
    root = deleteNode(root, value);
}

// Prywatna metoda rekurencyjna usuwaj�ca ca�e drzewo
void BST::deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Usuwa ca�e drzewo
void BST::clear() {
    deleteTree(root);
    root = nullptr;
}

// Znajduje w�ze� o podanej warto�ci
bool BST::find(int value) const {
    return findNode(root, value) != nullptr;
}

// Prywatna metoda rekurencyjna znajduj�ca w�ze� o podanej warto�ci
BST::Node* BST::findNode(Node* node, int value) const {
    if (!node) return nullptr;
    if (value == node->data) return node;
    if (value < node->data) return findNode(node->left, value);
    return findNode(node->right, value);
}

// Metoda preorder - wy�wietla w�z�y w porz�dku (root -> left -> right)
void BST::preorder(Node* node) const {
    if (!node) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Metoda inorder - wy�wietla w�z�y w porz�dku (left -> root -> right)
void BST::inorder(Node* node) const {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

// Metoda postorder - wy�wietla w�z�y w porz�dku (left -> right -> root)
void BST::postorder(Node* node) const {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

// Wy�wietla drzewo w porz�dku preorder
void BST::printPreorder() const {
    preorder(root);
    std::cout << std::endl;
}

// Wy�wietla drzewo w porz�dku inorder
void BST::printInorder() const {
    inorder(root);
    std::cout << std::endl;
}

// Wy�wietla drzewo w porz�dku postorder
void BST::printPostorder() const {
    postorder(root);
    std::cout << std::endl;
}

// Prywatna metoda zapisuj�ca drzewo do pliku tekstowego
void BST::writeToTextFile(Node* node, std::ofstream& file) const {
    if (!node) return;
    file << node->data << " ";
    writeToTextFile(node->left, file);
    writeToTextFile(node->right, file);
}

// Zapisuje drzewo do pliku tekstowego
void BST::saveToTextFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (file.is_open()) {
        writeToTextFile(root, file);
        file.close();
    }
}
