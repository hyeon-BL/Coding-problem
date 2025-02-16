#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> preorder, inorder, postorder;
unordered_map<int, int> inorderIndex;

void buildPreOrder(int inStart, int inEnd, int postStart, int postEnd)
{
    if (inStart > inEnd || postStart > postEnd)
        return;

    int root = postorder[postEnd]; // 후위 순회의 마지막 노드가 루트 노드
    preorder.push_back(root);      // 전위 순회의 첫번째 노드가 루트 노드

    int rootIndex = inorderIndex[root]; // 중위 순회에서 루트 노드의 인덱스
    int leftSize = rootIndex - inStart; // 왼쪽 서브트리의 크기

    buildPreOrder(inStart, rootIndex - 1, postStart, postStart + leftSize - 1);
    buildPreOrder(rootIndex + 1, inEnd, postStart + leftSize, postEnd - 1);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n; // n개의 정점
    cin >> n;

    inorder.resize(n + 1);
    postorder.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> inorder[i];
        inorderIndex[inorder[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> postorder[i];
    }

    buildPreOrder(1, n, 1, n);

    for (int i = 0; i < preorder.size(); i++)
    {
        cout << preorder[i] << " ";
    }

    return 0;
}