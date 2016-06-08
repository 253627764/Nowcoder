//��ķ�տ�ʼѧϰӢ�ĵ��ʣ��Ե�������ܸ���Ȥ��
//�������ķһ�鵥�ʣ����ܹ�Ѹ��ȷ���Ƿ���Խ���Щ����������һ���б��У�ʹ�ø��б����κε��ʵ�����ĸ��ǰһ���ʵ�Ϊ��ĸ��ͬ��
//���ܱ�дһ��������������ķ�����ж���
//
//�������� :
//
//�����������������ݡ�
//
//����ÿ��������ݣ���һ��Ϊһ��������n��������n�����ʡ�
//
//Ȼ����n���ַ���������n�����ʡ�
//
//��֤��
//
//2 <= n <= 200, ÿ�����ʳ��ȴ���1��С�ڵ���10, �����е��ʶ�����Сд��ĸ��ɡ�
//
//
//
//
//������� :
//����ÿ�����ݣ����"Yes"��"No"
//
//�������� :
//	 3
//	 abc
//	 cdefg
//	 ghijkl
//	 4
//	 abc
//	 cdef
//	 fghijk
//	 xyz
//
//
// ������� :
//Yes
//No


#include <iostream>
using namespace std;
#include <vector>
#include <string>

int main()
{
	int n;
	while (cin>>n)
	{
		vector<string> vc(n);
		for (int i = 0; i < n;i++)
		{
			cin >> vc[i];
		}
		bool flag = true;
		for (int i = 0; i < n-1;i++)   //���Ϊbool�ĺ���
		{
			int size = vc[i].size();
			if (vc[i][size-1]==vc[i+1][0])
			{
				continue;
			}
			else{
				flag = false;			
				break;
			}
			
		}
		if (flag)
		{
			cout << "Yes" << endl;
		}
		else
		{
			cout << "No" << endl;
		}
	}
	return 0;
}


//ҳ������㷨
//�ڼ�����У�ҳʽ����洢��ʵ�ֵ�һ���ѵ������ҳ����ȣ��û����㷨������һ��ʵ�ַ�ʽ��FIFO�㷨��
//FIFO�㷨����ҳ������ڴ��ʱ���Ⱥ�ѡ����̭ҳ�棬�Ƚ����ڴ��ҳ������̭��������ڴ�ĺ���̭��
//����Cache�Ĵ�СΪ2, ��5��ҳ�����󣬷ֱ�Ϊ 2 1 2 3 1����Cache��״̬ת��Ϊ��(2)->(2, 1)->(2, 1)->(1, 3)->(1, 3)�����е�1, 2, 4��ȱҳ����ȱҳ����Ϊ3��
//���ڸ���Cache�Ĵ�Сn��m��ҳ�����������ȱҳ����
//
//
//�������� :
//
//�����������������ݡ�
//
//����ÿ��������ݣ���һ����������n, m��
//
//Ȼ����m����������������ҳ��š�
//
//��֤��
//
//2 <= n <= 20, 1 <= m <= 100��1 <= ҳ��� <= 200.
//
//
//
//
//�������:
//����ÿ�����ݣ����һ������������ȱҳ��
//
//�������� :
//2 5
//2 1 2 3 1
//
//
//������� :
//	 3

#include <iostream>
using namespace std;
#include<vector>

int main()
{
	int n, m;
	while (cin>>n>>m)
	{
		int times = 0;
		vector<int> vc;  //Cache�Ĵ�Сn ,���������m��ҳ������m>n�Ų���ҳ���û�
		if (m<=n)
		{
			for (int i = 0; i < m; i++)  //m������
			{
				bool flag = false;
				int temp;
				cin >> temp;
				for (int j = 0; j < vc.size(); j++)
				{
					if (vc[j] == temp)  //����ͬ��ҳ��
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					vc.push_back(temp);
					times++;
				}
			}
		}
		else
		{
			for (int i = 0; i < n; i++)  //ǰn������
			{
				bool flag = false;
				int temp;
				cin >> temp;
				for (int j = 0; j < vc.size(); j++)
				{
					if (vc[j] == temp)  //����ͬ��ҳ��
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					vc.push_back(temp);
					times++;
				}
			}
			for (int i = n; i < m; i++)  //m������
			{
				bool flag = false;
				int temp;
				cin >> temp;
				for (int j = 0; j < n; j++)     //�ܷ��ҵ����Ϊbool�ĺ�����find()��������Ϊiterator�������Զ��庯����
				{
					if (vc[j] == temp)  //����ͬ��ҳ��
					{
						flag = true;
						break;
					}
				}
				if (!flag)
				{
					if (vc.size()==n)  //���bug���˺ܾã�����ǰ�����ظ��ģ�������û��װ��n����
					{
						vc.erase(vc.begin());
					}
					vc.push_back(temp);
					times++;
				}
			}
		}
		cout << times << endl;
	}
	return 0;
}


//�Ż���һЩ
#include <iostream>
#include <vector>

bool vecfind(std::vector<int>& vec, int num) {
	int len = vec.size();
	for (int i = 0; i < len; ++i){
		if (num == vec[i])
			return true;
	}
	return false;
}

int main() {
	int n, m;
	while (std::cin >> n >> m) {
		std::vector<int> vecCache;
		std::vector<int> vecPage(m);
		int cnt = 0;
		for (int i = 0; i < m; ++i) {
			std::cin >> vecPage[i];
		}
		for (int i = 0; i < m; ++i) {
			if (vecfind(vecCache, vecPage[i])) {
				continue;
			}
			else {
				if (vecCache.size() < n) {
					vecCache.push_back(vecPage[i]);
				}
				else{
					vecCache.erase(vecCache.begin());
					vecCache.push_back(vecPage[i]);
				}
				++cnt;
			}
		}

		std::cout << cnt << std::endl;
	}
	return 0;
}



//���̵����㷨
//����ҵ���ȣ�SJF, Shortest Job First���ֳ�Ϊ���̽������ȡ�SPN(Shortest Process Next)���Ƕ�FCFS�㷨�ĸĽ�����Ŀ���Ǽ���ƽ����תʱ�䡣
//����ҵ���ȵ����㷨��������һ��˼�룺
//����ʱ��̵����ȵ��ȣ�
//�������ʱ����ͬ��������ȷ�������Ľ��̡�
//�ȴ�ʱ�䣺һ�����̴ӷ������󵽿�ʼִ�е�ʱ������
//������n����������cpu��ÿ��������һ����Ԫ���ʾ��(p, q), p����ý��̷��������ʱ�䣬p������Ҫռ��cpu��ʱ�䡣
//�����n�����̵�ƽ���ȴ�ʱ�䡣
//
//
//�������� :
//
//
//�����������������ݡ�
//
//����ÿ��������ݣ���һ��Ϊһ������n��
//
//Ȼ����n�У�ÿ���������������������Ķ�Ԫ��(p, q).
//
//��֤:
//
//2 <= n <= 2000, 1 <= p <= 300, 1 <= q <= 100.
//
//
//
//
//������� :
//
//	 ����ÿ�����ݣ����һ��������������ƽ���ȴ�ʱ�䣬�뱣��4λ��Ч����
//
// �������� :
//
//4
//1 4
//1 3
//1 5
//2 1
//
//
//�������:
//
//5.2500


//�����д���Ŀ�У����ȵ����ȼ���
//1)����ʱ��̵����ȵ��ȣ�
//2)�������ʱ����ͬ��������ȷ�������Ľ��̡�
//Ӧ�������Ϊ����1����������2��
//�����������ݣ���ʱ���1��CPU�ӵ�������ֱ�Ϊ 1 3, 1 4, 1 5, ��ôӦ��������1 3, ��ʱʱ��Ϊ4(��������ռʽ���ȵĻ���, �Ѿ��ӵ��˵�������2 1��������Ӧ������2 1, ���õ��Ľ��Ӧ����3.5.
//��Ҫ�õ�5.25�Ľ����������1 3 ��Ӧ������ 1 4, ������� 1 5, ��� 2 1���Ǵ�ʱ���ȼ�����Ӧ��Ϊ��
//1)�ӵ������ʱ�䣻
//2) �������ʱ����ͬ����� ����ʱ����̵�����


//�ο���http://www.nowcoder.com/questionTerminal/6286bfa395c44b449031254d1ebd2a53
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;
const int maxn = 2010;

struct Node {
	int id, p, q;
	Node() { }
	Node(int _id, int _p, int _q) : id(_id), p(_p), q(_q) { }
	bool operator < (const Node &nd) const {
		if (q == nd.q) return p > nd.p;
		return q > nd.q;
	}
};
Node arr[maxn];
priority_queue<Node> pq;
bool mark[maxn];

int main() {

	//freopen("aa.in", "r", stdin);
	int n;
	double total = 0.0;
	int curt;
	int mins;
	int cnt;
	int lef;
	Node tmp;
	while (scanf("%d", &n) != EOF) {
		mins = 1010;
		for (int i = 0; i < n; ++i) {
			arr[i].id = i;
			scanf("%d %d", &arr[i].p, &arr[i].q);
			mins = min(mins, arr[i].p);
		}
		lef = n;
		cnt = 0;
		total = 0.0;
		curt = mins;
		memset(mark, false, sizeof(mark));
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < n; ++i) {
			if (arr[i].p == mins) {
				lef--;
				pq.push(arr[i]);
				mark[i] = true;
			}
		}
		while (cnt < n) {
			if (!pq.empty()) {
				tmp = pq.top(); pq.pop();
				cnt++;
				total += (curt - tmp.p);
				curt += tmp.q;
			}
			else {
				curt++;
			}
			if (lef > 0) {
				for (int i = 0; i < n; ++i) {
					if (mark[i]) continue;
					if (curt >= arr[i].p) { pq.push(arr[i]); lef--; mark[i] = true; }
				}
			}
		}
		printf("%.4f\n", total * 1.0 / n);
	}
	return 0;
}

typedef struct pro {
	int PRO_ID;
	int arrive_time;
	int sum_time;
	int flag;
}Pro;