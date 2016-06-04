//����һ���ַ���s������Դ���ɾ��һЩ�ַ���ʹ��ʣ�µĴ���һ�����Ĵ������ɾ������ʹ�û��Ĵ���أ�
//�����Ҫɾ�����ַ�������
//
//�������� :
//
//���������ж��飬ÿ�����һ���ַ���s���ұ�֤ : 1 <= s.length <= 1000.
//
//
//
//������� :
//
//	 ����ÿ�����ݣ����һ������������������Ҫɾ�����ַ�������
//
// �������� :
//						 abcda
//						 google
//
//						 ������� :
//						 2
//						 2


#include <iostream>
using namespace std;
#include <string>
#include <algorithm>
#include <memory.h>
const int MAX_NUM = 1010;
int dp[MAX_NUM][MAX_NUM];

//����s�ķ���reverse��Ȼ�������ǵ���Ĺ��������У�Ҫɾ�����ַ���������֪��
//ʱ�临�Ӷ�O(N^2)
int getRemoveNumber(string &str)
{
	string s(str);
	reverse(s.begin(), s.end());
	memset(dp, 0, sizeof(dp));
	int val = str.length();
	int val1 = str.size();
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = 0; j < s.size(); j++)
		{
			if (str[i] == s[j])
			{
				dp[i + 1][j + 1] = dp[i][j] + 1;
			}
			else
				dp[i + 1][j + 1] = max(dp[i][j+1],dp[i+1][j]);
		}
	}
	return s.size() - dp[s.size()][s.size()]-1;  //size()��length������
}

int main()
{
	string str;
	while (getline(cin,str))
	{
		cout << getRemoveNumber(str) << endl;
	}
	return 0;
}



#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

//�����ķ���ʵ��
int main() {
	string s;
	while (cin >> s) {
		int m = s.size();
		vector<vector<int>> dp(m, vector<int>(m, 0));
		for (int len = 1; len < m; ++len)
		for (int i = 0, j = 0; i + len < m; ++i) {
			j = i + len;
			if (s[i] == s[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
		}
		cout << dp[0][m - 1] << endl;
	}
}

//��Ŀ����
//
//����һ���ַ��������Ƿ���ͨ�����һ����ĸ�����Ϊ���Ĵ���
//
//�������� :
//һ��һ����Сд��ĸ���ɵ��ַ������ַ�������С�ڵ���10��
//
//
//������� :
//�����(YES\NO).
//
//�������� :
//	 coco
//
// ������� :
//YES

#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string str)
{
	string temp = str;
	reverse(str.begin(), str.end());
	return str == temp;
}

int main()
{
	string str;
	while (cin >> str)
	{
		if (str.size() <= 0 || str.size() == 1)
		{
			cout << "YES" << endl;
		}
		else
		{
			bool temp = true;
			for (size_t i = 0; i < str.size(); i++)
			{
				string strTemp = str;
				strTemp.erase(strTemp.begin() + i);   //  tmp = str.substr(0, i) + str.substr(i + 1);  
				if (isPalindrome(strTemp))
				{
					cout << "YES" << endl;
					temp = false;
					break;
				}
			}
			if (temp)
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}



////LCSʵ��

#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void LCSLength(char *x, char *y, int m, int n, int c[][MAXLEN], int b[][MAXLEN])
{
	int i, j;
	for (i = 0; i <= m; i++)
		c[i][0] = 0;
	for (j = 1; j <= n; j++)
		c[0][j] = 0;
	for (i = 1; i <= m; i++)
	{
		for (j = 1; j <= n; j++)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 0;
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 1;
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = -1;
			}
		}
	}
}

void PrintLCS(int b[][MAXLEN], char *x, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 0)
	{
		PrintLCS(b, x, i - 1, j - 1);
		printf("%c ", x[i - 1]);
	}
	else if (b[i][j] == 1)
		PrintLCS(b, x, i - 1, j);
	else
		PrintLCS(b, x, i, j - 1);
}

int main(int argc, char **argv)
{
	char x[MAXLEN] = { "ABCBDAB" };
	char y[MAXLEN] = { "BDCABA" };
	int b[MAXLEN][MAXLEN];
	int c[MAXLEN][MAXLEN];
	int m, n;

	m = strlen(x);
	n = strlen(y);

	LCSLength(x, y, m, n, c, b);
	PrintLCS(b, x, m, n);

	return 0;
}

