#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

/*
Trie 자료구조:
- 먹이 정보를 Trie에 저장
- Trie 출력

TrieNode 구조체:
- children: 자식 노드들을 저장하는 map

=> 문자열을 저장하고 탐색하는 데 유용한 자료구조

*/

struct TrieNode
{ // Trie의 노드 구조체
    map<string, TrieNode *> children;
};

class Trie
{
public:
    Trie()
    { // Trie constructor
        root = new TrieNode();
    }

    void insert(const vector<string> &foods)
    { // Trie에 먹이 정보 삽입
        TrieNode *node = root;
        for (const string &food : foods)
        {
            if (node->children.find(food) == node->children.end())
            { // 해당 먹이가 없으면 새로운 TrieNode 생성
                node->children[food] = new TrieNode();
            }
            node = node->children[food]; // 다음 TrieNode로 이동
        }
    }

    void print(TrieNode *node, int depth)
    { // Trie 출력
        for (auto &child : node->children)
        { // 모든 자식 노드에 대해
            for (int i = 0; i < depth; i++)
            { // 깊이에 따라 -- 출력
                cout << "--";
            }
            cout << child.first << '\n';
            print(child.second, depth + 1);
        }
    }

    void print()
    {
        print(root, 0);
    }

private:
    TrieNode *root;
};

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int N; // 먹이의 정보 개수
    cin >> N;

    Trie trie; // Trie 자료구조
    for (int i = 0; i < N; i++)
    {
        int K;
        cin >> K;
        vector<string> foods(K);
        for (int j = 0; j < K; j++)
        { // 먹이 정보 입력
            cin >> foods[j];
        }
        trie.insert(foods); // Trie에 먹이 정보 삽입
    }

    trie.print(); // Trie 출력
    return 0;
}