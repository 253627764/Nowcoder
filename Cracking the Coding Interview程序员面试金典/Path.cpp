/*****************************************************
* \file Path.cpp
* \date 2016/05/30 15:03

* \����������
����һ������ͼ����ʵ��һ���㷨���ҳ�����֮���Ƿ����һ��·����
����ͼ�е���������ָ��UndirectedGraphNode* a,UndirectedGraphNode* b(�벻Ҫ�����������ͣ�ͼ������ͼ),�뷵��һ��bool��
��������֮���Ƿ����һ��·��(a��b��b��a)��

* \���������
�����Ŀ�������ʵ������ͼ�ı�����ͼ�ı�����Ϊ������ȱ����͹�����ȱ�����������ȱ����ö�ջʵ�֣�������ȱ����ö���ʵ�֣��ڸ���Ŀ�и�����ÿ���ڵ���ӽڵ㣬��������ù�����ȱ�����
ͼ�Ĺ�����ȱ��������Ĳ�α������ƣ����ǲ�����ȫ��ͬ����Ϊͼ����ͨ�ģ��������Ǳ���ȥ��־�Ǹ��ڵ㱻���ʹ����Ǹ��ڵ�û�б����ʹ���������ȫ���������Ժ󣬻�û���ҵ�a��b��·�����򷵻�false��
ע��֪ʶ�㣺
��1��ͼ���л����ǵñ���Ƿ񱻷���
��2��Ҫ�ֱ�����������a->b��b->a��


*****************************************************/
#include<iostream>
using namespace std;
#include <vector>
#include <map>
#include <queue>

struct UndirectedGraphNode
{
	int label;
	vector<struct UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) :label(x){}
};
class Path
{
public:
	bool checkPath(UndirectedGraphNode* a, UndirectedGraphNode* b)
	{
		return check(a, b) || check(b,a);
	}
	bool check(UndirectedGraphNode* a, UndirectedGraphNode* b)
	{
	  if (a==nullptr||b==nullptr)
	  {
		  return false;
	  }
	  if (a==b)
	  {
		  return true;
	  }
	  map<UndirectedGraphNode*, bool> mapNode;
	  queue<UndirectedGraphNode*> que;
	  que.push(a);
	  while (!que.empty())
	  {
		  UndirectedGraphNode* ptr = que.front();
		  mapNode[ptr] = true;
		  for (int i = 0; i < ptr->neighbors.size();i++)
		  {
			  if (ptr->neighbors[i]==b)
			  {
				  return true;
			  }
			  if (ptr->neighbors[i]&&mapNode[ptr->neighbors[i]]!=true)
			  {
				  que.push(ptr->neighbors[i]);
			  }
		  }
		  que.pop();
	  }
	  return false;
	}
};