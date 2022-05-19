//program to calculate pascal traingle 
//Author: Piotr Kacprzak
#include<iostream>

using namespace std;

int main()
{
	double x = 1;

	cout << "ile wierszy trojkata obliczyc?" << endl;
	cin >> x;

	double** triangle = new double* [x];

	//create second dimension
	for (int i = 0; i < x; i++) {
			triangle[i] = new double[i];
	}

	//fill triangle with 0
	for (int i = 0; i < x; i++) {
		for (int b = 0; b < x; b++) {
			triangle[i][b] = 0;
		}
	}


	//calcualte pascal triangle
	for (int i = 0; i < x; i++) {
		if (i == 0) triangle[0][0] = 1;
		else {
			for (int b = 0; b < x; b++) {
				if (b == 0 || b == i) triangle[i][b] = 1;
				else {
					triangle[i][b] = triangle[i - 1][b - 1] + triangle[i - 1][b];
				}
			}
		}
	}

	//show pascal triangle
	for (int i = 0; i < x; i++) {
		for (int b = 0; b < x; b++) {
			cout << triangle[i][b] << " ";
		}
		cout << endl;
	}
	for (int i = 0; i < x; i++) {
		delete triangle[i];
	}
	return 0;
}