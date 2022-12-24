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
  cout << "Enter value" << endl;
  int data;
  cin >> data;

  if (data == -1)
  {
    return NULL;
  }
  root = new Node(data);
  cout << "Enter value for inserting left of " << data << endl;
  root->left = buildTree(root->left);
  cout << "Enter value for inserting right of " << data << endl;
  root->right = buildTree(root->right);
  return root;
}

void zigzag_order(Node *root)
{
  if (root == NULL)
  {
    return;
  }
  queue<Node *> q;
  q.push(root);
  int count = 0;
  while (!q.empty())
  {
    Node *temp = q.front();
    cout << temp->data << " ";
    q.pop();

    if (count % 2)
    {
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
    else
    {
      if (temp->right)
        q.push(temp->right);
      if (temp->left)
        q.push(temp->left);
    }
    count++;
  }
}

int main()
{
  Node *root = NULL;
  buildTree(root);
  cout << endl;
  zigzag_order(root);
  cout << endl;
}