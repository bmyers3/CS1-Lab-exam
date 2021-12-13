//Braeden Myers
//This program will run the lottery game for the university

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>  

using namespace std;

const int NUMBER_OF_STUDENTS = 50;

struct Students
{
	int id_num = 0;
	string student_name;
	int stu_nums[7];
	int matches = 0;
	double money = 0;
};

void getInfo(Students student_info[], int lottery_nums[7], int& num_of_students);
void matchChoices(Students student_info[], int lottery_nums[7], int& num_of_students);
void sortStudents(Students student_info[], int lottery_nums[7], int& num_of_students);
void displayLottoInfo(Students student_info[], int lottery_nums[7], int& num_of_students);

int main()
{
	Students student_info[NUMBER_OF_STUDENTS];
	int lottery_nums[7] = { 0 };
	int num_of_students = 0;

	getInfo(student_info, lottery_nums, num_of_students);
	matchChoices(student_info, lottery_nums, num_of_students);
	sortStudents(student_info, lottery_nums, num_of_students);
	displayLottoInfo(student_info, lottery_nums, num_of_students);
}

//This program inports the file
void getInfo(Students student_info[], int lottery_nums[7], int& num_of_students)
{
	ifstream inFile;  //Input file stream to open file and read         

	int i = 0; //index for position in array of structures
	inFile.open("g1.txt"); //open file to read from 

	if (!inFile) //check to see if file is open
		cout << "\n\n**** ERROR OPENING FILE. ******\n" << endl;
	else
	{
		while (!inFile.eof()) //while not at end of file(eof)
		{
			num_of_students++;
			inFile >> student_info[i].id_num; //read student id
			getline(inFile, student_info[i].student_name);//get name
			for (int j = 0; j < 7; j++)
			{
				inFile >> student_info[i].stu_nums[j];   
			}
			i++;
		}
	}
	inFile.close();
	num_of_students--;
}

//This matches and compares choices to the lotto numbers
void matchChoices(Students student_info[], int lottery_nums[7], int& num_of_students)
{
	cout << "Enter the 7 different, random numbers between 1 and 50 that were selected.";
	for (int i = 0; i < 7; i++)
	{
		cout << "\nNumber " << i + 1 << ": ";
		cin >> lottery_nums[i];
	}
	for (int i = 0; i < num_of_students; i++)
	{
		student_info[i].matches = 0;
		for (int j = 0; j < 7; j++)
		{
			for (int k = 0; k < 7; k++)
			{
				if (student_info[i].stu_nums[j] == lottery_nums[k])
					student_info[i].matches++;
			}
		}
	}

	for (int i = 0; i < num_of_students; i++)
	{
		if (student_info[i].matches == 7)
			student_info[i].money = 20;
		else if (student_info[i].matches == 6)
			student_info[i].money = 10;
		else if (student_info[i].matches == 5)
			student_info[i].money = 5;
		else if (student_info[i].matches < 5)
			student_info[i].money = 0;
	}
}

//sorts students into alphabetical order
void sortStudents(Students student_info[], int lottery_nums[7], int& num_of_students)
{
	int i, j;
	Students temp;
	for (i = 0; i < num_of_students - 1; i++)
	{
		for (j = 1; j < num_of_students; j++)
		{
			if (student_info[j].student_name < student_info[j-1].student_name)
			{
				temp = student_info[j];
				student_info[j] = student_info[j - 1];
				student_info[j - 1] = temp;
			}
		}
	}
}

//displays all info
void displayLottoInfo(Students student_info[], int lottery_nums[7], int& num_of_students)
{
	cout << "\n\n * * * * * * * * * * * * * * * * * Results Report  * * * * * * * * * * * * * * * * * \n\n";
	cout << "\nStudent ID	Student Name		Chosen Numbers			Matches		 Prize $" << endl << endl;
	for (int i = 0; i < num_of_students; i++)
	{
		cout << left;
		cout << setw(15) << student_info[i].id_num;
		cout << setw(20) << student_info[i].student_name;
		for (int j = 0; j < 7; j++)
		{
			cout << setw(4) << student_info[i].stu_nums[j];
		}
		cout << right;
		cout << "      	" << setw(4) << student_info[i].matches;
		cout << setprecision(2) << fixed;
		cout << "		" << setw(6) << student_info[i].money;
		cout << endl;
	}
	cout << endl << endl << endl;
	cout << "* * * * * * * * * Winnings Report * * * * * * * * * *\n\n";
	cout << "******** Students Who Matched All 7 Numbers *********\n\n";
	cout << "Student ID	 Student Name  Matches	Prize $\n\n";
	for (int i = 0; i < num_of_students; i++)
	{
		if (student_info[i].matches == 7)
		{
			cout << left;
			cout << setw(15) << student_info[i].id_num;
			cout << setw(20) << student_info[i].student_name;
			cout << setw(6) << student_info[i].matches;
			cout << setprecision(2) << fixed;
			cout << setw(6) << student_info[i].money;
			cout << endl;
		}
		else;
	}
	cout << "\n******** Students Who Matched All 6 Numbers *********\n\n";
	cout << "Student ID	Student Name   Matches	Prize $\n\n";
	for (int i = 0; i < num_of_students; i++)
	{
		if (student_info[i].matches == 6)
		{
			cout << left;
			cout << setw(15) << student_info[i].id_num;
			cout << setw(20) << student_info[i].student_name;
			cout << setw(6) << student_info[i].matches;
			cout << setprecision(2) << fixed;
			cout << setw(6) << student_info[i].money;
			cout << endl;
		}
		else;
	}
	cout << "\n******** Students Who Matched All 5 Numbers *********\n\n";
	cout << "Student ID	Student Name  Matches	Prize $\n\n";
	for (int i = 0; i < num_of_students; i++)
	{
		if (student_info[i].matches == 5)
		{
			cout << left;
			cout << setw(15) << student_info[i].id_num;
			cout << setw(20) << student_info[i].student_name;
			cout << setw(6) << student_info[i].matches;
			cout << setprecision(2) << fixed;
			cout << setw(6) << student_info[i].money;
			cout << endl;
		}
		else;
	}
}