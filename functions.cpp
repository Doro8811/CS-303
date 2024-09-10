#include <iostream>
#include <fstream>

using namespace std;

//user interface that will loop until the user enters a valid choice from 1-5, returns the appropriate value to continue the program
int menu() {
  while (true){
    int choice;
    cout << "Menu: " << endl;
    cout << "1. Find / locate integer" << endl;
    cout << "2. Modify integer" << endl;
    cout << "3. Add integer" << endl;
    cout << "4. Remove or Zero integer" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    if (choice == 1){
      cout << "Enter an integer to find: ";
      return choice;
    }
    else if (choice == 2){
      cout << "Enter an integer index to modify: ";
      return choice;
    }
    else if (choice == 3){
      cout << "Enter an integer to add: ";
      return choice;
    }
    else if (choice == 4){
      cout << "Enter an integer index to remove or zero out: ";
      return choice;
    }
    else if (choice == 5){
      cout << "Program exiting..." << endl;
      return choice;
    }
    else {
      cout << "Invalid choice. Please try again." << endl;
    }
  }
}

// Function for getting an integer input from the user, returns the valid integer value that the user enters
int getIntegerInput() {
    int input;
    cin >> input;
    try {
      if (cin.fail()) { //if the input value is not an integer, throw an exception
        throw runtime_error("Invalid input. Please enter an integer.");
      }
    } catch (runtime_error) {
      throw runtime_error("Input is not a valid integer.");
    }
    return input;
}

// Function to find the integer in the array and return the index
int findInteger(int* arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return i; // The index will be returned if the input integer is found
        }
    }
    return -1; // Return -1 if integer is not found
}

// Function to modify an integer at a given index, will first require the user to enter a valid index to modify and then another integer value for replacement
void modifyInteger(int* arr, int index, int newValue, int& oldValue) {
    oldValue = arr[index]; // Store the old value
    arr[index] = newValue; // Set the new value
}

// Function for adding an integer to the end of the array
int* addInteger(int* arr, int& size, int newValue) {
    int* newArr = new int[size + 1]; // Create a new array with one more index value
    for (int i = 0; i < size; i++) {
        newArr[i] = arr[i]; // Copy the existing values to the new array
    }
    newArr[size] = newValue; // Add the new integer based on the input from the user
    size++; // Incrementing size of the array
    delete[] arr; // Free the old array
    return newArr; // Return the new array
}

// Function to remove an integer at a given index
int* removeInteger(int* arr, int& size, int index) {
  int* newArr = new int[size - 1]; //Creation of a new array with one less index value
    for (int i = 0, j = 0; i < size; i++) {
      if (i != index) {
        newArr[j++] = arr[i];// Copy the existing values to the new array, skipping the value at the given index
      }
    }
  size--; //decrementing the old array
  delete[] arr; // Free the old array
  return newArr; // Return the new array
}

// Function to zero an integer at a given index
int* ZeroOutInteger(int* arr, int index) {
  arr[index] = 0; // Set the value at the given index from the user to zero
  return arr;
}
