//����һ�����������һ��ʱ�临�Ӷ�ΪO(n), ����ռ临�Ӷ�ΪO(1)���㷨���ж����Ƿ�Ϊ���Ľṹ��
//����һ�������ͷָ��A���뷵��һ��boolֵ���������Ƿ�Ϊ���Ľṹ����֤������С�ڵ���900��
//����������
//1->2->2->1
//���أ�true

#include <stdio.h>
#include <iostream>
using namespace  std;

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};


//˼·1���ռ�O(n) ��������������ߣ� ��һ��ջ����һ�������������ÿ��Ԫ��push��ջ�У��������е�Ԫ�ص�pop˳���������ĵ���������ڶ���Ϳ�ʼpopջ�����ݣ�ÿpopһ�����ݣ��Ͱ�������ݸ������н��жԱȣ������ͬ���������ߣ������ͬ����false��
//
//˼·2���ռ�O(1)��ʹ�ÿ���ָ�뷨����һ������һ����ָ���һ����ָ�룬��ָ��һ������������ָ��һ����һ��������������ָ����һ��Ϊnull��ʱ��˵����ָ���Ѿ�����һ�룬��Ϳ����ҵ��м�ڵ㡣�ڶ�����ת�м���������ָ�룬��������ͷβ���м�ɨ�裬�Ա�ÿ��Ԫ���Ƿ���ȣ��������ȣ����ǻ������������ǻ�������������������ˮ�����˴���ʵ�֣����ﲻ��������

class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		ListNode* pHead = nullptr;
	    ListNode* pNode=nullptr;
		ListNode* pSlow = A;
		ListNode* pQucik = A;
		//����ָ���ҵ��м�ڵ�
		while (pQucik!=nullptr&&pQucik->next!=nullptr)
		{
			pQucik = pQucik->next->next;
			pSlow = pSlow->next;
			
		}
		//���е�����ָ�뷴ת
		pNode = pSlow->next;
		while (pNode!=nullptr)
		{
			ListNode* temp = pNode;
			pNode = pNode->next;
			temp->next = pHead;
			pHead = temp;
		}
		while (A->next!=pHead)
		{
			if (A->next->val!=pHead->val)
			{
				return false;
			}
			A = A->next;
			pHead = pHead->next;
		}
		return true;
	}
};

class PalindromeList1 {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		if (A == nullptr || A->next == nullptr)
			return true;
		ListNode* head = nullptr;
		ListNode* node = A;
		while (node != nullptr){
			ListNode* temp = node;
			node = node->next;
			temp->next = head;
			head = temp;
		}
		while (A != nullptr&&head != nullptr){
			if (A->val != head->val){
				return false;
			}
			A = A->next;
			head = head->next;
		}
		return true;
	}
};

void print(ListNode* pHead)
{
	if (pHead==nullptr)
	{
		puts("����Ϊ�գ�");
		return;
	}
	puts("����Ϊ��");
	ListNode*pNode = pHead->next;
	while (pNode)
	{
		printf("%-d ->", pNode->val);
		pNode = pNode->next;
	}
	cout << "NULL\n";
}

ListNode* create()
{
	ListNode* pHead, *pNode, *temp;
	int x;
	pHead = pNode = (ListNode*)malloc(sizeof(ListNode));  //��ͷ�ڵ������
	printf("�������������ݣ���0Ϊ������־��\n");
	scanf("%d", &x);
	while (x)
	{
		temp = (ListNode*)malloc(sizeof(ListNode));
		temp->val = x;
		pNode->next = temp;
		pNode = temp;
		scanf("%d", &x);
	}
	pNode->next = nullptr;
	return pHead;
}


int main()
{
	ListNode *pHead = create();
	print(pHead);
	PalindromeList s;
	bool val=s.chkPalindrome(pHead);
	cout << val << endl;
	return 0;
}
