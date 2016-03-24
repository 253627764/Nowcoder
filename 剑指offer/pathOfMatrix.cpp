
#include<memory.h>

//��Ŀ����
//
//�����һ�������������ж���һ���������Ƿ����һ������ĳ�ַ��������ַ���·����
//·�����ԴӾ����е�����һ�����ӿ�ʼ��ÿһ�������ھ������������ң����ϣ������ƶ�һ�����ӡ�
//���һ��·�������˾����е�ĳһ�����ӣ����·�������ٽ���ø��ӡ� 
//���� a b c e s f c s a d e e �����а���һ���ַ���"bcced"��·�������Ǿ����в�����"abcb"·����
//��Ϊ�ַ����ĵ�һ���ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���ø��ӡ�

//˼·
//���ѵĻ������ͣ��ֱ���ÿ������Ϊ��㣬���ĸ�����ȥ������ֱ���ҵ�����������ַ�������
class Solution {
public:
	bool hasPath(char* matrix, int rows, int cols, char* str)
	{
		if (matrix==nullptr||str==nullptr||rows<1||cols<1)
		{
			return false;
		}
		//����һ��������飬�߹���λ��Ϊtrue��û�߹���Ϊfalse
		bool *vis = new bool[rows*cols];
		memset(vis,false,rows*cols);
		int pathLength = 0;
		for (size_t i = 0; i < rows; i++)
		{
			for (size_t j = 0; j < cols; j++)
			{
				if (hasPathCore(matrix,rows,cols,i,j,str,pathLength,vis))
				{
					return true;
				}
			}
		}
		delete[]vis;
		return false;
	}
	//�жϴ�һ��Ԫ�س����Ƿ����ҵ�һ��·��
	bool hasPathCore(char *matrix,int rows,int cols,int x,int y,char *str,int pathLength,bool *vis)
	{
		if (str[pathLength]=='\0')//Ƕ�׵��ó���
		{
			return true;
		}
		bool hasPath = false;//��������ֵ
		if (x>=0&&x<=rows&&y>=0&&y<=cols&&matrix[x*cols+y]==str[pathLength]&&!vis[x*cols+y])//���귶Χ�жϣ�x=0��ʼ������x*cols+y������ȷ
		{
			++pathLength;
			vis[x*cols + y] = true;
			hasPath = hasPathCore(matrix, rows, cols, x - 1, y, str, pathLength, vis)
				|| hasPathCore(matrix, rows, cols, x + 1, y, str, pathLength, vis)
				|| hasPathCore(matrix, rows, cols, x, y - 1, str, pathLength, vis)
				|| hasPathCore(matrix, rows, cols, x, y + 1, str, pathLength, vis);
			if (!hasPath) //û��·��ʱ�����ص�ԭ��λ��
			{
				--pathLength;
				vis[x*cols + y] = false;
			}		
		}
		return hasPath;
	}
	


};