/*****************************************************
* \file twoStacksSort.cpp
* \date 2016/05/07 23:58

* \����������
���дһ�����򣬰������ջ�������򣨼����Ԫ��λ��ջ������Ҫ�����ֻ��ʹ��һ�������ջ�����ʱ���ݣ������ý�Ԫ�ظ��Ƶ�������ݽṹ�С�
����һ��int[] numbers(C++��Ϊvector&ltint>)�����е�һ��Ԫ��Ϊջ�����뷵��������ջ����ע������һ��ջ����ζ�������������ֻ�ܷ��ʵ���һ��Ԫ�ء�
����������
[1,2,3,4,5]
���أ�[5,4,3,2,1]

* \���������



*****************************************************/


#include<iostream>
using namespace std;
#include<vector>

class TwoStacks {
public:
	vector<int> twoStacksSort(vector<int> numbers) {
		// write code here
		vector<int> ans;
		if (numbers.size()==0)
		{
			return ans;
		}
		while (numbers.size()!=0)
		{
			int temp = numbers.back();
			numbers.pop_back();
			while (ans.size()!=0&&temp<ans.back())     //num 4 3 5 1 2 (����Ϊback)
			{
				numbers.push_back(ans.back());
				ans.pop_back();
			}
			ans.push_back(temp);
		}
		while (ans.size()!=0)   
		{
			numbers.push_back(ans.back());  //��ʱnumΪ��
			ans.pop_back();
		}
		return numbers;
	}
};