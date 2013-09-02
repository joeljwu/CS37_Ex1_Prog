#include <iostream>
#include <iomanip>
using namespace std;

//TODO
/*
	x Allow the user to enter in the data for each student
	x For each student, calclate their total homework points, their total exam points, and their class percentage.
		The formulas to use are as follows:
			Total HW Points = HW1 + HW2 + HW3
			Total Exam Points = EX1 + EX2
			Class Percentage = (TotalHW / 1.875) + (TotalExam / 3.333) //The class percentage will range from 0 to 100
	3. Calculate the letter grade for each student based on the following scale:
		90 - 100 = A
		80 - 89.4 = B
		70 - 79.4 = C
		60 - 69.4 = D
		>59.4 = F
	4. Print out the name for each student followed by the results of your three calculations from Task 2 and the letter grade
	5. Calculate and print the average exam 1 score and the average exam 2 score
	6. Calculate and print how many ofeach letter grade was given for the students. That is, how many A's, how many B's, etc.
*/

//Student Class
class Student
{
	public:
		char name[32];
		float HWK1, HWK2, HWK3, EXM1, EXM2, PRCT;
};

//Prototypes
void Roster(Student tempRoster[5]);
void Print(Student localRoster[5]);
float Calculations(float hwPts, float examPts);

//Main
void main()
{
	Student Students[5];

	Roster(Students);
	Print(Students);
}

//Student Information
void Roster(Student tempRoster[5])
{
	float hwTotal;
	float exTotal;
	float cPercentage;

	for(int i = 0; i < 5; i++)
	{
		cout << "Enter student name: ";
		cin.getline(tempRoster[i].name, 32);
		cout << "Enter " << tempRoster[i].name << "'s Homework 1 points: ";
		cin >> tempRoster[i].HWK1;
		cout << "Enter " << tempRoster[i].name << "'s  Homework 2 points: ";
		cin >> tempRoster[i].HWK2;
		cout << "Enter  " << tempRoster[i].name << "'s Homework 3 points: ";
		cin >> tempRoster[i].HWK3;
		cout << "Enter " << tempRoster[i].name << "'s Exam 1 points: ";
		cin >> tempRoster[i].EXM1;
		cout << "Enter " << tempRoster[i].name << "'s Exam 2 points: ";
		cin >> tempRoster[i].EXM2;
		cin.ignore(32, '\n');
		hwTotal = tempRoster[i].HWK1 + tempRoster[i].HWK2 + tempRoster[i].HWK3;
		exTotal = tempRoster[i].EXM1 + tempRoster[i].EXM2;
		cPercentage = Calculations(hwTotal, exTotal);
		//temp to test calculation return
		cout << fixed << setprecision(2) << cPercentage << '\n';
	}
}

//Calculate percentage for letter grade
float Calculations(float hwPts, float examPts)
{
	float percentage;
	percentage = (hwPts / 1.875) + (examPts / 3.333);
	return percentage;
}

//Print all student information
void Print(Student localRoster[5]) //Print Student/Class information
{
	//Print out the name for each student followed by the results of your three calculations from Task 2 and the letter grade
	//Calculate and print the average exam 1 score and the average exam 2 score
	//Calculate and print how many ofeach letter grade was given for the students. That is, how many A's, how many B's, etc.
}