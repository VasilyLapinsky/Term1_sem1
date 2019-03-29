// Семестровая1.1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int n, m;
	cout << "Enter size= ";
	cin >> n >> m;
	while (!(n >= 1 && m >= 1 && m <= 400)){
		cout << "Enter size= ";
		cin >> n >> m;
	}
	int** mas = new int*[n];
	for (int i = 0; i < n; ++i){
		mas[i] = new int[m];
	}
	//Заполнение массива
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			cin >> mas[i][j];
		}
	}
	// находим максимальный элемент
	int x, y;
	x = y = 0;
	for (int i = 0; i < n; ++i){
		for (int j = 0; j < m; ++j){
			if (mas[x][y] < mas[i][j]){
				x = i;
				y = j;
			}
		}
	}
	int a;//box
	// передвигаем столбцы
	for (int i = 0; i < n; ++i){
		a = mas[i][0];
		mas[i][0] = mas[i][y];
		mas[i][y] = a;
	}
	//передвигаем строки
	for (int j = 0; j < m; ++j){
		a = mas[0][j];
		mas[0][j] = mas[x][j];
		mas[x][j] = a;
	}
	//Сортируем эл-ты 0 строки
	x = 0;
	y = 1;
	for (int k = 1; k < m-1 ; ++k){
		for (int j = k; j < m; ++j){
			if (mas[x][y] < mas[x][j]) y = j;
		}
		cout << mas[x][y] << endl;
		for (int i = 0; i < n; ++i){
			a = mas[i][k];
			mas[i][k] = mas[i][y];
			mas[i][y] = a;
		}
		
	}
	//Сортируем эл-ты 0 столбца
	x = 1;
	y = 0;
	for (int k = 1; k < n-1 ; ++k){
		for (int i = k; i < n; ++i){
			if (mas[x][y] < mas[i][y]) x = i;
		}
		for (int j = 0; j < m; ++j){
			a = mas[k][j];
			mas[k][j] = mas[x][j];
			mas[x][j] = a;
		}

	}

	//Выводим результат
	cout << mas[n - 1][m - 1] << endl;


	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			cout << mas[i][j] << ' ';
		}
		cout << endl;
	}

	system("pause");

	return 0;
}

