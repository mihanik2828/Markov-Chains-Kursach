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




	cout << "������� ���������� ��������� � �������" << endl;
	cin >> n;
	cout << "������� ���������� �����" << endl;
	cin >> m;
	int control; // ����� ����������
	cout << "������� <<1>> ���� ������ ������������ ���������� � <<2>> - ���� ���" << endl;
	cin >> control;

	if (control == 2)
	{
		double** dohod = new double* [n]; // ��� ������ � �������
		for (int count = 0; count < n; count++)
			dohod[count] = new double[n];

		double* income = new double[n];
		double* incomehelp = new double[n];

		double* q = new double[n];
		double* v0 = new double[n];

		double* chance = new double[n];
		double* chancehelp = new double[n];
		double** arr = new double* [n]; // ��� ������ � �������
		for (int count = 0; count < n; count++)
			arr[count] = new double[n];
		cout << "����� ���� ������������ �������� ��� ������ ��������� ������ ��������� ������� � ������ ����������� ������ ���� � �������� �� 0 �� 1" << endl;

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
					cout << "\n ������� ���������� �������� �� " << count_row + 1 << " ��������� � " << count_column + 1 << " ���������" << endl;
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
					cout << "\n ������� ���������� ����� �������� �� " << count_row + 1 << " ��������� � " << count_column + 1 << " ���������" << endl;
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
			cout << "\n ������� ����������� ���������� ���������� � " << i + 1 << "-�� ��������� ";
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
				cout << "\n ������������ ������� ����� " << number << "������ � " << i + 1 << "��������� ���������� :\t" << chance[i] << "\t";
			}

			cout << endl << endl;

			for (int i = 0; i < n; i++)
			{
				cout << "\n ���������� ����� ����� " << number << "������ " << i + 1 << "��������� ���������� :\t" << income[i] << "\t";
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
		cout << "������� ���������� ���������� ��� ������� ��������" << endl;
		cin >> controlcount;

		double*** dohod = new double** [controlcount]; // �������� ����������� ������� �������
		for (int i = 0; i < controlcount; i++) {
			dohod[i] = new double* [n]; //�������� ������ �� �������

			for (int j = 0; j < n; j++) {
				dohod[i][j] = new double[n]; //�������� ������ �� ������.
			}
		}

		double* incomeindex = new double[n];
		double* income = new double[n];
		double* incomehelp = new double[n];
		int* maxincomeindex = new int[n];// ������ ���� �������� 
		double* maxincome = new double[n];// �������� ��� ������ ������������� ������������ ������ ��� ������ ��������

		double** q = new double* [controlcount]; // ��� ������ � �������
		for (int count = 0; count < controlcount; count++)
			q[count] = new double[n];

		//double* q = new double[n];
		double* v0 = new double[n];

		double* chance = new double[n];
		double* chancehelp = new double[n];


		double*** arr = new double** [controlcount]; // �������� ����������� ������� ������������
		for (int i = 0; i < controlcount; i++) {
			arr[i] = new double* [n]; //�������� ������ �� �������

			for (int j = 0; j < n; j++) {
				arr[i][j] = new double[n]; //�������� ������ �� ������.
			}
		}


		cout << "����� ���� ������������ �������� ��� ������ ��������� ������ ��������� ������� � ������ ����������� ������ ���� � �������� �� 0 �� 1" << endl;

		int ten;
		cout << "ten????1da2net" << endl;
		cin >> ten;
		ifstream file; // ������� ������ ������ ifstream
		file.open("experiment10.txt"); // ��������� ����

		if (!file)
		{
			cout << "���� �� ������\n\n";
			
		}
		else
		{
			cout << "��� ��! ���� ������!\n\n";
			
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
						cout << "\n ������� ���������� ��� ������������� \n" << count_control + 1 << " ���������� \n�������� �� " << count_row + 1 << " ��������� � " << count_column + 1 << " ���������" << endl;
						cin >> arr[count_control][count_row][count_column];

						arr[count_control][count_row][count_column] = arr[count_control][count_row][count_column] / 2; // ��� ������� � 10-� ��������� , ������ ����� ���������� ������������

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
							cout << "\n ������� ���������� ����� ��� ������������� \n" << count_control + 1 << " ���������� \n �������� �� " << count_row + 1 << " ��������� � " << count_column + 1 << " ���������" << endl;
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
			cout << "\n������������� " << count_control << " ���������� \n" << "������� ������������\n";
			for (int count_row = 0; count_row < n; count_row++)
			{
				cout << "\n";
				
				for (int count_column = 0; count_column < n; count_column++)
					cout << arr[count_control][count_row][count_column] << "\t";
			}

			cout << endl;

			cout << "\n������������� " << count_control << " ���������� \n" << "������� ������\n";
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
			cout << "\n ������� ����������� ���������� ���������� � " << i + 1 << "-�� ��������� ";
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

		for (int count_row = 0; count_row < n; count_row++) // ��������� ������������ ��������� ����������� ����� ��� ������� ���������
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



		for (int number = 1; number <= m; number++) // ���� ����� 
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
				cout << "\n ������������ ������� ����� " << number << "������ � " << i + 1 << " ��������� ���������� :\t" << chance[i] << endl;
			}

			cout << endl;

			for (int i = 0; i < n; i++)
			{
				cout << "���������� ����� ����� " << number << "������ " << i + 1 << " ��������� ���������� :\t" << income[i] << endl;	
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
			cout << "\n��� ��������� " << i + 1 << " ���������� ����������� ����� " << maxincome[i] << " ��� ������� ������ ����������: " << maxincomeindex[i]+1 << endl;
		}

	}

	


	system("pause");
}





