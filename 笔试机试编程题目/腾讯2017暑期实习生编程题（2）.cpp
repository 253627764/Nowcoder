//СQ���������һ�����⣺��һ���ַ����Ĵ�д��ĸ�ŵ��ַ����ĺ��棬�����ַ������λ�ò��䣬�Ҳ����������Ŀռ䡣
//���ܰ��СQ��
//
//�������� :
//
//���������ж��飬ÿ�����һ���ַ���s���ұ�֤ : 1 <= s.length <= 1000.
//
//
//
//������� :
//
//	 ����ÿ�����ݣ������λ����ַ�����
//
// �������� :
//						 AkleBiCeilD
//
//						 ������� :
//						 kleieilABCD


#include<iostream>
using namespace  std;
#include <string>


//Ӧ�ô�ͷ����������������Ĵ�д��ĸ�ҵ�������Сд��ĸ��������
//������ҵ���д��ĸ��������������Сд��ĸ�������������Ĵ�д��ĸ����ô���أ�
//���ߴ�β��ͷ�������������ơ�
string changeSequenceStr(string &str)
{
	int size = str.size();
	/*for (int i = 0; i < size;i++)
	{
	if (isupper(str[i]))
	{
	int j = i+1;
	while (islower(str[j])&&j<size)
	{
	j++;
	}
	if (isupper(str[j])&&j<size)
	{
	char temp = str[i];
	for (int k = i; k < j; k++)
	{
	str[k] = str[k + 1];
	}
	str[j - 1] = temp;
	}
	}
	}*/

	for (int i = 0; i < size;i++)
	{
		if (isupper(str[i]))
		{
			int j = i;
			while (isupper(str[j])&&j<size)
			{
				j++;
			}
			if (j==(size-1)&&isupper(str[j]))
			{
				break;
			}
			if (islower(str[j])&&j<size)
			{
				char temp = str[j];
				for (int k = j; k > i;k--)
				{
					str[k] = str[k - 1];
				}
				str[i] = temp;
			}
		}
	}
	return str;
}

int main()
{
	string str;
	while (getline(cin,str))
	{
		cout << changeSequenceStr(str)<<endl;
	}
	return 0;
}