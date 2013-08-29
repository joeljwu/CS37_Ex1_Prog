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

//Prototypes
float calculations(float hwPoints, float examPoints); //average and percentage
void Print(string Student, float hwPoints, float examPoints, float percentage); //print statements to the console

class Student
{
	public:
		string name;
		float HWK1, HWK2, HWK3, EXM1, EXM2, PRCT;

};

void main()
{
	//Code goes here
	float HW1, HW2, HW3 = 0.0;
	float EX1, EX2 = 0.0;
	float classPct = 0.0;

	system("PAUSE");
}