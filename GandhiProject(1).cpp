//-------------------------------------------------------------------
// QUEST SUMMER 2023 HS RESEARCH PROJECT
//-------------------------------------------------------------------
// Student name: Parsh GANDHI
// Assignment: Week 5 Programming Assignment 
// Submission date: July 23, 2023
// Compiler Info: C++
// Purpose:     
//-------------------------------------------------------------------

#include <iostream> //requiered for input/output
#include <cmath> // Requiered to do matemathical operations such as power and square root 
#include <fstream> // To use ifstream
using namespace std;

//Definition of global variables


//Definition of functions 
void myWelcomeMessage()
{
// this function will give a Welcome Message to the user 
// it will also give info about the Program 

    cout << "Welcome! This program is to investigate the impact of COVID-19 Vaccine on the number of ICU patients in the United States. The data used was collected from https://ourworldindata.org/. This program analyzes the data and looks for a correlation between the two variables, Cases and ICU patients. The correlation will be analyzed between the two variables in two different time frames: the correlation between Cases and ICU patients within November 1st, 2020-March 1st, 2021 and the coorrelation between Cases and ICU patients within November 1st, 2021-March 1st, 2022." << endl;
}

double myCoorelationCoefficient(double arr1[], double arr2[], int size) // Coorelation coefficient function that will take 3 inputs: the two arrays and the size of them
{
    //Definition of function specific variables
    int i; // This integer variable represents the integer which will be used in the for loop
    double sum1 = 0; // Represents the sum of the numbers of the first array 
    double sum2 = 0; // Represents the sum of the numbers of the second array 
    double mean1; // Represents the average of the numbers of the first array 
    double mean2; // Represents the average of the numbers of the second array 
    double radicand1; // Represents the sum of powers from the first array
    double radicand2; // Represents the sum of powers from the second array
    double numerator; // Represents the numerator of the coorelation coefficient
    double denominator; // Represents the numerator of the coorelation coefficient
    double coorelationCoefficient; // Represents the coorelation coefficient

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

int sizeOfArray(string filename) // function definition with the parameter of the name of the file to be opened

{
    //Definition of function specific variables
    string line;

    // lines will keep track of the number of lines read in from the file (both
    // so far as each line is read in, and in total).  We initialize it to 0
    // because we have not read any lines from the file yet.
    int lines = 0;

    // ifstream file object is used to access the file
    ifstream file;

    // Use the open member function of the ifstream file object to open the file
    // with the filename provided by the user.
    file.open(filename);

    // If the file fails to open for some reason (e.g. the file doesn't exist),
    // the fail member function of the ifstream file object will return true.
    // If it does, we exit the program with an error message and status.
    if (file.fail())
    {
        // Output an error message for the user
        cout << "File failed to open." << endl;
    }

    // The .eof() member function will return true when we reach the end of the
    // file, so we continue the loop so long as this is NOT true using !file.eof()
    while (!file.eof())
    {
        // getline() will read the next line from the file and store it into the
        // string in the array at the index lines.
        getline(file, line);

        // Increment lines so that the next line in the file is stored in the next
        // index of the array.
        lines++;
    }

    // Close the file as we are now done working with it
    file.close();

    return lines;
}

void data(string filename, double arr1[], double arr2[], int size) // Function definition where input paremeters are the 2 arrays, filename, and size of the array
{
    // ifstream file object is used to access the file
    ifstream inputData; 

    // Use the open member function of the ifstream file object to open the file
    // with the filename provided by the user.
    inputData.open(filename);

    // For loop will scan through each array index 
    for (int i = 0; i < size; i++)
    {
        inputData >> arr1[i]; // Will put the number in index of the array of the first column of the file in the first array
        inputData >> arr2[i]; // Will put the number in index of the array of the first column of the file in the second array
    }

    // Close the file as we are now done working with it
    inputData.close();
}

void conclusion(float CC) // Function definition with the parameter of the coorelation coefficient
{
    // If loop to go through and display the findings according to the table below
    // Value of CC | Conclusion
    // 0 =         | There is no correlation
    // 0<=CC<0.2   | There is a very weak correlation
    // 0.2<=CC<0.4 | There is a weak correlation
    // 0.4<=CC<0.6 | There is a moderate correlation 
    // 0.6<=CC<0.8 | There is a strong correlation
    // 0.8<=CC<1   | There is a very strong correlation 
    // = 1         | There is a perfect coorelation     

    if (CC == 0.0)
    {
        cout << "the Coorelation Coefficient is: " << to_string(CC) << ". As it is equal to 0, there is no correlation between COVID-19 vaccination and the number of ICU cases." << endl;
    }
    else if (0.0 < CC && CC < 0.2)
    {
        cout << "the Coorelation Coefficient is: " << to_string(CC) << ". As it is between 0 and 0.2, there is a very weak correlation between COVID-19 vaccination and the number of ICU cases." << endl;
    }
    else if (0.2 <= CC && CC < 0.4)
    {
        cout << "the Coorelation Coefficient is: " << to_string(CC) << ". As it is between 0.2 and 0.4, there is a weak correlation between COVID-19 vaccination and the number of ICU cases." << endl;
    }
    else if (0.4 <= CC && CC < 0.6)
    {
        cout << "The Coorelation Coefficient is: " << to_string(CC) << ". As it is between 0.4 and 0.6, there is a moderate correlation between COVID-19 vaccination and the number of ICU cases." << endl;
    }
    else if (0.6 <= CC && CC < 0.8)
    {
        cout << "the Coorelation Coefficient is: " << to_string(CC) << ". As it is between 0.6 and 0.8, there is a strong correlation between COVID-19 vaccination and the number of ICU cases." << endl;
    }
    else if (0.8 <= CC && CC < 1.0)
    {
        cout << "the Coorelation Coefficient is: " << to_string(CC) << ". As it is between 0.8 and 1, there is a very strong correlation between COVID-19 vaccination and the number of ICU cases." << endl;
    }
    else
    {
        cout << "the Coorelation Coefficient is: " << to_string(CC) << ". As it is equal to 1, there is a perfect correlation between COVID-19 vaccination and the number of ICU cases." << endl;
    }
}

int main() {

    //Defining the variables
    int arraySizeBeforeVaccination; // array size of file BeforeVaccination.txt
    int arraySizeAfterVaccination; // array size of file AfterVaccination.txt
    float coorelationCoefficientBeforeVaccination; // coorelation coefficient of file BeforeVaccination.txt
    float coorelationCoefficientAfterVaccination;  // coorelation coefficient of file AfterVaccination.txt

    cout << endl << "Investigation of the Impact of COVID-19 Vaccine on the Number of ICU Patients in the United States" << endl << endl; // Title of program
    myWelcomeMessage(); // displays welcome message

    arraySizeBeforeVaccination = sizeOfArray("BeforeVaccination.txt"); // puts the size of the array into a variable
    arraySizeAfterVaccination = sizeOfArray("AfterVaccination.txt"); // puts the size of the array into a variable

    // Defining the 1D arrays
    double casesBeforeVaccination[arraySizeBeforeVaccination];
    double ICUpatientsBeforeVaccination[arraySizeBeforeVaccination];
    double casesAfterVaccination[arraySizeAfterVaccination];
    double ICUpatientsAfterVaccination[arraySizeAfterVaccination];

    data("BeforeVaccination.txt", casesBeforeVaccination, ICUpatientsBeforeVaccination, arraySizeBeforeVaccination); // fills the arrays with data values using the given function with paraemters 
    data("AfterVaccination.txt", casesAfterVaccination, ICUpatientsAfterVaccination, arraySizeAfterVaccination); // fills the arrays with data values using the given function with paraemters

    coorelationCoefficientBeforeVaccination = myCoorelationCoefficient(casesBeforeVaccination, ICUpatientsBeforeVaccination, arraySizeBeforeVaccination); // finds the coorelation coefficient and puts the value in the variable
    coorelationCoefficientAfterVaccination = myCoorelationCoefficient(casesAfterVaccination, ICUpatientsAfterVaccination, arraySizeAfterVaccination); // finds the coorelation coefficient and puts the value in the variable
    
    cout << endl << "Findings and the Conclusion of the Investigation" << endl; // displays text
    cout << "Within November 1, 2020 - March 1st, 2021 time frame ";
    conclusion(coorelationCoefficientBeforeVaccination); // displays the conclusion 
    cout << "Within November 1, 2021 - March 1st, 2022 time frame ";
    conclusion(coorelationCoefficientAfterVaccination); // displays the conclusion 

    cout << endl << "Thank you for using this program!" << endl; //displays text
    return 0;
}