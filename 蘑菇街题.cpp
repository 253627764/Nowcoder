//������һ�Ű뾶Ϊr��Բ����������λ��(x, y)�����������Բ���������Ƶ�(x1, y1)��ÿ���ƶ�һ������������Բ����Ե�̶�һ����Ȼ��Բ�����������ת����������Ҫ�ƶ�������
//
//�������� :
//һ���������r, x, y, x1, y1(1��r��100000, -100000��x, y, x1, y1��100000)
//
//
//������� :
//	 ���һ����������ʾ��

/**************************************************

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

**************************************************/


//����һ���������У�a1 <a2 <...<an ������������е������Ϊd = max{ ai + 1 - ai }(1��i<n), ����Ҫ��a2, a3 ..an - 1 ��ɾ��һ��Ԫ�ء�
//��ʣ�����е��������С�Ƕ��٣�
//
//�������� :
//��һ�У�һ��������n(1 <= n <= 100), ���г���; ������n��С��1000������������ʾһ���������С�
//
//
//������� :
//����𰸡�
/*

*/

#include<iostream>
using namespace std;
#include<vector>

int getMaxInterval(vector<int> ans)
{
	int result = 0;
	for (int i = 0; i < ans.size()-1; i++)
	{
		if (ans[i+1]-ans[i]>result)
		{
			result = ans[i + 1] - ans[i];
		}
	}
	return result;
}

int main()
{
	int n;
	vector<int> input,mid;
	while (cin>>n)
	{
		int reuslt=0;
		for (int i = 0; i < n; i++)
		{
			int temp=0;
			cin >> temp;
			input.push_back(temp);
		}
		mid = input;
		for (auto it = input.begin()+1; it != input.end()-1; it++)
		{
			input.erase(it);				
			if (reuslt>getMaxInterval(input))
			{
				reuslt = getMaxInterval(input);
			}
			else
			reuslt = (getMaxInterval(input));
			input = mid;
		}
	}
	return 0;
}