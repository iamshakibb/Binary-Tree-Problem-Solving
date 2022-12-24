#include <iostream>
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

// build tree function
Node *buildTree(Node *root)
{
  cout << "Enter the data: " << endl;
  int data;
  cin >> data;

  if (data == -1)
  {
    return NULL;
  }
  root = new Node(data);
  cout << "Enter data for inserting in left of " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter data for inserting in right of " << data << endl;
  root->right = buildTree(root->right);
  return root;
}

bool isSame(Node *root1, Node *root2)
{
  if (root1 == NULL && root2 == NULL)
  {
    return true;
  }

  if (root1 == NULL && root2 != NULL)
  {
    return false;
  }
  if (root1 != NULL && root2 == NULL)
  {
    return false;
  }

  bool left = isSame(root1->left, root2->left);
  bool right = isSame(root1->right, root2->right);
  bool value = root1->data == root2->data;
  if (left && right && value)
  {
    return true;
  }
  else
  {
    return false;
  }
}

int main()
{
  Node *root1 = NULL;
  Node *root2 = NULL;
  cout << "First Tree : " << endl;
  root1 = buildTree(root1);
  cout << endl;
  cout << "Second Tree : " << endl;
  root2 = buildTree(root2);
  bool ans = isSame(root1, root2);

  if (ans)
  {
    cout << "These two binary trees are the same." << endl;
  }
  else
  {
    cout << "These two binary trees are not the same." << endl;
  }
}