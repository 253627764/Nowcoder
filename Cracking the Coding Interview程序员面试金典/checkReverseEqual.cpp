
/*****************************************************
* \file checkReverseEqual.cpp
* \date 2016/04/06 17:59
*����������

�ٶ����Ƕ�֪���ǳ���Ч���㷨�����һ�������Ƿ�Ϊ�����ַ������Ӵ����뽫����㷨��д��һ�����������������ַ���s1��s2�����д������s2�Ƿ�Ϊs1��ת���ɣ�Ҫ��ֻ�ܵ���һ�μ���Ӵ��ĺ�����
���������ַ���s1, s2, �뷵��boolֵ����s2�Ƿ���s1��ת���ɡ��ַ������ַ�ΪӢ����ĸ�Ϳո����ִ�Сд���ַ�������С�ڵ���1000��
����������
"Hello world", "worldhello "
���أ�false
"waterbottle", "erbottlewat"
���أ�true


*���������

��s1=ABCDΪ���������ȷ���s1����ѭ����λ֮��Ľ����
ABCD->BCDA->CDAB->DABC->ABCD  .......
�������ǰ�ǰ�����ߵ����ݽ��б�����
ABCD->ABCDA->ABCDAB->ABCDABC->ABCDABCD.....
��˿�������s1��ѭ����λ�������ַ����������ַ���s1s1�����ַ��������s2������s1ѭ����λ�õ�����һ��������s1s1�ϡ�
������s1��������,�ж�s2�Ƿ�Ϊs1���Ӵ�,����string��find��ʵ��
s1ƴ���Լ�һ�ε���s3��s2�����s1��ת���ľͱض���s3���Ӵ�

****************************************************/


#include<iostream>
#include<string>
using namespace std;


class ReverseEqual {
public:	
	
	bool checkReverseEqual(string s1, string s2) {
		// write code 
		if (s1.size()==0||s2.size()==0)
		{
			return false;
		}
		string s = s2 + s2;
		if (s.find(s1)==-1)//if (str.contains(s1))  //int find(char c, int pos = 0) const;//��pos��ʼ�����ַ�c�ڵ�ǰ�ַ�����λ��
		{
			return false;
		}
		return true;
	}
	
};