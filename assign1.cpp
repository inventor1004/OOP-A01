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
#define kNumberGrade 4
#define kLetterGrade 3
#define kSpecialLetter 4
#define kNumberOfGrades 5
#define kInitializeTheCount -1


// Prototypes
int getString(char userInput[]);



# pragma warning(disable: 4996)
int main(void)
{
    // c string
    char userInput[kMaximumCharacters] = { };
    char checkTheInput1[kNumberGrade] = { };
  
    // pointer to c
    char* pCheckTheInput1 = (char*)calloc(kNumberGrade, sizeof(char));
    char* pCheckTheInput2 = (char*)calloc(kNumberGrade, sizeof(char));
    char* pTempStorage = (char*)calloc(kMaximumCharacters, sizeof(char));

    // calculate and distinguish the score
    int totalScore = 0;
    int isNum = 0;
    float isFloat = 0.0;
    char isLetter[kLetterGrade] = {0};
    
    // file I/O
    FILE* fp = NULL;
    char fileName[kMaximumCharacters] = { "\0" };
    char *pErrorChecker = (char*)calloc(kMaximumCharacters, sizeof(char));

    // extra variables
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
    while ( *pTempStorage != NULL)
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
                    printf("**ERROR : Invalid Input\n");
                    return -1;
                }

                totalScore += isNum;
                checkTheInput1[i] = '0';
                i = kInitializeTheCount;
            }
            else if (isFloat = atof(pCheckTheInput2))
            {
                if (isFloat < 0.0 || isFloat > 100.0)
                {
                    printf("**ERROR : Invalid Input\n");
                    return -2;
                }

                totalScore += isFloat;
                checkTheInput1[i] = '0';
                i = kInitializeTheCount;
            }
            else if (*pCheckTheInput2 == 'I')
            {
                printf("Student has Special Situation : I (Incomplete)\n");
            }
            else if (*pCheckTheInput2 == 'Q')
            {
                printf("Student has Special Situation : Q (Withdrawal After Drop/Refund Date)\n");
            }
            else if (*pCheckTheInput2 == 'AU')
            {
                printf("Student has Special Situation : AU (Audit Condition)\n");
            }
            else if (strcmp(pCheckTheInput2, "DNA") == 0)
            {
                printf("Student has Special Situation : DNA (Did Not Attend)\n");
            }
            else if (strcmp(pCheckTheInput2, "I/P") == 0)
            {
                printf("Student has Special Situation : I/P (In Process)\n");
            }
            else if (*pCheckTheInput2 == 'Z')
            {
                ++pTempStorage;
                break;
            }
        }

        ++i;
        ++pTempStorage;

    }

    // extract the filename
    pCheckTheInput1 = strchr(pTempStorage, ' ');
    *pCheckTheInput1 = '\0';
    strcpy(fileName, pTempStorage);

    // open and read the file name
    fp = fopen(pTempStorage, "r");
    if (fp == 0)
    {
        // When it fails to open the file, print the error message and returns -4
        printf("**File I/O ERROR\n");

        return -3;
    }
    else
    {

        // Extract file names line by line which are in teams.txt
        // And deliver the file name to processGames() as a pointer to char parameter.
        // The while loop repeats until there is nothing to read in the teams.txt file
        while (pErrorChecker = fgets(fileName, kMaximumCharacters, fp))
        {

            // Error checking and get first line from teams.txt file
            if (pErrorChecker == NULL)
            {
                // if the file can not be written, print the error message
                printf("**File I/O ERROR\n");
                return -4;
            }
        }
    }



    return 0;
}



int getString(char userInput[])
{
    char pTempStorage[kMaximumCharacters] = { };
   
    int i = 0;
        

    fgets(pTempStorage, kMaximumCharacters, stdin);
    while (pTempStorage[i] != NULL)
    {
        if (sscanf(&pTempStorage[i], "%s", &userInput[i]) != 1)
        {
            return -1;
        }

        strcat(&userInput[i], " ");
        i += strlen(&userInput[i]);
    }

    return 0;
}