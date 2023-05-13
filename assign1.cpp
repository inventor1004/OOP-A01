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
#include <ctype.h> 
#include <stdlib.h>
#include "assessGrade.h"


#define kMaximumCharacters 101
#define kNumberOfGrades 5


// Prototypes
int getString(char userInput[]);



# pragma warning(disable: 4996)
int main(void)
{
    char userInput[kMaximumCharacters] = { };
    char checkTheInput1[kMaximumCharacters] = { };
    char checkTheInput2[kMaximumCharacters] = { };
  
    char* pCheckTheInput1 = (char*)calloc(kMaximumCharacters, sizeof(char));
    char* pCheckTheInput2 = (char*)calloc(kMaximumCharacters, sizeof(char));
    char* pTempStorage = (char*)calloc(kMaximumCharacters, sizeof(char));

    int score = 0;
    int totalScore = 0;
    int isNum = 0;
    int i = 0;


    // get the user input of student's grades
    // The information getting from the user will be stored in
    // char array called 'userInput'
    printf("Enter Student¡¯s Grade(s) >>>");
    if (getString(userInput) != 0)
    {
        printf("Invalid input was entered.");
        return 0;
    }


    pTempStorage = userInput;
    pCheckTheInput1 = checkTheInput1;
    pCheckTheInput2 = checkTheInput1;

    // Put the user input information to checkTheInput[] step by step to check  
    // what information did the user enter
    while ( *pTempStorage != '/n')
    {
        checkTheInput1[i] = *pTempStorage;

        // extract the each block of the information separated by spaces
        if (*pTempStorage == ' ')
        {

            checkTheInput1[i] = '\0';

            // distinguish what type of grade information did the user entered
            // 1. number of grade
            // 2. letter grades 
            // 3. special letter
            // 3. file name
            if ((isNum = atoi(pCheckTheInput2)) != 0)
            { 
                if (isNum < 0 || isNum > 100)
                {
                    printf("Invalied number was entered.\n");
                    printf("The range of the grade should be more than 0 and less than 100.\n");

                    return 0;
                }
                totalScore += isNum;
                checkTheInput1[i] = '0';
                i = -1;
            }
        }



        ++i;
        ++pTempStorage;

    }


    return 0;
}



int getString(char userInput[])
{
    char tempStorage[kMaximumCharacters] = { };
   
    int i = 0;
        

    fgets(tempStorage, kMaximumCharacters, stdin);
    while (tempStorage[i] != NULL)
    {
        if (sscanf(&tempStorage[i], "%s", &userInput[i]) != 1)
        {
            return -1;
        }

        strcat(&userInput[i], " ");
        i += strlen(&userInput[i]);
    }

    return 0;
}