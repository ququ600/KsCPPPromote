#include "CustomArray.h"
using namespace std;
#include <cstring>
CustomArray::CustomArray(int n)
{
	if (n == 0) {
		Ptr = nullptr;
	}
	else {
		Ptr = new int[n];
		for (int i = 0; i < n; i++) {
			Ptr[i] = i;
		}
		Capacity = n;
	}
}

CustomArray::~CustomArray()
{
	delete[] Ptr;
}

void CustomArray::Reserve(int Num)
{
	if (Num > Size) {
		int* Temp = new int[Num];
		if (Temp) {
			if (Size > Num) {
				Size = Num;
			}
			memcpy(Temp, Ptr, sizeof(int) * Capacity);
			delete[] Ptr;
			Ptr = Temp;
			Capacity = Num;
		}
	}
	return;
}

void CustomArray::Push(int Num)
{
	if (Size < Capacity) {
		Ptr[Size] = Num;
		Size++;
	}
}

void CustomArray::Pop()
{
	if (Size > 0) {
		Remove(Size - 1);
	}
}

void CustomArray::Remove(int Index)
{
	if (Index > Size) {
		return;
	}
	else {
		std::memmove(Ptr + Index, Ptr + (Index + 1), (Size - Index) * sizeof(int));
	}
	Size--;
}

void CustomArray::Insert(int index, int value)
{
	if (index > Size) {
		return;
	}
	if (Size == Capacity) {
		int* Temp = new int[Size + 1];
		memcpy(Temp, Ptr, index * sizeof(index));

		if (index < Size) {
			memcpy(Temp + index + 1, Ptr + index, (Size - index) * sizeof(int));
		}
		delete Ptr;
		Ptr = Temp;
		Capacity++;
	}
	else {
		if (index < Size) {
			memmove(Ptr + index + 1, Ptr + index, (Size - index) * sizeof(int));
		}
	}
	Ptr[index] = value;
	Size++;


}

void CustomArray::Clear()
{
	Size = 0;
}

int CustomArray::FindIndex(int value)
{
	for (int i = 0; i < Size; i++) {
		if (Ptr[i] == value) {
			return i;
		}
	}
	return -1;
}

const int& CustomArray::operator[](int index)
{
	return Ptr[index];
}
