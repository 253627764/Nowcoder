//��Ŀ����
//
//д��һ�����򣬽���һ������ĸ�������Լ��ո���ɵ��ַ�������һ���ַ���Ȼ����������ַ����к��и��ַ��ĸ����������ִ�Сд��
//
//�������� :
//����һ������ĸ�������Լ��ո���ɵ��ַ�������һ���ַ���
//
//
//������� :
//��������ַ����к��и��ַ��ĸ�����
//
//�������� :
//ABCDEF
//A
//
//������� :
//1
#include<iostream>
using namespace std;
#include<string>
void main()
{
	string str;
	char temp;
	cin >> str;  //	getline(cin,str);
	cin >> temp;
	int result=0;  //result=getNumber(str,temp);д�ɺ�������ʽ���ں����ڽ���Сдת����Ȼ���ж�
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i]==temp)
		{
			result++;
		}
	}
	cout << result<<endl;
};