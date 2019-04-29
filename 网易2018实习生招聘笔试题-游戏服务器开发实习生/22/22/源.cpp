
/*平面内有n个矩形, 第i个矩形的左下角坐标为(x1[i], y1[i]), 右上角坐标为(x2[i], y2[i])。
如果两个或者多个矩形有公共区域则认为它们是相互重叠的(不考虑边界和角落)。
请你计算出平面内重叠矩形数量最多的地方,有多少个矩形相互重叠。*/
//需要超仔细的琢磨和细心
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 60;//假设最多60个矩形
long long X1[MAX];//左下横坐标
long long Y1[MAX];//左下纵坐标
long long X2[MAX];//右上横坐标
long long Y2[MAX];//右上纵坐标
vector<long long> XX;//全部点的横坐标
vector<long long> YY;//全部点的纵坐标

int main()//总体思想：对平面上任意一个点（可能都不是矩形的顶点），求有几个矩形覆盖了它，取覆盖最大值。为了边界值不计入的设定，
{                              //自己矩形边上的点不见得被计入被自己本身矩形覆盖
	int n;
	while (cin >> n)
	{
		for (int i = 0; i < n; ++i)
		{
			cin >> X1[i];
			XX.push_back(X1[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> Y1[i];
			YY.push_back(Y1[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> X2[i];
			XX.push_back(X2[i]);
		}
		for (int i = 0; i < n; ++i)
		{
			cin >> Y2[i];
			YY.push_back(Y2[i]);
		}

		int ans = 1;//这里是1是0都无所谓了

		for (int i = 0; i < XX.size(); ++i)
		{
			for (int j = 0; j < YY.size(); ++j)
			{
				int cnt = 0;
				for (int k = 0; k < n; ++k)
				{
					if (XX[i] > X1[k] && YY[j] > Y1[k] && XX[i] <= X2[k] && YY[j] <= Y2[k])//这里不能同时>= <=要防止边界 题目要求边界不算入    
						cnt++;                                       //这样可以避免把一个点刚好是一个个矩形的右上，是另外一个矩形的左下  ，或者其他的很多仅边重叠情况               
				}                                                    //这样这个点只会被右上的时候计算一次，然后避免重复计算
				ans = max(ans, cnt);
			}
		}
		cout << ans << endl;
	}
	return 0;

}
