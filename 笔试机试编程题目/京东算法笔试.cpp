/*****************************************************
* \file     SingletonPatternDemo.cpp
* \date     2016/07/13 18:20
* \author   ranjiewen
* \contact: ranjiewen@outlook.com
*****************************************************/

//��һ¥�ݹ�m�����տ�ʼʱ���ڵ�һ������ÿ��ֻ�ܿ���һ�����߶�����Ҫ����m�������ж����߷���ע���涨��һ����һ����0���߷���
//����һ��������int n���뷵��һ������������¥�ķ�ʽ������֤nС�ڵ���100��Ϊ�˷�ֹ������뷵�ؽ��Mod 1000000007��ֵ��
//����������
//3
//���أ�2


#include <iostream>
using namespace  std;

//// �Ѳ��������еķǵݹ�ⷨ
class GoUpstairs {
public:
	int countWays(int n) {
		// write code here
		/*if (n == 1)
			return 0;

			else if (n == 2)
			return 1;
			else if (n == 3)
			return 2;
			else
			return (countWays(n - 1) + countWays(n - 2)) % 1000000007;*/
		unsigned long long dp[101] = { 0 };
		dp[2] = 1;
		dp[3] = 2;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2];
			if (dp[i] > 1000000007)
			{
				dp[i] = dp[i] % 1000000007;   //59�Ժ������û�������ˣ�����ˡ�
			}
		}
		return dp[n];
	}
};

int main(int argc, char* argv[])
{
	int  count = 0;
	GoUpstairs s;
	cout << s.countWays(96) << endl;
	//cout << s.dp[96] << endl;
	return 0;
}

//С������������һ����¥����С������վ��¥���Ĳ�ͬ�㣬����С��վ��¥��������N�ף�����������������£�ÿ����غ������ϴ�����߶ȵ�һ�룬���Դ�����֪��ȫ���䵽���治������4��С��һ�������˶����ף�(���ֶ�Ϊ����)
//�����ĸ�����A, B, C, D���뷵����������
//����������
//100, 90, 80, 70
//���أ�1020


class Balls {
public:
	int calcDistance(int A, int B, int C, int D) {
		// write code here
		return 3 * (A + B + C + D);
	}

	int calcDistance(int A, int B, int C, int D) {
		int result = A + B + C + D;
		return result + distance(A) + distance(B) + distance(C) + distance(D);
	}
private:
	int distance(int n) {
		if (n <= 0)
			return 0;
		int mod = n % 2;
		return n + distance(n / 2) + mod;
	}
};
