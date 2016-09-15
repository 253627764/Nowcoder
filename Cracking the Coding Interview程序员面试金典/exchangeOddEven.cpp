//��Ŀ����
//
//���д���򽻻�һ�����Ķ����Ƶ�����λ��ż��λ����ʹ��Խ�ٵ�ָ��Խ�ã�
//����һ��int x���뷵�ؽ��������int��
//����������
//10
//���أ�5

class Exchange {
public:
	int exchangeOddEven(int x) {
		// write code here
		int result = 0;
		int times = 0;
		while (x!=0)
		{
			times = times + 2;
			int a = x & 1;
			result += a * pow(times-1);
			x >>= 1;
			int b = x & 1;
			result += b*pow(times - 2);
			x >>= 1;
		}
		return result;
	}
	int pow(int x)
	{
		int a = 1;
		while (x!=0)
		{
			a*=2;
			x--;
		}
		return a;
	}

	//��0xAAAAAAAA��x�����������λ������(ż��λ������Ϊ0)
	//	��0x 55555555 ��x�������ż��λ������(����λ������Ϊ0)

	//	oddVal����һλ even����һλ  ��Ӽ��ɡ�
	int exchangeOddEven(int x) {
		// write code here
		int oddVal = (x & 0xAAAAAAAA); // bit 1 3 5 ... 31
		int evenVal = (x & 0x55555555); // bit 0 2 4 ... 30
		return (oddVal >> 1) + (evenVal << 1);
	}

	//��Ϊint���з������ͣ��������x�����λΪ1����ôȡż��λ�õ�����even�����λҲΪ1�������ʱ���ƣ���ô���λ��1������0��������ʱ����п��ܳ����⣬��Ϊ1 | 0����1���ı��˲��ñ��ֵ��
};



#include<iostream>
using namespace std;

int main()
{
	Exchange e;
	cout << e.exchangeOddEven(10) << endl;
	return 0;
}
