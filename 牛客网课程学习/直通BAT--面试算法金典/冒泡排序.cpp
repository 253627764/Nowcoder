// ����һ��int���飬���дһ��ð�������㷨��������Ԫ������

// ����һ��int����A������Ĵ�Сn���뷵�����������顣 

// ����������
// [1,2,3,5,2,3],6
// [1,2,2,3,3,5]


class BubbleSort {
public:
    int* bubbleSort(int* A, int n) {
        // write code here
        for(int i=0;i<n;i++)
            {
            for(int j=0;j<n-i-1;j++)
                {
                if(A[j]>A[j+1])
                    {
                    int temp=A[j];
                    A[j]=A[j+1];
                    A[j+1]=temp;
                }
            }
        }
        return A;
    }
};