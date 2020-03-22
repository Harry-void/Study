//循环队列

#include<iostream>
#include<vector>

using namespace std;

class MyCircularQueue {
private:
	vector<int> data;
	int len;
	int head, tail;
	int insertNum;
public:
	/** Initialize your data structure here. Set the size of the queue to be k. */
	MyCircularQueue(int k) {
		len = k;
		head = 0;
		tail = 0;
		insertNum = 0;
		data.resize(k);
	}

	/** Insert an element into the circular queue. Return true if the operation is successful. */
	bool enQueue(int value) {
		if (insertNum == len)
		{
			return false;
		}
		if (head == 0)
		{
			head++;
		}
		tail++;
		if (tail > len)
		{
			tail = 1;
		}
		data[tail - 1] = value;
		insertNum++;

		return true;
	}

	/** Delete an element from the circular queue. Return true if the operation is successful. */
	bool deQueue() {
		if (insertNum == 0)
			return false;
		insertNum--;
		head++;
		if (insertNum == 0)
		{
			head = 0;
			tail = 0;
		}
		return true;
	}

	/** Get the front item from the queue. */
	int Front() {
		if (head == 0 && tail == 0)
			return -1;

		return data[head - 1];
	}

	/** Get the last item from the queue. */
	int Rear() {
		if (head == 0 && tail == 0)
			return -1;

		return data[tail - 1];
	}

	/** Checks whether the circular queue is empty or not. */
	bool isEmpty() {
		if (insertNum == 0)
			return true;
		else
			return false;
	}

	/** Checks whether the circular queue is full or not. */
	bool isFull() {
		if (insertNum == len)
			return true;
		else
			return false;
	}
};

/**
* Your MyCircularQueue object will be instantiated and called as such:
* MyCircularQueue* obj = new MyCircularQueue(k);
* bool param_1 = obj->enQueue(value);
* bool param_2 = obj->deQueue();
* int param_3 = obj->Front();
* int param_4 = obj->Rear();
* bool param_5 = obj->isEmpty();
* bool param_6 = obj->isFull();
*/

int main()
{
	MyCircularQueue circularQueue = MyCircularQueue(3); // 设置长度为 3

	cout << circularQueue.enQueue(1) << endl;;  // 返回 true

	cout << circularQueue.enQueue(2) << endl;  // 返回 true

	cout << circularQueue.enQueue(3) << endl;  // 返回 true

	cout << circularQueue.enQueue(4) << endl;  // 返回 false，队列已满

	cout << circularQueue.Rear() << endl;  // 返回 3

	cout << circularQueue.isFull() << endl;  // 返回 true

	cout << circularQueue.deQueue() << endl;  // 返回 true

	cout << circularQueue.enQueue(4) << endl;  // 返回 true

	cout << circularQueue.Rear() << endl;  // 返回 4


	return 0;
}