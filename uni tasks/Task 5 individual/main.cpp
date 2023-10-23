#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct Vertex
{
    int n;
    Vertex* left, * right;
    Vertex* parent;
    bool leaf;
    Vertex(int x) : n(x), left(nullptr), right(nullptr), parent(nullptr), leaf(1) {}
    Vertex(int x, Vertex* parent) : n(x), left(nullptr), right(nullptr), parent(parent), leaf(1) {}
};

class Tree
{
    Vertex* root;
    vector<int> LeftForwardOrder; // зачем?
public:
    Tree(int x)
    {
        root = new Vertex(x);
    }
    void AddVertex(int x)
    {
        Vertex* new_vertex = root;
        if (new_vertex->n == x)
            return;
        while ((new_vertex->n > x) ? new_vertex->left != nullptr : new_vertex->right != nullptr)
        {
            new_vertex = (new_vertex->n > x) ? new_vertex->left : new_vertex->right;
            if (new_vertex->n == x)
                return;
        }
        new_vertex->leaf = 0;
        (new_vertex->n > x) ? new_vertex->left = new Vertex(x, new_vertex) : new_vertex->right = new Vertex(x, new_vertex);
    }
    void MakeLeftFowardOrder(Vertex* v)
    {
        if (v == nullptr)
            return;
        LeftForwardOrder.push_back(v->n);
        MakeLeftFowardOrder(v->left);
        MakeLeftFowardOrder(v->right);
    }
    vector<int>& GetList()
    {
        return LeftForwardOrder;
    }
    Vertex* GetRoot()
    {
        return root;
    }
    bool RemoveVertex(int key)
    {
        bool q = 1;
        Vertex* this_ver = FindVertex(key); // так а если такой вершины нет?
        if (this_ver == nullptr)
        {
            return 0;
        }
        if (this_ver == root)
        {
            Vertex* new_ver = GetRightMin(root, q);
            if (new_ver == nullptr)
            {
                root = root->left;
                root->parent = nullptr;
            }
            else
            {
                root->n = new_ver->n;
                ((q /* о каком из q здесь идёт речь? Вернее, не равно ли q всегда 1? */) ? new_ver->parent->right : new_ver->parent->left) = new_ver->right;
            }
        }
        else
        {
            Vertex* new_ver = GetRightMin(this_ver, q);
            if (new_ver == nullptr)
            {
                ((this_ver->parent->right == this_ver) ? this_ver->parent->right : this_ver->parent->left) = this_ver->left;
            }
            else
            {
                this_ver->n = new_ver->n;
                ((q/* о каком из q здесь идёт речь? Вернее, не равно ли q всегда 1? */) ? new_ver->parent->right : new_ver->parent->left) = new_ver->right;
            }
        }
        return 1;
    }
private:
    Vertex* FindVertex(int key)
    {
        Vertex* v = root;
        while (v != nullptr && key != v->n)
        {
            if (key > v->n)
            {
                v = v->right;
            }
            else
            {
                v = v->left;
            }
        }
        return v;
    }
    Vertex* GetRightMin(Vertex* v, bool& q)
    {
        if (v == nullptr)
        {
            return v;
        }
        v = v->right;
        if (v == nullptr)
        {
            return v;
        }
        while (v->left != nullptr)
        {
            q = 0; // это я просто не пон зачем делать на каждом шаге
            v = v->left;
        }
        return v;
    }
};

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int rem_key;
    fin >> rem_key;
    int x;
    fin >> x;
    Tree tr(x);
    while (fin >> x)
    {
        tr.AddVertex(x);
    }
    tr.RemoveVertex(rem_key);
    tr.MakeLeftFowardOrder(tr.GetRoot());
    for (auto i : tr.GetList())
    {
        fout << i << '\n';
    }
    return 0;
}




/*
#include <iostream>
#include <fstream>


struct Node
{
    int value;
    int h;
    int placemark_inter_summs;
    bool is_there_a_subtrees;
    Node* left;
    Node* right;
    Node* parent;

    Node(int value, int h, int placemarkInterSumms, bool isThereASubtrees, Node *left, Node *right, Node *parent) :
        value(value),
        h(h),
        placemark_inter_summs(placemarkInterSumms),
        is_there_a_subtrees(isThereASubtrees),
        left(left),
        right(right),
        parent(parent)
        {};

    Node(Node& to_copy)
    {
        value = to_copy.value;
        h = to_copy.h;
        placemark_inter_summs = to_copy.placemark_inter_summs;
        is_there_a_subtrees = to_copy.is_there_a_subtrees;
        left = to_copy.left;
        right = to_copy.right;
        parent = to_copy.parent;
    }
};

struct Node_answer
{
    Node* to_delete;
    int path_way;
    Node_answer(Node* _to_delete, int _path_way) :
        to_delete(_to_delete),
        path_way(_path_way)
        {};
};


class Tree
{
    Node* root;
    Node_answer node_to_delete;

    void change_node_to_delete(Node_answer*& node_to_delete)
    {
        if (node_to_delete == nullptr)
        {
            // создать и инициировать ноду
        }
    }

public:
    bool is_exist(Node*& root)
    {
        if(root->right == nullptr || root->left == nullptr)
            return false;
        return true;
    }

    void PostOrderTraversalLeft(Node* root)
    {
        PostOrderTraversalLeft(root->left);
        PostOrderTraversalLeft(root->right);
        if (root == nullptr)
        {






            return;
        }
    }



};
int main() {

    return 0;
}
*/
