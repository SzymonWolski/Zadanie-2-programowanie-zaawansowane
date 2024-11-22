#include "BST.h"

// Konstruktor - inicjuje pusty korzeń
BST::BST() : root(nullptr) {}

// Destruktor - usuwa całe drzewo przy zakończeniu
BST::~BST() {
    clear();
}

// Prywatna metoda dodająca węzeł do drzewa BST
void BST::addNode(Node*& node, int value) {
    if (!node) {
        node = new Node(value); // Tworzy nowy węzeł, jeśli aktualny jest pusty
    }
    else if (value < node->data) {
        addNode(node->left, value); // Przechodzi do lewego poddrzewa
    }
    else if (value > node->data) {
        addNode(node->right, value); // Przechodzi do prawego poddrzewa
    }
}// dziadostwo jest na stosie bo tworzy nowe węzły przez `new`

// Publiczna metoda do dodawania wartości do drzewa
void BST::add(int value) {
    addNode(root, value);
}

// Prywatna metoda usuwająca węzeł o określonej wartości
BST::Node* BST::deleteNode(Node* node, int value) {
    if (!node) return nullptr; // Jesli węzeł jest pusty, zakończ
    if (value < node->data) {
        node->left = deleteNode(node->left, value); // Szuka węzła w lewym poddrzewie
    }
    else if (value > node->data) {
        node->right = deleteNode(node->right, value); // Szuka węzła w prawym poddrzewie
    }
    else {
        // Usuwa węzeł i reorganizuje drzewo
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

        // Znajduje najmniejszy węzeł w prawym poddrzewie
        Node* temp = node->right;
        while (temp->left) temp = temp->left;
        node->data = temp->data;
        node->right = deleteNode(node->right, temp->data);
    }
    return node;
}

// Publiczna metoda usuwajaca wartość z drzewa
void BST::remove(int value) {
    root = deleteNode(root, value);
}

// Prywatna metoda rekurencyjna usuwająca całe drzewo
void BST::deleteTree(Node* node) {
    if (!node) return;
    deleteTree(node->left);
    deleteTree(node->right);
    delete node;
}

// Usuwa całe drzewo
void BST::clear() {
    deleteTree(root);
    root = nullptr;
}

// Znajduje węzeł o podanej wartości
bool BST::find(int value) const {
    return findNode(root, value) != nullptr;
}

// Prywatna metoda rekurencyjna znajdująca węzeł o podanej wartości
BST::Node* BST::findNode(Node* node, int value) const {
    if (!node) return nullptr;
    if (value == node->data) return node;
    if (value < node->data) return findNode(node->left, value);
    return findNode(node->right, value);
}

// Metoda preorder - wyświetla węzły w porządku (root -> left -> right)
void BST::preorder(Node* node) const {
    if (!node) return;
    std::cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}

// Metoda inorder - wyświetla wezły w porządku (left -> root -> right)
void BST::inorder(Node* node) const {
    if (!node) return;
    inorder(node->left);
    std::cout << node->data << " ";
    inorder(node->right);
}

// Metoda postorder - wyświetla węzły w porządku (left -> right -> root)
void BST::postorder(Node* node) const {
    if (!node) return;
    postorder(node->left);
    postorder(node->right);
    std::cout << node->data << " ";
}

// Wyświetla drzewo w porzadku preorder
void BST::printPreorder() const {
    preorder(root);
    std::cout << std::endl;
}

// Wyświetla drzewo w porządku inorder
void BST::printInorder() const {
    inorder(root);
    std::cout << std::endl;
}

// Wyąwietla drzewo w porządku postorder
void BST::printPostorder() const {
    postorder(root);
    std::cout << std::endl;
}

// Prywatna metoda zapisująca drzewo do pliku tekstowego
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
