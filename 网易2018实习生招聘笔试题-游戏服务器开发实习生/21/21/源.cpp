#include<cstdio>
#include<iostream>
using namespace std;

int main()
{
	unsigned long n, k;
	while (cin >> n >> k)
	{
		if (k == 0)
		{
			cout << n * n << endl;
			continue;
		}
		unsigned long res = 0;
		for (unsigned long y = k+1; y <= n; ++y)
		{
			int beishu = n / y;
			res += beishu*(y - k);
			if (n % y >= k)
				res += n % y - k+1;
		}
		cout << res << endl;
	}
	return 0;
}