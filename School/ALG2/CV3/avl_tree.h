#pragma once
#include<iostream>

// Node structure for AVL Tree
struct Node {
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int k);
};

// AVL Tree class definition
class AVLTree {
private:
    Node* root;

    // Function to get the height of the tree
    int height(Node* node);

    // Right rotate subtree rooted with y
    Node* rightRotate(Node* y);

    // Left rotate subtree rooted with x
    Node* leftRotate(Node* x);

    // Get balance factor of node
    int getBalance(Node* node);

    // Recursive function to insert a key in the subtree rooted with node
    Node* insert(Node* node, int key);

    // Utility function to print preorder traversal
    void preOrder(Node* root);
    
    // Recursive function to delete a node with the given key
    Node* deleteNode(Node* root, int key);
    
    // Utility function to find the node with minimum key value in a tree
    Node* minValueNode(Node* node);
    
public:
    AVLTree();

    // Insert a key into the AVL tree
    void insert(int key);
    // Delete a key from the AVL tree
    void deleteKey(int key);

    bool find_element(int element);

    bool find_element_recursive(Node* node, int element);

    void print_all_elements();

    void print_inorder(Node* node);

    void print_tree_height();

    void get_all_nodes_info();

    void get_all_nodes_info_recursive(Node* node);
};

