#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

Node *insertNode(Node *root, int data)
{ // BST 삽입
    if (root == NULL)
    { // root가 비어있으면 새로운 노드 생성
        root = createNode(data);
        return root;
    }

    if (data < root->data)
    { // data가 root보다 작으면 왼쪽 서브트리로 이동
        root->left = insertNode(root->left, data);
    }
    else if (data > root->data)
    { // data가 root보다 크면 오른쪽 서브트리로 이동
        root->right = insertNode(root->right, data);
    }

    return root;
}

void postorder(Node *root)
{
    if (root == NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << '\n';
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    vector<int> preorder = {};
    while (true)
    {
        int num;
        cin >> num;
        if (cin.eof())
            break;
        if (num == 0)
            break;
        preorder.push_back(num);
    }

    Node *root = NULL;
    for (int i = 0; i < preorder.size(); ++i)
    {
        root = insertNode(root, preorder[i]);
    }

    postorder(root);
}