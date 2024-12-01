// Name: Peter Barybin
// KUID: 3057437
// LAB Session: Thursday 4 p.m.
// LAB Assignment: EC
// Description: Program that reads an input string and extracts and outputs a double-precision floating-point number to the user if the
// input was valid. Otherwise, program ouputs a message stating that the input was invalid.

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

using namespace std;

double extractNumeric(const string& str) {
    //sign is 1 for positive number and -1 for negative
    int sign = 1;
    int first_index = 0;
    int decimal_count = 0;
    double left = 0;
    double right = 0;
    double right_digits = 0;
    //set first index to index 1 if a + or - sign is first character
    if (str[0] == '+') {
        first_index = 1;
    }
    else if (str[0] == '-') {
        sign = -1;
        first_index = 1;
    }
    else if (str[0] == '.' || (str[0] >= '0' && str[0] <= '9')) {
        ;
    }
    //if first character is not +, -, ., or a digit 0-9 return the number for invalid
    else {
        return -999999.99;
    }
    //iterate through each potential number or decimal, and add to left or right side of decimal in double, or return number for invalid
    for (int i = first_index; i < str.length(); i++) {
        if (!(str[i] == '.' || (str[i] >= '0' && str[i] <= '9'))){
            return -999999.99;
        }
        if (str[i] == '.') {
            decimal_count++;
            continue;
        }
        //invalid if multiple decimals
        if (decimal_count > 1) {
            return -999999.99;
        }
        //add number to left side double if no decimal encountered yet
        else if (decimal_count == 0) {
            left = left * 10 + (str[i] - '0');
        }
        //add number to right side double if decimal has already been encountered
        else {
            right = right * 10 + (str[i] - '0');
            right_digits++;
        }
    }
    //string was a valid double-precision number, return the number
    return sign * (left + (right / pow(10.0, right_digits)));
}

//main that repeatedly asks for an input string until 'END' is entered
int main() {
    string input;

    while (true) {
        cout << "Enter a string (or 'END' to quit): ";
        cin >> input;

        if (input == "END") {
            break;
        }

        double number = extractNumeric(input);

        if (number != -999999.99) {
            //output for valid double-precision number
            cout << "The input is: " << fixed << setprecision(4) << number << endl;
        }
        else {
            //output for invalid input
            cout << "The input is invalid." << endl;
        }
    }
}