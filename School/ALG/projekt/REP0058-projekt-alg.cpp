#include <stack>
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

/**
 * @brief Allocates memory for a new node and initializes it with the given data.
 * 
 * @param data The data to be stored in the new node.
 * @return Pointer to the newly created node.
 */


/**
 * @brief Finds the index of the closing parenthesis corresponding to the opening parenthesis at index startIndex in the given string.
 * 
 * @param str The string to search in.
 * @param startIndex The index of the opening parenthestartIndexs.
 * @param endIndex The index of the last character in the substring to search in.
 * @return Index of the closing parenthesis, or -1 if not found.
 */
int find_Index(string str, int startIndex, int endIndex)
{
    if (startIndex > endIndex)
        return -1;

    stack<char> s;
    for (int i = startIndex; i <= endIndex; i++) {
        if (str[i] == '(')
            s.push(str[i]);
        else if (str[i] == ')') {
            if (s.top() == '(') {
                s.pop();
                if (s.empty())
                    return i;
            }
        }
    }
    return -1;
}

/**
 * @brief Converts the binary tree to a string in bracket representation.
 * 
 * @param root Pointer to the root of the binary tree.
 * @return Bracket representation of the binary tree.
 */
string binaryTreeToString(Node* root) {
    if (!root) return "";
    string result = to_string(root->data);
    if (root->left || root->right) {
        result += "(" + binaryTreeToString(root->left) + ")";
        if (root->right) result += "(" + binaryTreeToString(root->right) + ")";
    }
    return result;
}

/**
 * @brief Constructs a binary tree from the given string in bracket representation.
 * 
 * @param str The string in bracket representation.
 * @param startIndex The starting index of the substring to process.
 * @param endIndex The ending index of the substring to process.
 * @return Pointer to the root of the constructed binary tree.
 */
Node* tree_from_string(string str, int startIndex, int endIndex)
{
    if (startIndex > endIndex)
        return NULL;

    Node* root = new Node(str[startIndex] - '0');
    int index = -1;
    if (startIndex + 1 <= endIndex && str[startIndex + 1] == '(')
        index = find_Index(str, startIndex + 1, endIndex);

    if (index != -1) {
        root->left = tree_from_string(str, startIndex + 2, index - 1);
        root->right = tree_from_string(str, index + 2, endIndex - 1);
    }
    return root;
}

/**
 * @brief Main function.
 */
int main()
{
    string str = "1(2(3)(4))(5(6))";
    Node* root = tree_from_string(str, 0, str.length() - 1);
    cout << "Input string:" << str << endl;
    cout << "Reconstructed binary tree: " << binaryTreeToString(root) << endl;
}
