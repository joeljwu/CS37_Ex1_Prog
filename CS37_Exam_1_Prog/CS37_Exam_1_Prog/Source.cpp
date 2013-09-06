#include <iostream>
#include <iomanip>
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
	4. Print out the name for each student followed by the results of your three calculations from Task 2 and the letter grade
	5. Calculate and print the average exam 1 score and the average exam 2 score
	6. Calculate and print how many ofeach letter grade was given for the students. That is, how many A's, how many B's, etc.

	-- Include check to make sure only strings are entered for name variables
	-- Include check to make sure only numbers are entered for scores
	-- Set a maximum number of students you can enter (change array to dynamically sized)
*/

//Student Class
class Student
{
	public:
		char name[32], grade;
		float HWK1, HWK2, HWK3, EXM1, EXM2, PRCT;
		float TOTALHW, TOTALEX;
};

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
		cout << "\n\n";
		cin.ignore(32, '\n');
		
		//Calculate the averages and determine letter grade
		//Consider putting this as a method inside of the student class
		tempRoster[i].TOTALHW = tempRoster[i].HWK1 + tempRoster[i].HWK2 + tempRoster[i].HWK3;
		tempRoster[i].TOTALEX = tempRoster[i].EXM1 + tempRoster[i].EXM2;

		percentage = ceil(Calculations(tempRoster[i].TOTALHW, tempRoster[i].TOTALEX));
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
	float avgEX1, avgEX2;

	for(int i = 0; i < 5; i++)
	{
		//Print out the name for each student followed by the results of your three calculations from Task 2 and the letter grade
		cout << localRoster[i].name << "\n_______________\nTotal Homework Score:\t" << localRoster[i].TOTALHW << "\nTotal Exam Score:\t" << localRoster[i].TOTALEX 
			<< "\nClass Percentage:\t" << localRoster[i].PRCT  + '%' << "\nFinal Grade:\t" << localRoster[i].grade << endl;
		//Calculate and print the average exam 1 score and the average exam 2 score
		avgEX1 += localRoster[i].EXM1;
		avgEX2 += localRoster[i].EXM2;
		//Calculate and print how many of each letter grade was given for the students. That is, how many A's, how many B's, etc.

	}
	cout << "Class Exam 1 Average:\t" << avgEX1 / 5 << "\nClass Exam 2 Average:\t" << avgEX2 / 5 << endl;
}