/* Filename: assign1.cpp
 * By: Honggyu(Chris) Park
 * Date: 05/11/2023
 * Description: This program is designed to calculate the average of students' grades
               and determines whether they pass the course or not.
                The program can take four different types of input data depending on the 
               user's purpose.
               -1. Maximum 5 different numerical numbers
               -2. Maximum 5 different letter grades 
               -3. Special letters (I, Q, AU, DNA, I/P) for the certain student's status 
               -4. The name of the file which includes the information about the student's grade
                The user can exit the program by entering the 'X'
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "assessGrade.h"


#define kMaximumCharacters 101


// Prototypes
char* getString(char * pointerToInput);


int main(void)
{
    char* pPointerToInput = (char*)calloc(kMaximumCharacters, sizeof(char));

    // get the user input of student's grades
    // The information getting from the user can be found by pointer to char 
    // called 'pPointerToInput'
    printf("Enter Student¡¯s Grade(s) >>>");
    pPointerToInput = getString(pPointerToInput);

    

    return 0;
}

# pragma warning(disable: 4996)
char* getString(char* pPointerToInput)
{
    char userInput[kMaximumCharacters] = { };
    char tempStorage[kMaximumCharacters] = { };
    int i = 0;

    pPointerToInput = userInput;

    fgets(tempStorage, kMaximumCharacters, stdin);

    while (tempStorage[i] != NULL)
    {
        if (sscanf(&tempStorage[i], "%s", &userInput[i]) != 1)
        {
            return 0;
        }

        strcat(&userInput[i], " ");
        i += strlen(&userInput[i]);
    }

    return pPointerToInput;
}