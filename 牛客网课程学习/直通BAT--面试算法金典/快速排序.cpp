//��������ʵ�ַ���һ
void quick_sort(int s[],int l,int r)//��ȥ��һ��Ԫ����Ϊ��׼���Ӻ���Ƚ�
{
    int i = l, j = r, base = s[i];//�ڿ�
    while (i<j&&s[j]>base)
    {
        j--;
    }
    if (i<j)
    {
        s[i++] = s[j];//����
    }
    while (i<j&&s[i]<base)
    {
        i++;
    }
    if (i<j)
    {
        s[j++] = s[i];
    }
    s[i] = base;
    quick_sort(s,l,i-1);
    quick_sort(s, i + 1, r);
}

//ʵ�ַ�����


int patition(int gArr[], int begin, int end){
    int index, small;
    small = begin - 1;
    for (index = begin; index < end; index++){  //���һ����Ϊ��׼����ͷ��ʼ�Ƚ�
        if (gArr[index] < gArr[end]){
            small++;
            if (small != index)
                swap(index, small);
        }
    }
    small++;
    swap(small, end);
    return small;
}
void swap(int gArr[],int i, int j){
    int tmp = gArr[j];
    gArr[j] = gArr[i];
    gArr[i] = tmp;
}

//���ѡ���׼��ͷ����β��