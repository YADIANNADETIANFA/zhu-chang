//��Ҫ����ϸ����ĥ��ϸ��
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

const int MAX = 60;//�������60������
long long X1[MAX];//���º�����
long long Y1[MAX];//����������
long long X2[MAX];//���Ϻ�����
long long Y2[MAX];//����������
vector<long long> XX;//ȫ����ĺ�����
vector<long long> YY;//ȫ�����������

int main()//����˼�룺��ƽ��������һ���㣨���ܶ����Ǿ��εĶ��㣩�����м������θ���������ȡ�������ֵ��Ϊ�˱߽�ֵ��������趨��
{                              //�Լ����α��ϵĵ㲻���ñ����뱻�Լ�������θ���
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

		int ans = 1;//������1��0������ν��

		for (int i = 0; i < XX.size(); ++i)
		{
			for (int j = 0; j < YY.size(); ++j)
			{
				int cnt = 0;
				for (int k = 0; k < n; ++k)
				{
					if (XX[i] > X1[k] && YY[j] > Y1[k] && XX[i] <= X2[k] && YY[j] <= Y2[k])//���ﲻ��ͬʱ>= <=Ҫ��ֹ�߽� ��ĿҪ��߽粻����    
						cnt++;                                       //�������Ա����һ����պ���һ�������ε����ϣ�������һ�����ε�����  �����������ĺܶ�����ص����               
				}                                                    //���������ֻ�ᱻ���ϵ�ʱ�����һ�Σ�Ȼ������ظ�����
				ans = max(ans, cnt);
			}
		}
		cout << ans << endl;
	}
	return 0;

}