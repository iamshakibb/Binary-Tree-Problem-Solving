#include <iostream>
#include <queue>
#include <stack>
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
  stack<Node *> s;
  q.push(root);
  while (!q.empty())
  {
    Node *temp = q.front();
    q.pop();
    s.push(temp);
    if (temp->right)
      q.push(temp->right);
    if (temp->left)
      q.push(temp->left);
  }
  while (!s.empty())
  {
    Node *temp = s.top();
    cout << temp->data << " ";
    s.pop();
  }
  cout << endl;
}

int main()
{
  Node *root = NULL;
  root = buildNode(root);
  cout << endl;
  levelOrderPrint(root);
}
