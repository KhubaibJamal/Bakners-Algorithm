#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

COORD coord = { 0, 0 };
void gotoxy(int x, int y) //set cursoer position
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


int main()
{
	system("color FF");     //  for console color
	gotoxy(17, 5);
	cout << "--------------------------------------------" << endl;
	gotoxy(17, 7);
	cout << "||            Banker's Alogorithm          ||" << endl;
	gotoxy(17, 9);
	cout << "--------------------------------------------" << endl;
	gotoxy(17, 11);
	cout << "|Subject Teacher -->> Sir Rahil Usman <<-- |\n" << endl;
	gotoxy(17, 13);
	cout << ">>>---------Project Implemented By---------<<<" << endl;
	gotoxy(22, 15);
	cout << "Khubaib Jamal\t   (2020F-BCS-265)" << endl;
	gotoxy(22, 16);
	cout << "Hammad Shoaib\t   (2020F-BCS-038)" << endl;
	gotoxy(22, 17);
	cout << "Muhammad Talha\t   (2020F-BCS-044)" << endl << endl;
	system("pause");
	system("cls");
	system("color F1");

	int resorces, process;
	int intances[5]; // at least 5 values
	// Enter the Resorces
	cout << "Enter No. of Resorces: ";
	cin >> resorces;
	cout << endl;
	// user value for Intances
	for (int i = 0; i < resorces; i++)
	{
		cout<<"Enter the instance of resource R[" << i << "]: "; 
		cin >> intances[i];
		// available[i] = intances[i];
	}

	// Enter the Process
	cout << "\nEnter the No. of Process: ";
	cin >> process;
	// user value for Aloocation Resorces 
	//Allocated Resorces allocation[process][resorces]
	//								[row][column]
	int** allocation = new int*[process];
	for (int i = 0; i < process; i++)
	{
		allocation[i] = new int[resorces];
	}
	for (int i = 0; i < process; i++)
	{
		cout << "\nFOR THE PROCESS P[" << i << "]" << endl;
		for (int j = 0; j < resorces; j++)
		{
			cout << "allocation of resource R[" << j << "]is: ";
			cin >> allocation[i][j];
		}
	}

	// User value for Maximum Resources
	cout << "\n\t\t----------MAXIMUM Resources----------" << endl;
	int** max = new int*[process];
	for (int i = 0; i < process; i++)
	{
		max[i] = new int[resorces];
	}
	for (int i = 0; i < process; i++)
	{
		cout << "\nFOR THE PROCESS P[" << i << "]" << endl;
		for (int j = 0; j < resorces; j++)
		{
			cout << "Max Resource R[" << j << "]is: ";
			cin >> max[i][j];
		}
	}

	// Calculation For Need Resorces (Need = max - allocation)
	int** need = new int*[process];
	for (int i = 0; i < process; i++)
	{
		need[i] = new int[resorces];
	}
	for (int i = 0; i < process; i++)
	{
		for (int j = 0; j < resorces; j++)
		{
			need[i][j] = max[i][j] - allocation[i][j];
		}
	}

	// Printing Allocation, Max, Need Resources
	cout << "\tALLOCATION\t\t\tMAX\t\t\t\tNEED" << endl;
	for (int i = 0; i < resorces; i++)
	{
		cout << "\tR[" << i << "] ";
	}
	cout << endl;
	for (int i = 0; i < process; i++)
	{
		cout << "P[" << i << "]";
		for (int j = 0; j < resorces; j++)
		{
			cout << "\t" << allocation[i][j];
		}
		cout << "\t";
		for (int k = 0; k < resorces; k++)
		{
			cout << "\t" << max[i][k];
		}
		cout << "\t";
		for (int k = 0; k < resorces; k++)
		{
			cout << "\t" << need[i][k];
		}
		cout << endl;
	}
	
	// Available
	//int available[resorces];
	int *avail = new int[resorces];
	for (int i = 0; i < resorces; i++)
	{
		int cSum = 0;
		for (int j = 0; j < process; j++)
		{
			cSum += allocation[j][i];
		}
		avail[i] = cSum;
	}

	// Available Resorces
	int*available = new int[resorces];
	for (int i = 0; i < resorces; i++)
	{
		available[i] = intances[i] - avail[i];
	}

	// Check for Safe State
	int* finish = new int[process];
	int* answer = new int[process];
	int index = 0;
	for (int i = 0; i < process; i++)
	{
		finish[i] = 0;
	}
	int y = 0;
	for (int k = 0; k < process; k++)
	{
		for (int i = 0; i < process; i++)
		{
			if (finish[i] == 0)
			{
				int flag = 0;
				for (int j = 0; j < resorces; j++)
				{
					if (need[i][j] > available[j]) {
						flag = 1;
					}
					break;
				}
				if (flag == 0)
				{
					answer[index++] = i;
					for (y = 0; y < resorces; y++)
					{
						available[y] += allocation[i][y];
					}
					finish[i] = 1;
				}
			}
		}
	}
	cout << "\nFollowing are the Safe Sequence:" << endl;
	if (process == index)
	{
		for (int i = 0; i < process - 1; i++)
		{
			cout << "P" << answer[i] << " ";
		}
		cout << "P" << answer[process - 1];
		cout << "\nSystem is not in Deadlock" << endl;
	}
	else
	{
		cout << "\nSystem is in Deadlock" << endl;
	}
	cout << endl;
	_getch();
	return 0;
}