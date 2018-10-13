//Author:               Angelo Gonzales
//Assignment Number:    Lab 3
//File Name:			backwardsIterative
//Course/Selection:     COSC 2436 Section 003
//Due Date:             10/11/18
//Instructor:           Ku, Bernard
//Description:			This program takes a text file name and runs that file
//						through an iterative funtion to make a backwards text
//						file. Times the time it takes for the functions to run
//						and then do a comparison of the results to display to
//						the user.
/*
ALGORITHM:
		Read inputted text file name
		Creates new file for backwards text file
*/

#include <iostream>
#include <fstream>
#include <ios>
#include <vector>
using namespace std;

template <class BidirectionalIterator, class OutputIterator>
OutputIterator backwardsCopy(BidirectionalIterator first, BidirectionalIterator last, OutputIterator result)
	{
		while (first!=last) 
		{
    		--last;
    		*result = *last;
    		++result;
  		}
  		return result;
  	}

void backwardsIterative()
{
    ifstream input_file("leipzig1m.txt", std::ios_base::binary); // read text file
    ofstream output_file("leipzig1m.reversed.txt", std::ios_base::binary | ios::trunc); // create new text file
    istreambuf_iterator<char> input_begin(input_file);
    istreambuf_iterator<char> input_end;
	ostreambuf_iterator<char> output_begin(output_file);
    vector<char> input_data(input_begin, input_end);
    backwardsCopy(input_data.begin(), input_data.end(), output_begin);
}

