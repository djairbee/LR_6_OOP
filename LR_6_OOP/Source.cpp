#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

template <typename T>

class Two_dimensional_array {

private:
	T** arr;		
	int count_rows = 0;

public:
	Two_dimensional_array(int rows, int columns)
	{
		arr = new T * [rows];
		for (int i = 0; i < rows; i++)
		{
			arr[i] = new T[columns];
		}
	}

	~Two_dimensional_array()
	{
		for (int i = 0; i < count_rows; i++)
		{
			delete[] arr[i];
		}
	}

	void input_element(int rows, int columns)
	{
		cout << endl << " Введіть елементи матриці  " << endl;
		for (int i = 0; i < rows; i++)
		{
			cout << " ";
			for (int j = 0; j < columns; j++)
			{
				cin >> arr[i][j];
			}
		}
		count_rows = rows;
	}
	void output_element(int r, int c)
	{
		cout << endl << " Введена матриця : " << endl;
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << " " << arr[i][j] << " ";
			}
			cout << endl;
		}
	}
	void copy_column(T* carray, int n, int r)
	{
		for (int i = 0; i < r; i++)
		{
			carray[i] = arr[i][n];
		}
		cout << endl;
		for (int k = 0; k < r; k++)
		{
			cout << " " << carray[k] << " ";
		}
	}
	void copy_row(T* carray2, int n, int c)
	{
		for (int i = 0; i < c; i++)
		{
			carray2[i] = arr[n][i];
		}
		cout << endl;
		for (int i = 0; i < c; i++)
		{
			cout << " " << carray2[i] << " ";
		}
	}
	void copy_ar_column(T** carray2, int c, int r)
	{
		for (int i = 0; i < c; i++)
		{
			copy_column(carray2[i], i, r);
		}
	}

	void copy_ar_row(T** carray2, int c, int r)
	{
		for (int i = 0; i < r; i++)
		{
			copy_row(carray2[i], i, c);
		}
	}
	void function(int r, int c, int r1, int c1, T arrr[], T arrr2[], T* (arrr3)[], T** arrr4)
	{
		this->input_element(r, c);
		this->output_element(r, c);
		cout << endl << endl << " Копія заданого рядка.";
		this->copy_row(arrr, r1, c);
		cout << endl << endl << endl << " Копія заданого стовпця.";
		this->copy_column(arrr2, c1, r);
		cout << endl << endl << endl << " Копія масиву по рядках.";
		this->copy_ar_row(arrr3, c, r);
		cout << endl << endl << endl << " Копія масиву по стовпцях.";
		this->copy_ar_column(arrr4, c, r);
	}
};
int main()
{
	system("chcp 1251");
	system("cls");
	char format;
	int r, c, r1, c1;
	cout << " Введіть розмірність матриці  ((к-сть рядків) (к-сть стовпців)): ";
	cin >> r >> c;
	cout << " Введіть рядок який хочете скопіювати : ";
	cin >> r1;
	r1--;
	if (r1 >= r)
	{
		r1 = r;
		r1--;
	}
	cout << " Введіть стовпець який хочете скопіювати : ";
	cin >> c1;
	c1--;
	if (c1 >= c)
	{
		c1 = c;
		c1--;
	}
skip:
	cout << " Введіть формат : i - int, d - double, c - char, s - string : ";
	cin >> format;
	if (format == 'i')
	{
		int* arrr = new int[c], * arrr2 = new int[r];
		int** arrr3, ** arrr4;
		arrr3 = new int* [r];
		for (int i = 0; i < r; i++)
		{
			arrr3[i] = new int[c];
		}
		arrr4 = new int* [c];
		for (int i = 0; i < c; i++)
		{
			arrr4[i] = new int[r];
		}
		Two_dimensional_array<int>a(r, c);
		a.function(r, c, r1, c1, arrr, arrr2, arrr3, arrr4);
		delete[]arrr;
		delete[]arrr2;
		for (int i = 0; i < r; i++)
		{
			delete[]arrr3[i];
		}
		for (int i = 0; i < c; i++)
		{
			delete[]arrr4[i];
		}
	}
	else if (format == 'd')
	{
		double* arrr = new double[c], * arrr2 = new double[r];
		double** arrr3, ** arrr4;
		arrr3 = new double* [r];
		for (int i = 0; i < r; i++)
		{
			arrr3[i] = new double[c];
		}
		arrr4 = new double* [c];
		for (int i = 0; i < c; i++)
		{
			arrr4[i] = new double[r];
		}
		Two_dimensional_array<double>a(r, c);
		a.function(r, c, r1, c1, arrr, arrr2, arrr3, arrr4);
		delete[]arrr;
		delete[]arrr2;
		for (int i = 0; i < r; i++)
		{
			delete[]arrr3[i];
		}
		for (int i = 0; i < c; i++)
		{
			delete[]arrr4[i];
		}
	}
	else if (format == 'c')
	{
		char* arrr = new char[c], * arrr2 = new char[r];
		char** arrr3, ** arrr4;
		arrr3 = new char* [r];
		for (int i = 0; i < r; i++)
		{
			arrr3[i] = new char[c];
		}
		arrr4 = new char* [c];
		for (int i = 0; i < c; i++)
		{
			arrr4[i] = new char[r];
		}
		Two_dimensional_array<char>a(r, c);
		a.function(r, c, r1, c1, arrr, arrr2, arrr3, arrr4);
		delete[]arrr;
		delete[]arrr2;
		for (int i = 0; i < r; i++)
		{
			delete[]arrr3[i];
		}
		for (int i = 0; i < c; i++)
		{
			delete[]arrr4[i];
		}
	}
	else if (format == 's')
	{
		string* arrr = new string[c], * arrr2 = new string[r];
		string** arrr3, ** arrr4;
		arrr3 = new string * [r];
		for (int i = 0; i < r; i++)
		{
			arrr3[i] = new string[c];
		}
		arrr4 = new string * [c];
		for (int i = 0; i < c; i++)
		{
			arrr4[i] = new string[r];
		}
		Two_dimensional_array<string>a(r, c);
		a.function(r, c, r1, c1, arrr, arrr2, arrr3, arrr4);
		delete[]arrr;
		delete[]arrr2;
		for (int i = 0; i < r; i++)
		{
			delete[]arrr3[i];
		}
		for (int i = 0; i < c; i++)
		{
			delete[]arrr4[i];
		}
	}
	else
	{
		cout << " Неправильний формат!!!!";
		goto skip;
	}
	cout << endl << endl << endl;
	(void)getchar();
	(void)getchar();
	(void)getchar();
	return 0;
}
