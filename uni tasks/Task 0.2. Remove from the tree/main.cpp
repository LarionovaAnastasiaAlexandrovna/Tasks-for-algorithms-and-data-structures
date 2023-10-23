#include <iostream>
#include <fstream>
#include <string>

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

void erase(Node*& root, int key_to_delete)
{
    Node* current = root;

    while (current != nullptr && current->value != key_to_delete) // тут мы или находим Node по key_to_delete или обнаруживаем, что её нет
    {
        key_to_delete < current->value ? current = current->left : current = current->right;
    }
    if (current == nullptr) // ключ не найден
    {
        return;
    }

    if (current == root && (root->left == nullptr && root->right != nullptr || root->left != nullptr && root->right == nullptr))
    {

        if (current->left != nullptr)
        {
            root = current->left;
            root->parent = nullptr;
        }
        if (current->right != nullptr)
        {
            root = current->right;
            root->parent = nullptr;
        }
        return;
    }

    if (current->left == nullptr && current->right == nullptr) // это лист
    {
        if (current->parent == nullptr)
            // т е Node это корень ака единственная вершина в дереве
        {
            root = nullptr; // всё, дерева нет :)
        }
        else if (current == current->parent->left) // т е если наша Node левый лист
        {
            current->parent->left = nullptr;
        }
        else if (current == current->parent->right)//  т е если наша Node правый лист
        {
            current->parent->right = nullptr;
        }
        return;
    }

    else if (current->left != nullptr && current->right == nullptr) // существует только левое поддерево
    {
        if (current->parent == nullptr) // т е в дереве всего 2 вершины
        {
            root = current->left;
            root->parent = nullptr;
        }
        else if (current == current->parent->left)
        {
            current->parent->left = current->left;
            current->left->parent = current->parent;
        }
        else
        {
            current->parent->right = current->left;
            current->left->parent = current->parent;
        }
        return;
    }

    else if (current->left == nullptr && current->right != nullptr) // существует только правое поддерево
    {
        if (current->parent == nullptr)
        {
            root = current->right;
            root->parent = nullptr;
        }
        else if (current == current->parent->right) // проверка, что это правое поддерево
        {
            current->parent->right = current->right;
            current->right->parent = current->parent;
        }
        else
        {
            current->parent->left = current->right;
            current->right->parent = current->parent;
        }
        return;
    }
    else // существуют оба поддерева
    {
        Node* temp = current->right; // т к у нас правое удаление
        while (temp->left != nullptr) // ищем Node с минимальным value в данном поддереве
        {
            temp = temp->left;
        }
        current->value = temp->value; // присваиваем минимальное значение в то место, где мы планируем удалять вершину

//        if (current->right == temp)
//        {
//            current->right = nullptr;
//            return;
//        }

        if (temp == temp->parent->left)
        {
            temp->parent->left = temp->right;
            if (temp->right != nullptr)
            {
                temp->right->parent = temp->parent;
            }
        }
        else
        {
            temp->parent->right = temp->right;
            if (temp->left != nullptr)
            {
                temp->right->parent = temp->parent;
            }
        }
        delete temp;
        return;
    }
}

void print(Node* root, std::ofstream& fout) // прямой левый обход
{
    if (root == nullptr)
    {
        return;
    }
    fout << root->value << "\n";
    print(root->left, fout);
    print(root->right, fout);
}

int main() {
    Node* root = nullptr;

    std::ifstream fin("input.txt");
    if (!fin.is_open())
    {
        std::cerr << "Error open input.txt";
    }
    std::string temp, key_to_delete;
    std::getline(fin, key_to_delete);
    fin.ignore();
    while (std::getline(fin, temp))
    {
        insert(root, stoi(temp));
    }
    fin.close();

    std::ofstream fout("output.txt");
    erase(root, stoi(key_to_delete));
    print(root, fout);
    fout.close();

    return 0;
}