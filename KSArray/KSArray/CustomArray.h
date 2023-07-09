#pragma once
// ToDO 增加template，增加初始化列表，增加其他构造函数
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
	// 分配的长度
	int Capacity;
	// 数据
	int* Ptr;
	// 当前容量
	int Size;
};

  