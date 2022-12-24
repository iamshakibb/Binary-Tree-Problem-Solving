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

Node *buildNode(Node *&root)
{
  cout << "Enter a value" << endl;
  int data;
  cin >> data;
  if (data == -1)
    return NULL;

  root = new Node(data);
  cout << "Enter a value for left of " << data << endl;
  root->left = buildNode(root->left);
  cout << "Enter a value for right of " << data << endl;
  root->right = buildNode(root->right);
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
  cout << endl;
}

bool is_unival(Node *root)
{
  if (root == NULL)
  {
    return true;
  }

  if (root->left != NULL && root->data != root->left->data)
    return false;
  if (root->right != NULL && root->data != root->right->data)
    return false;

  return is_unival(root->left) && is_unival(root->right);
};

int main()
{
  Node *root = NULL;
  buildNode(root);
  cout << endl;
  levelOrderPrint(root);
  if (is_unival(root))
  {
    cout << "This is an uni-valued tree" << endl;
  }
  else
  {
    cout << "This is not an uni-valued tree." << endl;
  }
}