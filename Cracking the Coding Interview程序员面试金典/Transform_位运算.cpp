//��Ŀ����
//
//��дһ��������ȷ����Ҫ�ı伸��λ�����ܽ�����Aת�������B��
//������������int A��int B���뷵����Ҫ�ı����λ������
//����������
//10, 5
//���أ�4


//˼·��A ��Ҫ�任 ����λ ���ܵõ�B��λ�任�޷Ǿ���0 - 1, 1 - 0�Ĺ������ԣ�A��B֮�� �ж��ٵĲ�ͬ��0 - 1, 1 - 0�ı任������Ҫ����λ�ı任��
//������������ ��ͬΪ0 ��ͬΪ1 Ҳ��1 - 0, 0 - 1�Ľ��Ϊ1��Ҳ����ת����A^B֮�� 1 �ĸ�����⣻--->����ת��

class Transform {
public:
	int calcCost(int A, int B) {
		// write code here
		int res = A ^ B;
		int count = 0;
		while (res != 0)
		{
			if ((res & 1) != 0)
			{
				count++;
			}
			res >>= 1;
		}
		return count;
	}

	int calcCost(int A, int B) {
		// write code here
		int res = A ^ B;
		int count = 0;
		while (res != 0)
		{
			count++;
			//ȥ�����һλ��1 ���� 1111 & ��1111-1�� = 1110 �����һλ1 ȥ��
			res &= (res - 1);
		}
		return count;
	}
};