#include <iostream>
#include <queue>
#include <cstdlib>
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
}

int tileCount(Node *root, int *titl)
{
  if (root == NULL)
  {
    return 0;
  }
  int left = tileCount(root->left, titl);
  int right = tileCount(root->right, titl);
  *titl += abs(left - right);
  return left + right + root->data;
}

int findTilt(Node *root)
{
  if (root == NULL)
  {
    return 0;
  }
  int tilt = 0;
  tileCount(root, &tilt);
  return tilt;
};

int main()
{
  Node *root = NULL;
  buildNode(root);
  cout << endl;
  cout << findTilt(root) << endl;
}