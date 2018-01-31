#include <iostream>
using namespace std;

typedef struct node
{
	int data;
	struct node *pNext;
}NODE, *PNODE;

class Queue
{
public:
	Queue()
	{
		this->pHead = this->pTail = new NODE;
		this->pHead->pNext = NULL;
	}

	void InQueue(int val)
	{
		PNODE pNew = new NODE;

		pNew->data = val;
		pNew->pNext = NULL;

		pTail->pNext = pNew;
		pTail = pNew;

		return;
	}

	bool Empty() const
	{
		if (this->pHead == pTail)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	int OutQueue()
	{
		if (Empty())
		{
			cout << "队列为空，无法出队！" << endl;
		}
		else
		{
			PNODE pTemp = pHead->pNext;
			pHead->pNext = pTemp->pNext;
			int val = pTemp->data;

			delete pTemp;

			if (NULL == pHead->pNext)
			{
				pTail = pHead;
			}

			return val;
		}
	}

	void Traverse(void) const
	{
		PNODE pTemp = pHead->pNext;

		while (pTemp != NULL)
		{
			cout << pTemp->data << "  ";
			pTemp = pTemp->pNext;
		}
		cout << endl;
	}

	void Clear()
	{
		while (!this->Empty())
		{
			OutQueue();
		}
	}

	~Queue()
	{
		this->Clear();
		delete pHead;
	}

private:
	PNODE pHead, pTail;
};

int hmain(void)
{
	Queue Q;

	for (int i = 0; i < 5; i++)
	{
		Q.InQueue(i + 1);
	}

	Q.Traverse();

	Q.OutQueue();
	Q.OutQueue();

	Q.Traverse();

	Q.Clear();
	Q.OutQueue();

	return 0;
}