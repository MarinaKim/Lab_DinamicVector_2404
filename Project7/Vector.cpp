#include"Vector.h"
// по умолчанию
vector::vector() {
	cur_size = 0;
	buf_size = 0;
	els = nullptr;
}

//
vector::vector(int size) {
	this->cur_size = size;
	this->buf_size = size;
	this->els = new double[buf_size];
	for (int i = 0; i < buf_size; i++)
		els[i] = 0;
}

//copy constructor
vector::vector(const vector &obj) {
	this->cur_size = obj.cur_size; //obj.size()
	this->buf_size = obj.cur_size; //экономия памяти. не надо копировать весь буффер, curent  может быть меньше
	this->els = new double[cur_size];//this->buf_size|| this->size()
	for (int i = 0; i < this->size(); i++)
	{
		this->els[i] = obj.els[i];
	}
}

//оператор присваивания
vector vector:: operator=(const vector &obj) {//возврщаем объект
	this->cur_size = obj.cur_size; //obj.size()
	this->buf_size = obj.cur_size; //экономия памяти. не надо копировать весь буффер, curent  может быть меньше
	this->els = new double[cur_size];//this->buf_size|| this->size()
	for (int i = 0; i < this->size(); i++)
	{
		this->els[i] = obj.els[i];
	}
	return *this;// this- указатель на текущий объект, *- разименование
}

	double& vector::push_back(double e) {
		if (buf_size <= 0) {
			buf_size = 2;
			els = new double[buf_size];
		}
		else {
			if (cur_size >= buf_size) {
				buf_size *= 2;
				double *tmp;
				tmp = new double[size()];
				for (int i = 0;i < size();i++) {
					tmp[i] = els[i];
				}
				delete[]els;
				els = tmp;
			}
		}
		els[cur_size++] = e;
		return els[cur_size - 1];
	}

	double& vector::at(int index) {
		if (index<0 || index>size())
			return els[0];
		else
			return els[index];
	}

	double& vector::operator[](int index) //vector v,v.at(2)==v[2]
	{
		if (index<0 || index>size())
			return els[0];
		else
			return els[index];
	}

// оператор сравнения
bool vector::operator==(const vector &obj) {
	if (this->cur_size != obj.size())
		return false;
	else {
		for (int i = 0;i < size();i++) {
			if (els[i] != obj.els[i])
				return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& os, vector v) {
	for (int i = 0;i < v.size();i++) {
		os << v[i] << "\t";
	}
	return os;
}