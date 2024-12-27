#include <iostream>

#include "CustomVector.h"

// CH2 ������ ���α׷��� ���� 1�� ���� ����

// �Է��� �޴� �Լ�
void InputNumber(CustomVector& NumberArr, int& sortOrder)
{
	int maxInput;

	std::cout << "�Է��Ϸ��� ������ ������ �Է����ּ���" << std::endl;
	std::cin >> maxInput;

	for (int i = 0; i < maxInput; ++i)
	{
		int inputValue = 0;

		std::cout << i << " ��° ������ ���� �Է����ּ���. : ";
		std::cin >> inputValue;

		NumberArr.push_back(inputValue);
	}

	std::cout << "������ �Է��� ���ƽ��ϴ�." << std::endl;

	std::cout << "=================================" << std::endl;

	std::cout << "�������� 1 �������� 2" << std::endl;
	std::cout << "��� �����Ͻðڽ��ϱ�?" << std::endl;
	std::cin >> sortOrder;
}

// ���� ������ ���� �迭�� ��ġ�� �����ϴ� �Լ�
void merge(CustomVector& array, int left, int mid, int right, int sortOrder)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	CustomVector L(n1), R(n2);
	for (int i = 0; i < n1; ++i)
	{
		L[i] = array[left + i];
	}
	for (int j = 0; j < n2; ++j)
	{
		R[j] = array[mid + j + 1];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (sortOrder == 1)
		{
			(L[i] <= R[j]) ? array[k++] = L[i++] : array[k++] = R[j++];
		}
		else
		{
			(L[i] >= R[j]) ? array[k++] = L[i++] : array[k++] = R[j++];
		}

	}

	while (i < n1)
	{
		array[k++] = L[i++];
	}
	while (j < n2)
	{
		array[k++] = R[j++];
	}
}

// ���� ������ ���� �迭�� �и��ϴ� �Լ�
void mergeSort(CustomVector& array, int left, int right, int sortOrder)
{
	if (left < right)
	{
		int mid = left + (right - left) / 2;
		mergeSort(array, left, mid, sortOrder);
		mergeSort(array, mid + 1, right, sortOrder);
		merge(array, left, mid, right, sortOrder);
	}
}

// ����ϴ� �Լ�
void PrintResult(CustomVector& NumberArr)
{
	for (int i = 0; i < NumberArr.size(); ++i)
	{
		std::cout << NumberArr[i];

		if (i + 1 != NumberArr.size())
		{
			std::cout << ", ";
		}
	}
}

int main()
{
	CustomVector NumberArr{};
	int sortOrder;

	InputNumber(NumberArr, sortOrder);

	mergeSort(NumberArr, 0, NumberArr.size() - 1, sortOrder);

	PrintResult(NumberArr);
}