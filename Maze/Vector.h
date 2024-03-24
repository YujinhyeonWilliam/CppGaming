#pragma once
#include "assert.h"
#include "stdexcept"

class Vector
{
	using T = Pos;

public:
	explicit Vector()
	{
		
	}

	~Vector()
	{
		if(_buffer != nullptr)
			delete[] _buffer;
	}

	void clear()
	{
		if(_buffer != nullptr)
		{
			delete[] _buffer;
			_buffer = new T[_capacity];
		}

		_size = 0;
	}

	void push_back(const T& data)
	{
		if (_size == _capacity)
		{
			// 증설작업 
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		_buffer[_size] = data;
		_size++;
	}

	// TODO : 맨 뒤 요소 제거
	void pop_back()
	{
		if (_size > 0)
		{
			_buffer[_size - 1] = T();
			_size--;
		}
		else
			throw std::out_of_range("벡터가 비어있습니다.");
	}

	void reserve(int capacity)
	{
		if (_capacity >= capacity)
			return;

		_capacity = capacity;
		T* newData = new T[_capacity];

		for (int i = 0; i < _size; i++)
			newData[i] = _buffer[i];

		if (_buffer != nullptr)
			delete[] _buffer;

		_buffer = newData;
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < _size);
		return _buffer[index];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _buffer = nullptr;
	int _size = 0;
	int _capacity = 0;
};

