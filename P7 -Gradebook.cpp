/*----------------------------------------------------*/
/* Name: Yenny Davidson                               */
/* Class: ENGR-2304-003 Fall 2019                     */
/* Assignment #:  PA7- Gradebook                      */
/* Due Date: 26OCT19                                  */
/*                                                    */
/* Gradebook - Dynamically allocate a loca            */
/* one-dimensional array to store grades              */

// Preprocessor directives
#include <iostream>  //Required for cout
#include <iomanip> //Required for manipulation 

// Using directive
using namespace std;

//Function Prototypes: 
void fillArray (int *ptr, int size); 
void highScore (int *ptr,  int size);
void lowScore (int *ptr,  int size);
void averageScore (int *ptr, int size); 

// Main function
int main()
{
	//declare variables 
    
	int arraySize; 
	int *arrayPtr = nullptr;
	float sum = 0; 
	float average = 0; 

	
	cout << "Welcome to your Gradebook!" << endl; 
	
	// ask user how many students do they have in their class
	do {
		cout << "How many students are in your class? " ; 
		cin >> arraySize; 
		cout << endl; 
	
		if (arraySize <= 0) cout << "Invalid entry. Please try again." << endl; 
	
	} while (arraySize <= 0); 
	
	//dynamically create the array
	arrayPtr = new int[arraySize]; 
	
	//fill the array 
	fillArray (arrayPtr, arraySize); 
	cout << endl; 
	
	//Display the high Score
    highScore (arrayPtr, arraySize); 
	
	//Display the low Score
    lowScore (arrayPtr, arraySize); 

	//Display the class average
	averageScore (arrayPtr, arraySize);

	
	//deallocate emory 
	delete [] arrayPtr; 
	
	return 0; 
}
	
	//Programmer defined functions 
	
	// Function: fillArray 
	// Job: populate a matrix with user input 
	// Input: a pointer to an array, the size of the array
	// Output: nothing 
	// Precondition: The array has been allocated and pointed to by the ptr
	// Postcondition: The array is updated with the values from the user. 
	
	void fillArray (int *arrayPtr, int arraySize) {
	    
		for (int i= 0; i <arraySize; i ++) {
			cout << "Enter the grade for student "  << (i +1) <<  ": " ; 
			cin >> *(arrayPtr + i); 
		}

		return; 
	}	
	
	
	// Function: highScore
	// Job: print put the highest score
	// Input: grades
	// Output: highest score 
	
		void highScore (int *arrayPtr, int arraySize) {
	    
	    int tempMax; 
	    int swap;  
	    
	    for (int i = 0; i < arraySize -1; i++) {
	        if (arrayPtr[i] > arrayPtr[i+1])  {
	           // swap them
	           swap = 1;
               tempMax = arrayPtr[i];
               arrayPtr[i] = arrayPtr[i +1];
               arrayPtr[i+1] = tempMax;
	        }
	    }
	 
	    //choose the highest Score
		cout << "The high score is: " << tempMax << endl; 
	    
	    return;
	}
	
	
	// Function: lowScore
	// Job: print put the lowest score
	// Input: grades
	// Output: lowest score 
	
	void lowScore (int *arrayPtr, int arraySize) {
	    
	    int tempMin; 
	    int swap;  
	    
	    for (int i = 0; i < arraySize -1; i++) {
	        if (arrayPtr[i] < arrayPtr[i+1])  {
	           // swap them
	           swap = 1;
               tempMin = arrayPtr[i];
               arrayPtr[i] = arrayPtr[i +1];
               arrayPtr[i+1] = tempMin;
	        }
	    }

	    //choose the lowest Score
		cout << "The lowest score is: " << tempMin<< endl; 
	    
	    return;
	}
		
	// Function: averageScore
	// Job: calculate the class average
	// Input: grades
	// Output: average grade 	
    void averageScore (int *arrayPtr, int arraySize) {
	
	    int sum = 0; 
	    float average = 0;
	    
	    
	    for (int i= 0; i < arraySize; i ++) {
	        
	        //De-bug
	        //cout << "For index" << i << "the element is" << *(arrayPtr + i) << endl; 
		    sum += *(arrayPtr + i); 
            
            //De-bug
		    //cout << "Updated sum is " << sum << endl; 
	    }
	    
	    average = (float) sum / arraySize; 
	    //print results for the user: 
	   
	    cout << fixed << setprecision (2); 
	    cout << "The class average is: " << average << endl; 
        
        return;

	}
	

	
/*----------------------------------------------------*/

