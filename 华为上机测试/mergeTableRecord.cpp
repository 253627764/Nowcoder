//��Ŀ����
//
//���ݱ��¼��������������ֵ����Ա�������ͬ�ļ�¼���кϲ���������ͬ��������ֵ����������㣬�������keyֵ������������
//
//�������� :
//�������ֵ�Եĸ���
//Ȼ������ɶԵ�index��valueֵ���Կո����
//
//
//������� :
//����ϲ���ļ�ֵ�ԣ����У�

//#include<iostream>
//#include<map>
//using namespace std;
//
//int main(int, char**){
//	int count;
//	cin >> count;
//	int a, b;
//	map<int, int> maps;
//	for (int i = 0; i != count; i++){
//		cin >> a >> b;
//		maps[a] += b;
//	}
//	typedef map<int, int>::iterator Iter;
//	for (Iter iter = maps.begin(); iter != maps.end(); iter++){
//		cout << iter->first << " " << iter->second << "\n";
//	}
////	getchar();
////	getchar();
//	return 0;
//}

#include<iostream>
#include<map>
using namespace std;
int main()

{
	int value, key;
	int n;
	while (cin>>n)
	{
		map<int, int> maps;
		for (size_t i = 0; i < n; i++)
		{
			cin >> key >> value;
			pair<map<int, int>::iterator, bool > rel = maps.insert(make_pair(key,value));
			if (!rel.second) //�������key���ڣ����ۼ�value
			{
				rel.first->second += value;
			}
		}
		for (auto it = maps.begin(); it !=maps.end(); it++)
		{
			cout << (*it).first << " " << (*it).second << endl;
		}
	}
	system("pause");
	return 0;
}


//#include <iostream>
//#include <map>
//#include <set>
//using namespace std;
//int main()
//{	int inSum;
//	while (cin >> inSum)
//	{
//		int key, value;
//		set<int> si;
//		map<int, int> mii;
//		while (inSum--)
//		{
//			cin >> key;
//			si.insert(key);
//			cin >> value;
//			mii[key] = mii[key] + value;
//		}
//		set<int>::iterator it;
//		for (it = si.begin(); it != si.end(); it++)
//		{
//			cout << *it << " " << mii[*it] << endl;
//		}
//	}
//	return 0;
//
//}