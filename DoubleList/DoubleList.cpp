// DoubleList.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "DoubleList.h"


KDoubleList::KDoubleList()
{
    Head = new KListNode();
    Tail = new KListNode();
    Head->Prev = nullptr;
    Head->Next = Tail;

   
    Tail->Prev = Head;
    Tail->Next = nullptr;
    
}

KListNode* KDoubleList::Push(int value)
{
    KListNode* Temp = new KListNode();
    Temp->SetData(value);
    
    Temp->Next = Tail;
    Temp->Prev = Tail->Prev;

    Tail->Prev->Next = Temp;
    Tail->Prev = Temp;
    return Temp;
    
}

KListNode* KDoubleList::Insert(KListNode* node, int value)
{
    KListNode* Temp = new KListNode();
    Temp->SetData(value);

    Temp->Prev = node;
    Temp->Next = node->Next;

    node->Prev->Next = Temp;
    node->Prev = Temp;
    return Temp;
}

KListNode* KDoubleList::Find(int value)
{
    KListNode* Temp = this->Head;
    while (Temp != nullptr) {
        if (Temp->GetData() == value) {
            return Temp;
        }
        Temp = Temp->Next;
    }
    return nullptr;
}

void KDoubleList::Remove(KListNode* node)
{
    node->Prev->Next = node->Next;
    node->Next->Prev = node->Prev;
    delete node;
}

void KDoubleList::PopAll()
{
    KListNode* temp = this->Head;
    while (temp != Tail) {
        
        temp = temp->Next;
        delete temp->Prev;
    }
    delete temp;
}


int main()
{
    std::cout << "Hello World!\n";
    auto List = new KDoubleList();
    auto node1 = List->Push(1);
    auto node2 = List->Push(2);
    auto node3 = List->Push(3);


    auto ret = List->Find(2);
    List->Remove(node2);

    List->PopAll();
    return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
