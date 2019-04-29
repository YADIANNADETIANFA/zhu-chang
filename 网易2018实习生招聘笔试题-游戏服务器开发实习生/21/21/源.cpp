/*牛牛以前在老师那里得到了一个正整数数对(x, y), 牛牛忘记他们具体是多少了。
但是牛牛记得老师告诉过他x和y均不大于n, 并且x除以y的余数大于等于k。
牛牛希望你能帮他计算一共有多少个可能的数对。*/
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
