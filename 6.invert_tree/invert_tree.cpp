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
  cout << "Enter a value " << endl;
  int value;
  cin >> value;
  if (value == -1)
    return NULL;
  root = new Node(value);
  cout << "Enter a value for inserting left of " << value << endl;
  root->left = buildTree(root->left);

  cout << "Enter a value for inserting left of " << value << endl;
  root->right = buildTree(root->right);

  return root;
}

void levelOrderPrint(Node *root)
{
  if (root == NULL)
    return;
  queue<Node *> q;
  q.push(root);
  while (!q.empty())
  {
    Node *temp = q.front();
    cout << temp->data << " ";
    q.pop();
    if (temp->left)
      q.push(temp->left);
    if (temp->right)
      q.push(temp->right);
  }
}

Node *invert_tree(Node *root)
{
  if (root == NULL)
  {
    return NULL;
  }
  Node *left = invert_tree(root->left);
  Node *right = invert_tree(root->right);
  root->left = right;
  root->right = left;
  return root;
};

int main()
{
  Node *root = NULL;
  buildTree(root);
  cout << endl;
  cout << "before" << endl;
  levelOrderPrint(root);
  cout << endl;
  invert_tree(root);
  cout << endl;
  cout << "after" << endl;
  levelOrderPrint(root);
  cout << endl;
}