#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    Node (int k = 0, Node *l = NULL, Node *r = NULL)
    {
        key = k;
        left = l;
        right = r;
    }

};

void in_order(Node *root)
{
    if(root == NULL)
        return;
    in_order(root->left);
    cout << root->key << " ";
    in_order(root->right);
}

void left_order(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << " ";
    left_order(root->left);
    left_order(root->right);
}

void right_order(Node *root)
{
    if(root == NULL)
        return;
    right_order(root->left);
    right_order(root->right);
    cout << root->key << " ";
}

void insert(Node **root, int value)
{
    Node *new_node = new Node(value);
    if(*root == NULL)
        *root = new_node;
    Node *current_root = *root;
    if(value < current_root->key)
    {
        insert(&current_root->left, value);
        current_root = current_root->left;
    }

    if(value >(*root)->key)
    {
        insert(&current_root->right, value);
        current_root = current_root->right;
    }

}

Node *find_value(Node *root, int value)
{
    if(root == NULL)
        return NULL;
    if(value == root->key)
        return root;
    if(value < root->key)
        return find_value(root->left, value);
    if(value > root->key)
        return find_value(root->right, value);
}

Node *find_min(Node *root)
{
    if(root == NULL)
        return NULL;
    while(root->left)
        root = root->left;
    return root;
}

Node *find_max(Node *root)
{
    if(root == NULL)
        return NULL;
    while(root->right)
        root = root->right;
    return root;
}


/*
TODO:
    add delete node
    find previoud node and success node
    add parent area
/*

int main()
{
    int a[] = {1, 4, 7, 2};
    Node *root = NULL;
    for(int i = 0; i < 4; i++)
    {
        insert(&root, a[i]);
    }
    in_order(root);
    cout << endl;
    left_order(root);
    cout << endl;
    right_order(root);
    cout << endl;


    Node *p = find_value(root, 4);
    cout << p << endl;
    cout << p->key << endl;

    Node *p1 = find_value(root, 8);
    cout << p1 << endl;

    Node *min = find_min(root);
    cout << min->key << endl;

    Node *max = find_max(root);
    cout << max->key << endl;
    return 0;
}
