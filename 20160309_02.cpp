//��Ŀ����
//
//��������ѧУ����һЩͬѧһ����һ���ʾ���飬Ϊ��ʵ��Ŀ͹��ԣ������ü����������N��1��1000֮������������N��100����
//���������ظ������֣�ֻ����һ������������ͬ����ȥ������ͬ������Ӧ�Ų�ͬ��ѧ����ѧ�š�Ȼ���ٰ���Щ����С��������
//�����źõ�˳��ȥ��ͬѧ�����顣����Э��������ɡ�ȥ�ء��롰���򡱵Ĺ�����
//
//Input Param
//n               ����������ĸ���
//inputArray      n�����������ɵ�����
//
//Return Value
//OutputArray    ����������������
//
//ע������������֤�����������ȷ�ԣ�������������֤��
//
//�������� :
//������У���������������ĸ�������������Ӧ����������
//
//������� :
//���ض��У������Ľ��
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int n,temp;
	//cin >> n;
	while (cin>>n)  //����Ϊʲô288������û�д�����
	{
		////�����ȴ����ݵ�ʱ�򣬰��ظ�����ȥ����������Ҳ������������ȥ��
		vector<int> vec;
		for (size_t i = 0; i < n; i++)
		{
			cin >> temp;
			vec.push_back(temp);
			//vec[i]=temp;
		}
		sort(vec.begin(), vec.end()); 
		if (n == 1)
		{
			cout << vec[0] << endl;
		}
		else
		{
			cout << vec[0] << endl;
			for (size_t i = 1; i < vec.size(); i++)
			{
				if (vec[i] != vec[i - 1])
				{
					cout << vec[i] << endl;
				}
			}
			/*vector<int>::iterator it;
			for (it = vec.begin(); it != vec.end(); it++)
			{
				cout << *it << endl;
			}*/
		}
	}
	return 0;
}


