#include <iostream>

using namespace std;

// Function declarations
float add(float x, float y);
float subtract(float x, float y);
float multiply(float x, float y);
float divide(float x, float y);

int main() {
    cout << "Simple Calculator" << endl;
    cout << "Select operation:" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;

    char choice;
    cout << "Enter choice (1/2/3/4): ";
    cin >> choice;

    float num1, num2;
    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    float result;

    switch (choice) {
        case '1':
            result = add(num1, num2);
            cout << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '2':
            result = subtract(num1, num2);
            cout << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '3':
            result = multiply(num1, num2);
            cout << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '4':
            result = divide(num1, num2);
            if(result == -1){
                cout << "Cannot divide by zero" << endl;
            } else {
                cout << num1 << " / " << num2 << " = " << result << endl;
            }
            break;
        default:
            cout << "Invalid Input. Please enter a valid choice." << endl;
            break;
    }

    return 0;
}

// Function definitions
float add(float x, float y) {
    return x + y;
}

float subtract(float x, float y) {
    return x - y;
}

float multiply(float x, float y) {
    return x * y;
}

float divide(float x, float y) {
    if (y != 0) {
        return x / y;
    } else {
        return -1; // Indicate division by zero
    }
}
