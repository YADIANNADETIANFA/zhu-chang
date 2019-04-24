//�ݹ�
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
}food[MAX];//���볣��ֵ

bool compare(Food food1, Food food2)
{
	return food1.weight < food2.weight;
}

long long Num_of_save(vector<Food> food_weight, long long num_of_food, long long remain_bag_contain,int num_of_food_needIn,int select_band)//��Ҫ�ݹ麯��
{
	if (num_of_food_needIn == 0 && remain_bag_contain >= 0)//һ��Ҫ����3�����ȷ���1�����ٷ���1�����ٷ���1������������Ƿ����Ҫ��
		return 1;                                           //����÷������㣬����ͼ�1

	int count = 0;//�����������3����ȡ2���������һ�����кܶ�ȡ������countһһ�г�
	for (int i = select_band; i < num_of_food; ++i)//1��2+3��1+2��3������ȡ������ʽ��ͬ�������ظ���Ϊ���⣬����ֻȡĿǰ�ô����������ʳ��ֻ���Ҳ�����
	{
		if (food_weight[i].weight > remain_bag_contain)//���Ϻ�AC��80��100�����Ӷ�Ҳ����ʱ��
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

		long long ans = 1;//��ʼɶҲ��װ
		int get_max = 0;//���װ������ʳ
		long long contain_current = 0;
		while (contain_current <= bag_contain && get_max < num_of_food)
		{
			contain_current += food_weight[get_max].weight;
			++get_max;
		}
		if (contain_current > bag_contain)
			--get_max;

		if (get_max == num_of_food)//���Ϻ�AC��60��80�����Ӷ�Ҳ����ʱ��
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