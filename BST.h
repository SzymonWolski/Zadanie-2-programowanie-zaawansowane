#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>

// Klasa BST - implementacja drzewa binarnego poszukiwañ
class BST {
private:
    // Struktura wêz³a drzewa
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root; // Korzeñ drzewa

    // Metody prywatne pomocnicze
    void addNode(Node*& node, int value);         // Dodaje wêze³ do drzewa
    Node* deleteNode(Node* node, int value);      // Usuwa wêze³ z drzewa
    void deleteTree(Node* node);                  // Usuwa ca³e drzewo
    Node* findNode(Node* node, int value) const;  // Znajduje wêze³ o podanej wartoœci
    void preorder(Node* node) const;              // Wyœwietla wêz³y w porz¹dku preorder
    void inorder(Node* node) const;               // Wyœwietla wêz³y w porz¹dku inorder
    void postorder(Node* node) const;             // Wyœwietla wêz³y w porz¹dku postorder
    void writeToTextFile(Node* node, std::ofstream& file) const; // Zapisuje drzewo do pliku tekstowego

public:
    BST();                  // Konstruktor
    ~BST();                 // Destruktor
    void add(int value);    // Dodaje wartoœæ do drzewa
    void remove(int value); // Usuwa wartoœæ z drzewa
    void clear();           // Usuwa ca³e drzewo
    bool find(int value) const; // Sprawdza, czy wartoœæ znajduje siê w drzewie
    void printPreorder() const; // Wyœwietla drzewo w porz¹dku preorder
    void printInorder() const;  // Wyœwietla drzewo w porz¹dku inorder
    void printPostorder() const; // Wyœwietla drzewo w porz¹dku postorder
    void saveToTextFile(const std::string& filename) const; // Zapisuje drzewo do pliku tekstowego
};

#endif // BST_H
