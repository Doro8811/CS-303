#pragma once

#include <iostream>
#include <array>
using namespace std;

//Main menu function that will server as the interface the user sees
int menu();

//Function that will prompt user for an integer input, used for other functions down below
int getIntegerInput();

//Function that utilizes the return from getIntegerInput to then search through the array for the designated input and return the index
int findInteger(int* arr, int size, int num);

//Function that will take the integer index input from the user and then prompt the user for a new integer to replace the old one
void modifyInteger(int* arr, int index, int newValue, int& oldValue);

//Function that will ask the user for an integer input and add said integer to the end of the array
int* addInteger(int* arr, int& size, int newValue);

//Function that will first ask the user for an index, then proceed to delete the integer at that index
int* removeInteger(int* arr, int& size, int index);

//Function that will first ask the user for an index, then proceed to zero out the integer at that index
int* ZeroOutInteger(int* arr, int index);
