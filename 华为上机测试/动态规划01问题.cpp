//��������:
//����ĵ� 1 �У�Ϊ��������������һ���ո������N m
//������ N �� <32000 ����ʾ��Ǯ���� m �� <60 ��Ϊϣ��������Ʒ�ĸ�������
//
//�ӵ� 2 �е��� m + 1 �У��� j �и����˱��Ϊ j - 1 ����Ʒ�Ļ������ݣ�ÿ���� 3 ���Ǹ����� v p q
//
//������ v ��ʾ����Ʒ�ļ۸� v<10000 ���� p ��ʾ����Ʒ����Ҫ�ȣ� 1 ~5 ���� q ��ʾ����Ʒ���������Ǹ�������� q = 0 ��
//                ��ʾ����ƷΪ��������� q>0 ����ʾ����ƷΪ������ q �����������ı�ţ�
//
//������� :
//����ļ�ֻ��һ����������Ϊ��������Ǯ������Ʒ�ļ۸�����Ҫ�ȳ˻����ܺ͵����ֵ�� <200000 ����


/* �㷨����˼�룺

���ö�̬�滮˼�� ��������Ϊ��f[i][v]��ʾǰi����Ʒǡ����һ������Ϊv�ı������Ի�õ�����ֵ��

��״̬ת�Ʒ����ǣ�f[i][v]=max{f[i-1][v],f[i-1][v-c[i]]+w[i]}    //������̷ǳ���Ҫ�����������и�������ص�����ķ��̶����������������ġ�

����һ������ķ��̣�����ǰi����Ʒ��������Ϊv�ı����С���������⣬���ֻ���ǵ�i����Ʒ�Ż��߲��ţ���ô�Ϳ���ת��Ϊֻ�漰ǰi-1����Ʒ�����⣬��1��������ŵ�i����Ʒ��������ת��Ϊ��ǰi-1����Ʒ��������Ϊv�ı����С���2������ŵ�i����Ʒ��������ת��Ϊ��ǰi-1����Ʒ����ʣ�µ�����Ϊv-c[i]�ı����С�(��ʱ�ܻ�õ�����ֵ����f [i-1][v-c[i]]�ټ���ͨ�������i����Ʒ��õļ�ֵw[i])����f[i][v]��ֵ����1��2�������Ǹ�ֵ��

��ע�⣺f[i][v]�����嵱�ҽ�������һ��ǰi����Ʒ���Ӽ���������ܺ�Ϊv�����԰���������̵�����Ϻ����յĴ𰸲���һ����f[N] [V]������f[N][0..V]�����ֵ���� */

//��̬�滮��(0,1)��������
#include<iostream>
using namespace std;

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct InputBuf
{
	int price;
	int weight;
	int type;
};

struct InputBuf inputBuf[60];
int sum_money = 0;
int sum_num = 0;

int countMaxvalue(int index, int money, int f)
{
	int a = 0, b = 0;
	if (index >= sum_num) return 0;
	if (inputBuf[index].type == 0)  //����
	{
		if (money >= inputBuf[index].price)
		{
			a = countMaxvalue(index + 1, money - inputBuf[index].price, 1) + inputBuf[index].price * inputBuf[index].weight;  //���index����Ʒ�ĸ���
			b = countMaxvalue(index + 1, money, 0);    //������
			return a > b ? a : b;
		}
		else
			return countMaxvalue(index + 1, money, 0);
	}
	else if ((inputBuf[index].type != 0) && (f == 1))  //������������������
	{
		if (money >= inputBuf[index].price)
		{
			a = countMaxvalue(index + 1, money - inputBuf[index].price, f) + inputBuf[index].price * inputBuf[index].weight;
			b = countMaxvalue(index + 1, money, f);
			return a > b ? a : b;
		}
	}
	else
	{
		return countMaxvalue(index + 1, money, f);
	}
	return 0;
}



int main(void)
{
	int i = 0;
	scanf("%d %d", &sum_money, &sum_num);
	for (i = 0; i < sum_num; i++)
	{
		scanf("%d %d %d", &inputBuf[i].price, &inputBuf[i].weight, &inputBuf[i].type);
	}
	printf("%d", countMaxvalue(0, sum_money, 1));
	return 0;
}