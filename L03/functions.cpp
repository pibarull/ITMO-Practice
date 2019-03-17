#include <iostream>
#include "functions.h"
using namespace std;

int GCD(int a, int b)//���������� ����� ��������
{
	if ((a < 1) || (a > 1500)|| (b < 1) || (b > 1500))
		throw out_of_range("argunents must be in range [1..1500]");
	while (a % b != 0)
	{
		a %= b;
		swap(a, b);
	}
	return b;
}

bool Check(int x)//�������� �������� �� ����������� ������ ���� 2^x
{
	if ((x < 1) || (x > 1500))
		throw out_of_range("argunent must be in range [1..1500]");
	for (int i = 0; i <= 10; ++i)
		if (x == (1 << i))//��������� �� 2 � ������� i(��������� ������)
			return true;
	return false;
}

int GetLevel(int x) //���������� ����� ��������� �
{
	if ((x < 1) || (x > 9999))
		throw out_of_range("argunent must be in range [1..9999]");
	for (int i = 0; i <= 10; ++i)
		if (x < (1 << (i + 1)) - 1)
			return i;
	return -1;
}
