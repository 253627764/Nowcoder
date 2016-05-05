/*****************************************************
* \file removeListNode.cpp
* \date 2016/04/23 10:48

* \����������
ʵ��һ���㷨��ɾ�����������м��ĳ����㣬�ٶ���ֻ�ܷ��ʸý�㡣
������ɾ���Ľڵ㣬��ִ��ɾ�����������ýڵ�Ϊβ�ڵ㣬����false�����򷵻�true

* \���������



*****************************************************/

struct ListNode
{
	int val;
	struct ListNode* next;
	ListNode(int x) :val(x), next(nullptr){}
};

class Remove {
public:
	bool removeNode(ListNode* pNode) {   //pNodeΪɾ���ڵ�
		// write code here
		if (pNode==nullptr||pNode->next==nullptr)
		{
			return false;
		}
		ListNode* node = pNode->next;//nodeɾ���ڵ�
		pNode->next = node->next;
		return true;
	}
};

/*****************************************************
* \file removeListNode.cpp
* \date 2016/04/23 11:01

* \����������
��д���룬�Ը���ֵxΪ��׼������ָ�������֣�����С��x�Ľ�����ڴ��ڻ����x�Ľ��֮ǰ
����һ�������ͷָ�� ListNode* pHead���뷵���������к�������ͷָ�롣ע�⣺�ָ��Ժ󱣳�ԭ��������˳�򲻱䡣

* \���������
Ҫ������������Ҫ�ر�С�ģ���Ϊ��Ǩ����Ҫ�漰���ƶ�Ԫ�صĿ��������ƶ������Ԫ�������׺ܶ࣬���ǲ���Ҫ�ƶ��ͽ��������е�Ԫ�أ�
ֻ�Ǹı�һ��ÿ���ڵ��nextָ��Ϳ��ԣ����ǿ��Դ�����������һ�������Ǵ��С��x��Ԫ�أ���һ�������Ŵ��ڵ���x��Ԫ�أ�
Ȼ�����һ��ԭ��������С��xԪ�صĽڵ�ӵ���һ�������ϣ������ڵ���xԪ�صĽڵ�ӵ��ڶ��������ϡ����ʵ�ַָ
������Ա���Խ�䡷��Ŀ��⣺http://blog.csdn.net/zdplife/article/category/5799903

���ߣ�
ʱ��O(n)�� �ռ�O(1)��������
����˼·�Ǵ�ͷ��β����һ�飬��val����x���򽫸ý��ת�Ƶ�List��β����
˼·�ܼ򵥣���Ҫע���������ת�ƽ��ʱ�ҵ����ĸ���㣬��ֹList�ϵ���

*****************************************************/
class Partition {
public:
	ListNode* partition(ListNode* pHead, int x) {
		// write code here
		ListNode *pSamllFirst = new ListNode(0);
		ListNode *pBigFirst = new ListNode(0);
		ListNode *pSamll = pSamllFirst, *pBig = pBigFirst;

		if (pHead==nullptr)
		{
			return pHead;
		}
		while (pHead)
		{
			if (pHead->val<x)
			{
				pSamll->next = pHead;
				pSamll = pSamll->next;
			}
			else
			{
				pBig->next = pHead;
				pBig = pBig->next;
			}
			pHead = pHead->next;
		}
		pBig->next = nullptr;
		pSamll->next = pBigFirst->next;
		return pSamllFirst->next;
	}
};

#include <iostream>
using namespace std;
int main()
{


	return 0;
}