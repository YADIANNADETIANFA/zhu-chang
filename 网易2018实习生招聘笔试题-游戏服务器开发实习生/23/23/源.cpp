//牛牛准备参加学校组织的春游, 出发前牛牛准备往背包里装入一些零食, 牛牛的背包容量为w。
//牛牛家里一共有n袋零食, 第i袋零食体积为v[i]。
//牛牛想知道在总体积不超过背包容量的情况下,他一共有多少种零食放法(总体积为0也算一种放法)。
//递归
#include<cstdio>
#include<algorithm>
#include<vector>
#include<iostream>
using namespace std;

const int MAX = 35;
struct Food
{
	long long weight = 0;
	//bool InBag = false;
}food[MAX];//必须常量值

bool compare(Food food1, Food food2)
{
	return food1.weight < food2.weight;
}

long long Num_of_save(vector<Food> food_weight, long long num_of_food, long long remain_bag_contain,int num_of_food_needIn,int select_band)//主要递归函数
{
	if (num_of_food_needIn == 0 && remain_bag_contain >= 0)//一共要放入3袋，先放入1袋，再放入1袋，再放入1袋，看放完后是否符合要求，
		return 1;                                           //如果该方案满足，结果就加1

	int count = 0;//举例，如果共3袋已取2袋，那最后一袋还有很多取法，用count一一列出
	for (int i = select_band; i < num_of_food; ++i)//1、2+3和1+2、3这两种取三袋方式相同，属于重复，为避免，我们只取目前该袋后面袋的零食，只向右不会左
	{
		if (food_weight[i].weight > remain_bag_contain)//加上后，AC从80到100，复杂度也不超时了
			break;
		count += Num_of_save(food_weight, num_of_food, remain_bag_contain - food_weight[i].weight, num_of_food_needIn - 1, i + 1);
	}
	return count;
}
int main()
{
	long long num_of_food, bag_contain;
	while (cin >> num_of_food >> bag_contain)
	{
		vector<Food> food_weight;
		for (int i = 0; i < num_of_food; ++i)
		{
			cin >> food[i].weight;
			food_weight.push_back(food[i]);
		}
		sort(food_weight.begin(), food_weight.begin() + num_of_food, compare);

		long long ans = 1;//初始啥也不装
		int get_max = 0;//最多装几包零食
		long long contain_current = 0;
		while (contain_current <= bag_contain && get_max < num_of_food)
		{
			contain_current += food_weight[get_max].weight;
			++get_max;
		}
		if (contain_current > bag_contain)
			--get_max;

		if (get_max == num_of_food)//加上后AC从60到80，复杂度也不超时了
			ans = pow(2, get_max);
		else
		{
			for (int i = 1; i <= get_max; ++i)
			{
				ans += Num_of_save(food_weight, num_of_food, bag_contain, i, 0);

			}
		}
		cout << ans << endl;
	}
	return 0;
}
