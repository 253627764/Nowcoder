//СQ�������ϲ���ʱ�뵽��������⣺��n������������ɶ�Ԫ�飬����С���ж��ٶ��أ�������أ�
//
//�������� :
//
//�����������������ݡ�
//
//����ÿ��������ݣ�
//
//N - �������������n����
//
//a1, a2...an - ��Ҫ���������
//
//��֤ :
//
//1 <= N <= 100000, 0 <= ai <= INT_MAX.
//
//
//
//������� :
//
//	 ����ÿ�����ݣ��������������һ������ʾ����С�Ķ������ڶ�������ʾ�����Ķ�����
//
// �������� :
//6
//45 12 45 32 5 6
//
//������� :
//	 1 2

#include <iostream>
using namespace std;
#include <vector>
#include <limits.h>
void getMin_Max_N(vector<int> vc,int &minN,int &maxN)
{
	int min=INT_MAX, max=0;
	for (int i = 0; i < vc.size();i++)
	{
		for (int j = 0; j < vc.size();j++)
		{
			if (i!=j)
			{
				if (vc[i]-vc[j]<min)
				{
					min = vc[i] - vc[i];
					minN = 1;
				}
				if (vc[i] - vc[j] == min)
				{
					minN++;
				}
				if (vc[i]-vc[j]>max)
				{
					max = vc[i] - vc[j];
					maxN = 1;
				}
				if (vc[i] - vc[j] == max)
				{
					maxN++;
				}
			}
		}
	}
}

int main()
{
	int N;
	while (cin>>N)
	{
		vector<int> vc(N,0);
		for (int i = 0; i < N;i++)
		{
			cin >> vc[i];  //���ַ�ʽ���룬�����ʼ����С���������������
		}
		int minN = 1, maxN = 1;
		getMin_Max_N(vc, minN, maxN);
		cout << minN << " " << maxN << endl;
	}
	
}

//�ο���
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> nVec(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> nVec[i];
		}
		if (n == 1)
		{
			cout << 0 << " " << 0 << endl;
			continue;
		}
		sort(nVec.begin(), nVec.end());
		int nMinDvalueNum = 0;
		int nMinDvalue = nVec[1] - nVec[0];
		int nMaxNum = count(nVec.begin(), nVec.end(), nVec[n - 1]);
		int nMinNum = count(nVec.begin(), nVec.end(), nVec[0]);
		for (int i = 1; i < n; ++i)
		{
			nMinDvalue = nMinDvalue>(nVec[i] - nVec[i - 1]) ? nVec[i] - nVec[i - 1] : nMinDvalue;
		}
		for (int i = 1; i < n; ++i)
		{
			for (int j = i - 1; j >= 0; --j)
			{
				int temp = nVec[i] - nVec[j];
				if (nMinDvalue == temp)
				{
					nMinDvalueNum++;
				}
				else
				{
					break;
				}
			}
		}
		//���ֵ����Сֵ��ͬ
		if (nVec[0] == nVec[n - 1])
		{
			int num = 1 << nMaxNum - 1;
			cout << num << " " << num << endl;
		}
		else
		{
			cout << nMinDvalueNum << " " << nMaxNum*nMinNum << endl;
		}
	}
	return 0;
}

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;

int main(){
	int n;
	while (cin >> n){
		vector<int> a(n);
		for (int i = 0; i < n; i++){
			cin >> a[i];
		}
		if (n == 1){
			cout << 0 << " " << 0 << endl;
			continue;
		}
		sort(a.begin(), a.end());

		int maxnum = count(a.begin(), a.end(), a[n - 1]);
		int minnum = count(a.begin(), a.end(), a[0]);
		int max = maxnum*minnum;
		int minvalue = a[1] - a[0];
		for (int i = 1; i < n; i++){
			if (a[i] - a[i - 1] < minvalue)
				minvalue = a[i] - a[i - 1];
		}
		int min = 0;
		for (int i = 1; i < n; i++){
			for (int j = i - 1; j >= 0; j--){
				if (a[i] - a[j] == minvalue)
					min++;
				else
					break;
			}
		}
		if (a[0] == a[n - 1]){
			int num = a.size()*(a.size() - 1) / 2;
			cout << num << " " << num << endl;
			continue;
		}
		cout << min << " " << max << endl;

	}
	return 0;