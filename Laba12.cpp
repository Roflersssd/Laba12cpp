#include <stdio.h>
#include <math.h>
#include <locale.h>

const double epsilon = 0.000'001;//Точность
const double step = 0.1;//Шаг
const double A = 3.0;//Конечное значение аргумента
const int M = 4;//Количество строк для вывода ответа

int fact(int x);
double mySh(double x);

int main() {
	int len = roundf((((A - 0) / step) + 1) / M);//Количество значений в строке вывода
	int count = 0;//Счетчик выведенных элементов
	for (double i = 0; i<A+step; i += step) {//Цикл для 
		if (count % len != 0) {
			printf(" %f", mySh(i));
		}//if
		else {
			printf("\n%f", mySh(i));
		}//else
		count++;
	}//for i от 0 до А
	return 0;
}//main

double mySh(double x) {
	double res = 0;
	int n = 0;
	double term=0;
	do {
		if (n == 0) {
			term = x;
			res += term;
		}
		else {
			term =term*x*x;
			term = term /((2 * n * (2 * n + 1)));
			res += term;
		}
		n++;
	} while (term >= epsilon);
	return res;
}//mySh
