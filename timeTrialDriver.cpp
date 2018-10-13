//Author:               Angelo Gonzales & Avery Vanausdal
//Assignment Number:    Lab 3
//File Name:			backwardsIterative
//Course/Selection:     COSC 2436 Section 003
//Due Date:             10/11/18
//Instructor:           Ku, Bernard
//Description:			This program takes a text file name and runs that file
//						through an iterative and recursive funtion to make a 
//						backwards text file. Times the time it takes for the 
//						functions to run and then do a comparison of the results 
//						to display to the user.

#include <iostream>
#include <iomanip>
#include <ctime>

#include "backwardsIterative.cpp"
#include "backwardsRecursive.cpp"

using namespace std;
void speedBackwardsRecursive(int);
void speedBackwardsIterative(int);

int main ()
{
int numTrials = 0;

cout << "Enter Integer of trials for backwards file: ";
cin >> numTrials;

speedBackwardsIterative(numTrials);
speedBackwardsRecursive(numTrials);

return 0;
}


void speedBackwardsRecursive(int trials)
{
	
	ofstream outFile("bibleTrialOutput.txt", ios::binary | ios::trunc);
	
	int sum = 0;
	
	cout << "\n***Recursive Time***\n";
	
	cout << fixed << showpoint << setprecision (5);
	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer
	cout << "Start Recursive Time  = " << setw(5) << start << " seconds" << endl; //displays start time
	
	if (trials >0)
	{
		for (int i=1; i<=trials; i++)
		{
		backwardsRecursive("bible.txt"); //calls backwards Recursive and tests number of trials
		if (i == 2500 || i == 5000 || i == 7500 || i == 10000) outFile<<"Runs: "<<i<<"\tTime: "<<(double(clock()) / CLOCKS_PER_SEC) - start<<" seconds"<<endl;
		}
		
		//cout << "Fibonacci number is: " << fibonacciRecursive(num) << endl;
	}
		
	double finish = double(clock()) / CLOCKS_PER_SEC;
	cout << "Finish Recursive Time: " << setw(5) << finish << " seconds" << endl; //displays total time from beginning of program to end of recursive fibonacii
																					   
	double elapsed = (finish - start);  //Takes final time - beginning time, to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time to complete each trial
	cout << "Time Elapsed to do Recursive: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	cout << "Average time to do Recursive trial " << trials << " times: " << setw(5) << average << " seconds" << endl; //displays average time
	outFile.close();
}


void speedBackwardsIterative(int trials)
{
	//int sum = 0;
	
	ofstream outFile("leipzig1mTrialOutput.txt", ios::binary | ios::trunc);

	cout << "\n***Iterative Time***\n";
	
	cout << fixed << showpoint << setprecision (5);
	double start = double(clock()) / CLOCKS_PER_SEC; //starts timer
	cout << "Start Iterative Time  = " << setw(5) << start << " seconds" << endl; //displays start time
	
	if (trials>0)
	{
		for (int i=0; i<=trials; i++)
		{
		backwardsIterative(); //calls backwards iterative and tests number of trials
		if (i == 2500 || i == 5000 || i == 7500 || i == 10000) outFile<<"Runs: "<<i<<"\tTime: "<<(double(clock()) / CLOCKS_PER_SEC) - start<<" seconds"<<endl;
		}
		

		//cout << "Fibonacci number is: " << backwardsIterative(name) << endl;
	}
		
	double finish = double(clock()) / CLOCKS_PER_SEC;
	cout << "Finish Iterative Time  = " << setw(5) << finish << " seconds" << endl; //displays total time from beginning of program to end of iterative fibonacci
																					   
	double elapsed = (finish - start);  //Takes final time - beginning time to get time to complete all iterative trials
	double average = (finish - start)/trials;//finds average time of total trial number
	cout << "Time Elapsed to do Iterative: " << setw(5) << elapsed << " seconds" << endl; //displays elapsed time
	cout << "Average time to do Itertive trial " << trials << " times: " << setw(5) << average << " seconds" << endl; //displays average
	
	outFile.close();
}

