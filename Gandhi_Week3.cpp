//-------------------------------------------------------------------
// QUEST SUMMER 2023 HS RESEARCH PROJECT
//-------------------------------------------------------------------
// Student name: Parsh GANDHI
// Assignment: Week 3 Programming Assignment 
// Submission date: July 9, 2023
// Compiler Info: C++
// Purpose: An “ATM Software” is developed for Silverlight Bank. 
// This ATM software will accept deposits and can make withdrawals. It can also show the user their account balance. 
// The users account balance starts with 650 and changes with every task they perform. 

// At first the user is prompted with a greeting screen where they will pick a task to perform: 1.Deposit Money, 2.Withdraw Money, and 3.Show Account Balance & Exit
// The software will not end until the user picks task 3, and will keep prompting the user to pick a task while running task 1 and 2 when choosen

// This software utilizes functions for each task and based on the users input one of them will be run:
// optionOne (task 1, desposit money)
// optionTwo (task 2, withdraw money)
// optionThree (task 3, show account balance and exit)

// The software will also send error messages in each of the following cases:

// MESSAGE 1: There must be a warning message of “ Invalid Entry !” : if the user enters a choice ( option) which is NOT 
// given in the menu items ( i.e. 5), then the user will be prompted by “ Invalid Entry !” and the menu items must be shown
// again to give the user an opportunity to make correct selection. Program will NOT proceed unless user makes a valid selection. 

// MESSAGE 2: If the entered Withdraw amount is more than what is available in the account balance, the following 
// warning message should appear on the screen: Sorry, you do not have sufficient funds to do this transaction. Try Again 
// (The program will NOT do any update on the account balance)

// MESSAGE 3: If the total amount becomes less than $500, the following message should
// appear on the screen: Warning! You balance is less than $500, please Deposit funds soon

//-------------------------------------------------------------------

#include <iostream> //requiered for input/output
using namespace std;

//Definition of variables
double accBalance; // How much the user has in his account after tasks, dynamic variable
int initialBalance = 650; // Balance user starts with 
int input; // Task that the user picks to perform
double amount; // How much the user enters to deposit/withdraw

void greetingScreen()
{
// this function will give a Welcome Message to the user 

    cout << "==============================================" << endl;
    cout << "Welcome to Silverlight Bank ATM" << endl;
    cout << "Your Friend in the Business Environment" << endl;
    cout << "==============================================" << endl << endl; // Displays a list of tasks the user could perform
    cout << "How can I help you today?" << endl;
    cout << "1) Deposit Money" << endl;
    cout << "2) Withdraw Money" << endl;
    cout << "3) Show Account Balance & Exit" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter the number of what task you would like to perform: "; // Will signal the user to pick a task to perform
    cin >> input; // Takes the user input of what task they would like to perform 1, 2, or 3
}

void sessionStart()
{
// This function will give a list of tasks to perform
// This will show up everytime after task one or two has been completed 

    cout << "==============================================" << endl << endl;
    cout << "How can I help you today?" << endl;
    cout << "1) Deposit Money" << endl;
    cout << "2) Withdraw Money" << endl;
    cout << "3) Show Account Balance & Exit" << endl;
    cout << "---------------------------------" << endl;
    cout << "Enter the number of what task you would like to perform: "; // Will signal the user to pick a task to perform
    cin >> input; // Takes the user input of what task they would like to perform 1, 2, or 3
}

void optionOne()
{
// This function will complete task 1, depositing money into the users account 

    cout << endl << "---------------------------------" << endl;
    cout << "Thank you for depositing funds today." << endl;
    cout << "Please enter the amount: "; // Will signal the user to enter an amount to deposit 
    cin >> amount; // Takes the user input of how much they would like to deposit

    accBalance = accBalance + amount; // Adds how much the user chooses to deposit to their account balance
    amount = 0; // Resets the amount variable to zero for when the variable is used again when the user selects another task
}

void optionTwo()
{
// This function is to complete task two, withdawing funds from a users account 

    cout << endl << "---------------------------------" << endl;
    cout << "Thank you for widthdrawing funds today." << endl;
    cout << "Please enter the amount: "; // Will signal the user to enter an amount to withdraw 
    cin >> amount; // Takes the user input of how much they would like to deposit

    // if else statements to display error messages
    if (amount >= accBalance) // If the amount the user inputs is greater than their account balance the withdrawal cannot be made, thus an error message 
    {
        cout << "Sorry, you do not have sufficient funds to do this transaction. Try Again" << endl;
    }
    else if (accBalance - amount <= 500) // If the amount the user inputs brings their total account balance below 500 the withdawal is made, but a warning message is shown
    {
        cout << "Warning! You balance is less than $500, please deposit funds soon" << endl;
        accBalance = accBalance - amount;
    }
    else // If none of the above cases are met the withdawal is done with no errors or warnings
    {
        accBalance = accBalance - amount; // Subtracts how much the user chooses to withdraw from their account balance
    }
    amount = 0;// Resets the amount variable to zero for when the variable is used again when the user selects another task
}

void optionThree()
{
// This function will simply display the users account balance

    cout << "==============================================" << endl;
    cout << "Your account balance: " + to_string(accBalance) << endl; // Displays balance
    cout << "Thank you for your business today." << endl;
    cout << "Hope to see you sometime soon. Bye." << endl;
    cout << "==============================================" << endl;

}

int main() {

    accBalance = initialBalance; // Sets their account balance to 650 to start

    greetingScreen(); // Runs function which will display welcome message
    
    while (input != 3) // Will keep running until the user signals they want to see their account balance
    {
        if (input == 1) // If the user types 1, task 1 will be performed
        {
            optionOne(); // The task one function is run
        }
        else if (input == 2) // If the user types 2, task 2 will be performed
        {
            optionTwo(); // The task two function is run
        }
        else // If the user enters an incorrect number an error message is shown
        {
            cout << "Invalid entry! Please make a selection from what is shown." << endl;
        }
        sessionStart();
    }

    optionThree(); // If the user types 3, task 3 will be performed and the program will end

    return 0;
}