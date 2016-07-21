/*!
 * \file ��������ʵϰ.cpp
 * \date 2016/07/20 17:33
 *
 * \author ranjiewen
 * \contact: ranjiewen@outlook.com
 *
 */

//��Ŀ���ӣ�http://www.nowcoder.com/questionTerminal/243c12aea2e14de1a05fcbb412556853?difficulty=00100&orderByHotValue=0&pos=3

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int getNum(vector<string> data, int i, string &s)
{
	int num = 0;
	int j;
	for (j = 0; j < data[i].size(); j++)
	{
		char a = data[i][j];
		if (s.find(a) == string::npos)
		{
			s.push_back(a);
			if (i == data.size() - 1)
			{
				num++;
				s.pop_back();
			}
			else
			{
				num += getNum(data, i + 1, s);
				s.pop_back();
			}
		}
	}
	//s.pop_back();
	return num;
}

int main()
{
	vector<string> data;
	int n;
	while (cin >> n)
	{
		int i = 0;
		string s = "";  
		int num = 0;
		for (int j = 0; j < n; j++)
		{
			string tmp;
			cin >> tmp;
			data.push_back(tmp);
		}
		cout << getNum(data, i, s) << endl;
		data.clear();
	}
	return 0;
}


////*������ת��Ϊ��һ������n���ж���Ҷ�ӽڵ�����⣬����ʹ��DFS������ֻ��Ҫ�ж�����Щ��֧��n�㼴��*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int res;
vector<string> vc;  //��¼ÿ�ַ�������bug
string str = {};
void getNumDFS(vector<string>, vector<int>, int, int);
int main(){
	int n;
	while (cin >> n){
		res = 0;
		vector<int> visit = { 0, 0, 0, 0, 0, 0 };
		vector<string> data;
		for (int i = 0; i < n; i++){
			string tmp;
			cin >> tmp;
			data.push_back(tmp);
		}
		getNumDFS(data, visit, n, 0);
		cout << res << endl;
	}
	return 0;
}
void getNumDFS(vector<string> data, vector<int> visit, int n, int p){
	if (n == p){
		res++;
		vc.push_back(str);
		str.erase(0,n);
		return;
	}
	for (int i = 0; i < data[p].size(); i++){  //�ӵ�һ�㿪ʼ������ȡֵ
		if (visit[data[p][i] - '0'] == 0){
			visit[data[p][i] - '0'] = 1;
			char temp = data[p][i];
			str += temp;   // ����������
			getNumDFS(data, visit, n, p + 1);   //pΪ����������N�㣬ÿ��ȡֵ
			visit[data[p][i] - '0'] = 0;
		}
	}
	str.clear();
}



//��Ŀ���ӣ�http://www.nowcoder.com/questionTerminal/382b23292d4640cea476cfa7a137db51

//���������ħ���������У��հض��Լ��ı��ֶ������⡣
//Ϊ�˾�������ս�����հ����������������в��ҵ��˻���ʦ�����������ø���Ϊ�Լ����߽׻������ǡ�
//���������ĵȴ��Ժ󣬻���˳�����������ǣ��հغ����⣬���������һЩС�ѡ�
//�հظ�С������ԭ��ģ�
//1.���ո�������Ǯ������5�ı�����
//2.С�ѱ���ռ����֧�����õ�5%~10 % ֮�䣨�����߽磩��
//�����ܹ��ķ�Aħ�����հ����ϴ���Bħ�����հ���֪�����ж�����֧�������ɹ�ѡ��
//ע��ħ����һ�ֻ��ҵ�λ������֧������ = ����֧���� + С��

#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int A, B;
	while (cin >> A&&cin >> B){		
		////�ܷ��õķ�ΧΪ   A / 0.95 <= f <= A / 0.9
		int a = ceil(A / 0.95), b = floor(A / 0.9);
		int count = 0;
		while (a%5!=0&&a<b)
		{
			a++;
		}
		for (int i = a; i <= b&&i<=B;i=i+5)
		{
			count++;
		}
		cout << count << endl;
	}
	return 0;
}


#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int A, B, R;
	while (cin >> A&&cin >> B){
		////�ܷ��õķ�ΧΪ   A / 0.95 <= f <= A / 0.9
		int a = ceil(A / 0.95), b = floor(A / 0.9);
		//����һ
		R = 0;
		if (a <= B){
			if (b > B){      
				R = B / 5 - a / 5;
			}
			else{
				R = b / 5 - a / 5;
			}
			if (a % 5 == 0)   //�ﵽÿ��++5�Ĺ���
				R++;
		}
		cout << R << endl;
	}
	return 0;
}


#include<iostream>
#include<math.h>
using namespace std;
int main(){
	int A, B;
	while (cin >> A&&cin >> B){		
		//����������С�ѵĽǶȳ����أ��� ���ǳ�ʱ
		int start = A;
		int num = 0;
		while (start % 5 != 0 && start<B)
		{
			start++;
		}
		for (int i = start; i < B && ((start - A) <= start*0.1);i=i+5)
		{
			num++;
		}
		cout << num << endl;
	}
	return 0;
}

//��Ŀ���ӣ�http://www.nowcoder.com/questionTerminal/2fdc144e8b5e4a9c8035bf7359a062fd?orderByHotValue=1&pos=129
//ֻ��Ҫ��һ���������һ�� ���ù��ɶ���x*x+y*y = r*r ���ɽ���ķ�֮һԲ�ܵĵ� *4 ��Ϊ���

#include <iostream>
using namespace std;
#include <math.h>
int main()
{
	int S;
	while (cin>>S)
	{
		int num = 0;
		for (int i = 1; i*i <= S;i++)
		{
			int temp = S - i*i;
			int r = sqrt(temp);
			if (r*r==temp)
			{
				num++;
			}
		}
		cout << 4 * num << endl;
	}
}
