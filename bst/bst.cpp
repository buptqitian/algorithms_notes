#include <iostream>
using namespace std;

struct Node
{
    int key;
    int count;
    Node *left, *right, *parent;
    Node (int k = 0,int c = 1, Node *l = NULL, Node *r = NULL, Node *p = NULL)
    {
        key = k;
        count = c;
        left = l;
        right = r;
        parent = p;
    }

};

void in_order(Node *root)
{
    if(root == NULL)
        return;
    in_order(root->left);
    cout << root->key << "(" << root->count << ") ";
    in_order(root->right);
}

void left_order(Node *root)
{
    if (root == NULL)
        return;
    cout << root->key << "(" << root->count << ") ";
    left_order(root->left);
    left_order(root->right);
}

void right_order(Node *root)
{
    if(root == NULL)
        return;
    right_order(root->left);
    right_order(root->right);
    cout << root->key << "(" << root->count << ") ";
}

void insert_node(Node **root, int key)
{
    *p = *root;
    if(*root == NULL)
    {
        Node *new_node = new Node(key);
        *root = new_node;
        return;
    }
    Node *current_root = *root;

    if(key < current_root->key)
        insert_node(&current_root->left, key);

    if(key > current_root->key)
        insert_node(&current_root->right, key);

    if(key == current_root->key)
    {
        current_root->count++;
        return;
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


void delete_node(Node **root, int key)
{
    Node *current_root = *root;
    if(current_root == NULL)
        return;
    if(key < current_root->key)
        delete_node(&current_root->left, key);

    if(key > current_root->key)
        delete_node(&current_root->right, key);

    if(key == current_root->key)
    {
        if(current_root->count > 1)
        {
            current_root->count--;
            return;
        }

        if(current_root->left != NULL && current_root->right != NULL)
        {
            Node *temp = find_min(current_root->right);
            current_root->key = temp->key;
            current_root->count = temp->count;
            delete_node(&temp, temp->key);

        }
        else
        {
            if(current_root->left == NULL)
            {
                current_root->key = current_root->right->key;
                current_root->count = current_root->right->count;
                current_root->left = NULL;
                delete current_root->right;
                current_root->right = NULL;
            }
            else
            {
                current_root->key = current_root->left->key;
                current_root->count = current_root->left->count;
                current_root->right = NULL;
                delete current_root->left;
                current_root->left = NULL;
            }
        }
    }
}

/*
TODO:
    add delete node
    find previoud node and success node
    add parent area
*/

int main()
{
    int a[] = {1, 4, 2, 5, 9, 2};
    int length = sizeof(a)/sizeof(int);
    Node *root = NULL;
    for(int i = 0; i < length; i++)
    {
        insert_node(&root, a[i]);
    }
    in_order(root);
    cout << endl;

    delete_node(&root, 2);
    in_order(root);
    cout << endl;

    delete_node(&root, 1);
    in_order(root);
    cout << endl;


    return 0;
}
