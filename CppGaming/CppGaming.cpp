#include <iostream>
using namespace std;
#include <vector>
#include <queue>

template<typename T, typename Predicate = less<T>>
class PriorityQueue
{
public:
	// O(logN)
	void push(const T& data)
	{
		// ��Ģ2: �켱 �� �������� �����ش�.
		_heap.push_back(data);

		// ��Ģ1: �θ� ���� �׻� �ڽ� ��庸�� ū ���� ������.
		int now = static_cast<int>(_heap.size()) - 1;
		while (now > 0)
		{
			int next = parent(now);

		  //if (_heap[now] < _heap[next])
			if(_predicate(_heap[now], _heap[next]))
				break;

			::swap(_heap[now], _heap[next]);
			now = next;
		}
	}

	// O(logN)
	void pop()
	{
		_heap[0] = _heap.back();
		_heap.pop_back();

		int now = 0;
		int heapSize = static_cast<int>(_heap.size());
		while (true)
		{
			int left = leftChild(now);
			int right = rightChild(now);

			// ������ ������ ���
			if (left >= heapSize)
				break;

			int next = now;
			if (_heap[now] < _heap[left])
				next = left;
			
			//if (right < heapSize && _heap[next] < _heap[right])
			if (right < heapSize && _predicate(_heap[next], _heap[right]))
				next = right;

			if (next == now)
				break;
			else
			{
				::swap(_heap[now], _heap[next]);
				now = next;
			}
		}
	}

	// O(1)
	T& top()
	{
		return _heap[0];
	}

	// O(1)
	bool empty()
	{
		return _heap.empty();
	}

private: 
	// O(1)
	int leftChild(int index)
	{
		return index * 2 + 1;
	}

	// O(1)
	int rightChild(int index)
	{
		return index * 2 + 2;
	}

	// O(1)
	int parent(int index)
	{
		return (index - 1) / 2;
	}

private:
	vector<T> _heap;
	Predicate _predicate;
};

int main()
{
	PriorityQueue<int, greater<int>> pq;
	pq.push(10);
	pq.push(40);
	pq.push(30);
	pq.push(50);
	pq.push(20);
	int value = pq.top();
	pq.pop();
	cout << " Top = " << value << endl;
}