#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int value;                   // 노드의 값
    vector<TreeNode *> parents;  // 부모 노드의 포인터를 저장하는 벡터
    vector<TreeNode *> children; // 자식 노드의 포인터를 저장하는 벡터

    TreeNode(int val) : value(val) {} // 생성자
};

int countLeafNodes(TreeNode *node)
{
    if (node->children.empty())
    {
        return 1; // 리프 노드
    }
    int count = 0;
    for (TreeNode *child : node->children)
    {
        count += countLeafNodes(child);
    }
    return count;
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 노드의 개수
    cin >> N;

    vector<TreeNode *> nodes(N); // 노드 포인터를 저장할 벡터
    for (int i = 0; i < N; ++i)
    {
        nodes[i] = new TreeNode(i + 1); // 노드 생성
    }
    for (int i = 0; i < N; ++i)
    {
        int parentIndex;
        cin >> parentIndex; // 부모 노드의 인덱스 입력

        if (parentIndex != -1)
        {                                                     // 부모가 존재하는 경우
            nodes[parentIndex]->children.push_back(nodes[i]); // 부모 노드에 자식 노드 추가
            nodes[i]->parents.push_back(nodes[parentIndex]);  // 자식 노드에 부모 노드 추가
        }
    }

    int removedNodeIndex; // 제거할 노드의 인덱스
    cin >> removedNodeIndex;

    TreeNode *removedNode = nodes[removedNodeIndex]; // 제거할 노드 포인터

    // 제거할 노드의 부모 노드에서 제거
    for (TreeNode *parent : removedNode->parents)
    {
        auto it = find(parent->children.begin(), parent->children.end(), removedNode);
        if (it != parent->children.end())
        {
            parent->children.erase(it); // 제거
        }
    }

    // 제거된 노드의 자식 노드도 제거
    removedNode->children.clear();

    // 루트 노드 찾기
    TreeNode *root = nullptr;
    for (TreeNode *node : nodes)
    {
        if (node->parents.empty() && node != removedNode)
        {
            root = node;
            break;
        }
    }

    // 리프 노드 개수 계산
    if (root == nullptr)
    {
        cout << 0; // 모든 노드가 제거된 경우
    }
    else
    {
        cout << countLeafNodes(root);
    }

    // 메모리 해제
    for (TreeNode *node : nodes)
    {
        delete node;
    }
}