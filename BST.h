#ifndef BST_H
#define BST_H

#include <iostream>
#include <vector>
#include <fstream>

// Klasa BST - implementacja drzewa binarnego poszukiwa�
class BST {
private:
    // Struktura w�z�a drzewa
    struct Node {
        int data;
        Node* left;
        Node* right;
        Node(int value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root; // Korze� drzewa

    // Metody prywatne pomocnicze
    void addNode(Node*& node, int value);         // Dodaje w�ze� do drzewa
    Node* deleteNode(Node* node, int value);      // Usuwa w�ze� z drzewa
    void deleteTree(Node* node);                  // Usuwa ca�e drzewo
    Node* findNode(Node* node, int value) const;  // Znajduje w�ze� o podanej warto�ci
    void preorder(Node* node) const;              // Wy�wietla w�z�y w porz�dku preorder
    void inorder(Node* node) const;               // Wy�wietla w�z�y w porz�dku inorder
    void postorder(Node* node) const;             // Wy�wietla w�z�y w porz�dku postorder
    void writeToTextFile(Node* node, std::ofstream& file) const; // Zapisuje drzewo do pliku tekstowego
    
public:
    BST();                  // Konstruktor
    ~BST();                 // Destruktor
    void add(int value);    // Dodaje warto�� do drzewa
    void remove(int value); // Usuwa warto�� z drzewa
    void clear();           // Usuwa ca�e drzewo
    bool find(int value) const; // Sprawdza, czy warto�� znajduje si� w drzewie
    void printPreorder() const; // Wy�wietla drzewo w porz�dku preorder
    void printInorder() const;  // Wy�wietla drzewo w porz�dku inorder
    void printPostorder() const; // Wy�wietla drzewo w porz�dku postorder
    void saveToTextFile(const std::string& filename) const; // Zapisuje drzewo do pliku tekstowego
};

#endif // BST_H
