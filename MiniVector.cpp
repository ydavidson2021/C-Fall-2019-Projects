/// ENGR 2304 - Mini Program
// Week 11 - OOP Applications
// Yenny Davidson 
// oop-vectordata.cpp
// This program will open both an input and output data File
// Data from the input file will be read into a vector, sorted, and
// then written to the output file. 

#include <iostream>
#include <fstream>   // Required for file I/O
#include <vector>
#include <algorithm>

using namespace std;

// function prototuypes
void printVector(vector<double> v);

// main() function
int main() {

    // open input file
    string filename = "input.txt";
    ifstream input(filename);
    if (input.fail()) {
        cerr << "ERROR: could not open file " << filename << endl;
        exit(1);
    }

    // open output file
    filename = "output.txt";
    ofstream output(filename);
    if (output.fail()) {
        cerr << "ERROR: could not open file " << filename << endl;
        exit(1);
    }
  
    // read from input file, remove comma, write to output
    double number;
    vector<double> v;
  
    cout << "Reading list of numbers from input file." << endl;
    do {

        // TO DO: insert code here to read a number from the input file and
        // add it to the vector v
        
        input >> number; 
        for (int i = 0; i < number; i ++)
            v.push_back(number);
            input >> number; 
    } while (!input.eof());
    
    cout << "Original list of numbers..." << endl; 
    printVector(v);

    // TO DO: insert code to sort the vector using a function from the STL
    sort (v.begin(), v.end()); 
    for (auto i = v.begin(); i != v.end(); i++)
        cout << *i << " "; 
    cout << endl;
    cout << "Sorted list of numbers..." << endl; 
    printVector(v);
  
    cout << "Printing sorted list to output file." << endl;
  
    // TO DO: insert code to write the sorted vector to the output file
    for (double &s : v) {
        cout << s << " "; 
        output << s << " ";
    };
    
    // close input and output files
    input.close();
    output.close();

    return 0;
}

// function definitions

void printVector(vector<double> v) {
    
	// TO DO: insert code to print the vector to standard output
    for (int i = 0 ; i < v.size (); i++)
        cout << v[i]<< endl; 
}