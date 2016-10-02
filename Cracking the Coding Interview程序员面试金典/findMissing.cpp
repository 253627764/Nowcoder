/*****************************************************
* \file findMissing.cpp
* \date 2016/10/02 11:29
* \author ranjiewen
* \contact: ranjiewen@outlook.com 
* \����������

����A������0��n������������������ȱʧ��һ��������������⣬�����趨���ƣ�ʹ��һ�β����޷�ȡ������number��ĳ���������������ݡ�Ψһ�Ŀ��ò�����ѯ�������е�i��Ԫ�صĶ����Ƶĵ�jλ(���λΪ��0λ)���ò�����ʱ�临�Ӷ�Ϊ������������㷨����O(n)��ʱ�����ҵ��������
����һ������number��������ʣ�µ�������С�������еĶ����Ƹ�λ��ֵ����A[0][1]��ʾʣ�µĵڶ����������ƴӵ͵��ߵĵڶ�λ��ͬʱ����һ��int n���������⡣�뷵��ȱʧ������
����������
[[0],[0,1]]
���أ�1


* \���������
˼·������ֵx�Ķ����Ʊ�ʾ���λΪ1��ʱ��xΪ���������λΪ0ʱ��xΪż����
���������е�����0~nʣ�������մ�С����������еģ������ȱʧ��֮ǰ�������б���������ȵģ����б�i = x����ʱ�б�i % 2��ֵ��������numbers[i][0]����ȵģ���iΪ������numbers[i][0]Ϊ1��Ϊż��ʱ��numbers[i][0]Ϊ0.
��һ�� i % 2��numbers[i][0]����ȴ���Ϊȱʧ����
Ҫע��ȱʧ��Ϊn�����ֵ�������Ҫ����return n��


*****************************************************/

//�����Ŀ��


#include <iostream>
using namespace std;
#include <vector>
class Finder {
public:
	//O(N)
	int findMissing(vector<vector<int> > numbers, int n) {
		// write code here
		for (int i = 0; i < n;i++)
		{
			if (numbers[i][0]!=i%2)
			{
				return i;
			}
		}
		return n;
	}

	// O(logN)
	int method2(vector<vector<int> > numbers, int n) {
		int low = 0, high = numbers.size() - 1;
		while (low <= high) {
			int mid = low + (high - low) / 2;
			if (numbers[mid][0] == (mid & 1))
				low = mid + 1;
			else
				high = mid - 1;
		}
		if (low == numbers.size()) 
			return n;
		else 
			return low;
	}
};