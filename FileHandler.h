#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "BST.h"
#include <string>

class FileHandler {
public:
    static void saveBinaryTree(const BST& tree, const std::string& filename);
    static void loadBinaryTree(BST& tree, const std::string& filename);
    static void loadFromTextFile(BST& tree, const std::string& filename);
};

#endif 
