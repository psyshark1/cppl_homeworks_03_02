#include <iostream>

class smart_array
{
public:
	smart_array(const int& len);
	smart_array(const smart_array& sa);
	~smart_array();
	void add_element(const int& val);
	int get_element(const int& number);
	void print();
	smart_array& operator = (const smart_array& sa);
private:
	int* arr{ nullptr };
	int arr_length{ 0 };
	int arr_length_logic{ 0 };
	void delete_arr();
	void assign(const smart_array& t);
	void expand_arr();
};

int main(int argc, char** argv)
{
	try {
		smart_array arr(5);
		arr.add_element(1);
		arr.add_element(4);
		arr.add_element(155);

		arr = arr;

		smart_array new_array(2);
		new_array.add_element(44);
		new_array.add_element(34);

		arr = new_array;
		smart_array arr2(arr);
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
	this->arr_length = len;
	this->arr = new int[this->arr_length] {0};
}

smart_array::smart_array(const smart_array& sa)
{
	this->assign(sa);
}

void smart_array::add_element(const int& val)
{
	if (this->arr_length_logic + 1 > this->arr_length)
	{
		this->expand_arr();
	}
	this->arr[this->arr_length_logic++] = val;
	//if (number < 1)
	//{
	//	throw std::exception("Некорректный размер элемента массива!");
	//}

	//if (number > this->arr_length + 1)
	//{
	//	this->expand_arr(true, number);
	//}

	//if (number <= this->arr_length_logic + 1) { ++this->arr_length_logic; }

	//if (this->arr_length_logic >= this->arr_length)
	//{
	//	this->expand_arr(false, number);
	//}

	//if (number >= 1 && number <= this->arr_length_logic + 1)
	//{
	//	for (int i = this->arr_length_logic; i > number - 1; --i)
	//	{
	//		this->arr[i] = this->arr[i - 1];
	//	}
	//}
	//else if (number > this->arr_length_logic)
	//{
	//	//this->arr[number] = value;
	//}
}

int smart_array::get_element(const int& number)
{
	if (number < 0 || number >= this->arr_length_logic) { throw std::exception("Некорректный размер элемента массива!"); }
	return arr[number];
}

void smart_array::delete_arr()
{
	delete[] this->arr;
	this->arr = nullptr;
}

void smart_array::expand_arr()
{
	int nsz = this->arr_length << 1;

	//(oversize) ? nsz = number - 1 : nsz = this->arr_length * 2;

	int* tmp = new int[nsz] { 0 };
	for (int i = 0; i < this->arr_length; ++i)
	{
		tmp[i] = this->arr[i];
	}
	delete_arr();
	this->arr = tmp;
	this->arr_length = nsz;
}

smart_array::~smart_array()
{
	delete_arr();
}

void smart_array::print()
{
	for (int i = 0; i < this->arr_length_logic; ++i)
	{
		std::cout << this->arr[i] << ' ';
	}
	std::cout << '\n';
}

smart_array& smart_array::operator = (const smart_array& r)
{
	if (this != &r) {
		this->delete_arr();
		this->assign(r);
		return *this;
	}
	return *this;
}

void smart_array::assign(const smart_array& t)
{
	this->arr = new int[t.arr_length] {0};
	this->arr_length = t.arr_length;
	for (int i = 0; i < this->arr_length; ++i)
	{
		this->arr[i] = t.arr[i];
	}
}