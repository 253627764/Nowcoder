
#include<memory.h>


//��Ŀ����
//
//������һ��m�к�n�еķ���һ�������˴�����0, 0�ĸ��ӿ�ʼ�ƶ���ÿһ��ֻ�������ң��ϣ����ĸ������ƶ�һ��
//���ǲ��ܽ�������������������λ֮�ʹ���k�ĸ��ӡ� ���磬��kΪ18ʱ���������ܹ����뷽��35, 37������Ϊ3 + 5 + 3 + 7 = 18��
//���ǣ������ܽ��뷽��35, 38������Ϊ3 + 5 + 3 + 8 = 19�����ʸû������ܹ��ﵽ���ٸ����ӣ�

//˼·
//���ѻ����⣬��0��ʼ�����ĸ�����ݹ���⼴��
class Solution {
public:
	int movingCount(int threshold, int rows, int cols)
	{
		bool *vis = new bool[rows*cols];
		memset(vis,false,rows*cols);
		int result = movingCountCore(threshold,rows,cols,0,0,vis);
		delete[]vis;
		return result;
	}
	int movingCountCore(int threshold,int rows,int cols,int x,int y,bool *vis)
	{
		int count = 0;
		if (x >= 0 && x<rows && y >= 0 && y<cols && getSum(x) + getSum(y) <= threshold && !vis[x*cols + y])
		{
			vis[x*cols + y] = true;
			count = 1 + movingCountCore(threshold, rows, cols, x - 1, y, vis)
				+ movingCountCore(threshold, rows, cols, x + 1, y, vis)
				+ movingCountCore(threshold, rows, cols, x, y - 1, vis)
				+ movingCountCore(threshold, rows, cols, x, y + 1, vis);
		}
		return count;
	}
	int getSum(int num)
	{
		int sum = 0;
		while (num)
		{
			sum += num % 10;//��ȡ��λ
			num /= 10;//�ӵ͵���λ
		}
		return sum;
	}
};

