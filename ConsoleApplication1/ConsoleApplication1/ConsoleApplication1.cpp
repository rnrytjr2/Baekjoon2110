// ConsoleApplication1.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>
#define collection cin.tie(NULL);ios_base::sync_with_stdio(false);
using namespace std;
int N, C,answer=0;
long long X[200000];
int ParametricSearch(int index)
{
	int count = 0;
	int last = X[0];
	for(int i=1;i<N;i++)
	{
		if (X[i] - index >= last)
		{
			last = X[i];
			count++;
		}
	}
	return count;
}
int main()
{
	cin >> N >> C;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
	}
	sort(X, X + N);
	long long left = 0, right = X[N-1];
	answer = X[N - 1] - X[0];
	while (left + 1 < right)
	{
		long long mid = (left + right) / 2;
		if (ParametricSearch(mid) >= C-1)
		{
			answer = mid;
			left = mid;
		}
		else
		{
			right = mid;
		}
	}

	cout << answer;
}

