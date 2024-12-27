#include <iostream>

#include "CustomVector.h"

// CH2 ������ ���α׷��� ���� 1�� �ʼ� ����

// �Է��� �޴� �Լ�
void InputNumber(CustomVector& NumberArr)
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

}

// ������ ������ ���ϴ� �Լ�
int accumulate(int* first, int* last)
{
	int totalSum = 0;

	for (; first != last; ++first)
	{
		totalSum += *first;
	}

	return totalSum;
}

// ����� ���ϴ� �Լ�
double calculateAverage(int totalSum, int count)
{
	if (count == 0) return 0;

	return totalSum / static_cast<double>(count);
}

int main()
{
	CustomVector NumberArr{};

	InputNumber(NumberArr);

	int totalSum = accumulate(NumberArr.begin(), NumberArr.end());

	double average = calculateAverage(totalSum, NumberArr.size());

	std::cout << "���ڵ��� �����Դϴ�. : " << totalSum << std::endl;

	std::cout << "���ڵ��� ����Դϴ�. : " << average << std::endl;
}