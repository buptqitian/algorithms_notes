#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int key;
    Node *left, *right;
    int attach;
    Node (int k = 0, Node *l = NULL, Node *r = NULL)
    {
        key = k;
        left = l;
        right = r;
    }

};

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

    if(value > current_root->key)
    {
        insert(&current_root->right, value);
        current_root = current_root->right;
    }


}

void in_order(Node *root)
{
    if(root == NULL)
        return;
    in_order(root->left);
    cout << root->key << " ";
    in_order(root->right);
}

void bst_to_list(Node *root, vector<int> &result)
{
    if(root == NULL)
        return;
    bst_to_list(root->left, result);
    result.push_back(root->key);
    bst_to_list(root->right, result);
}



void sort(int *nums, int length)
{
    int i,j;
    Node *root = NULL;
    for(i = 0; i < length; i++)
        insert(&root, nums[i]);
    //in_order(root);
    //cout << endl;
    vector<int> result;
    bst_to_list(root, result);
    for(int i = 0; i < length; i++)
        nums[i] = result[i];
}

void print_array(int *nums, int length)
{
    for(int i = 0; i < length; i++)
        cout << nums[i] << " ";
}

//TODO add same value insert!
int main()
{
    int a[] = {2, 1, 5, 9, 10};
    int length = sizeof(a)/sizeof(int);

    sort(a, length);
    print_array(a, length);
    cout << endl;
}
