#include <iostream>
#include <queue>
#include <algorithm>
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

int second_minimum(Node *root)
{
  if (root == NULL)
  {
    return -1;
  }
  if (root->left == NULL && root->right == NULL)
  {
    return -1;
  }
  int left = root->left->data;
  int right = root->right->data;
  if (left == root->data)
    left = second_minimum(root->left);
  if (right == root->data)
    right = second_minimum(root->right);

  if (left != -1 && right != -1)
    return min(left, right);

  if (left != -1)
    return left;
  else
    return right;
};

int main()
{
  Node *root = NULL;
  buildNode(root);
  cout << endl;
  cout << "Ans : " << endl;
  cout << second_minimum(root) << endl;
}