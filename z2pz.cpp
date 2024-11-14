#include "BST.h"
#include "FileHandler.h"
#include <iostream>

// Funkcja wyświetlająca menu programu
void printMenu() {
    std::cout << "Menu:\n"
        << "1. Dodaj element\n"
        << "2. Usuń element\n"
        << "3. Usuń całe drzewo\n"
        << "4. Szukaj elementu\n"
        << "5. Wyświetl drzewo (preorder)\n"
        << "6. Wyświetl drzewo (inorder)\n"
        << "7. Wyświetl drzewo (postorder)\n"
        << "8. Zapisz do pliku tekstowego\n"
        << "9. Zapisz do pliku binarnego\n"
        << "10. Wczytaj z pliku binarnego\n"
        << "11. Wczytaj z pliku tekstowego\n"
        << "0. Wyjście\n";
}

int main() {
    BST tree; // Obiekt drzewa BST
    int choice, value;
    std::string filename;

    // Pętla główna menu programu
    while (true) {
        printMenu();
        std::cout << "Wybierz opcję: ";
        std::cin >> choice;

        switch (choice) {
        case 1: // Dodaj element
            std::cout << "Podaj wartość do dodania: ";
            std::cin >> value;
            tree.add(value);
            break;
        case 2: // Usuń element
            std::cout << "Podaj wartość do usunięcia: ";
            std::cin >> value;
            tree.remove(value);
            break;
        case 3: // Usuń całe drzewo
            tree.clear();
            std::cout << "Drzewo usunięte.\n";
            break;
        case 4: // Szukaj elementu
            std::cout << "Podaj wartość do wyszukania: ";
            std::cin >> value;
            std::cout << (tree.find(value) ? "Znaleziono\n" : "Nie znaleziono\n");
            break;
        case 5: // Wyświetl drzewo preorder
            std::cout << "Preorder: ";
            tree.printPreorder();
            break;
        case 6: // Wyświetl drzewo inorder
            std::cout << "Inorder: ";
            tree.printInorder();
            break;
        case 7: // Wyświetl drzewo postorder
            std::cout << "Postorder: ";
            tree.printPostorder();
            break;
        case 8: // Zapisz do pliku tekstowego
            std::cout << "Podaj nazwę pliku tekstowego: ";
            std::cin >> filename;
            tree.saveToTextFile(filename);
            break;
        case 9: // Zapisz do pliku binarnego
            std::cout << "Podaj nazwę pliku binarnego: ";
            std::cin >> filename;
            FileHandler::saveBinaryTree(tree, filename);
            break;
        case 10: // Wczytaj z pliku binarnego
            std::cout << "Podaj nazwę pliku binarnego: ";
            std::cin >> filename;
            FileHandler::loadBinaryTree(tree, filename);
            break;
        case 11: // Wczytaj z pliku tekstowego
            std::cout << "Podaj nazwę pliku tekstowego: ";
            std::cin >> filename;
            FileHandler::loadFromTextFile(tree, filename);
            break;
        case 0: // Wyjście
            return 0;
        default:
            std::cout << "Nieprawidłowy wybór.\n";
        }
    }
}
