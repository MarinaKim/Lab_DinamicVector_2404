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
			for (int i = 0; i < size(); i++) {
				tmp[i] = els[i];
			}
			delete[]els;
			els = tmp;
		}
	}
	els[cur_size++] = e;
	return els[cur_size - 1];
}

vector vector:: operator >> (double e) {
	if (buf_size <= 0) {
		buf_size = 2;
		els = new double[buf_size];
	}
	else {
		if (cur_size >= buf_size) {
			buf_size *= 2;
			double *tmp;
			tmp = new double[size()];
			for (int i = 0; i < size(); i++) {
				tmp[i] = els[i];
			}
			delete[]els;
			els = tmp;
		}
	}
	els[cur_size++] = e;
	return *this;
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

void vector::delPos(const int &pos)
{
	for (int i = pos - 1; i < cur_size; i++)
		els[i] = els[i + 1];
	cur_size--;
}

// оператор сравнения
bool vector::operator==(const vector &obj) {
	if (this->cur_size != obj.size())
		return false;
	else {
		for (int i = 0; i < size(); i++) {
			if (els[i] != obj.els[i])
				return false;
		}
	}
	return true;
}

bool vector::operator!=(const vector &obj) {
	if (this->cur_size != obj.size())
		return false;
	else {
		for (int i = 0; i < size(); i++) {
			if (els[i] != obj.els[i])
				return false;
		}
	}
	return true;
}

ostream& operator<<(ostream& os, vector v) {
	for (int i = 0; i < v.size(); i++) {
		os << v[i] << "\t";
	}
	return os;
}

istream&  operator >> (istream& in, vector v) {
	for (int i = 0; i < v.size(); i++) {
		in >> v[i];
	}
	return in;
}

vector vector:: operator+(const vector &obj)
{
	if (this->cur_size == obj.cur_size) {
		for (int i = 0; i < cur_size; i++)
		{
			els[i] += obj.els[i];
		}
	}
	return *this;
}
vector vector:: operator~() {
	for (int i = 0; i < this->cur_size-1; i++) {
		for (int j = i+1; j < this->cur_size; j++) {
			if (this->els[i] == this->els[j]) {
				this->delPos(i);
					this->delPos(j);
			}
		}
	}
	return *this;
}

/*Оператор << удаляет из вектора элемент с индексом указанным в качестве второго операнда и возвращает удаленное значение*/
double& vector::operator<<(int index) {
	double e;
	e = this->els[index];
	for (int i = index; i < cur_size; i++)
		els[i] = els[i + 1];
		cur_size--;
	return e;
}

vector vector::operator-(const vector &obj) {
	vector vNew;
	
	for (int i = 0; i < this->cur_size; i++) {
		int count = 0;
		for (int j = 0; j < obj.cur_size; j++) {
			if (this->els[i] == obj.els[j])
			{
				count = 1;
				break;
			}
		}
		if (count == 0) {
			vNew.push_back(els[i]);
		}
	}	
	cout << vNew << endl;
	return vNew;
}


