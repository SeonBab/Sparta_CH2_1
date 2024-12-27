#pragma once
#include <iostream>

class CustomVector
{
private:
	// ���� �迭�� ���� ������
	int* startPointer;
	// ���� ��� ����
	size_t size_;
	// ���� �Ҵ�� �뷮�� ũ��
	size_t capacity_;

	void Reallocate(size_t newCapacity);

public:
	// ������
	CustomVector() : startPointer(nullptr), size_(0), capacity_(0) {}

	CustomVector(int size)
	{
		int* newData = new int[size];
		startPointer = newData;

		size_ = size;
		capacity_ = size;
	}

	// �Ҹ���
	~CustomVector() { delete[] startPointer; }

	// ���� ��� ���� ��ȯ
	size_t size() const { return size_; }

	// ���� �Ҵ�� �뷮�� ũ�� ��ȯ
	size_t capacity() const { return capacity_; }

	// ù ��° ��� ��ȯ
	int* begin() const { return startPointer; }

	// ������ ��� �ڸ� ��ȯ
	int* end() const { return startPointer + size_; }

	void push_back(const int& value);

	int& operator[](size_t index)
	{
		if (index >= size_)
		{
			throw std::out_of_range("�ε����� ������ ������ϴ�.");
		}

		return startPointer[index];
	}
};