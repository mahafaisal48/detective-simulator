#include<iostream>
#include "dynamic.h"
#include"clue.h"
#include"suspect.h"
#include"room.h"
#include"game_obj.h"
using namespace std;

template<class T>
void dynamic_array<T>::double_capacity()
{
	if (len == cap)
		cap = cap * 2 + 1;

	T* temp = new T[len];
	for (int i = 0;i < len;i++)
		temp[i] = arr[i];

	delete[]arr;
	arr = new T[cap];
	for (int i = 0;i < len;i++)
		arr[i] = temp[i];

	delete[] temp;
}

template<class T>
dynamic_array<T>::dynamic_array()
{
	len = 0;
	cap = 1;
	arr = new T[cap];
}

template<class T>
dynamic_array<T>::dynamic_array(int count, T value)
{
	len = count;
	cap = len + 1;
	arr = new T[cap];

	for (int i = 0;i < len;i++)
		arr[i] = value;
}

template<class T>
dynamic_array<T>::dynamic_array(const dynamic_array& other)
{
	len = other.len;
	cap = len + 1;
	arr = new T[cap];
	for (int i = 0;i < len;i++)
		arr[i] = other.arr[i];
}

template<class T>
dynamic_array<T>::dynamic_array(T* vals, int size)
{
	len = size;
	cap = len + 1;
	arr = new T[cap];

	for (int i = 0; i < len; i++)
	{
		arr[i] = vals[i];
	}
}

template<class T>
dynamic_array<T>& dynamic_array<T>::operator=(const dynamic_array& other)
{
	if (this != &other)
	{
		if (arr)
			delete[] arr;
		cap = other.cap;
		len = other.len;
		arr = new T[cap];
		for (int i = 0;i < len;i++)
			arr[i] = other.arr[i];
	}
	return *this;
}

template<class T>
T& dynamic_array<T>::operator[](int index)
{
	return arr[index];
}

template<class T>
const T& dynamic_array<T>::operator[](int index) const
{
	return arr[index];
}

template<class T>
bool dynamic_array<T>::operator==(const dynamic_array& other) const
{
	if (len != other.len)
		return false;

	for (int i = 0;i < len;i++)
	{
		if (arr[i] != other.arr[i])
			return false;
	}

	return true;
}

template<class T>
bool dynamic_array<T>::operator!=(const dynamic_array& other) const
{
	bool equal = *this == other;
	if (equal)
		return false;
	else
		return true;
}

template<class T>
dynamic_array<T> dynamic_array<T>::operator+(const dynamic_array& other) const
{
	dynamic_array temp;
	temp.len = len + other.len;
	temp.cap = temp.len + 1;
	temp.arr = new T[temp.cap];

	for (int i = 0;i < len;i++)
		temp.arr[i] = arr[i];

	for (int i = 0;i < other.len;i++)
		temp.arr[len + i] = other.arr[i];

	return temp;
}

template <class T>
dynamic_array<T>& dynamic_array<T>::operator+=(const dynamic_array& other)
{
	dynamic_array temp = *this;
	*this = temp + other;
	return *this;
}

template <class T>
void dynamic_array<T>::push(T value)
{
	if (len == cap)
		double_capacity(); 

	arr[len++] = value;     
}

template<class T>
void dynamic_array<T>::pop()
{
	dynamic_array temp;
	temp.cap = len;
	temp.len = len - 1;;
	temp.arr = new T[temp.cap];

	for (int i = 0;i < temp.len;i++)
		temp.arr[i] = arr[i];

	delete[] arr;
	*this = temp;
}

template <class T>
void dynamic_array<T>::insert_at(int index, T value)
{
	dynamic_array temp;
	temp.len = len + 1;
	temp.cap = temp.len + 1;
	temp.arr = new T[temp.cap];
	int idx = 0;

	for (int i = 0;i < temp.len;i++)
	{
		if (i == index)
		{
			temp.arr[i] = value;
		}

		else
		{
			temp.arr[i] = arr[idx];
			idx++;
		}
	}

	delete[] arr;
	*this = temp;
}

template <class T>
void dynamic_array<T>::delete_at(int index)
{
	dynamic_array temp;
	temp.len = len - 1;
	temp.cap = temp.len + 1;
	temp.arr = new T[temp.cap];
	int idx = 0;

	for (int i = 0;i < len;i++)
	{
		if (i != index)
		{
			temp.arr[idx] = arr[i];
			idx++;
		}
	}

	delete[] arr;
	*this = temp;
}

template <class T>
void dynamic_array<T>::reserve(int new_capacity)
{
	dynamic_array temp;
	temp.cap = cap + new_capacity;
	temp.len = len;
	temp.arr = new T[temp.cap];
	for (int i = 0;i < len;i++)
		temp.arr[i] = arr[i];
	delete[] arr;
	*this = temp;
}

template <class T>
void dynamic_array<T>::clear()
{
	len = 0;
	cap = 1;
	delete[] arr;
	arr = new T[cap];
}

template <class T>
void dynamic_array<T>::swap(dynamic_array& other)
{
	dynamic_array temp;
	temp = *this;
	delete[] arr;
	*this = other;
	delete[] other.arr;
	other = temp;
}

template <class T>
void dynamic_array<T>::shrink_to_fit()
{
	dynamic_array temp;
	temp.cap = len;
	temp.len = len;
	temp.arr = new T[temp.cap];
	for (int i = 0;i < len;i++)
		temp.arr[i] = arr[i];
	delete[] arr;
	*this = temp;
}

template <class T>
void dynamic_array<T>::reverse()
{
	dynamic_array temp;
	temp.len = len;
	temp.cap = temp.len + 1;
	temp.arr = new T[temp.cap];
	int idx = 0;

	for (int i = len - 1;i >= 0;i--)
	{
		temp.arr[idx] = arr[i];
		idx++;
	}

	delete[] arr;
	*this = temp;
}

template <class T>
bool dynamic_array<T>::empty() const
{
	if (len == 0)
		return true;

	return false;
}

template <class T>
int dynamic_array<T>::size() const
{
	return len;
}

template <class T>
T& dynamic_array<T>::at(int index)
{
	return arr[index];
}

template <class T>
const T& dynamic_array<T>::at(int index) const
{
	return arr[index];
}

template <class T>
T& dynamic_array<T>::front()
{
	return arr[0];
}

template <class T>
const T& dynamic_array<T>::front() const
{
	return arr[0];
}

template <class T>
T& dynamic_array<T>::back()
{
	return arr[len - 1];
}

template <class T>
const T& dynamic_array<T>::back() const
{
	return arr[len - 1];
}

template <class T>
int dynamic_array<T>::find(T value) const
{
	for (int i = 0;i < len;i++)
	{
		if (arr[i] == value)
			return i;
	}

	return -1;
}

template <class T>
void dynamic_array<T>::print()
{
	for (int i = 0; i < len; i++)
	{
		cout<<arr[i];
		cout<< " ";
	}
	cout << "\n";
}

template <class T>
void dynamic_array<T>::print() const
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i];
		cout << " ";
	}
	cout << "\n";
}

template <class T>
dynamic_array<T>::~dynamic_array()
{
	delete[] arr;
}

template class dynamic_array<char>;
template class dynamic_array<int>;
template class dynamic_array<clue>;
template class dynamic_array<suspect>;
template class dynamic_array<room>;
template class dynamic_array<game_obj>;