#ifndef DYNAMIC_H
#define DYNAMIC_H
template<class T>
class dynamic_array
{
	T* arr;
	int len;
	int cap;
	void double_capacity();

public:
	dynamic_array();
	dynamic_array(int count, T value);
	dynamic_array(const dynamic_array& other);
	dynamic_array(T* vals, int size);

	dynamic_array& operator=(const dynamic_array& other);
	T& operator[](int index);
	const T& operator[](int index) const;
	bool operator==(const dynamic_array& other) const;
	bool operator!=(const dynamic_array& other) const;
	dynamic_array operator+(const dynamic_array& other) const;
	dynamic_array& operator+=(const dynamic_array& other);

	void push(T value);
	void pop();
	void insert_at(int index, T value);
	void delete_at(int index);
	void reserve(int new_capacity);
	void clear();
	void swap(dynamic_array& other);
	void shrink_to_fit();
	void reverse();

	bool empty() const;
	int size() const;
	T& at(int index);
	const T& at(int index) const;
	T& front();
	const T& front() const;
	T& back();
	const T& back() const;
	int find(T value) const;
	void print();
	void print() const;

	~dynamic_array();
};

#endif