#include <iostream>
#include <iomanip>
#include <string>
#include <map>																	//Testing maps to keep track of grades
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
	-- Set a maximum number of students you can enter (change array to dynamically sized? Vector?)
	-- Clean up output code
*/

class Student																	//Student Class
{
	public:
		string fullName, fName, lName;
		char grade;
		float HWK1, HWK2, HWK3, EXM1, EXM2, PRCT;
		float TOTALHW, TOTALEX;

		float getTotalHW(void);													//Class Member function declarations
		float getTotalEX(void);
		void splitName(string);
};


float Student::getTotalHW(void)
{
	return HWK1 + HWK2 + HWK3;													//Get total homework points
}

float Student::getTotalEX(void)
{
	return EXM1 + EXM2;															//Get total exam points
}

void Student::splitName(string split)
{
	size_t position = split.find(" ");											//Find the first blank space position
	fName = split.substr(0, position);											//Split the first name from position 0 to first blank space
	lName = split.substr(++position);											//Split the last name from first blank space to end
}

void Roster(Student tempRoster[5]);												//Prototypes
void Print(Student localRoster[5]);
float Calculations(float, float);

void main()																		//Main
{
	Student Students[5];

	Roster(Students);
	Print(Students);
}

void Roster(Student tempRoster[5])												//Student Information
{
	float percentage;

	for(int i = 0; i < 5; i++)
	{
		cout << "Enter full student name: ";
		getline(cin, tempRoster[i].fullName);									//Store full name
		tempRoster[i].splitName(tempRoster[i].fullName);						//Split up the first and last names
		cout << "Enter " << tempRoster[i].fName << "'s Homework 1 points: ";	//Need to limit Homework points to >26, use another for loop
		cin >> tempRoster[i].HWK1;
		cout << "Enter " << tempRoster[i].fName << "'s  Homework 2 points: ";
		cin >> tempRoster[i].HWK2;
		cout << "Enter  " << tempRoster[i].fName << "'s Homework 3 points: ";
		cin >> tempRoster[i].HWK3;
		cout << "Enter " << tempRoster[i].fName << "'s Exam 1 points: ";		//Need to limit Exam points to >101
		cin >> tempRoster[i].EXM1;
		cout << "Enter " << tempRoster[i].fName << "'s Exam 2 points: ";
		cin >> tempRoster[i].EXM2;
		cout << "\n\n";
		cin.ignore(21, '\n');													//Flush the buffer

		percentage = ceil(Calculations(tempRoster[i].getTotalHW(), tempRoster[i].getTotalEX()));

		tempRoster[i].PRCT = percentage;

		if(percentage >= 90)													//Think about changing this to a switch for readability...
			tempRoster[i].grade = 'A';
		else if(percentage < 90 && percentage >= 80)
			tempRoster[i].grade = 'B';
		else if(percentage < 80 && percentage >= 70)
			tempRoster[i].grade = 'C';
		else if(percentage < 70 && percentage >= 60)
			tempRoster[i].grade = 'D';
		else
			tempRoster[i].grade = 'F';
	}
}

float Calculations(float hwPts, float examPts)									//Calculate percentage for letter grade
{
	float percentage;

	percentage = ((hwPts / 1.875) + (examPts / 3.333));

	return percentage;
}

void Print(Student localRoster[5])												//Print Student/Class information
{
	float avgEX1 = 0, avgEX2 = 0;												//Placeholders for Exam Average counts

	map<char, int> TotalGrades;													//Using a Map here to store key/value pairs for grade counter

	TotalGrades['A', 'B', 'C', 'D', 'F'] = 0;

	system("CLS");																//Clearing the screen to prepare for full output
			
	cout << setprecision(0) << fixed << endl;									//Headers per category
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
		cout << left << localRoster[i].fName.length() << 
			localRoster[i].lName << ", " << setw(18 - localRoster[i].lName.length()) << 
			localRoster[i].fullName << setw(4) << right <<
			localRoster[i].HWK1 << setw(4) << 
			localRoster[i].HWK2 << setw(4) << 
			localRoster[i].HWK3 << setw(9) << 
			localRoster[i].getTotalHW() << setw(6) << 
			localRoster[i].EXM1 << setw(6) << 
			localRoster[i].EXM2 << setw(9) << 
			localRoster[i].getTotalEX() << setw(4) << 
			localRoster[i].PRCT << setw(6) << 
			localRoster[i].grade << endl;

		avgEX1 += localRoster[i].EXM1;										//Calculate the average exam 1 score and the average exam 2 score
		avgEX2 += localRoster[i].EXM2;							

		
		TotalGrades[localRoster[i].grade] += 1;								//Calculate how many of each letter grade was given for the students
		
	}
	cout << "Class Exam 1 Average:\t" << avgEX1 / 5 << "\nClass Exam 2 Average:\t" << avgEX2 / 5 << endl;
	cout << "Total Class Grades: " << 
		"\nA - " << TotalGrades['A'] <<
		"\nB - " << TotalGrades['B'] << 
		"\nC - " << TotalGrades['C'] << 
		"\nD - " << TotalGrades['D'] << 
		"\nF - " << TotalGrades['F'] << endl;
}