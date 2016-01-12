#include <iostream>
using namespace std;


struct Node
{
    int key;
    int count;
    Node *left;
    Node *right;

    Node(int k = 0, int c = 1, Node *l = NULL, Node *r = NULL)
    {
        key = k;
        count = c;
        left = l;
        right = r;
    }
};

class BST
{
public:
    Node *find_key(int);
    Node *find_parent(int);
    Node *find_min(Node *);
    Node *find_max(Node *);
    void in_order(Node *);
    void pre_order(Node *);
    void post_order(Node *);

public:
    BST();
    void insert(int);
    void remove(int);
    void tranverse();

public:
    Node *root;
    Node *current;

};


BST::BST()
{
    root = current = NULL;
}

Node *BST::find_key(int key)
{
    Node *p = root;
    while(p != NULL && p->key != key)
    {
        if(key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return p;
}

Node *BST::find_parent(int key)
{
    Node *p = root;
    Node *q = NULL;
    while((p != NULL) && (p->key != key))
    {
        q = p;
        if(key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }
    return q;
}

Node *BST::find_max(Node *p)
{
    Node *successor = p;
    while(successor->right != NULL)
    {
        successor = successor->right;
    }
    return successor;

}

void BST::insert(int key)
{
    if(root == NULL)
    {
        root = new Node(key);
    }
    else
    {
        Node *p = find_key(key);
        if(p == NULL)
        {
            Node *parent = root;
            if(p != root)
            {
                parent = find_parent(key);
            }

            if(key > parent->key)
            {
                parent->right = new Node(key);
            }
            else
            {
                parent->left = new Node(key);
            }
        }
        else
        {
            p->count++;
        }

    }
}

void BST::remove(int key)
{
    Node *p = find_key(key);
    if(p != NULL)
    {
        if(p->count > 1)
        {
            p->count--;
        }
        else
        {
            if(p->left == NULL && p->right == NULL)
            {
                if(p != root)
                {
                    Node *parent = find_parent(key);
                    if(key < parent->key)
                {
                    parent->left = NULL;
                }
                else
                {
                    parent->right = NULL;
                }
            }
            else
            {
                root = NULL;
            }
                delete p;
            }
            else if(p->left != NULL && p->right == NULL)
            {
                if(p != NULL)
                {
                    Node *parent = find_parent(key);
                    if(key < parent->key)
                    {
                        parent->left = p->left;
                    }
                    else
                    {
                        parent->right = p->left;
                    }
                }
                else
                {
                    root = NULL;
                }
                delete p;
            }
            else if(p->left == NULL && p->right != NULL)
            {
                if(p != NULL)
                {
                    Node *parent = find_parent(key);
                    if(key < parent->key)
                    {
                        parent->left = p->right;
                    }
                    else
                    {
                        parent->right = p->right;
                    }
                }
                else
                {
                    root = NULL;
                }
                delete p;
            }
            else
            {
                Node *pre = find_max(p->left);
                Node *parent = find_parent(pre->key);
                p->key = pre->key;
                if(parent != p)
                {
                    parent->right = pre->left;
                }
                else
                {
                    p->left = pre->left;
                }

            }
        }
    }
}

void BST::in_order(Node *p)
{
    if(p != NULL)
    {
        in_order(p->left);
        cout << p->key << "(" << p->count << ") ";
        //cout << p->key << " ";
        in_order(p->right);
    }
}

void BST::tranverse()
{
    in_order(root);
    cout << endl;
}


int main()
{
    BST tree;
    tree.insert(10);
    tree.insert(2);
    tree.insert(4);
    tree.insert(12);
    tree.insert(23);
    tree.insert(12);
    tree.tranverse();

    tree.remove(10);
    tree.tranverse();

    tree.remove(4);
    tree.tranverse();

    tree.remove(12);
    tree.tranverse();

    tree.remove(12);
    tree.tranverse();

    return 0;
}
