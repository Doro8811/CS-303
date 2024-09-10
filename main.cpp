//CS303 Assignment 1
//Wei Hong Weng

#include <iostream>
#include <fstream>
#include "header.h"
using namespace std;

//Initilization of the initial size variable for creating the array as well as the variable for keeping track of user input
int array_size = 100;
int userChoice;

int main() {
  //Begin by opening and confirming the input file
  ifstream inputFile("A1input.txt");
  if (!inputFile.is_open()) {
    cout << "Error opening file." << endl; //return an error if the file is not properly opened.
    return 1;
  }
  //Initializing array with the predetermined variable size of 100
  int* arr = new int[array_size];
  //Read integers from the file into the array
  int size = 0;
  int num;
  while (inputFile >> num) {
    arr[size++] = num;
  }
  inputFile.close(); //file is immediately closed after the first iteration of the array is created

  while (userChoice != 5) { //while loop for facilitating the program as it allows the user to freely manipulate the array when run
    userChoice = menu(); //calling the menu functionand returning the user's choice
    if (userChoice == 1){ //choice one is to find an integer in the array if designated from user choice
      int toFind; //2 variables used for what number the user wants to find as well as the index of the number to return
      int index;
      toFind = getIntegerInput(); //defined in functions.cpp
      index = findInteger(arr, size, toFind);
      if (index != -1)
        cout << "Integer is found at index: " << index << endl;
      else {//function will return appropriate response depending on the result of the search
        cout << "Integer not found." << endl;
      }
    }
    else if (userChoice == 2){
      try {
        int index;
        index = getIntegerInput();
        if (index < 0 || index >= size) {
            throw out_of_range("Index is out of bounds."); //first try and except block, will throw exception if the user inputs an index that is out of bounds
        }
        int newValue;
        cout << "Enter new value to replace old value with: "; //prompt user for the replacement value after receiving a valid index to work with
        newValue = getIntegerInput();
        int oldValue;
        modifyInteger(arr, index, newValue, oldValue); //function for modifing the integer at a given index
        cout << "Old value: " << oldValue << ", New value: " << newValue << endl;
      } catch (invalid_argument) {
        cerr << "Invalid input: Please enter a valid integer." << endl; //exception returned if user does not enter a valid integer
      } catch (out_of_range) {
        cerr << "Error: Invalid Index" << endl; //exception returned if user inputs an index that is out of bounds
      }
    }
    else if (userChoice == 3){
      try {
        int newValue;
        newValue = getIntegerInput(); //same function as used previously for getting an input from the user
        arr = addInteger(arr, size, newValue); //function for adding an integer to the end of the array
        cout << "Integer added successfully!" << endl; 
      } catch (invalid_argument) {
        cerr << "Invalid input: Please enter a valid integer." << endl; //exception thrown if the user inputs an invalid integer
      }
    }
    else if (userChoice == 4){
      int index;
      char choice; //char variable for receiving user choice after receiving a valid index
      cin >> index;
      if (index >= 0 && index < size) { //if index is valid, will ask user for "r" or "z" to remove or zero out the integer at the given index, respectively.
          cout << "Enter 'r' to remove or 'z' to zero: ";
          cin >> choice;
          if (choice == 'r') {
              arr = removeInteger(arr, size, index); //remove integer function
              cout << "Integer removed successfully!" << endl;
          } else if (choice == 'z') {
              arr = ZeroOutInteger(arr, index); //zero out integer function
              cout << "Integer set to zero!" << endl;
          } else {
              cout << "Invalid action." << endl; //will return an error message for the user if they do not enter "r" or "z"
          }
      } else {
          cout << "Invalid index." << endl; //default error message if the user enters invalid index
      }

    }
  }
  cout << "Good bye...";
  return 1;
}
