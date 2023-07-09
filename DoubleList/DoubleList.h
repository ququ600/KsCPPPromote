#pragma once

class KListNode {
public:
	KListNode(int value = 0) :Data(value) {}
	inline int GetData() { return Data; }
	inline void SetData(int Data) { Data = Data; }
	inline KListNode* GetNode() { return this; }
	KListNode* Prev;
	KListNode* Next;
private:
	int Data;

};
class KDoubleList
{
public:
	KDoubleList();
	KListNode* Head;
	KListNode* Tail;

	KListNode* Push(int value);
	KListNode* Insert(KListNode* node, int value);
	KListNode* Find(int value);
	void Remove(KListNode* node);
	void PopAll();

};

