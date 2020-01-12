/*----------------------------------------------------*/
/* Name: Yenny Davidson                               */
/* Class: ENGR-2304-003 Fall 2019                     */
/* Assignment #: PA 10 - College Savings              */
/* Due Date: 07DEC19                                  */
/*                                                    */
/* Comparing Invested College Invested invested       */
/* in savings account vs 529 plan                     */

// Preprocessor directives
#include <iostream>  //Required for cout
#include <fstream> 
#include <cmath>

// Using directive
using namespace std;

// Main function
int main()
{
    double pmt; 
    double years; 
    //Ask user for money contribution
    cout << "Let's compare your college savings options..." << endl; 
    cout << "How much do you plan to contribute monthly? "; 
    cin >> pmt; 
    cout << "For how many years will you contribute? "; 
    cin >> years; 
    // Open an output file to write data 
    string filename = "savings.txt"; 
    ofstream output(filename); 
    if (output.fail ()) {
        cerr << "ERROR: could not open file." << filename << endl; 
        exit(1); 
    }
    
    // Calculate savings 
    double numMonths = years * 12; 
    double interestRate;
    double monthlyRate; 
    double totalSavings; 
    double totalPlan; 
    
    for (int i = 1; i <= numMonths; i++) {
        interestRate = 0.06;
        monthlyRate = (interestRate/100)/12;
        totalSavings = pmt * ((pow((1 + monthlyRate),(i)) - 1)/ monthlyRate); 
        interestRate = 7; 
        monthlyRate = (interestRate/100)/12;
        totalPlan = pmt * ((pow((1 + monthlyRate) , (i)) - 1) / monthlyRate); 
        output << i << " " << totalSavings << " " << totalPlan << " " << endl; 
        
    }
    
    cout << "Output file savings.txt has been generated." << endl; 
  // Exit program
  return 0;
}
/*----------------------------------------------------*/