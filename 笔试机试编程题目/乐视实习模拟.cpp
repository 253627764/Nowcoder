//�����ַ�����ͳ��ĳһ�ַ����ֵĴ���

#include<iostream>
using namespace  std;
#include<string>

int main()
{
	string str;
	while (getline(cin,str))
	{
		char ch;
		int times = 0;
		cin >> ch;
		for (int i = 0; i < str.size();i++)
		{
			if (str[i]==ch)
			{
				times++;
			}
		}
		cout << times<<endl;
	}
	return 0;
}


#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	while (getline(cin, str))
	{
		char s;
		cin >> s;
		int count = 0;
		for (int i = 0; i < str.size(); i++)
		{
			if (s == str[i])
				count++;
		}
		cout << count << endl;
		cin.ignore();
	}
}

//����������
//while (getline(cin, str))
//cin >> s
//ѭ����ʱ�������⣬�ڶ���ѭ��������s���������һ��cin.ignore()�ͺ��ˣ������г��ִ�������ˡ���


//�����ַ������һ�����ʵ��ַ���

#include <string>
#include <iostream>
using namespace std;
int main()
{
	//cout << "�������ַ�����";
	string str;
	int count = 0;
	getline(cin, str);
	for (int i = str.size()-1; i >=0; i--)
	{

		if (str[i] == ' ')
			break;
		else
			count++;
	}
	cout << count << endl;
	//	cout << str.size();
	return 0;
}

// C++
//��Щͬѧ�Ĵ�û���ǵ�ĩβ�пո�����������ĩβ�пո�Ķ����Ϊ0�ˡ�
//��hello world     ����Ȼ���5.

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	while (getline(cin, s)){
		int n = 0, flag = 1;
		for (int i = s.length() - 1; i >= 0; --i){//���ż���
			if (flag && s[i] == ' '){//���ĩβ�пո������ĩβ�ո�
				continue;
			}
			else if (s[i] != ' '){
				flag = 0;
				++n;
			}
			else{
				break;
			}
		}
		cout << n << endl;
	}
	return 0;
}


//���ĳһ�����������й�����
//��������

#include<iostream>
using namespace std;
int main()
{
	int N;
	while (cin>>N)
	{
		int i = 2;
		while (N!=1)
		{			
			if (N%i==0)
			{
				N = N / i;
				cout << i << " ";
				continue;
			}
			i++;	
		}
		cout << endl;
	}
	return 0;
}

//�������ĸ���


//