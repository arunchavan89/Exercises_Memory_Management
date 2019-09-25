#include <iostream>
#include <assert.h>

class Binary_Tree
{
public:
    Binary_Tree(int data);
    ~Binary_Tree();
    void addData(int new_data);
    bool searchItem(int new_data);
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        Node(int data, Node *left, Node *right) : data(data), left(left), right(right){}
        ~Node()
        {
            if (left)
            {
                delete left;
            }
            if (right)
            {
                delete right;
            }
        }
    };

    Node *m_root;
    void add(int data, Node *ptr);
    bool search(int data, Node *ptr);

};

Binary_Tree::Binary_Tree(int data)
{
    m_root = new Node(data, nullptr, nullptr);
}

Binary_Tree::~Binary_Tree()
{
    delete m_root;
}

void Binary_Tree::add(int new_data, Node *ptr)
{
    if (new_data > ptr->data)
    {
        if (ptr->left != nullptr)
        {
            add(new_data, ptr->left);
        }
        else
        {
            ptr->left = new Node(new_data, nullptr, nullptr);
        }
    }
    else if (new_data <= ptr->data)
    {
        if (ptr->right != nullptr)
        {
            add(new_data, ptr->right);
        }
        else
        {
            ptr->right = new Node(new_data, nullptr, nullptr);
        }
    }
}

bool Binary_Tree::search(int data, Node *ptr)
{
    if (!ptr->left && !ptr->right)
    {
        if (data == ptr->data)
        {
            return true;
        }

        return false;
    }

    if (data > ptr->data && ptr->left)
    {
        search(data, ptr->left);
    }
    else if (data <= ptr->data && ptr->right)
    {
        search(data, ptr->right);
    }
    else
    {
        return false;
    }
}

void Binary_Tree::addData(int new_data)
{
    add(new_data, m_root);
}

bool Binary_Tree::searchItem(int new_data)
{
    return search(new_data, m_root);
}

int main()
{
    Binary_Tree tree(2);
    tree.addData(10);
    tree.addData(1);
    tree.addData(20);
    tree.addData(0);

    std::cout << tree.searchItem(0) << std::endl;
    std::cout << tree.searchItem(9) << std::endl;
    tree.addData(11);
    std::cout << tree.searchItem(11) << std::endl;
    /* OUTPUT:
    1
    0
    1
    */
    return 0;
}
