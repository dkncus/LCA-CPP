//Adapted code from GeeksForGeeks.org
#include <iostream> 
#include <vector> 
using namespace std;

struct Node
{int key; struct Node* left; struct Node* right;};

Node* newNode(int k)
{
    Node* t = new Node;
    t->key = k;
    t->left = NULL;
    t->right = NULL;
    return t;
}

bool pathTrace(Node* root, vector<int>& path, int k)
{
    if (root == NULL) return false;
    path.push_back(root->key);

    if (root->key == k) return true;
    if ((root->left && pathTrace(root->left, path, k)) || (root->right && pathTrace(root->right, path, k))) return true;

    path.pop_back();
    return false;
}

int lowestCommonAncestor(Node* root, int n1, int n2)
{
    vector<int> path1;
    vector<int> path2;

    if (!pathTrace(root, path1, n1) || !pathTrace(root, path2, n2)) return -1;

    int i;
    for (i = 0; i < path1.size() && i < path2.size(); i++)
        if (path1[i] != path2[i])
            break;
    return path1[i - 1];
}

int main()
{
    //Root Node
    Node* root = newNode(0);

    //Tier 1
    root->left = newNode(1);
    root->right = newNode(2);
    
    //Tier 2
    root->left->left = newNode(3);
    root->left->right = newNode(4);

    //Tier 2
    root->right->left = newNode(5);
    root->right->right = newNode(6);

    //Tier 3
    root->left->left->left = newNode(7);
    root->left->left->right = newNode(8);
    root->left->right->left = newNode(9);
    root->left->right->right = newNode(10);

    //Tier 3
    root->right->left->left = newNode(11);
    root->right->left->right = newNode(12);
    root->right->right->left = newNode(13);
    root->right->right->right = newNode(14);

    cout << lowestCommonAncestor(root, 11, 13)<< '\n';
    cout << lowestCommonAncestor(root, 9, 10) << '\n';
    cout << lowestCommonAncestor(root, 3, 4)  << '\n';
    cout << lowestCommonAncestor(root, 7, 8)  << '\n';
    cout << lowestCommonAncestor(root, 11, 12)<< '\n';

    return 0;
}