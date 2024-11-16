//-------------------------------------------------------------------
// QUEST SUMMER 2023 HS RESEARCH PROJECT
//-------------------------------------------------------------------
// Student name: Parsh Gandhi
// Assignment: Week 2 Programming Assignment 2 
// Submission date: July 2, 2023
// Compiler Info: C++
// Purpose: This is to prepare the modules section that we will use for the main program later on.  
// This assignment is about preparing some of the messages we will use to inform the user when the program is completed. 
// There is no data processing, no calculation, and no data transfer in the assignment.

// The three void modules that will be prepared are as follows:
// myWelcomeMessage  ()
// This module will provide a welcome message and inform the user about the programs purpose when called
//
// myDataTransferMessage()
// This module is to inform the user, the input data file  was reached, opened and the contents were transferred into one 1- Dimensional  array 
// 
// myCCoefficientMessage(Case Number, correlation coefficient) 
// This module will inform the user about the correlation coefficient depending on the case.  
// The correlation coefficient of the case "Case Number" is "correlation coefficient"

// Using the given parameters (Case Number = 1  and the correlation coefficient = 0.5) and the void modules
// the program will call the modules and the outputs will be displayed on the screen
//-------------------------------------------------------------------

#include <iostream> //requiered for input/output
using namespace std;

void myWelcomeMessage()
{
// this function will give a Welcome Message to the user 
// it will also give info about the Program 

    cout << "Welcome to this program. This program is to investigate the impact of COVID-19 Vaccine on the number of ICU patients in the United States.  The data was collected from https://ourworldindata.org/. This program analyzes the data and looks for a correlation between the two variables, Cases and ICU patients. The correlation will be analyzed between the two variables in two different time frames. Correlation between Cases and ICU patients within November 1 2020- March 1st in 2021 time frame. Correlation between Cases and ICU patients within November 1 2021- March 1st in 2022 time frame." << endl << endl;
}

void myDataTransferMessage()
{
// this function will send a message and inform the user that
// the input data file  was reached, opened and the contents were transferred into one 1- Dimensional  array

    cout << "The input data file has been reached, opened, and the contents were transffered into one, 1-Dimensional array" << endl << endl;
}

void myCCoefficientMessage(int caseNumber, double correlationCoefficient)
{
// this program has 2 variable paremeters, the case number which is an integer value and the coorelation coefficient which is a 
// this function informs the user about the correlation coefficient depending on the case
// the correlation coefficient of the case("Case Number") is the cc()"correlation coefficient").

    string message;
    message = "The correlation coefficient of case " + to_string(caseNumber) + " is " + to_string(correlationCoefficient);
    cout << message << endl << endl;
}

int main() {

    myWelcomeMessage(); //this line will call the function "myWelcomeMessage" and display a welcome message & info about the prrogram to the user

    myDataTransferMessage(); //this line will call the function "myDataTransferMessage" and display a message about the input data file to the user

    
    myCCoefficientMessage(1, 0.5); //this line will call the function "myCCoefficientMessage" and display a message about the correlation coefficient depending on the case


    cout << "End of program" << endl;
    return 0;
}