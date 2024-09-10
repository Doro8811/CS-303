# CS-303
CS303 Assignment 1

The program was written to include a looping menu that allows for user manipulation of the array.

Selecting choice 1 will prompt the user for an integer input that will then iterate through the array and return the corresponding index value of the integer.

Selecting choice 2 will again, prompt the user for an integer input this time to designate the index to which the user would like to edit. After obtaining the first integer input, the program will ask the user again for another integer input, this time for the value that the user would like to place at the previously selected index. The program will then update the integer at selected index location after receiving two valid integer inputs. The function will internally check for valid reponses, whether the index is within the range of the array, and that the inputs are strictly integers, or else exceptions will be thrown.

Selecting choice 3 will prompt the user for an integer input, this time to add to the end of the array. After receiving a valid integer input from the user (a non-integer input will cause an exception to be thrown), the program will automatically add the integer value to the end of the array, after resizing the array to fit the addition of the new integer.

Selecting choice 4 will prompt the user for an integer input to designate the index for deletion or zeroing. After receving a valid integer value, the program will prompt the user for letter inputs of "r" or "z", for removing and zeroing respectively. The integer removal function will correctly delete the integer at the indicated index location, while also resizing the array to account for the removal of the integer. Conversely, the zeroing function will not resizing the array, but just modify the integer at the index location to be a "0"

Selecting choice 5 will terminate the program after printing a good bye message

Any inputs other than the integers 1-5 on the main menu will loop the program until a valid input is received.
