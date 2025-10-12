#include <iostream>
#include <vector>
#include <numeric>
#include <map>
#include <algorithm>

// k번째 캐릭터의 i번째 속성을 쿼리하는 함수
int query(int k, int i)
{
    std::cout << "? " << k << " " << i << std::endl;
    int value;
    std::cin >> value;
    return value;
}

int main()
{
    std::cin.tie(0);
    std::ios::sync_with_stdio(0);

    int M, N, Q;
    std::cin >> M >> N >> Q;

    std::vector<int> a(N);
    for (int i = 0; i < N; ++i)
    {
        std::cin >> a[i];
    }

    // 잠재적으로 겹칠 수 있는 캐릭터들의 인덱스 리스트 (후보군)
    std::vector<int> candidates(M);
    std::iota(candidates.begin(), candidates.end(), 1); // 1, 2, ..., M으로 초기화

    std::vector<int> result(N);

    // 각 속성(attribute)을 순차적으로 결정
    for (int i = 1; i <= N; ++i)
    {
        // 더 이상 고려할 후보가 없으면 나머지 속성은 1로 채우고 종료
        if (candidates.empty())
        {
            for (int j = i; j <= N; ++j)
            {
                result[j - 1] = 1;
            }
            break;
        }

        // 현재 후보군을 i번째 속성 값에 따라 그룹화
        std::map<int, std::vector<int>> groups;
        for (int k : candidates)
        {
            int val = query(k, i);
            groups[val].push_back(k);
        }

        // 가장 작은 그룹을 찾기 위한 변수
        size_t min_size = M + 1;
        int best_val = 1;

        // 가능한 모든 속성 값(1 ~ a[i-1])을 확인
        for (int v = 1; v <= a[i - 1]; ++v)
        {
            // Case 1: '잭팟'. 해당 속성 값을 가진 캐릭터가 아무도 없는 경우
            if (groups.find(v) == groups.end())
            {
                best_val = v;
                min_size = 0;
                break;
            }
            // Case 2: 가장 작은 그룹을 찾아서 갱신
            if (groups[v].size() < min_size)
            {
                min_size = groups[v].size();
                best_val = v;
            }
        }

        // 이번 속성의 값을 최적의 값(best_val)으로 결정
        result[i - 1] = best_val;

        // '잭팟'이 터졌으면 다음 후보군은 비어있게 됨
        if (min_size == 0)
        {
            candidates.clear();
        }
        else
        {
            // 다음 단계에서 고려할 후보군을 가장 작은 그룹으로 갱신
            candidates = groups[best_val];
        }
    }

    // 최종 결과 출력
    std::cout << "! ";
    for (int i = 0; i < N; ++i)
    {
        std::cout << result[i] << (i == N - 1 ? "" : " ");
    }
    std::cout << std::endl;

    return 0;
}