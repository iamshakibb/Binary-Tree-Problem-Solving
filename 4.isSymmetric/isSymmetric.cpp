#include <iostream>
#include <queue>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int value)
  {
    this->data = value;
    this->left = NULL;
    this->right = NULL;
  }
};

Node *buildTree(Node *&root)
{
  cout << "Enter the value: " << endl;
  int data;
  cin >> data;

  if (data == -1)
  {
    return NULL;
  }

  root = new Node(data);

  cout << "Enter the data for inserting in left of " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter the data for inserting in right of " << data << endl;
  root->right = buildTree(root->right);

  return root;
}

bool isMirrorImageTree(Node *root1, Node *root2)
{
  if (root1 == NULL && root2 == NULL)
    return true;
  if (root1 == NULL || root2 == NULL)
    return false;
  if (root1->data != root2->data)
    return false;
  if (isMirrorImageTree(root1->left, root2->right) && isMirrorImageTree(root1->right, root2->left))
    return true;

  return false;
}

bool isSymmetric(Node *root)
{
  return isMirrorImageTree(root, root);
}

int main()
{
  Node *root = NULL;
  buildTree(root);
  cout << endl;
  if (isSymmetric(root))
  {
    cout << "This tree is a symmetric tree." << endl;
  }
  else
  {
    cout << "This tree is not a symmetric tree." << endl;
  }
}
