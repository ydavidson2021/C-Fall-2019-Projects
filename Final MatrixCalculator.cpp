/*----------------------------------------------------*/
/* Name: Yenny Davidson                               */
/* Class: ENGR-2304-003 Fall 2019                     */
/* Assignment #: PA6- Matrix Calculator               */
/* Due Date: 19OCT19                                  */
/*                                                    */
/* Calculate 2x2 matrices based on user's choice of   */
/* operation: addition, subtraction, multiplication.  */
// Preprocessor directives
#include <iostream>  //Required for cout
#include <iomanip>   //Required for manipulatio
#include <cstdlib>   //Required for functions

// Using directive
using namespace std;

//Global constants
const int SIZE = 2; 

//Function Prototypes
void printMatrix (const float matrix[][SIZE], int size); 
void addMatrix (const float matrix_1[][SIZE], const float matrix_2[]
               [SIZE],float result[][SIZE]);
void subMatrix (const float matrix_1[][SIZE], const float matrix_2[]
               [SIZE],float result[][SIZE]);
void multiplyMatrix (const float matrix_1[][SIZE], const float matrix_2[]
               [SIZE],float result[][SIZE]);



// Main function
int main()
{
  // Declare variables
  float matrix_1 [SIZE][SIZE] = {0}; //initialize to zero
  float matrix_2 [SIZE][SIZE] = {0}; //initialize to zero
  float result [SIZE][SIZE]= {0}; // results
  char selection; 
  int flag = 0; 
  
        
        
  // Welcome User 
  cout <<"Welcome to my Matrix Calculator! " << endl << endl;  
  cout << " | A B |" << endl; 
  cout << " | C D |" << endl << endl; 
  
  // Get coefficients for first matrix from user
  cout << "Please enter the coefficients for the first matrix in the "
          "order A B C D: "; 
  cin >> matrix_1[0][0] >> matrix_1 [0][1] >> matrix_1[1][0] >>matrix_1[1][1];
  
  cout << endl; 
  // Get coefficients for second matrix from user
  cout << "Please enter the coefficients for the second matrix in the " 
          "order A B C D: "; 
  cin >> matrix_2[0][0] >> matrix_2[0][1] >> matrix_2[1][0] >>matrix_2[1][1];
  cout << endl; 
  // Show menu of choices for calculation to be performed on the matrices
  
 do {
    flag = 0;   
    cout << endl; 
    cout << "Here are your calculation choices:" << endl; 
    cout <<"a - add the two matrices" << endl; 
    cout <<"b - subtract the second matrix from the first" << endl; 
    cout <<"c - multiply the two matrices" << endl; 
    cout <<"q - quit" << endl << endl;  
    cout << "What would you like me to do? " ;
    cin >> selection; 
  
    switch (selection) {
        case 'a':                       //add both matrices together
        case 'A':                       //add both matrices together
            addMatrix (matrix_1, matrix_2, result); 
            cout <<  "The addition result is " << endl; 
            printMatrix (result, SIZE);
            flag = 1; 
            break; 
    
        case 'b':                       //subtract matrix 2 from matrix 1
        case 'B':                       //substract matrix 2 from matrix 1
            subMatrix (matrix_1, matrix_2, result); 
            cout <<  "The subtraction result is " << endl; 
            printMatrix (result, SIZE);
            flag = 1; 
            break; 
    
        case 'c':                       //multiply the two matrices
        case 'C':                       //multiply the two matrices 
            multiplyMatrix (matrix_1, matrix_2, result); 
            cout <<  "The multiplication result is " << endl; 
            printMatrix (result, SIZE);
            flag = 1; 
            break; 
    
        case 'q':                       //quit program 
        case 'Q':                       //quit program
            cout << endl; 
            cout << "Goodbye!";
            flag = 0; 
            break; 
        
        default: 
        cout << "Invalid entry. Try again"; 
        flag = 1;
        break; 
  
    }
  }  while (flag);

 // Exit program
  return 0;
  
}
  
  /* Programmer defined functions ---------------------*/
  
  // Function: printMatrix
  // Job: print Matrix
  
  void printMatrix (const float matrix [][SIZE], int size) {
      
      for (int i=0; i < size; i++) {
        cout << "|";
        for (int j=0; j < size; j++) {
          cout << matrix [i][j] << " ";
        } 
        cout << "|" << endl; 
      }
  }
  
  //Function: addMatrix
  //Job: add both matrices together
  //Input: a 2x2 array 
  //Output: nothing
  
  void addMatrix (const float matrix_1[][SIZE], const float matrix_2[]
                 [SIZE],float result[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result [i][j] = matrix_1[i][j] + matrix_2[i][j];
        }
    }
  }

  //Function: subMatrix
  //Job: subtract matrix_2 from matrix_1
  //Input: a 2x2 array 
  //Output: nothing
  
  void subMatrix (const float matrix_1[][SIZE], const float matrix_2[]
                 [SIZE],float result[][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result [i][j] = matrix_2 [i][j] - matrix_1 [i][j];  
        }
    }
    return; 
  }
  
  //Function: multiplyMatrix
  //Job: multiply both matrices 
  //Input: a 2x2 array 
  //Output: nothing
  
  void multiplyMatrix (const float matrix_1[][SIZE], const float matrix_2[]
                      [SIZE],float result[] [SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result [i][j] = matrix_1[i][j] * matrix_2 [i][j];  
        }
    }
    return;
  } 
 
  
/*----------------------------------------------------*/