// computing-student-grades.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ios>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;
using std::streamsize;
using std::setprecision;


int main()
{
	cout << "Please enter your name: ";
	string name;
	cin >> name;

	cout << "Hello, " + name + "!" << endl;
	cout << "Please enter your midterm and final grades: " << endl;

	double midterm;
	double final;
	cin >> midterm >> final;

	cout << "Please enter your homework grades: " << endl;
	vector<double> homeworks;

	double x;
	while (cin >> x) {
		homeworks.push_back(x);
	}

	typedef vector<double>::size_type vec_sz;
	vec_sz size = homeworks.size();

	if (size == 0) {
		cout << "You must enter your homework grades. Please try again." << endl;
		return 1;
	}

	sort(homeworks.begin(), homeworks.end());

	vec_sz mid = size / 2;
	double median;
	median = size % 2 == 0 ? (homeworks[mid] + homeworks[mid - 1]) / 2 : homeworks[mid];

	streamsize prec = cout.precision();
	cout << "Your final grade is: " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
