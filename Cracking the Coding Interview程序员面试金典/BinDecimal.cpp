
//��Ŀ����
//
//��һ������0��1֮���ʵ��������Ϊdouble���������Ķ����Ʊ�ʾ������������޷���ȷ����32λ���ڵĶ����Ʊ�ʾ�����ء�Error����
//����һ��double num����ʾ0��1��ʵ�����뷵��һ��string����������Ķ����Ʊ�ʾ���ߡ�Error����
//����������
//0.625
//���أ�0.101


//���ַ��������������

#include <iostream>
using namespace std;
#include <string>

class BinDecimal {
public:
	string printBin(double num) {
		// write code here
		double base = 0.5;
		string str = "0.";
		while (num)
		{
			if (num>=base)
			{
				num -= base;
				str += "1";
			}
			else
			{
				str += "0";
			}
			if (str.size()>=32)
			{
				str = "Error";
				break;
			}
	//		num -= base;  �߼�����
			base=base/2;
		}
		return str;
	}
};

class BinDecimal {
public:
	string printBin(double num) {
		// write code here
		string str = "0.";
		for (int i = 0; i < 32;i++)
		{
			num *= 2;
			if (num>=1)
			{
				str += "1";
				num -= 1.0;
			}
			else
			{
				str += "0";
			}
			if (num<=0.0)
			{
				return str;
			}
		}
		if (num>0.0)
		{
			return "Error";
		}
		return str;
	}
};

int main()
{
	double val = 0.625;
	BinDecimal b;
	cout<<b.printBin(val)<<endl;
	return 0;
}