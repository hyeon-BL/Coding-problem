#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int testn;
	int n, m;
	int mj;
	int count;

    cin >> testn;
	for (int i = 0; i < testn; i++) { // 테스트 케이스 수 만큼 반복
		count = 0;
        cin >> n >> m; // n: 문서의 개수, m: 궁금한 문서의 위치
		
		priority_queue<int> pq; // 내림차순 정렬
		queue<pair<int, int>> q;

		for (int j = 0; j < n; j++) { // 문서의 중요도 입력
            cin >> mj;
			q.push({ j, mj });
			pq.push(mj);
		}

		while (!q.empty()) {
			int loc = q.front().first;
			int val = q.front().second;
			q.pop();
            
			if (pq.top() == val) {
				pq.pop();
				count++;
				if (m == loc) {
					printf("%d\n", count);
					break;
				}
			}

			else q.push({ loc, val });
		}
	}

	return 0;
}