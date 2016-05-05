
/*****************************************************
* \file SetOfStacks.cpp
* \date 2016/05/05 17:49

* \����������
��ʵ��һ�����ݽṹSetOfStacks���ɶ��ջ��ɣ�����ÿ��ջ�Ĵ�СΪsize����ǰһ��ջ����ʱ���½�һ��ջ��
�����ݽṹӦ֧������ͨջ��ͬ��push��pop������
����һ����������int[][2] ope(C++Ϊvector<vector<int>>)��ÿ�������ĵ�һ��������������ͣ�
��Ϊ1����Ϊpush��������һ����ΪӦpush�����֣���Ϊ2����Ϊpop��������һ���������塣
�뷵��һ��int[][](C++Ϊvector<vector<int>>)��Ϊ������в������SetOfStacks��˳��ӦΪ���µ��ϣ�Ĭ�ϳ�ʼ��SetOfStacksΪ�ա���֤���ݺϷ���

* \���������
�����Ŀ����ûʲô���ɣ����Ƕ�ջ��ջ�Ĺ��̣��൱���ö��������ʵ��һ����ջ�����һ���������ˣ�
��ʹ����һ���飬�������������ˣ���Ѹ�����ɾ��������ǰһ�������в�����ʵ�ֵ�ʱ��ע�����齻������ʱӦ������жϡ�

*****************************************************/

#include <iostream>
using namespace std;
#include <vector>
class SetOfStacks {
public:
	vector<vector<int> > setOfStacks(vector<vector<int> > ope, int size) {
		// write code here
		if (ope.size()==0)
		{
			return ope;
		}
		vector<vector<int>> vec_result;
		vector<int> vec;
		int top = 0;
		for (int i = 0; i < ope.size();i++)
		{
			if (ope[i][0]==1)   //��˳��ִ�У�����Ҫif--else
			{
				vec.push_back(ope[i][1]);
				if (++top==size)  //ջ�������½�һ��ջ
				{
					vec_result.push_back(vec);
					vec.clear();
					top = 0;
				}
			}
			else
			{
				if (top==0)  //ջΪ�գ������һ��ջ��
				{
					vec = vec_result.back();
					vec_result.pop_back();
					top = size;
				}
				vec.pop_back();
				top--;
			}
		}

		//vector<vector<int> > st;
		//vector<int> temp;
		//for (int i = 0; i < ope.size(); i++){
		//	if (ope[i][0] == 1){//��ջ
		//		if (temp.size() == size){//ջ�������½�һ��ջ������ջ
		//			st.push_back(temp);
		//			temp.clear();
		//			temp.push_back(ope[i][1]);
		//		}
		//		else
		//			temp.push_back(ope[i][1]);
		//	}
		//	if (ope[i][0] == 2){//��ջ
		//		if (temp.size() != 0)//��ǰջ��Ϊ�գ�ֱ�ӳ�ջ
		//			temp.pop_back();
		//		else if (st.size() != 0){//��ǰջΪ�գ������һ��ջ��
		//			temp = st[st.size() - 1];
		//			temp.pop_back();
		//			st.pop_back();
		//		}
		//	}
		//}

		if (!vec.empty())   //����û����size������Ԫ�ص�vec,���ѹ�뷵�ؽ��
		{
			vec_result.push_back(vec);
		}
		return vec_result;
	}
};