#include <iostream>
using namespace std;

//TODO
/*
	1. Allow the user to enter in the data for each student
	2. For each student, calclate their total homework points, their total exam points, and their class percentage.
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
class Student
{
	public:
		char name[32];
		float HWK1, HWK2, HWK3, EXM1, EXM2, PRCT;
};

//Prototypes
void Roster(Student tempRoster[5]);
float Calculations(float hwPts, float examPts);

void main()
{
	//Code goes here
	Student Students[5];

	Roster(Students);
}

void Roster(Student tempRoster[5]) //Student info
{
	float hwTotal;
	float exTotal;
	float cPercentage;

	for(int i = 0; i < 5; i++)
	{
		cout << "Enter a name: " << endl;
		cin.getline(tempRoster[i].name, 32);
		cout << "Enter Homework 1 points: " << endl;
		cin >> tempRoster[i].HWK1;
		cout << "Enter Homework 2 points: " << endl;
		cin >> tempRoster[i].HWK2;
		cout << "Enter Homework 3 points: " << endl;
		cin >> tempRoster[i].HWK3;
		hwTotal = tempRoster[i].HWK1 + tempRoster[i].HWK2 + tempRoster[i].HWK3;
		exTotal = tempRoster[i].EXM1 + tempRoster[i].EXM2;
		cPercentage = Calculations(hwTotal, exTotal);
		//Buffer needs to be cleared out here
	}
}

float Calculations(float hwPts, float examPts) //Calculate averages and percentages
{
	float percentage;
	percentage = (hwPts / 1.875) + (examPts / 3.333);
	return percentage;
}

void Print(Student localRoster[5]) //Print Student/Class information
{
	//Print out the name for each student followed by the results of your three calculations from Task 2 and the letter grade
	//Calculate and print the average exam 1 score and the average exam 2 score
	//Calculate and print how many ofeach letter grade was given for the students. That is, how many A's, how many B's, etc.
}



