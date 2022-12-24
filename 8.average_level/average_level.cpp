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

void average_level(Node *root)
{
  if (root == NULL)
    return;
  queue<Node *> q;
  q.push(root);
  cout << root->data << " ";
  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();
    if (temp->left)
      q.push(temp->left);
    if (temp->right)
      q.push(temp->right);
    if (temp->left && temp->right)
    {
      float average = float(temp->left->data + temp->right->data) / 2;
      cout << average << " ";
    }
  }
  cout << endl;
};

int main()
{
  Node *root = NULL;
  buildNode(root);
  cout << endl;
  levelOrderPrint(root);
  average_level(root);
}