
//����һ���������ַ�����������Ҫ������(Ҳ����O(n))��ʱ���������һЩ���Ρ���������ַ����а�����һЩ�ո�
//����"Hello World"һ����Ȼ������Ҫ�����ǰ��Ÿ��ַ������ɿո�����ĵ��ʷ���ͬʱ��תÿ���ַ��Ĵ�Сд��
//����"Hello World"���κ�ͱ����"wORLD hELLO"��

//��������:
//����һ���ַ���s�Լ����ĳ���n(1��n��500)
//
//������� :
//	 �뷵�ر��κ���ַ�������Ŀ��֤�������ַ������ɴ�Сд��ĸ�Ϳո񹹳ɡ�
//
// �������� :
//"This is a sample", 16
//
//������� :
//	 "SAMPLE A IS tHIS"

//
//����⿴��ȥ���Ǻ��ѣ����Ǻܶ�߽����� ��Ҫ���ǡ�
//���磺##this#is#a#sample## ���� ##SAMPLE#A#IS#THIS##��������SAMPLE#A#IS#THIS����Tips:#����ո�
//�����˼·�����Ƚ��ַ�����Сд�����滻��Ȼ��ת�����ַ��������תÿ�����ʣ������Ĳ��ı䡣
#include <iostream>
using namespace std;
#include <string>
#include <stack>
#include <vector>
class Transform {
public:
	string trans(string s, int n) {
		// write code here
		vector<char> vec;
		stack<vector<char> > sta;
		for (int i = 0; i < n;i++)
		{
			if ('Z'>=s[i]&&s[i]>='A')
			{
				s[i] = s[i] + 32;
				vec.push_back(s[i]);
				if (i == (n - 1))  //���û�н�����־
				{
					sta.push(vec);
					vec.clear();
				}
			}
			else if ('a'<=s[i]&&'z'>=s[i])
			{
				s[i] = s[i] - 32;
				vec.push_back(s[i]);
				if (i==(n-1))
				{
					sta.push(vec);
					vec.clear();
				}
			}
			else if (s[i]==' ')
			{
				if (!vec.empty()) //Ϊ�ո�����
				{
					sta.push(vec);
					vec.clear();
				}		
				vec.push_back(s[i]);
				sta.push(vec);
				vec.clear();
			}

		}
		string result;
		while (!sta.empty())
		{
			vector<char> temp=sta.top();
			for (auto it = temp.begin(); it!= temp.end();it++)
			{
				result += *it;
			}
		//	result += ' ';
			sta.pop();
		}
		return result;
	}
};

int main()
{
	Transform t;
	string str;
	int n;
	getline(cin,str);
	cin >> n;
	//t.trans(str,n);
	cout << t.trans(str, n)<<endl;
}

//���԰ѷ�ת�ʹ�Сд�仯�ֿ����С�
class Transform {
public:
	string trans(string s, int n) {
		// write code here
		//��Сд�滻
		for (int i = 0; i < n; i++){
			if (s[i] >= 'a'&&s[i] <= 'z'){
				s[i] = toupper(s[i]);
			}
			else if (s[i] >= 'A'&&s[i] <= 'z'){
				s[i] = tolower(s[i]);
			}
		}
		//��ת�����ַ���
		reverse(s.begin(), s.end());
		auto pbegin = s.begin();
		auto pend = s.begin();
		while (*pend != '\0'){
			if (*pend == ' '){
				//�����ո���ת����
				reverse(pbegin, pend);
				pbegin = pend + 1;
			}
			++pend;
		}
		//����߽�������ַ���ĩβ�ĵ�����Ҫ��ת
		reverse(pbegin, pend);
		return s;
	}
};