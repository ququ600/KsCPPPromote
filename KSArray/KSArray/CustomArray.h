#pragma once
// ToDO ����template�����ӳ�ʼ���б������������캯��
class CustomArray
{
public:

	CustomArray(int n = 0); 
	~CustomArray();

	void Reserve(int Num);
	void Push(int Num);
	void Pop();
	void Remove(int Index);
	void Insert(int value, int index);
	void Clear();
	int FindIndex(int value);
	const int& operator[] (int index);
private:
	// ����ĳ���
	int Capacity;
	// ����
	int* Ptr;
	// ��ǰ����
	int Size;
};

  