
//��Ŀ����
//
//������32λ����n��m�����д�㷨��m�Ķ�������λ���뵽n�Ķ����Ƶĵ�j����iλ, ���ж����Ƶ�λ���ӵ�λ������λ����0��ʼ��
//����������int n��int m��ͬʱ����int j��int i�����������������뷵�ز������������֤n�ĵ�j����iλ��Ϊ�㣬��m�Ķ�����λ��С�ڵ���i - j + 1��
//����������
//1024��19��2��6
//���أ�1100

class BinInsert {
public:
	int binInsert(int n, int m, int j, int i) {
		// write code here
		////��֤n��j��iλ��Ϊ0����m�Ķ�����λ��С�ڵ���i-j+1
		//return n | (m << j);

		////ȡm��ÿһλ����n�Ķ�Ӧλ����
		//int k = 0;
		//while (m!=0)
		//{
		//	int bit = m & 1;
		//	if (bit)
		//	{
		//		n |= 1 << (k + j);//Ϊ1����һλҲҪΪ1�����Ի�
		//	}
		//	else
		//	{
		//		n &= ~(1 << (k + j));
		//	}
		//	k++;
		//	m >>= 1;
		//}

		//����ķ�ʽ  //��������
		int mask = ~(((1 << (i - j + 1)) - 1) << j);  //111->111000->000111;�Ժ����û��Ӱ��
		n &= mask;  //i��jλ��Ϊ0
		n |= (m << j);

		return n;
	}
};


#include <iostream>
using namespace std;

int main()
{
	int i = 5, j = 2;
    int	n = 234;
	int m = 9;
	//����ķ�ʽ
	int mask = ~(((1 << (i - j + 1)) - 1) << j);  //
	n &= mask;  //i��jλ��Ϊ0
	n |= (m << j);
	cout << mask;
	return	0;
}