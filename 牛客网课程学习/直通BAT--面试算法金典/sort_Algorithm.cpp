
//����һ��int���飬���дһ��ѡ��ð���㷨��������Ԫ������
//����һ��int����A������Ĵ�Сn���뷵�����������顣
//����������
//[1, 2, 3, 5, 2, 3], 6
//[1, 2, 2, 3, 3, 5]


#include <iostream> 
using namespace std;
#include<string>



void printResult(string str,int* A,int n)
{
	cout << str << "�Ľ��:\n";
	for (int i = 0; i < n; i++)
	{
		cout << A[i] <<" ";
	}
	cout << endl;
}

void swap(int a, int b)
{
	int temp=a;
	a = b;
	b = a;
}

class BubbleSort {
public:
	int* bubbleSort(int* A, int n) {
		// write code here
		for (int i = 0; i<n; i++)
		{
			for (int j = 0; j<n - i - 1; j++)
			{
				if (A[j]>A[j + 1])
				{
					int temp = A[j];
					A[j] = A[j + 1];
					A[j + 1] = temp;
				}
			}
		}
		return A;
	}
};


//���дһ��ѡ�������㷨
class SelectionSort {
public:
	int* selectionSort(int* A, int n) {
		// write code here
		int k = 0;
		for (int i = 0; i < n-1; i++)
		{
			k = i;
			for (int j = i; j < n; j++)
			{
				if (A[k]>A[j])
				{
					k = j;
				}
			}
			if (k!=i)
			{
				int temp = A[i];
				A[i] = A[k];
				A[k] = temp;
			}
		}
		return A;
	}
};

//���дһ��ѡ������㷨

class InsertionSort
{
public:
	int* insertionSort(int* A, int n)
	{
		for (int i = 1; i < n; i++)
		{
			int temp = A[i];
			int j = i - 1;
			for (; j >= 0;j--)   //jǰ����Ѿ��ź��򣬴Ӻ�����ǰ�Ƚϣ���û�бȵ�ǰֵ���ʱ��bereak;
			{
				if (A[j]>temp)
				{
					A[j + 1] = A[j];
				}
				else
				{
					break;
				}
			}
			A[j + 1] = temp;
		}
		return A;
	}
};


int main()
{

	int N = 0;
	cout << "�������ݸ�����\n";
	cin >> N;
	int* A = new int[N];
	cout << "���������������ݣ�\n";
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	BubbleSort bubble;
	bubble.bubbleSort(A,N);
	printResult("bubbleSort", A, N);

	SelectionSort select;
	select.selectionSort(A, N);
	printResult("selectSort", A, N);

	InsertionSort insert;
	insert.insertionSort(A, N);
	printResult("InsetSort", A, N);


	return 0;
}