//��Ŀ����
//
//��һ����NxN�����ʾ��ͼ������ÿ��������һ��int��ʾ�����дһ���㷨���ڲ�ռ�ö����ڴ�ռ�������(����ʹ�û������)��
//��ͼ��˳ʱ����ת90�ȡ�
//����һ��NxN�ľ��󣬺;���Ľ���N, �뷵����ת���NxN����, ��֤NС�ڵ���500��ͼ��Ԫ��С�ڵ���256��
//����������
//[[1, 2, 3], [4, 5, 6], [7, 8, 9]], 3
//���أ�[[7, 4, 1], [8, 5, 2], [9, 6, 3]]

#include<iostream>
using namespace std;
#include<vector>
class Transform {
public:
	vector<vector<int> > transformImage(vector<vector<int> > mat, int n) {
		// write code here
		//ת�õ�ʵ��
		/*for (size_t i = 0; i < mat.size(); i++)
		{
			for (size_t j = 0; j < n; j++)
			{
				int temp = mat[i][j];
				mat[i][j] = mat[j][i];
				mat[j][i] = temp;
			}
		}*/


		/* ˼·�������ת����������ڣ�����layer��ʾ��ǰ������Ĳ㣬ÿ�ζ���n*n�����п����γɷ����е��ĸ���������ת��
		         ��->�ϣ���->����->�£���->�ҵ�˳���ڵ�һ��֮ǰ�ȴ洢���ϡ��е�ֵ*/
		//for (int layer = 0; layer < n / 2; layer++){   
		//	int first = layer;
		//	int last = n - 1 - layer;
		//	for (int i = first; i < last; i++){    //ÿ���ڲ������ݱ任����
		//		int offset = i - first;
		//		int top = mat[first][i];
		//		//left -> top
		//		mat[first][i] = mat[last - offset][first];
		//		//bottom -> left
		//		mat[last - offset][first] = mat[last][last - offset];
		//		//right -> bottom
		//		mat[last][last - offset] = mat[i][last];
		//		//top -> right
		//		mat[i][last] = top;
		//	}
		//}

		
		/*˼·��������һ��
			�Ѿ������һ����У�һȦ����һȦ����һȦÿһ���߱���һȦÿһ���߳��ȶ�2��ÿһ����ֻ�б߳��� - 1��Ԫ����Ҫ������һ���ߵĶ�ӦԪ�أ�
			��Ϊÿһ�����������������ཻ��һ���ߵ�һ��Ԫ����ת90����ʵ���ǵ�����һ���ߵ����һ��Ԫ�أ�Ҳ�����ڱߵĵ�һ��Ԫ�ء�*/
		/*int temp;
		for (int i = 0; i<n / 2; i++){   //�ֲ�
			for (int j = i; j<n - 1 - i; j++){
				temp = mat[i][j];
				mat[i][j] = mat[n - j - 1][i];
				mat[n - j - 1][i] = mat[n - i - 1][n - j - 1];
				mat[n - i - 1][n - j - 1] = mat[j][n - i - 1];
				mat[j][n - i - 1] = temp;
			}
		}*/
		
		//���б任���ڴζԽ��߶Գƽ���   ���� �ȴζԽ��߽��������б任
		int i, j, temp = 0;
		//�����н���
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n / 2; j++) 
			{
				temp = mat[i][j];
				mat[i][j] = mat[i][n - 1 - j];
				mat[i][n - 1 - j] = temp;
			}
		}
		//ÿ���Խ��߶Գƽ���
		for (i = 0; i<n; i++)
		{
			for (j = 0; j<n - i; j++)
			{
				temp = mat[i][j];
				mat[i][j] = mat[n - 1 - j][n - 1 - i];
				mat[n - 1 - j][n - 1 - i] = temp;
			}
		}
		return mat;
	}
};