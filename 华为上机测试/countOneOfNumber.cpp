//��Ŀ����
//
//����һ��int�����ݣ��������int���������ڴ��д洢ʱ1�ĸ�����
//
//�������� :
//����һ��������int���ͣ�

#include<iostream>
using namespace std;
void countOneNumber(int num)
{
	int count = 0;
	for (size_t i = 0; i < 32&&num!=0; i++)
	{
		count += num & 1;
		num =num>> 1;
	}
	cout << count << endl;
}
int main()
{
	int input;
	while (cin>>input)
	{
		countOneNumber(input);
	}
	return 0;
}

//������
#include<iostream>
using namespace std;
int getnum(int n)
{
	int count = 0;
	while (n)
	{
		n &= (n - 1);
		count++;
	}
	return count;
}
int main()
{
	int n;
	while (cin >> n)
	{
		cout << getnum(n) << endl;
	}
	return 0;
}