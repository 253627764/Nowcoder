//��Ŀ����
//
//д��һ�����򣬽���һ��������ֵ���������ֵ�Ľ�������ֵ�����С�������ֵ���ڵ���5, ����ȡ����С��5��������ȡ����
//�������� :
//����һ��������ֵ
//
//
//������� :
//�������ֵ�Ľ�������ֵ

#include<iostream>
using namespace std;

int main()

{
	float input;
	while (cin>>input)
	{
		//int integer = (int)input;
		int integer = static_cast<int>(input);
		if (input-integer>=0.5)
		{
			cout << integer + 1;
		}
		else
		{
			cout << integer;
		}
	}
	return 0;
}
