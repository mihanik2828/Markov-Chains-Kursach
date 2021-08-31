#include <iostream>
#include<ctime>
#include<string>
#include<algorithm>
#include<cmath>
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m, p;
	double r1, re;




	cout << "Введите количество состояний в системе" << endl;
	cin >> n;
	cout << "Введите количество шагов" << endl;
	cin >> m;
	int control; // Выбор управления
	cout << "Введите <<1>> если хотите использовать управление и <<2>> - если нет" << endl;
	cin >> control;

	if (control == 2)
	{
		double** dohod = new double* [n]; // две строки в массиве
		for (int count = 0; count < n; count++)
			dohod[count] = new double[n];

		double* income = new double[n];
		double* incomehelp = new double[n];

		double* q = new double[n];
		double* v0 = new double[n];

		double* chance = new double[n];
		double* chancehelp = new double[n];
		double** arr = new double* [n]; // две строки в массиве
		for (int count = 0; count < n; count++)
			arr[count] = new double[n];
		cout << "Сумма всех вероятностей перехода для одного состояния должна равняться единице и каждая вероятность должна быть в границах от 0 до 1" << endl;

		for (int count_row = 0; count_row < n; count_row++)
		{
			double sum = 0;
			//	while (sum != 1)
			//	{
			sum = 0;
			for (int count_column = 0; count_column < n; count_column++)
			{
				do
				{
					cout << "\n Введите веротность перехода из " << count_row + 1 << " состояния в " << count_column + 1 << " состояние" << endl;
					cin >> arr[count_row][count_column];



					sum += arr[count_row][count_column];
				} while ((arr[count_row][count_column] > 1) || ((arr[count_row][count_column]) < 0));

			}
		}
		for (int count_row = 0; count_row < n; count_row++)
		{
			for (int count_column = 0; count_column < n; count_column++)
			{
				do
				{
					cout << "\n Введите полученный доход перехода из " << count_row + 1 << " состояния в " << count_column + 1 << " состояние" << endl;
					cin >> dohod[count_row][count_column];
				} while ((arr[count_row][count_column] > 1) || ((arr[count_row][count_column]) < 0));

			}

		}

		for (int count_row = 0; count_row < n; count_row++)
		{
			cout << "\n";
			for (int count_column = 0; count_column < n; count_column++)
				cout << arr[count_row][count_column] << "\t";
		}

		cout << endl;

		for (int count_row = 0; count_row < n; count_row++)
		{
			cout << "\n";
			for (int count_column = 0; count_column < n; count_column++)
				cout << dohod[count_row][count_column] << "\t";
		}

		double sum = 0;
		//while (sum != 1)
		//{
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			cout << "\n Введите вероятность начального нахождения в " << i + 1 << "-ом состоянии ";
			cin >> chance[i];
			chancehelp[i] = 0;
			sum += chance[i];
		}
		//}

		double sum1 = 0;

		for (int count_row = 0; count_row < n; count_row++)
		{
			q[count_row] = 0;
		}


		for (int count_row = 0; count_row < n; count_row++)
		{
			for (int count_column = 0; count_column < n; count_column++)
			{
				q[count_row] += arr[count_row][count_column] * dohod[count_row][count_column];
			}
		}

		for (int count_row = 0; count_row < n; count_row++)
		{
			income[count_row] = q[count_row];
		}

		for (int number = 1; number <= m; number++)
		{

			for (int count_row = 0; count_row < n; count_row++)
			{
				incomehelp[count_row] = q[count_row];
				for (int count_column = 0; count_column < n; count_column++)
				{
					sum1 = arr[count_row][count_column] * chance[count_row];
					chancehelp[count_column] += sum1;
					sum1 = 0;

					incomehelp[count_row] += income[count_column] * arr[count_row][count_column];
				}

				sum1 = 0;
			}

			for (int i = 0; i < n; i++)
			{
				chance[i] = chancehelp[i];
				chancehelp[i] = 0;
			}


			for (int i = 0; i < n; i++)
			{
				cout << "\n Вероятоность попасть через " << number << "тактов в " << i + 1 << "состояние составляет :\t" << chance[i] << "\t";
			}

			cout << endl << endl;

			for (int i = 0; i < n; i++)
			{
				cout << "\n Полученный доход через " << number << "тактов " << i + 1 << "состояния составляет :\t" << income[i] << "\t";
			}

			for (int i = 0; i < n; i++)
			{
				income[i] = incomehelp[i];
				incomehelp[i] = 0;
			}

		}
	}
	else
	{

		int controlcount;
		cout << "Введите количество управлений для каждого элемента" << endl;
		cin >> controlcount;

		double*** dohod = new double** [controlcount]; // Создание трехмерного массива доходов
		for (int i = 0; i < controlcount; i++) {
			dohod[i] = new double* [n]; //выделяем память на столбцы

			for (int j = 0; j < n; j++) {
				dohod[i][j] = new double[n]; //выделяем память на строки.
			}
		}

		double* incomeindex = new double[n];
		double* income = new double[n];
		double* incomehelp = new double[n];
		int* maxincomeindex = new int[n];// Индекс этой величины 
		double* maxincome = new double[n];// Величина для поиска максимального одношагового дохода для каждой величины

		double** q = new double* [controlcount]; // две строки в массиве
		for (int count = 0; count < controlcount; count++)
			q[count] = new double[n];

		//double* q = new double[n];
		double* v0 = new double[n];

		double* chance = new double[n];
		double* chancehelp = new double[n];


		double*** arr = new double** [controlcount]; // Создание трехмерного массива вероятностей
		for (int i = 0; i < controlcount; i++) {
			arr[i] = new double* [n]; //выделяем память на столбцы

			for (int j = 0; j < n; j++) {
				arr[i][j] = new double[n]; //выделяем память на строки.
			}
		}


		cout << "Сумма всех вероятностей перехода для одного состояния должна равняться единице и каждая вероятность должна быть в границах от 0 до 1" << endl;

		int ten;
		cout << "ten????1da2net" << endl;
		cin >> ten;
		ifstream file; // создаем объект класса ifstream
		file.open("experiment10.txt"); // открываем файл

		if (!file)
		{
			cout << "Файл не открыт\n\n";
			
		}
		else
		{
			cout << "Все ОК! Файл открыт!\n\n";
			
		}

		for (int count_control = 0; count_control < controlcount; count_control++)
		{
			for (int count_row = 0; count_row < n; count_row++)
			{
				double sum = 0;
				//	while (sum != 1)
				//	{
				sum = 0;
				cout << endl;
				for (int count_column = 0; count_column < n; count_column++)
				{
					//do
					//{
					if (ten == 2)
					{
						cout << "\n Введите веротность при использовании \n" << count_control + 1 << " управления \nперехода из " << count_row + 1 << " состояния в " << count_column + 1 << " состояние" << endl;
						cin >> arr[count_control][count_row][count_column];

						arr[count_control][count_row][count_column] = arr[count_control][count_row][count_column] / 2; // для примера с 10-ю примерами , убрать после проведения эксперимента

						sum += arr[count_control][count_row][count_column];
						//} while ((arr[count_control][count_row][count_column] > 1) || ((arr[count_control][count_row][count_column]) < 0));
					}
					else
						file >> arr[count_control][count_row][count_column];
					arr[count_control][count_row][count_column] = arr[count_control][count_row][count_column] / 2;
					cout << arr[count_control][count_row][count_column] << " ";
				}
			}
		}
		
		
		
		for (int count_control = 0; count_control < controlcount; count_control++)
		{
			for (int count_row = 0; count_row < n; count_row++)
			{
				cout << endl;
				for (int count_column = 0; count_column < n; count_column++)
				{
//					do
	//				{
						if (ten == 2)
						{
							cout << "\n Введите полученный доход при использовании \n" << count_control + 1 << " управления \n перехода из " << count_row + 1 << " состояния в " << count_column + 1 << " состояние" << endl;
							cin >> dohod[count_control][count_row][count_column];
						}
						else
							file >> dohod[count_control][count_row][count_column];
						cout << dohod[count_control][count_row][count_column] << " ";
	//				} while ((arr[count_control][count_row][count_column] > 1) || ((arr[count_row][count_column]) < 0));

				}

			}
		}


		for (int count_control = 0; count_control < controlcount; count_control++)
		{
			cout << "\nИспользование " << count_control << " управления \n" << "Матрица вероятностей\n";
			for (int count_row = 0; count_row < n; count_row++)
			{
				cout << "\n";
				
				for (int count_column = 0; count_column < n; count_column++)
					cout << arr[count_control][count_row][count_column] << "\t";
			}

			cout << endl;

			cout << "\nИспользование " << count_control << " управления \n" << "Матрица дохода\n";
			for (int count_row = 0; count_row < n; count_row++)
			{
				cout << "\n";
				
				for (int count_column = 0; count_column < n; count_column++)
					cout << dohod[count_control][count_row][count_column] << "\t";
			}
		}

		double sum = 0;
		//while (sum != 1)
		//{
		sum = 0;
		for (int i = 0; i < n; i++)
		{
			cout << "\n Введите вероятность начального нахождения в " << i + 1 << "-ом состоянии ";
			cin >> chance[i];
			chancehelp[i] = 0;
			sum += chance[i];
		}
		//}

		double sum1 = 0;
		for (int count_control = 0; count_control < controlcount; count_control++)
		{
			for (int count_row = 0; count_row < n; count_row++)
			{
				q[count_control][count_row] = 0;
			}
		}

		for (int count_control = 0; count_control < controlcount; count_control++)
		{
			for (int count_row = 0; count_row < n; count_row++)
			{
				for (int count_column = 0; count_column < n; count_column++)
				{
					q[count_control][count_row] += arr[count_control][count_row][count_column] * dohod[count_control][count_row][count_column];
					//cout << "count_control " <<count_control << "\tcount_row " << count_row << "\tcount_column " <<count_column  << "   q "<<q[count_control][count_row] << endl;
				}
			}
		}


		for (int count_control = 0; count_control < controlcount; count_control++)
		{
			for (int count_row = 0; count_row < n; count_row++)
			{

				cout << q[count_control][count_row] << " \n";
			}
			cout << endl;
		}
		

		for (int i = 0; i < n; i++)
		{
			maxincome[i] = -9999;
			maxincomeindex[i] = 0;
		}

		for (int count_row = 0; count_row < n; count_row++) // Вычисляем максимальный ожидаемый одношаговый доход для каждого состояния
		{
			for (int count_control = 0; count_control < controlcount; count_control++)
			{
				if (q[count_control][count_row] > maxincome[count_row])
				{
					maxincome[count_row] = q[count_control][count_row];
					maxincomeindex[count_row] = count_control;
				}
			}
			income[count_row] = maxincome[count_row];
			incomeindex[count_row] = maxincomeindex[count_row];
		}



		for (int number = 1; number <= m; number++) // Цикл шагов 
		{

			for (int count_row = 0; count_row < n; count_row++)
			{
				incomehelp[count_row] = maxincome[count_row];
				for (int count_column = 0; count_column < n; count_column++)
				{
					sum1 = arr[maxincomeindex[count_row]][count_row][count_column] * chance[count_row];
					chancehelp[count_column] += sum1;
					sum1 = 0;

					incomehelp[count_row] += income[count_column] * arr[maxincomeindex[count_row]][count_row][count_column];
				}

				sum1 = 0;
			}


			for (int i = 0; i < n; i++)
			{
				chance[i] = chancehelp[i];
				chancehelp[i] = 0;
			}

			cout << endl << endl;

			for (int i = 0; i < n; i++)
			{
				cout << "\n Вероятоность попасть через " << number << "тактов в " << i + 1 << " состояние составляет :\t" << chance[i] << endl;
			}

			cout << endl;

			for (int i = 0; i < n; i++)
			{
				cout << "Полученный доход через " << number << "тактов " << i + 1 << " состояния составляет :\t" << income[i] << endl;	
			}

			for (int i = 0; i < n; i++)
			{
				income[i] = incomehelp[i];
				incomehelp[i] = 0;
			}

		}
		cout << endl << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "\nДля состояния " << i + 1 << " наибольший одношаговый доход " << maxincome[i] << " при условии выбора управления: " << maxincomeindex[i]+1 << endl;
		}

	}

	


	system("pause");
}





