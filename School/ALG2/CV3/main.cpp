#include "avl_tree.h"

int main() {
    AVLTree tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(4);
    tree.insert(8);

    std::cout << "Element 10 nalezen: " << tree.find_element(10) << std::endl; // True
    std::cout << "Element 15 nalezen: " << tree.find_element(15) << std::endl; // False

    std::cout << "Všechny elementy ve stromu: ";
    tree.print_all_elements();
    std::cout << std::endl;

    tree.print_tree_height();

    std::cout << "Informace o všech uzlech:" << std::endl;
    tree.get_all_nodes_info();

    return 0;
}
