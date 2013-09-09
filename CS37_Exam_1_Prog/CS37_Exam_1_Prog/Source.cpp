#include <iostream>
#include <iomanip>
#include <map> //Testing maps to keep track of grades
using namespace std;

//TODO
/*
	x Allow the user to enter in the data for each student
	x For each student, calclate their total homework points, their total exam points, and their class percentage.
		The formulas to use are as follows:
			x Total HW Points = HW1 + HW2 + HW3 //Range is from 0 - 25
			x Total Exam Points = EX1 + EX2 //Range is 0 - 100
			x Class Percentage = (TotalHW / 1.875) + (TotalExam / 3.333) //The class percentage will range from 0 to 100
	x Calculate the letter grade for each student based on the following scale:
		x 90 - 100 = A
		x 80 - 89.4 = B
		x 70 - 79.4 = C
		x 60 - 69.4 = D
		x 59.4 = F
	x Print out the name for each student followed by the results of your three calculations from Task 2 and the letter grade
	x Calculate and print the average exam 1 score and the average exam 2 score
	x Calculate and print how many ofeach letter grade was given for the students. That is, how many A's, how many B's, etc.

	-- Include check to make sure only strings are entered for name variables
	-- Include check to make sure only numbers are entered for scores
	-- Set a maximum number of students you can enter (change array to dynamically sized)
	-- Clean up output code
*/

//Student Class
class Student
{
	public:
		char name[32], grade;
		float HWK1, HWK2, HWK3, EXM1, EXM2, PRCT;
		float TOTALHW, TOTALEX;

		//Member function declarations
		float getTotalHW(void);
		float getTotalEX(void);
};

float Student::getTotalHW(void)
{
	//Get total homework points
	return HWK1 + HWK2 + HWK3;
}

float Student::getTotalEX(void)
{
	//Get total exam points
	return EXM1 + EXM2;
}

//Prototypes
void Roster(Student tempRoster[5]);
void Print(Student localRoster[5]);
float Calculations(float, float);

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
	float percentage;

	for(int i = 0; i < 5; i++)
	{
		cout << "Enter student name: ";
		cin.getline(tempRoster[i].name, 32);
		//Need to limit Homework points to >26
		cout << "Enter " << tempRoster[i].name << "'s Homework 1 points: ";
		cin >> tempRoster[i].HWK1;
		cout << "Enter " << tempRoster[i].name << "'s  Homework 2 points: ";
		cin >> tempRoster[i].HWK2;
		cout << "Enter  " << tempRoster[i].name << "'s Homework 3 points: ";
		cin >> tempRoster[i].HWK3;
		//Need to limit Exam points to >101
		cout << "Enter " << tempRoster[i].name << "'s Exam 1 points: ";
		cin >> tempRoster[i].EXM1;
		cout << "Enter " << tempRoster[i].name << "'s Exam 2 points: ";
		cin >> tempRoster[i].EXM2;
		cout << "\n\n";
		cin.ignore(32, '\n');

		percentage = ceil(Calculations(tempRoster[i].getTotalHW(), tempRoster[i].getTotalEX()));
		tempRoster[i].PRCT = percentage;

		//Think about changing this to a switch for readability...
		if(percentage >= 90)
		{
			tempRoster[i].grade = 'A';
		}
		else if(percentage < 90 && percentage >= 80)
		{
			tempRoster[i].grade = 'B';
		}
		else if(percentage < 80 && percentage >= 70)
		{
			tempRoster[i].grade = 'C';
		}
		else if(percentage < 70 && percentage >= 60)
		{
			tempRoster[i].grade = 'D';
		}
		else
		{
			tempRoster[i].grade = 'F';
		}
	}
}

//Calculate percentage for letter grade
float Calculations(float hwPts, float examPts)
{
	float percentage;

	percentage = ((hwPts / 1.875) + (examPts / 3.333));

	return percentage;
}

//Print all student information
void Print(Student localRoster[5]) //Print Student/Class information
{
	float avgEX1 = 0, avgEX2 = 0;
	map<char, int> TotalGrades;

	TotalGrades['A', 'B', 'C', 'D', 'F'] = 0;
	system("CLS");

	//Headers per category
	cout << setprecision(0) << fixed << endl;
	cout << setw(20) << left << 
		"NAME" << right << setw(4) << 
		"HW1" << setw(4) << 
		"HW2" << setw(4) << 
		"HW3" << setw(9) << 
		"HW_TOTAL" << setw(6) << 
		"EXAM1" << setw(6) << 
		"EXAM2" << setw(9) << 
		"EX_TOTAL" << setw(4) << 
		"%" << setw(6) << 
		"GRADE" << endl;

	for(int i = 0; i < 5; i++)
	{
		cout << left << setw(strlen(localRoster[i].name)) << localRoster[i].name << 
			setw(18-strlen(localRoster[i].name)) << 
			localRoster[i].HWK1 << setw(4) << 
			localRoster[i].HWK2 << setw(4) << 
			localRoster[i].HWK3 << setw(9) << 
			localRoster[i].getTotalHW() << setw(6) << 
			localRoster[i].EXM1 << setw(6) << 
			localRoster[i].EXM2 << setw(9) << 
			localRoster[i].getTotalEX() << setw(4) << 
			localRoster[i].PRCT << setw(6) << 
			localRoster[i].grade << endl;

		//Calculate the average exam 1 score and the average exam 2 score
		//Adding each exam score to local var
		avgEX1 += localRoster[i].EXM1;
		avgEX2 += localRoster[i].EXM2;
		
		//Calculate how many of each letter grade was given for the students
		//Using a map here to keep track of the grades given to all students, the key is the char for the letter grade ('A', 'B', etc.)
		TotalGrades[localRoster[i].grade] += 1;
	}
	cout << "Class Exam 1 Average:\t" << avgEX1 / 5 << "\nClass Exam 2 Average:\t" << avgEX2 / 5 << endl;
	cout << "Total Class Grades: " << 
		"\nA - " << TotalGrades['A'] <<
		"\nB - " << TotalGrades['B'] << 
		"\nC - " << TotalGrades['C'] << 
		"\nD - " << TotalGrades['D'] << 
		"\nF - " << TotalGrades['F'] << endl;
}