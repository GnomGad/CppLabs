// 7 �������
//<Zhenya><������ ����><17:00><08.09.2019>
#include <cstdio>
#include <iostream>
#include <ctime>

//��������������� ������
int processArray(float* a);

const int _size = 15;

int main()
{
	//������������� �������
	float mass[_size] = { 0.0F };
	int a = processArray(mass);
	for (int i = 0; i < _size; i++)
	{
		printf("%i", static_cast<int>(mass[i])); 
			printf(" ");
	}
	mass[5] = 10;
	return 0;
}

int processArray(float* a)
{
	//����������� ��������
	int min = INT_MAX;
	//������� � �������
	int pos = 0;
	//��������� ���� ��� �������, time(0) ��� ������� �������
	srand(time(0));


	//i++ ��� ����� a++ ��� ���������� ������
	for (int i = 0; i < _size; i++, a++)
	{
		//����������� �������� �� 20 �� 100
		a[0] = 20 + rand() % 81;

		if (min > a[0])
		{
			min = a[0];
			pos = i;
		}
		//������� ��� ������ �������� � int ��� ����� ��� �������� �� ����������
		printf("%i", static_cast<int>(a[0]));
		printf(" ");
	}
	printf("\n");
	for (int i = _size; i > pos; i--, a--)
	{
		a[0] = min;
	}

	return min;
}