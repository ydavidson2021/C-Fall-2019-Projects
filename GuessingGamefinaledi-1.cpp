/*----------------------------------------------------*/
/* Name: Yenny Davidson                               */
/* Class: ENGR-2304-003 Fall 2019                     */
/* Assignment #: PA5- Guessing Game                   */
/* Due Date: 05OCT19                                  */
/*                                                    */
/* User will set a range and program will generate    */
/* a random number. User is to guess the mystery      */
/* number with 5 chances.                             */

// Preprocessor directives
#include <iostream>  //Required for cout
#include <cstdlib> //Required for random
#include <ctime> // Require for time

// Using directive
using namespace std;

// Function Prototypes
int getRandom (int a, int b);

//Declare constants 
const int GUESS_TRIALS = 5; 

// Main function
int main()
{
    //Declare variables
    int i,low, high, number, guess;
    int flag = 0; 
    char repeat; 
    
   
    
    // seed the random generator using the current time 
    srand(time(0)); 
    
    cout << "Welcome to Guess the Number!" << endl; 
    
    do {
        flag = 0; 
        repeat = 'n'; 
        
        cout << "I will let you pick the range for the mystery number." << endl; 
        
        // ask the user for the low and high end of the desired range 
        cout << "What is the low end of the range?" << endl; 
        cin >> low; 
        cout << "What is the high end of the range?" << endl; 
        cin >> high; 
        cout << "Got it, I will pick a number between " << low  << " and " << high << " (inclusive). " << endl; 
        cout << "I've got one! Try and guess it." << endl;
        
        // generate random number 
        number = getRandom(low, high); 
        
        //User has 5 tries to guess the number
        for (int i= 1; i <= GUESS_TRIALS; i++) {
            cin >> guess; 
            if (guess < number) {
                cout << "Nope, that's too low. Guess again." << endl; 
            } else if (guess > number) {
                cout << "Nope, that's too high. Guess again." << endl;
            } else if (guess == number) {
                cout << "You're a mind reader! The mystery number was "<< number << "." << endl;
                flag = 1; 
                break;
            }
        } 
        if (guess != number) {
            cout << "Sorry, you're out of guesses! The mystery number was " << number << "." << endl; 
        }
        cout << "Do you want to play again? (y for yes or n for no): " << endl; 
        cin >> repeat; 
        cout << endl;
        
    } while (repeat =='y' || repeat == 'Y');  
    cout << "Ok, see you again soon!"; 
    
  // Exit program
  return 0; 
}


/* Programmer defined functions --------------------------------- */

// Function: getRandom
// Job: generate random numbers using parameters set by user
// Input: none
// Output: integer for generated random number.
	
int getRandom (int a, int b) {
	
	return a + rand() % (b - a + 1);

}