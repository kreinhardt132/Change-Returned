//Name: Kain Reinhardt
//Date: November 8, 2024
//Purpose: This program is meant to output the amount of different
    //type of bills that can fit into an amount given by the user

//Use iostream for the input and ouput and use cmath for things
    //like floor
#include <iostream>
#include <cmath>

using namespace std;

//moneyCounter is a function that takes two parameters. One is amount
    // which the total given by the user and the other is position
    //which is the number we want to divide the amount by.
    //The purpose of the function is to return how many times the
    //position can fit into the amount.
int moneyCounter(float amount, int position);

//The main function is used to get the total amount of money from the
    //user then call the moneyCounter function for each dollar
    //bill and cent. Main will ouput how many there is of each
int main()
{
    //Create a float title total, this variable will be used to store
	//the amount of money inputed
    float total = 0;
    //Create an integer named counter, this variable will be used to
	//store the amount of a certain item
    int counter = 0;
    //Create a change variable that will store the total change
	// attached to the dollar amount
    float cents = 0;

    //Ask the user for the amount of money
    cout << "Please enter the amount of money: ";
    cin >> total;

    //Round the total amount down to seperate the dollar amount and
	// the cent amount
    cents = floor(total);
    //Multiply the total by 100 and the cents by hundered to
	//preserve accuracy, then subtract each other to get
	//the cents as a whole number
    cents = (total * 100) - (cents * 100);
    //Round down the total to get the amount of whole dollars
    total = floor(total);

    //Call moneyCounter to get the amount of 10 dollar bills
    counter = moneyCounter(total, 10);
    //Subtract the amount of money in 10 dollar bills from the total
    total -= counter*10;
    //Out put the amount of 10 dollar bills
    cout << counter  << "-$10 bill"<< endl;

    //Do the same with 5 dollar bills
    counter = moneyCounter(total, 5);
    total -= counter*5;
    cout << counter << "-$5 bill" << endl;

    //Do the same with 1 dollar bills
    counter = moneyCounter(total, 1);
    total -= counter;
    cout << counter << "-$1 bill" << endl;

    //Now its time to work on the cents so do the same things you did
	//with dollars but with the cents
    counter = moneyCounter(cents, 25);
    cents -= counter*25;
    cout << counter << "-quarters" <<endl;

    //Do it for dimes
    counter = moneyCounter(cents, 10);
    cents -= counter*10;
    cout << counter << "-dimes" << endl;

    //Do it for pennies
    counter = moneyCounter(cents, 1);
    cents -= counter;
    cout << counter << "-pennies" << endl;


    //All of the output is done so end the program
    return 0;
}

int moneyCounter(float amount, int position)
{
    //Create a float that will hold a float to see if a
	//number is divisible by position
    float hold = 0;
    //Create a variable division to divide hold, set division to the
	//number the user wants to divide by which is position
    int division = position;
    //Create a bool to go through the loop until we stop it
    bool checker = true;

    //Create a while loop to run until we find the maximuim amount of
	//times amount can be divided by division
    while(checker)
    {

	//divide amount by division to get a number and store
	    //it in hold
        hold = amount/division;

	//If hold is greater than one that means we can divide amount
	    //more times if it is less than 1 then we have exceeded
	    //the maximuim amount of times amount could be divided
        if(hold>=1)
        {
	    //If hold is greater than one then increase the division
            division += position;
        }

        else
        {
	    //If hold is less than one then stop the loop
            checker = false;
        }
    }

    //Return the amount of times position could go into amount and
	//subtract by one to get rid of off by one error
    return (division/position) - 1;
}
