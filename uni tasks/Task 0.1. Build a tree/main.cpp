#include <iostream>
#include <fstream>

struct Node
{
    int value;
    Node* left;
    Node* right;
    Node* parent;
};

void insert(Node*& root, int value)
{
    if (root == nullptr)
    {
        root = new Node{value, nullptr, nullptr, nullptr};
        return;
    }

    Node* current = root;
    while (true)
    {
        if (value < current->value)
        {
            if (current->left == nullptr)
            {
                current->left = new Node{value, nullptr, nullptr, current};
                return;
            }
            current = current->left;
        }
        else if (value > current->value)
        {
            if (current->right == nullptr)
            {
                current->right = new Node{value, nullptr, nullptr, current};
                return;
            }
            current = current->right;
        }
        else
            return;
    }
}

void print(Node*& node, std::ofstream& fout) // прямой левый обход
{
    if (node == nullptr)
    {
        return;
    }
    fout << node->value << "\n";
    print(node->left, fout);
    print(node->right, fout);
}

int main() {
    Node* root = nullptr;

    std::ifstream fin("input.txt");
    if (!fin.is_open())
    {
        std::cerr << "Error open input.txt";
    }
    std::string temp;
    while (getline(fin, temp))
    {
        insert(root, stoi(temp));
    }
    fin.close();

    std::ofstream fout("output.txt");
    print(root, fout);
    fout.close();

    return 0;
}




//void printPath(Node*& node, std::ofstream& fout)
//{
//    if (node == nullptr)
//    {
//        return;
//    }
//    fout << node->value << "\n";
//    printPath(node->parent, fout);
//}


/*
#include <fstream>
#include <iostream>
//#include <bits/stdc++.h>

class Solution
{
    struct Node {
        int value;
        Node* left;
        Node* right;
        Node* parent;
    };

    Node* root = nullptr;

public:
    void insert(int value) {
        if (root == nullptr) {
            root = new Node{value, nullptr, nullptr, nullptr};
            return;
        }

        Node* current = root; // переприсваиваем
        while (true) {
            if (value < current->value)
            {
                if (current->left == nullptr)
                {
                    current->left = new Node{value, nullptr, nullptr, current};
                    return;
                }
                current = current->left;
            }
            else if (value > current->value)
            {
                if (current->right == nullptr)
                {
                    current->right = new Node{value, nullptr, nullptr, current};
                    return;
                }
                current = current->right;
            }
            else
            {
                return;
            }
        }
    }

//    void print(Node* node) {
//        if (node == nullptr) {
//            return;
//        }
//        std::cout << node->value << " ";
//        print(node->left);
//        print(node->right);
//    }

    void static printPath(Node* node, std::ofstream& fout) {
        if (node == nullptr) {
            return;
        }
        fout << node->value << "\n";
        printPath(node->parent, fout);
    }
};


int main() {
    Solution tree;
    std::ifstream fin("input.txt");
    if (!fin.is_open())
    {
        std::cerr << "Error open input.txt";
    }
    std::string temp;
    while (getline(fin, temp))
    {
        tree.insert(stoi(temp));
    }
    fin.close();

    std::ofstream fout("output.txt");
    Solution::printPath(tree, fout);

//    print(root);
//    cout << endl;
//
//    Node* node = root->left->left;
//    printPath(node);
//    cout << endl;

    return 0;
}
*/
