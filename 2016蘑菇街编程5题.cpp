
//������һ�Ű뾶Ϊr��Բ����������λ��(x, y)�����������Բ���������Ƶ�(x1, y1)��ÿ���ƶ�һ������������Բ����Ե�̶�һ����Ȼ��Բ�����������ת����������Ҫ�ƶ�������
//
//�������� :
//һ���������r, x, y, x1, y1(1��r��100000, -100000��x, y, x1, y1��100000)
//
//
//������� :
//	 ���һ����������ʾ��


#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	long long r, x, y, x1, y1;  //��������
	while (cin >> r >> x >> y >> x1 >> y1)  //��β���
	{
		long d = sqrt((x - x1)*(x - x1) + (y - y1)*(y - y1));
		long result = (d % (2 * r) == 0) ? (d / (2 * r)) : (d / (2 * r) + 1);
		cout << result << endl;
	}

	return 0;
}



//����һ���������У�a1 <a2 <...<an ������������е������Ϊd = max{ ai + 1 - ai }(1��i<n), ����Ҫ��a2, a3 ..an - 1 ��ɾ��һ��Ԫ�ء�
//��ʣ�����е��������С�Ƕ��٣�
//
//�������� :
//��һ�У�һ��������n(1 <= n <= 100), ���г���; ������n��С��1000������������ʾһ���������С�
//
//
//������� :
//����𰸡�

/*************************�������İ�******************************/
#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int getMaxInterval(vector<int> ans)
{
	int result = 0;
	for (int i = 0; i < ans.size() - 1; i++)
	{
		if (ans[i + 1] - ans[i]>result)
		{
			result = ans[i + 1] - ans[i];
		}
	}
	return result;
}

int main()
{
	int n;
	vector<int> input, mid;
	while (cin >> n)
	{
		for (int i = 0; i < n; i++)
		{
			int temp = 0;
			cin >> temp;
			input.push_back(temp);
		}
		/*mid = input;       //�Լ�д���д�
		for (auto it = input.begin() + 1; it != input.end() - 1; it++)
		{
		input.erase(it);
		if (reuslt>getMaxInterval(input))
		{
		reuslt = getMaxInterval(input);
		}
		else
		reuslt = (getMaxInterval(input));
		input = mid;
		}*/
		/*	int min = INT_MAX;    //�ο����˵�
		for (int i = 1; i < input.size() - 1; ++i)
		{
		vector<int> tmp = input;//��������ʱ����
		tmp.erase(tmp.begin() + i);
		if (getMaxInterval(tmp) < min)
		min = getMaxInterval(tmp);
		}
		*/

		//��¼����Ԫ�صļ��ֵ�����ֵ�����ֵ
		vector<int> temp;
		int maxd = 0;
		for (int i = 1; i <= input.size() - 1; i++)
		{
			temp.push_back(input[i] - input[i - 1]);
			maxd = (input[i] - input[i - 1])>maxd ? (input[i] - input[i - 1]) : maxd;
		}
		//���ڼ��ֵ�ϲ����ҳ���С�������
		//��ɾ��Ԫ����ԭ����������������Ԫ��ʱ����������󣬵�������λ��ʱ��
		//�����������䣬����λ�õļ������
		int result = 10000;
		for (int i = 1; i <= temp.size() - 1; i++)
		{
			int d = temp[i] + temp[i - 1];
			if (d > maxd)
			{
				//�����������������С�ģ�ֻ�е�ɾ��ÿ��Ԫ�ض�Ӧ�ļ��������maxd�����������Сֵ��������
				if (d<result)   //vs����ô��仰��ִ�а�������
				{
					result = d;
				}
				//   result = min(d,result);  //������������Сֵ
			}
			else     //������һ�������maxdС�������ǵ����������maxd;�����м��ֵ��maxdСʱ�����������Сֵ����maxd
			{
				result = maxd;
			}
		}
		cout << result << endl;
	}
	return 0;
}

/*********************************************************/


//A��B�Ǻ��ѣ����Ǿ����ڿ���ʱ�����죬A�Ŀ���ʱ��Ϊ[a1, b1], [a2, b2]..[ap, bp]��
//B�Ŀ���ʱ����[c1 + t, d1 + t]..[cq + t, dq + t], ����tΪB����ʱ�䡣��Щʱ������˱߽�㡣B����ʱ��Ϊ[l, r]��һ��ʱ�̡�
//��һ����ʱ����ʹ����������ʱ�����죬��ô���ʱ����Ǻ��ʵģ����ж��ٸ����ʵ���ʱ�䣿
//
//�������� :
//��һ�������ĸ�������p,q,l,r��1��p,q��50,0��l��r��1000)��������p������ÿһ����һ������ai��bi(0��ai<bi��1000)��ʾa��ʱ���
//������p��ÿ��һ������ci��di(0��ci,di��1000)��ʾb��ʱ�����֤ai+1>bi,ci+1>di
//
//������� :
//����𰸸���

//����˼·��
//
//СĢ��ʱ�����Ϊ[a��b]��С����ʱ�������[c + t��d + t]��С���𴲵�ʱ����t��[l��r]
//��ô��"a < b < (c+t) < (d+t)"����"(c+t) < (d+t) < a < b"�����ʱ��СĢ��С���޷����죬����Ŀ������֪"a < b"��"c < d"����ô�Ƴ�"(c+t) < (d+t)"
//���Խ�����"b < (c+t)"����"(d+t) < a"ʱ�޷����죬����������ǿ��������
/**********************************************************************/
#include<iostream>
using namespace std;
#include<vector>
int p, q, l, r;
bool isAdapter(int t,vector<vector<int>> m,vector<vector<int> > n)
{
	int count = 0;
	for (int i = 0; i < p; i++)
	{
		for (int j = 0; j < q; j++)
		{
			if (!(m[i][1] + t)<n[j][0] || !(n[j][2] + t)<m[i][0])
			{
				return true;
			}
		}
	}
	return false;
}
int main()
{
	while (cin>>p>>q>>l>>r)
	{	
		int temp=0;
		vector<vector<int>> m(p,vector<int>(2)), n(q,vector<int>(2));
		for (int i = 0; i < p; i++)  //������Ч��
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> temp;
				m[i][j] = temp;
			}
		}
		for (int i = 0; i < q; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				cin >> temp;
				n[i][j] = temp;
			}
		}
		int count = 0;
		for (int t = l; t <= r; t++)
		{
			if (isAdapter(t, m, n))
				count++;
		}
		cout << count << endl;
	}
	return 0;
}

/************************************************************************************/

//��һ��Ͷ����Ϸ������p������    ���Ϊ0��1...��p - 1   ��ÿ���������и����ӣ�ÿ���������װһ������
//��n������ÿ������xi �������ǽ�����Ϊxi ������Ͷ��xi ��p������Ϊ��ŵĴ�������������������򵯳���Ϸ����  ���i  �������ظ���������Ͷ�ꡣ
//��� - 1������Ϸ���յ������ʲô��
//��������:
//��һ����������p, n��2��p, n��300)��pΪ��������nΪ������������n��Ϊ�����ϵ�����xi(0��xi��1e9)
//�������:
//�����Ϸ�Ľ��
//�������� :
//10 5
//0
//21
//53
//41
//53
//�������:
//4
/*********************************************************/
#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int p, n;
	while (cin>>p>>n)
	{
		vector<long long> bNumber(n,0);  //bNumber(n,0) ����push_back()��ӵ������ʼ�ۼӣ�ǰ��5��Ϊ0��Ȼ����push����
		vector<bool> pNumber(p, false);
		long long temp = 0;
		for (int i = 0; i < n; i++)
		{
			//cin >> temp;
			//bNumber.push_back(temp);
			cin >> bNumber[i];   //�������Ա���ӵ�����ۼӣ�ȷ�����±�
		}
		bool complete = true;
		for (size_t i = 0; i < bNumber.size(); i++)
		{
			if (pNumber[bNumber[i] % p] == false)
			{
				pNumber[bNumber[i] % p] =true;
				//continue;
			}
			else if (pNumber[bNumber[i] % p] == true)
			{
				complete = false;
				cout<< i+1<<endl;
				break;
			}
		}
		if (complete)  //������
		{
			cout << -1 << endl;
		}
	}
	return 0;
}

/*********************************************************/


//����һ���ַ��������Ƿ���ͨ�����һ����ĸ�����Ϊ���Ĵ���
//��������:
//
//һ��һ����Сд��ĸ���ɵ��ַ������ַ�������С�ڵ���10��
//������� :
//
//�����(YES\NO).

//1.��Ȼ��ͨ������һ���ַ���ɻ��Ĵ�����һ��Ҳ����ͨ��ɾ��һ���ַ���ɻ��Ĵ�����һ��ѭ����ÿ��ѭ������ɾ��һ���ַ���Ȼ�����´��Ƿ��ǻ��Ĵ����������򵥷�����ࡣ
//2.������������λ�����a-z,�����ж��Ƿ�������Ĵ�
//3.��������ָ�룬һ����ͷ���һ����β��ǰ�����һ���ͼ����������һ���ͳ�������һ�������һ���ͼ�����ֱ��ָ������
//4.ת�������˼�벻���ж�ԭ�ַ����ͷ�ת�ַ���������������г����Ƿ��ԭ�ַ�������С1�����
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool isPalindrome(string str)
{
	string temp = str;
	reverse(str.begin(),str.end());
	return str == temp;
}

int main()
{
	string str;
	while (cin>>str)
	{
		if (str.size()<=0||str.size()==1)
		{
			cout << "YES" << endl;
		}
		else
		{
			bool temp = true;
			for (size_t i = 0; i < str.size(); i++)
			{
				string strTemp = str;
				strTemp.erase(strTemp.begin() + i);   //  tmp = str.substr(0, i) + str.substr(i + 1);  
				if (isPalindrome(strTemp))
				{
					cout << "YES" << endl;
					temp = false;
					break;
				}
			}
			if (temp)
			{
				cout << "NO" << endl;
			}
		}
	}
	return 0;
}