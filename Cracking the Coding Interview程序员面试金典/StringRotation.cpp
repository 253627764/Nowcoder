/*****************************************************
* \file StringRotation.cpp
* \date 2016/06/23 17:11

* \����������

����һ���ַ��������ַ����е�ĳһλ�ã������һ���㷨��������iλ�����ڵ���ಿ���ƶ����ұߣ����Ҳಿ���ƶ�����ߡ�
�����ַ���A�����ĳ���n�Լ��ض�λ��p���뷵����ת��Ľ����
����������
"ABCDEFGH",8,4
���أ�"FGHABCDE"

* \���������



*****************************************************/

#include<iostream>
using namespace std;
#include<string>
class StringRotation {
public:
	string rotateString(string A, int n, int p) {
		// write code here
		string B;
		B.assign(A.begin()+p+1, A.begin() + n);  
		for (int i = 0; i <= p;i++)
		{
			B.push_back(A[i]);
		}
		return B;
	}
};

//return A.substr(p+1) + A.substr(0, p+1);

// string b=A+A;
// string a = b.substr(p + 1, n);
// return a;

int main()
{
	string A = "ABCDEFGHJK";
	StringRotation s;
	string B=s.rotateString(A, 10, 7);
	cout << B << endl;
}