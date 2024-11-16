//-------------------------------------------------------------------
// QUEST SUMMER 2023 HS RESEARCH PROJECT
//-------------------------------------------------------------------
// Student name: Parsh GANDHI
// Assignment: Week 4 Programming Assignment 
// Submission date: July 16, 2023
// Compiler Info: C++
// Purpose: The following CPP program will be a Correlation Coefficient calculator. 
// The analytical Correlation Coefficient formula will be transformed into numerical CPP code. 
//
// This user-defined function will calculate the correlation coefficient between two 1D arrays (X and Y).
// Where the input parameters are the two arrays
// The CPP function will be named "myCorrelationCoefficientCalculator" 
//
// In the main body of the code the function will be run to 
// pass the 1D array values into the user-defined correlation coefficient calculator function.
// This will then produce and display the correlation coefficient between given 1D arrays
//
// Coorelation Coefficient formula:
// (∑ ( (x[i]-xaverage) * (y[i]-yaverage) ) )/√( (∑(x[i]-xaverage)^2) * (∑(y[i]-yaverage)^2) )
//-------------------------------------------------------------------

#include <iostream> //requiered for input/output
#include <cmath> // Requiered to do matemathical operations such as power and square root 
using namespace std;

//Definition of variables
double coorelationCoefficient; // Represents the coorelation coefficient

// The two 1D arrays
int x[] = {34, 28, 27, 20, 37, 25};
int y[] = {15, 14, 17, 7, 19, 20};

double myCoorelationCoefficient(int arr1[], int arr2[], int size) // Coorelation coefficient function that will take 3 inputs: the two arrays and the size of them
{
    //Definition of variables
    int i; // This integer variable represents the integer which will be used in the for loop
    double sum1 = 0; // Represents the sum of the numbers of the first array 
    double sum2 = 0; // Represents the sum of the numbers of the second array 
    double mean1; // Represents the average of the numbers of the first array 
    double mean2; // Represents the average of the numbers of the second array 
    double radicand1; // Represents the sum of powers from the first array
    double radicand2; // Represents the sum of powers from the second array
    double numerator; // Represents the numerator of the coorelation coefficient
    double denominator; // Represents the numerator of the coorelation coefficient

    for (i = 0; i < size; i++) // This for loop finds the sum of the numbers in each array 
    {
        sum1 += arr1[i]; 
        sum2 += arr2[i];
    }

    // Calculate the mean of each array by using the sum of the numbers and dividing it by the given size of the array
    mean1 = sum1 / size;
    mean2 = sum2 / size;

//numerator calculations 
    for (i = 0; i < size; i++) // To find the numerator we use this for loop to get the sum of the product of the subtraction between two arrays and their resepctive averages 
    {
        numerator += ((arr1[i] - mean1) * (arr2[i] - mean2));

    }

//denominator calculations 
    for (i = 0; i < size; i++) // To find the denominator we first use a for loop to find the sum of the subtraction between two arrays and their resepctive averages raised to the second power
    {
        radicand1 += pow((arr1[i] - mean1), 2);
        radicand2 += pow((arr2[i] - mean2), 2);

    }

    denominator = sqrt(radicand1 * radicand2); // The second step to finding thee denominator is to get the square root of the product of the two arrays sum 

//coorelation coefficient calculations 
    coorelationCoefficient = numerator / denominator; // Finally to get the coorelation coefficient we dividie the numerator and denominator 
    return coorelationCoefficient; // We return the result of the coorelation coefficient

}

int main() {

    myCoorelationCoefficient(x, y, 6); // Input the two 1D arrays and their size to ther function
    cout << "The Coorelation Coefficient is: " << to_string(coorelationCoefficient) << endl; // Display the coorelation coefficiecient

    return 0;
}