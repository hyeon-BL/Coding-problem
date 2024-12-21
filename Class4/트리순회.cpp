#include <iostream>
#include <unordered_map>
using namespace std;

struct Node
{
    char left, right;
};

unordered_map<char, Node> tree;

void preorder(char root)
{ // root -> left -> right
    if (root == '.')
        return;
    cout << root;
    preorder(tree[root].left);
    preorder(tree[root].right);
}

void inorder(char root)
{ // left -> root -> right
    if (root == '.')
        return;
    inorder(tree[root].left);
    cout << root;
    inorder(tree[root].right);
}

void postorder(char root)
{ // left -> right -> root
    if (root == '.')
        return;
    postorder(tree[root].left);
    postorder(tree[root].right);
    cout << root;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N;
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        char root, left, right;
        cin >> root >> left >> right;
        tree[root] = {left, right}; // root를 key로 하는 노드를 생성
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
}