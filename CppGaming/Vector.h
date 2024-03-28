#pragma once
#include "assert.h"
#include "stdexcept"
	// it++;
	// v.begin();
	// v.end();
	// it != v.end();
	// *it;
template<typename T>
class Iterator
{
public:
	Iterator() : _ptr(nullptr){}
	Iterator(T* ptr) : _ptr(ptr){}

	T& operator*()
	{
		return *_ptr;
	}

	// ������ ++it
	Iterator& operator++()
	{
		_ptr++;
		return *this;
	}

	// ������ it++
	Iterator operator++(int)
	{
		Iterator temp = *this;
		_ptr++;
		return temp;
	}

	Iterator operator+(const int count)
	{
		Iterator temp = *this;
		temp._ptr += count;
		return temp;
	}

	bool operator==(const Iterator& other)
	{
		return _ptr == other._ptr;
	}

	bool operator!=(const Iterator& other)
	{
		return !(_ptr == other._ptr);
	}

public:
	T* _ptr = nullptr;
};

template<typename T>
class Vector
{
public:
	using iterator = Iterator<T>;

	iterator begin() { return iterator(&_buffer[0]); }
	iterator end() { return begin() + _size; }

	explicit Vector()
	{

	}

	~Vector()
	{
		if (_buffer != nullptr)
			delete[] _buffer;
	}

	void clear()
	{
		if (_buffer != nullptr)
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
			// �����۾� 
			int newCapacity = static_cast<int>(_capacity * 1.5);
			if (newCapacity == _capacity)
				newCapacity++;

			reserve(newCapacity);
		}

		_buffer[_size] = data;
		_size++;
	}

	// TODO : �� �� ��� ����
	void pop_back()
	{
		if (_size > 0)
		{
			_buffer[_size - 1] = T();
			_size--;
		}
		else
			throw std::out_of_range("���Ͱ� ����ֽ��ϴ�.");
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

	void resize(int size)
	{
		//TODO
		reserve(size);
		_size = size;

	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < _size);
		return _buffer[index];
	}

	T& back()
	{
		return _buffer[_size - 1];
	}

	int size() { return _size; }
	int capacity() { return _capacity; }

private:
	T* _buffer = nullptr;
	int _size = 0;
	int _capacity = 0;
};

