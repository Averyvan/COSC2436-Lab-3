// Author: Avery VanAusdal
// Assignment Number: Lab 3 part 2
// File Name: backwardsRecursive.cpp
// Course/Section: COSC 1337 Section 3
// Date: 9/25/2018
// Instructor: Bernard Ku
#include <iterator>
#include <fstream>
#include <vector>
//#include <iostream>
using namespace std;

/*
param:	first: iterator at first location in vector<char> to be reversed
		last: iterator at last location in vector<char> that needs to be reversed
		result: iterator in output file to write to
process:	moves last iterator one closer to beginning, sets new last iterater value to
			value of result in the output file, and repeats 10,000 times, moving the result
			iterator up by one char every recursion.
			After 10,000 characters, clears the buffer by going back to the original call,
			and going another 10,000 times until first == last, which means the file is done.
output: a reversed file
*/
void backwardsRecursive (vector<char>::iterator &first, //beginning of file
					vector<char>::iterator &last,  //end of file
					ostreambuf_iterator<char> &result, //output file
					int counter = 0) //how many recursions deep the call is
{
	if (first != last && counter != 10000) //not at end AND recursed less than 10k times
	{
		--last; //Move the last pointer one from the end
		*result = *last; //write new last to output file
		backwardsRecursive(first, last, ++result, counter+1); //move output pointer by one, go again
	} //after looping 10k times, clears buffer by unspooling to here
	if (counter == 0 && first != last) //not at end AND done unspooling, resume operations.
	{
		backwardsRecursive(first, last, result); //goes back to the top with the same pointers
	}
}

/*
param: fileName of a .txt to be reversed
process:	fills vector with chars from fileName, in order.
			calls overloaded backwardsRecursive with iterators pointing to 
			vector start, end, and output file start
*/
void backwardsRecursive (string fileName) 
{
	ifstream inFile(fileName);
	ofstream outFile("ReversedFile.txt", ios::binary | ios::trunc);
	ostreambuf_iterator<char> output_begin(outFile);
	vector<char> inputData;
	while (!(inFile.peek() == ifstream::traits_type::eof())) //as long as it's not the end of the file
	{
		inputData.push_back(inFile.get());
	} //fill vector with chars
	vector<char>::iterator first = inputData.begin();
	vector<char>::iterator last = inputData.end();
	ostreambuf_iterator<char> result = output_begin;
	backwardsRecursive(first, last, result);
	inFile.close();
	outFile.close();
}

/* Retired testing code
int main()
{

	//backwardsRecursive("bible.txt");
	//All that is needed now
	
	
	
//	ifstream inFile("bible.txt");
//	ofstream outFile("bible.reversed.txt", ios::binary | ios::trunc);
//	ostreambuf_iterator<char> output_begin(outFile);
//	vector<char> inputData;
//	while (!(inFile.peek() == ifstream::traits_type::eof()))
//	{
//		inputData.push_back(inFile.get());
//	}
//	backwardsFile(inputData.begin(), inputData.end(), output_begin);
//	inFile.close();
//	outFile.close();

//    ifstream input_file("bible.txt", ios::binary);
//    ofstream output_file("jokes.reversed.txt", ios::binary);
//    istreambuf_iterator<char> input_begin(input_file);
//    istreambuf_iterator<char> input_end;
//    ostreambuf_iterator<char> output_begin(output_file);
//    vector<char> input_data(input_begin, input_end);
//
//    backwardsFile(input_data.begin(), input_data.end(), output_begin);
}
*/
