
//��Ŀ����
//
//����һ��������㹤�ߣ� A��ʾ�����ƶ���D��ʾ�����ƶ���W��ʾ�����ƶ���S��ʾ�����ƶ����ӣ�0, 0���㿪ʼ�ƶ����������ַ��������ȡһЩ���꣬�����������������������ļ����档
//
//���룺
//
//�Ϸ�����ΪA(����D����W����S) + ���֣���λ���ڣ�
//
//����֮����; �ָ���
//
//�Ƿ��������Ҫ���ж�������AA10;  A1A;  $%$;  YAD; �ȡ�
//
//������һ���򵥵����� �磺
//
//A10; S20; W10; D30; X; A1A; B10A11;; A10;
//
//������̣�
//
//��㣨0, 0��
//
//+ A10 = �� - 10, 0��
//
//+ S20 = (-10, -20)
//
//+ W10 = (-10, -10)
//
//+ D30 = (20, -10)
//
//+ x = ��Ч
//
//+ A1A = ��Ч
//
//+ B10A11 = ��Ч
//
//+ һ���� ��Ӱ��
//
//+ A10 = (10, -10)
//
//
//
//��� ��10�� - 10��

#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main()
{
	string str;
	//getline(cin,str);
	while (getline(cin, str))
	{
		vector<string> ve;
		string sub;
		int pos=0;//��ʼ��
		while (pos<str.size())
		{
			if (str[pos] == ';')
			{
				ve.push_back(sub);
				sub.clear();
			}
			else
			{
				sub += str[pos];
			}
			pos++;
		}
		int xx = 0, yy = 0;//���Զ���Ϊ�ṹ��
		for (int i = 0; i<ve.size(); i++)
		{
			int flag = true;
			string t = ve[i];
			if (t.length() == 0 || t.length() == 1 || t.length()>3) continue;
			switch (t[0])
			{
			case 'W':
				for (int i = 1; i < t.length(); i++)
				{
					if (t[i] >= '0'&&t[i] <= '9');
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
				else
				{
					int temp = atoi(&t[1]);  //atoi��ASCII to integer ����д���ǰ��ַ���ת���ɳ���������һ�ֺ���  int atoi(const char *nptr);
					yy += temp;
				}
				break;
			case 'A':
				for (int i = 1; i < t.length(); i++)
				{
					if (t[i] >= '0'&&t[i] <= '9');
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
				else
				{
					int temp = atoi(&t[1]);
					xx -= temp;
				}
				break;
			case 'S':

				for (int i = 1; i < t.length(); i++)
				{
					if (t[i] >= '0'&&t[i] <= '9');
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
				else
				{
					int temp = atoi(&t[1]);
					yy -= temp;
				}
				break;

			case 'D':
				for (int i = 1; i < t.length(); i++)
				{
					if (t[i] >= '0'&&t[i] <= '9');
					else
					{
						flag = false;
						break;
					}
				}
				if (flag == false)
				{
					break;
				}
				else
				{
					int temp = atoi(&t[1]);
					xx += temp;
				}
				break;
			default:
				break;
			}
		}
		cout << xx << "," << yy << endl;
		ve.clear();
	}
	return 0;
}