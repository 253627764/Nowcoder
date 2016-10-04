
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
void swap(int *a, int *b)
{
	int temp=*a;
	*a = *b;
	*b = temp;
}

//ð������ O(n^2) 
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

//���дһ��ѡ�������㷨 O(n^2) 
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

//���дһ�������㷨 O(n^2) 
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

//�鲢���� O(N*log(N))
class MergeSort {
public:
	int* mergeSort(int* A, int n) {
		// write code here
		mergeSort(A, 0, n - 1);
		return A;
	}
	void mergeSort(int* A, int beg, int end)
	{
		if (beg < end)
		{
			int mid = beg + (end - beg) / 2;
			mergeSort(A, beg, mid);
			mergeSort(A, mid + 1, end);
			merge(A,beg,mid,end);
		}
		return;
	}
	void merge(int* A, int beg_, int mid_, int end_)
	{
		int *B = new int[end_ - beg_ + 1];
		int index1 = beg_;
		int index2 = mid_ + 1;
		int i = 0;
		while (index1<=mid_&&index2<=end_)
		{
			if (A[index1]<=A[index2])
			{
				B[i++] = A[index1++];
			}
			else
			{
				B[i++] = A[index2++];
			}
		}
		while (index1 <= mid_)
		{
			B[i++] = A[index1++];
		}
		while (index2<=end_)
		{
			B[i++] = A[index2++];
		}
		//memcpy(A,B,end_-beg_+1);
		for (int i = 0; i < end_ - beg_ + 1;i++)
		{
			A[beg_+i] = B[i];   //A[beg_++] ����д���ı����������
		}
		delete[] B;
	}
};

//�������� O(N*log(N))
#include <math.h>
class QuickSort {
public:
	int* quickSort(int* A, int n) {
		// write code here
		quickSort(A, 0, n - 1);
		return A;
	}
	void quickSort(int* A, int low, int high)
	{
		if (low <= high)
		{
			int part = partition(A, low, high);
			quickSort(A, low, part - 1);
			quickSort(A, part + 1, high);
		}
		return;
	}

	int partition(int* A, int low, int high)
	{
		int privotKey = A[low];	//��׼Ԫ��
		while (low < high)
		{	    //�ӱ�����˽�������м�ɨ��
			while (low < high  && A[high] >= privotKey) 
				--high;  //��high ��ָλ����ǰ���������ൽlow+1 λ�á����Ȼ�׼Ԫ��С�Ľ������Ͷ�
			swap(&A[low], &A[high]);
			while (low < high  && A[low] <= privotKey) 
				++low;
			swap(&A[low], &A[high]);
		}
		return low;
	}
};
class QuickSort2 {
public:
	int* quickSort(int* A, int n) {
		// write code here
		quickSort(A, 0, n - 1);
		return A;
	}
	void quickSort(int* A, int low, int high)
	{
		if (low <= high)
		{
			int randn = low + rand() % (high - low + 1);  //���ѡ��ؼ��ֵ��±�
			swap(&A[randn], &A[high]);                      //void swap(int* A,int index1,int index2) //��ö������±�

			int part = partition(A, low, high);
			quickSort(A, low, part - 1);
			quickSort(A, part + 1, high);
		}
		return;
	}

	int partition(int* A, int low, int high) //O(N)
	{
		//int pivot = A[low];//�ܶ����ѡ����������棬��������ֵ����ʽȷ���������±���Ϊ�ؼ���
		
		int pivot = low-1; //�ؼ��ֵ�λ��
		for (int i = low ; i <= high; i++)
		{
			if (A[i] <= A[high])
			{
				swap(&A[i], &A[++pivot]);  //�о��������A����ǰ���ֵ���ǣ�-->��ʵû�н�����Ч�����ǰ�ǰ��Ľ���������
			}
		}
		return pivot;
	}
};

//������  O(N*log(N))
class HeapSort {
public:
	int* heapSort(int* A, int n) {
		// write code here
		buildHeap(A, n); //��ʼʱ������
		//�����һ��Ԫ�ؿ�ʼ�����н��е���
		for (int i = n - 1; i >= 0;i--)
		{
			swap(&A[0], &A[i]);
			heapAdjust(A,0,i);
		}
		return A;
	}

	void buildHeap(int* A, int size_A)
	{
		for (int i = (size_A)/ 2-1; i >= 0; i--)
		{
			heapAdjust(A,i,size_A);
		}
	}

	void heapAdjust(int* A, int root, int size_A) //�󶥶�
	{
		int leftchild = 2 * root + 1;
		if (leftchild<size_A) //�ݹ���ʽ
		{
			int rightchild = leftchild + 1;
			if (rightchild<size_A)
			{
				if (A[leftchild]<A[rightchild])
				{
					leftchild = rightchild;
				}
			}
			//leftchildΪ�����ӽڵ��нϴ�Ľ��
			if (A[root]<A[leftchild])
			{
				int temp = A[root];
				A[root] = A[leftchild];   //���ϴ���ֵ���Ƶ����ڵ�
				A[leftchild] = temp; //��ɽ������ӽڵ��Ϊ��ǰ�ĸ��ڵ�
				heapAdjust(A, leftchild, size_A);
			}
		}
		return;
	}
};
class HeapSort2 {
public:
	int* heapSort(int* A, int n) {
		// write code here
		buildHeap(A, n); //��ʼʱ������
		//�����һ��Ԫ�ؿ�ʼ�����н��е���
		for (int i = n - 1; i >= 0; i--)
		{
			swap(&A[0], &A[i]);
			heapAdjust(A, 0, i);
		}
		return A;
	}

	void buildHeap(int* A, int size_A)
	{
		for (int i = (size_A - 1) / 2; i >= 0; i--)
		{
			heapAdjust(A, i, size_A);
		}
	}

	void heapAdjust(int* A, int root, int size_A)  //����Ϊ�󶥶�
	{
		int temp = A[root];
		int leftchild = 2 * root + 1;
		while (leftchild < size_A) //�ǵݹ���ʽ
		{
			int rightchild = leftchild + 1;
			if (rightchild < size_A)
			{
				if (A[leftchild] < A[rightchild])
				{
					leftchild = rightchild;
				}
			}
			//leftchildΪ�����ӽڵ��нϴ�Ľ��
			if (A[root] < A[leftchild])
			{
				A[root] = A[leftchild];   //���ϴ���ֵ���Ƶ����ڵ�
				root = leftchild;         //�����µĸ��ڵ�
				leftchild = 2 * root + 1;		
			}
			else  //��ǰ�����������ӽڵ�����Ҫ����
			{
				break;
			}		
			A[root] = temp; //��ɽ������ӽڵ��Ϊ��ǰ�ĸ��ڵ�
		}
		return;
	}
};

//ϣ������  O(N*log(N)) ---���ȶ�
class ShellSort {
public:
	int* shellSort(int* A, int n) {
		// write code here
		int dk = n / 2;
		while (dk>=1)
		{
			shellSort2(A,n,dk);
			dk /= 2;
		}
		return A;
	}
	void shellSort(int* A, int n, int dk)
	{
		for (int i = dk; i < n;i++)
		{
			int index = i; //��ǰ���ʵ�λ��
			while (index>=dk)
			{
				if (A[index-dk]>A[index])
				{
					swap(&A[index-dk],&A[index]); //�����������ţ��ҵ�����λ�òŽ���
					index -= dk;
				}
				else
				{
					break;
				}
			}
		}
	}
	void shellSort2(int* A,int n,int dk)
	{
		for (int i = dk; i < n;i++)
		{
			if (A[i]<A[i-dk]) //�ҵ�����λ��
			{
				int x = A[i];//�����ڱ�
				A[i] = A[i - dk];
				int j = i - dk; //�Ӹ�λ����ǰ����
				while (x<A[j]&&j>=0) //��ֹjԽ��
				{
					A[j] = A[j - dk];
					j -= dk; //��ǰ�ƶ�
				}
				A[j + dk] = x;// ���뵽��ȷλ��
			}
		}
	}

};


#define N 13
int main()
{
	//�����������뷽ʽ��
		/*int N = 0;
		cout << "�������ݸ�����\n";
		cin >> N;
		int* A = new int[N];
		cout << "���������������ݣ�\n";
		for (int i = 0; i < N; i++)
		{
		cin >> A[i];
		}*/
	//����ֱ�Ӹ���	
		int B[N] = { 1, 6, 3, 5, 2, 4 };
		int C[13] = { 54, 35, 48, 36, 27, 12, 44, 44, 8, 14, 26, 17, 2 };
		int* A = C;

	//���ļ��ж�ȡ���������ݣ�����ʱ�临�Ӷ�
		
	printResult("����ԭʼ���ݣ�", C, N);

	BubbleSort bubble;
	bubble.bubbleSort(A,N);
	printResult("bubbleSort", A, N);

	SelectionSort select;
	select.selectionSort(A, N);
	printResult("selectSort", A, N);

	InsertionSort insert;
	insert.insertionSort(A, N);
	printResult("InsetSort", A, N);

	MergeSort merge;
	merge.mergeSort(A, N);
	printResult("MergeSort", A, N);

	QuickSort qucik;
	qucik.quickSort(A, N);
	printResult("QucikSort",A,N);

	QuickSort2 qucik2;
	qucik2.quickSort(A, N);
	printResult("QucikSort2", A, N);

	HeapSort heap;
	heap.heapSort(A, N);
	printResult("heapSort", A, N);

	HeapSort2 heap2;
	heap2.heapSort(A, N);
	printResult("heapSort2", A, N);


	ShellSort shell;
	shell.shellSort(A,N);
	printResult("shellSort", A, N);

	return 0;
}