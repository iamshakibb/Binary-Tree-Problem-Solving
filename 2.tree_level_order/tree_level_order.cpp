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

void level_order(Node *root)
{
  if (root == NULL)
  {
    return;
  }
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

int main()
{
  Node *root = NULL;
  root = buildTree(root);
  cout << endl;
  level_order(root);
}
