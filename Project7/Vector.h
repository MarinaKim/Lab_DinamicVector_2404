#pragma once
#include<iostream>

using namespace std;

class vector {
private:
	int cur_size;
	int buf_size;
	double *els;

public:
	//constructors
	vector();
	vector(int size);
	vector(const vector &obj);

	int size()const { return cur_size; } //const - ����� ���������� ����� �onst �������


	//operators
	vector operator=(const vector &obj);
	vector operator+(const vector &obj);
	vector operator-(const vector &obj);
	vector operator >> (double e);
	vector operator~();
	// methods
	double& push_back(double e); // ���������� ���������
	double& at(int index);
	double& operator[](int index);
	double& operator<<(int index);
	void delPos(const int &pos);

	bool operator==(const vector &obj);
	bool operator!=(const vector &obj);


	~vector() { delete[]els; }
	
	friend ostream& operator<<(ostream& os, vector v); //ostream - ����� �� ���������� iostream; &- ������ ����� � ����� ��������� ���������
	                                                  //cout<<v

	friend istream&  operator >> (istream& in, vector v);
};

