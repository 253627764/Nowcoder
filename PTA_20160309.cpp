#include<iostream>
using namespace std;
int main()
{
	int i = 1, A, B, C, T;
	cin >> T;
	while (T>10)
	{
		std::cout << "������count<=10";
		cin >> T;
	}
	bool *result = new bool[T+1];//ΪʲôT���ڴ����
	while (i <= T)
	{
		cin >> A >> B >> C;
		result[i] = (A + B > C) ? true : false;
		i++;
	}
	for (int i = 1; i <= T; i++)
	{
		if (result[i])
		{
			std::cout << "Case #" << i << ":true";
		}
		else
		{
			std::cout << "Case #" << i << ":false";
		}
		std::cout << endl;
	}
	delete[] result;
	return 0;
}

////��ʵ��int�;͹��ˣ�ֻ��Ҫת��һ��˼·����ĿҪ��A + B>C������Խ�����⣬���Ƿ���������
////ֻҪA>C - B �����������ˡ�
//
//#include <iostream>
//using namespace std;
//
//int main()
//{
//	int cnt(0), A[10], B[10], C[10];
//	cin >> cnt;
//	for (int i = 0; i != cnt; ++i) {
//		cin >> A[i] >> B[i] >> C[i];
//	}
//	for (int i = 0; i != cnt; ++i) {
//		if (A[i] > (C[i] - B[i]))
//			cout << "Case #" << i + 1 << ": true" << endl;
//		else
//			cout << "Case #" << i + 1 << ": false" << endl;
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(long int a, long int b, long int c)
//{
//	int r = ((a + b)>c ? (1) : (0));
//	return r;
//}
//
//int main()
//{
//	int num = 0, i = 0;
//	long int a, b, c;
//	scanf("%d", &num);
//	int k[num];  //��Ȼͨ����
//	for (i = 0; i<num; i++){
//		scanf("%ld%ld%ld", &a, &b, &c);
//		k[i] = cmp(a, b, c);
//	}
//	for (i = 0; i<num; i++){
//		if (k[i] == 1)
//			printf("Case #%d: true\n", i + 1);
//		else
//			printf("Case #%d: false\n", i + 1);
//	}
//	return 0;
//}