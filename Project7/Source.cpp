#include<iostream>
#include"Vector.h"
using namespace std;
int main() {
	vector v;
	v.push_back(10);
	v.push_back(2.5);
	v.push_back(4.3);

	/*for (int i = 0;i < v.size();i++)
		cout << v.at(i) << endl;*/

	cout << v << endl;
	cout << "--------------------------------------------------"<<endl;
	v[0] = 1.8;
	v.at(1) = 5.4;
	/*for (int i = 0;i < v.size();i++)
		cout << v[i] << endl;*/

	cout << v << endl;

	cout << "Vector v2" << endl;
	vector v2(v);
	/*for (int i = 0;i < v2.size();i++)
		cout << v2[i] << endl;*/
	cout << v2 << endl;
	cout << "------------------------------------------------------------------------" << endl;
	cout << "=:"<<endl;
		vector v1=(v);
		/*for (int i = 0;i < v1.size();i++)
			cout << v1[i] << endl;*/
		cout << "Vector v1" << endl;
		cout << v1 << endl;
		cout << "------------------------------------------------------------------------" << endl;
        //==
		cout << "==:" << endl;
		cout << (v1 == v) << endl;
		cout << "------------------------------------------------------------------------" << endl;
		//+
		cout << "+" << endl;
		cout << (v1 + v2) << endl;
		cout << "------------------------------------------------------------------------" << endl;
		//!=
		cout << "!=:" << endl;
		cout << (v1 != v) << endl;
		cout << "------------------------------------------------------------------------" << endl;

		//>>
		cout << ">>" << endl;
		cout << (v1 >> 5.2) << endl;
		cout << "------------------------------------------------------------------------" << endl;

		//>>
		cout << "<<" << endl;
		cout << "Vector v1" << endl;
		cout << v1 << endl;
		cout << (v1 <<2) << endl;
		cout << "Vector v1" << endl;
		cout << v1 << endl;
		cout << "------------------------------------------------------------------------" << endl;

		//~
		v1.push_back(5.2);
		cout << "Vector v1" << endl;
		cout << v1 << endl;
		cout << "~" << endl;
		cout << (v1.operator~()) << endl;
		cout << "------------------------------------------------------------------------" << endl;

		//-
		v1.push_back(1.8);
		cout << "Vector v1" << endl;
		cout << v1 << endl;
		cout << "-" << endl;
		cout << (v1 - v2) << endl;
		cout << "------------------------------------------------------------------------" << endl;
		

	system("pause");
	return 0;
}