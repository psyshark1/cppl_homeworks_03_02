#include <iostream>

class smart_array
{
public:
	smart_array(const int& len);
	~smart_array();
	void add_element(const int& number);
	int get_element(const int& number);
	smart_array& operator = (const smart_array& r);
private:
	int* arr{ nullptr };
	int arr_length{ 0 };
	void delete_arr();
	void assign(const smart_array& t);
};

int main(int argc, char** argv)
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
	}
	catch (const std::exception& ex) {
		std::cout << ex.what() << std::endl;
		return 1;
	}
	return 0;
}

smart_array::smart_array(const int& len)
{
	if (len < 1) { throw std::exception("Некорректный размер элемента массива!"); }
	arr_length = len;
	this->arr = new int[arr_length] {0};
}

void smart_array::add_element(const int& number)
{
	if (number < 1) { throw std::exception("Некорректный размер элемента массива!"); }
	if (number <= arr_length) { throw std::exception("Такой элемент массива уже существует!"); }
	delete_arr();
	this->arr = new int[number] {0};
}

int smart_array::get_element(const int& number)
{
	if (number < 1 && number > arr_length) { throw std::exception("Некорректный размер элемента массива!"); }
	return arr[number];
}

void smart_array::delete_arr()
{
	if (arr != nullptr)
	{
		delete[] this->arr;
		this->arr = nullptr;
	}
}

smart_array::~smart_array()
{
	delete_arr();
}

smart_array& smart_array::operator = (const smart_array& r)
{
	this->delete_arr();
	this->assign(r);
	return *this;
}

void smart_array::assign(const smart_array& t)
{
	this->arr = new int[t.arr_length] {0};
	this->arr_length = t.arr_length;
	for (unsigned i = 0; i < this->arr_length; ++i)
	{
		this->arr[i] = t.arr[i];
	}
}