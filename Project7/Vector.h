#pragma once
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

	// methods
	double& push_back(double e); // ���������� ���������
	double& at(int index);
	double& operator[](int index);

	bool operator==(const vector &obj);
	~vector() { delete[]els; }
};