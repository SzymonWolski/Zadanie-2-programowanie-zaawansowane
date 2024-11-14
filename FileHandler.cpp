#include "FileHandler.h"
#include <fstream>

void FileHandler::saveBinaryTree(const BST& tree, const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (file.is_open()) {
        tree.saveToTextFile(filename);
        file.close();
    }
}
//aledlaczegomuszetorobic
void FileHandler::loadBinaryTree(BST& tree, const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    int value;
    while (file.read(reinterpret_cast<char*>(&value), sizeof(value))) {
        tree.add(value);
    }
    file.close();
}
// azbest 
void FileHandler::loadFromTextFile(BST& tree, const std::string& filename) {
    std::ifstream file(filename);
    int value;
    while (file >> value) {
        tree.add(value);
    }
    file.close();
}
