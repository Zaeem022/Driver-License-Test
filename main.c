/*
                       PROJECT DETAILS
Project Name: License Test
Project Description: This project is about the license test of car and motorbike.
                     It takes the data of the candidates and then gives them the test.
                     After the test it shows the report of the candidates.
                     It also shows the passed and failed candidates.
                     It also prints the scripts of the candidates.
Project Language: C
Project Type: Console Application
Project Status: Completed
Project Date: 21/12/20221

*/

/*
                    PROJECT PARTICIPANTS
     Member 1
      Name:     Zaeem Raza
      Roll No:  BCSF21M022
      Email:    bcsf21m022@pucit.edu.pk


      Member 2
      Name:     Asad Naeem
      Roll No:  BCSF21M030
      Email:    bcsf21m030@pucit.edu.pk

*/

/*
                        FEATURES
1. Take License Test
2. Show Full Report
3. Passed Candidates
4. Failed Candidates
5. Print Scripts
*/

/**
 *                       Request
 * 1. Please use the full screen of the console.
 * 2. Please use vs code for better experience.
 * 3.Please input the data carefully.
 */

#include <stdio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <ctype.h>
#include <stdlib.h>
#include "source.h"
#include "source.c"
#define SIZE 100 // for strings
#define SIZE2 50 // number of maximum candidates

// Structure Candidates
struct candidates
{
  unsigned int id;
  char name[SIZE];
  char fatherName[SIZE];
  unsigned int age;
  char gender[SIZE];
  char address[SIZE];
  char phoneNo[SIZE];
  char city[SIZE];
  char cnic[SIZE];
  char vehicle[SIZE];
  char status[SIZE];

} candArray[SIZE2];
// Global Variable
int n = 0; // Counter for Candidates

// Function Protoypes
void data(struct candidates *ptrCand);
void testStart(struct candidates *ptrCand);
void showReport(struct candidates *ptrCand);
void passCandReport(struct candidates *ptrCand);
void failCandReport(struct candidates *ptrCand);
void printScripts(struct candidates *ptrCand);
// Main ()
int main()
{
  // Welcome;
  car();
  Print("      Welcome       ");
  FILE *f = fopen("candidates.txt", "w"); // this file stores the data of applicants until the program is running
  fclose(f);

  FILE *f2 = fopen("Data.txt", "a"); // this file stores the data of applicants from the starting of this project to the end
  fclose(f2);

  int input; // for switch case
  do
  {
    blue();
    fprintf(f, "\t\t\t\t\t\t\t Welcome To Candidates Record File \n");
    printf("Choose your option \n");
    printf("1. Take License Test \n");
    printf("2. Show Full Report \n");
    printf("3. Passed Candidates \n");
    printf("4. Failed Candidates \n");
    printf("5. Print Scripts \n");
    printf("6. Exit \n");

    printf("Enter your Choice: ");
    scanf("%d", &input);
    while (input < 1 || input > 6)
    {
      printf("Enter your Choice Again: ");
      scanf("%d", &input);
    }
    switch (input)
    {
    case 1:
      data(candArray);
      break;
    case 2:
      showReport(candArray);
      break;
    case 3:
      passCandReport(candArray);
      break;
    case 4:
      failCandReport(candArray);
      break;
    case 5:
      printScripts(candArray);
      break;
    case 6:
      printf("Thank You! \n");
      break;
    }
    clear();
  } while (input != 6);
  return 0;
}

// functions body
void data(struct candidates *ptrCand)
{
  clearScreen();
  green();
  struct candidates *ptr = ptrCand;
  struct candidates *ptr2 = ptrCand;
  int age;
  char str[SIZE] = "Car";
  char str2[SIZE] = "Motorbike";
  char male[SIZE] = "Male";
  char female[SIZE] = "Female";

  printf("Enter your Age: ");
  scanf("%d", &age);
  while (age < 1 || age > 130)
  {
    beep();
    red();
    printf("Enter your Age Again: ");
    scanf("%d", &age);
    green();
  }
  if (age < 18)
  {
    red();
    printf("Sorry! You are underage \n");
    beep();
    green();
  }
  else
  {
    n = n;
    ptr = ptr + n;
    srand(time(0));
    ptr->id = 200 + rand() % 5000;

    printf("Enter Your Name: ");
    scanf(" %[^\n]", ptr->name);
    nameValidation(ptr->name);
    convertTitle(ptr->name);
    printf("Enter your Father's Name: ");
    scanf(" %[^\n]", ptr->fatherName);
    nameValidation(ptr->fatherName);
    convertTitle(ptr->fatherName);
    printf("Enter your Address: ");
    scanf(" %[^\n]", ptr->address);
    validateAddress(ptr->address);
    printf("Enter your Phone No: ");
    scanf(" %[^\n]", ptr->phoneNo);
    validatePhone(ptr->phoneNo);
    printf("Enter your City's Name: ");
    scanf(" %[^\n]", ptr->city);
    validateCity(ptr->city);
    convertTitle(ptr->city);
    printf("Enter your CNIC: ");
    scanf(" %[^\n]", ptr->cnic);
    ptr->age = age;
    validateCnic(ptr->cnic);

    // validation for unique CNIC
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
      if (strcmp(ptr->cnic, ptr2->cnic) == 0)
      {
        flag = 1;
        break;
      }
      ptr2++;
    }
    while (flag == 1)
    {
      beep();
      red();
      printf("You have already taken your chance: \nEnter new CNIC:");
      scanf(" %[^\n]", ptr->cnic);
      ptr2 = ptrCand;
      flag = 0;
      for (int i = 0; i < n; i++)
      {
        if (strcmp(ptr->cnic, ptr2->cnic) == 0)
        {
          flag = 1;
          break;
        }
        ptr2++;
      }
      green();
    }
    printf("Enter your test's Category (Car/Mototbike): ");
    scanf(" %[^\n]", ptr->vehicle);
    convertTitle(ptr->vehicle);
    while (strcmp(ptr->vehicle, str) != 0 && strcmp(ptr->vehicle, str2) != 0)
    {
      beep();
      red();
      printf("Enter test's Category Again: ");
      scanf(" %[^\n]", ptr->vehicle);
      convertTitle(ptr->vehicle);
      green();
    }
    printf("Enter your Gender: (Male/Female) ");
    scanf(" %[^\n]", ptr->gender);
    convertTitle(ptr->gender);
    while (strcmp(ptr->gender, male) != 0 && strcmp(ptr->gender, female) != 0)
    {
      beep();
      red();
      printf("Enter Gender Again: ");
      scanf(" %[^\n]", ptr->gender);
      convertTitle(ptr->gender);
      green();
    }
    if (strcmp(ptr->gender, male) == 0)
    {
      printf("Welcome Sir \n");
    }
    else if (strcmp(ptr->gender, female) == 0)
    {
      printf("Welcome Mam \n");
    }
    printf("\n");

    n += 1;
    testStart(ptr);
    FILE *f = fopen("candidates.txt", "a");

    fprintf(f, "Id: %d\n", ptr->id);
    fprintf(f, "Name: %s\n", ptr->name);
    fprintf(f, "Father's Name: %s\n", ptr->fatherName);
    fprintf(f, "Age: %d\n", ptr->age);
    fprintf(f, "Gender: %s\n", ptr->gender);
    fprintf(f, "Address: %s\n", ptr->address);
    fprintf(f, "Phone No: %s\n", ptr->phoneNo);
    fprintf(f, "City: %s\n", ptr->city);
    fprintf(f, "CNIC: %s\n", ptr->cnic);
    fprintf(f, "Vehicle: %s\n", ptr->vehicle);
    fprintf(f, "Status: %s\n", ptr->status);
    fprintf(f, "------------------------------ \n");
    fprintf(f, "\n");

    fclose(f);
    FILE *f2 = fopen("Data.txt", "a"); // data.txt

    fprintf(f2, "Id: %d\n", ptr->id);
    fprintf(f2, "Name: %s\n", ptr->name);
    fprintf(f2, "Father's Name: %s\n", ptr->fatherName);
    fprintf(f2, "Age: %d\n", ptr->age);
    fprintf(f2, "Gender: %s\n", ptr->gender);
    fprintf(f2, "Address: %s\n", ptr->address);
    fprintf(f2, "Phone No: %s\n", ptr->phoneNo);
    fprintf(f2, "City: %s\n", ptr->city);
    fprintf(f2, "CNIC: %s\n", ptr->cnic);
    fprintf(f2, "Vehicle: %s\n", ptr->vehicle);
    fprintf(f2, "Status: %s\n", ptr->status);
    fprintf(f2, "------------------------------ \n");
    fprintf(f2, "\n");

    fclose(f2);
  }
}
void testStart(struct candidates *ptrCand)
{
  system("pause");
  system("cls");
  struct candidates *ptr = ptrCand;
  printf("\t\t\t\t\t Now Lets Start the Test \n");
  int totalQuest = 10;
  int score = 0;
  printf("Total Questions: %d\n\n", totalQuest);

  for (int i = 1; i <= totalQuest; i++)
  {
    int input;
    switch (i)
    {
    case 1:
      clearScreen();
      blue();
      printf("Q %d: The white line on the road means : \n", i);
      printf("1. The border line of a carriageway \n");
      printf("2. The line prohibiting lane change \n");
      printf("3. Central line \n");
      printf("4. Lane Dividing line of the road \n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 4)
      {
        score += 5;
      }
      reset();
      break;
    case 2:
      clearScreen();
      cyan();
      printf("Q %d: The pavement Path for passengers on the road is called:  \n", i);
      printf("1. Lion Crossing \n");
      printf("2. Zebra Crossing \n");
      printf("3. Passenger Crossing \n");
      printf("4. Footpath \n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 2)
      {
        score += 5;
      }
      reset();
      break;
    case 3:
      clearScreen();
      purple();
      printf("Q %d: The Speed limit on Highway is: ( per hour) \n", i);
      printf("1. 50km \n");
      printf("2. 70km\n");
      printf("3. 90km \n");
      printf("4. 100km \n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 4)
      {
        score += 5;
      }
      reset();
      break;
    case 4:
      clearScreen();
      // make console red
      red();
      printf("Q %d: Red Light of traffic signal means: \n", i);
      printf("1. Stop \n");
      printf("2. Don't Stop \n");
      printf("3. Go \n");
      printf("4. None of these \n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 1)
      {
        score += 5;
      }
      reset();
      break;
    case 5:
      clearScreen();
      // make console yellow
      yellow();
      printf("Q %d: Yellow Light of traffic signal means: \n", i);
      printf("1. Stop \n");
      printf("2. Don't Stop \n");
      printf("3. Signal is changing \n");
      printf("4. None of these \n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 3)
      {
        score += 5;
      }
      reset();
      break;
    case 6:
      clearScreen();
      // make console green
      green();
      printf("Q %d: Green Light of traffic signal means: \n", i);
      printf("1. Stop \n");
      printf("2. Move \n");
      printf("3. I don't know \n");
      printf("4. None of these \n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 2)
      {
        score += 5;
      }
      reset();
      break;
    case 7:
      clearScreen();
      blue();
      printf("Q %d:At what place, use of horn is not Allowed? \n", i);
      printf("1. Restaurant\n");
      printf("2. Hospital \n");
      printf("3. Parking \n");
      printf("4. None \n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 2)
      {
        score += 5;
      }
      reset();
      break;
    case 8:
      clearScreen();
      cyan();
      printf("Q %d:Driving in the fog, you should use: \n", i);
      printf("1. Front lights \n");
      printf("2. back lights \n");
      printf("3. Fog lights \n");
      printf("4. None of the above \n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 3)
      {
        score += 5;
      }
      reset();
      break;
    case 9:
      clearScreen();
      purple();
      printf("Q %d: What is the speed limit on Motorway (per hours)?\n", i);
      printf("1. 50km\n");
      printf("2. 70km\n");
      printf("3. 100km \n");
      printf("4. 120km\n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 4)
      {
        score += 5;
      }
      reset();
      break;

    case 10:
      clearScreen();
      blue();
      printf("Q %d:How many seconds are required to overtake a vehcle: \n", i);
      printf("1. 2s \n");
      printf("2. 5s\n");
      printf("3. 7s \n");
      printf("4. 12s \n");

      printf("Select your Option: ");
      scanf("%d", &input);
      while (input < 1 || input > 4)
      {
        printf("Select from given options: ");
        scanf("%d", &input);
      }
      printf("\n");
      if (input == 2)
      {
        score += 5;
      }
      reset();
      break;
    }
  }
  float percentage = (float)score * 100 / 50;
  if (percentage >= 75)
  {
    strcpy(ptr->status, "PASS");
  }
  else
  {
    strcpy(ptr->status, "FAIL");
  }
  clearScreen();
  Print("      Results       ");
  blue();
  printf("Score: %d\n", score);
  if (score >= 75)
  {
    green();
  }
  else
  {
    red();
  }
  printf("\n\n\t\t\tStatus: %s\n", ptr->status);
}
void showReport(struct candidates *ptrCand)
{
  system("cls");
  green();
  struct candidates *ptr = ptrCand;
  if (n == 0)
  {
    beep();
    red();
    printf("There is no data available at this time \n");
    blue();
  }
  else
  {
    for (int i = 0; i < n; i++)
    {
      printf("\n");
      printf("Id: %d\n", ptr->id);
      printf("Name: %s\n", ptr->name);
      printf("Father's Name: %s\n", ptr->fatherName);
      printf("Age: %d\n", ptr->age);
      printf("Gender: %s\n", ptr->gender);
      printf("Address: %s\n", ptr->address);
      printf("Phone No: %s\n", ptr->phoneNo);
      printf("City: %s\n", ptr->city);
      printf("CNIC: %s\n", ptr->cnic);
      printf("Vehicle: %s\n", ptr->vehicle);
      printf("Status: %s\n", ptr->status);
      printf("------------------------------ \n");
      printf("\n");
      ptr++;
    }
  }
  blue();
}
void failCandReport(struct candidates *ptrCand)
{
  if (n == 0)
  {
    beep();
    red();
    printf("There is no data available at this time \n");
  }
  else
  {
    int flag = 0;
    green();
    struct candidates *ptr = ptrCand;
    for (int i = 0; i < n; i++)
    {
      if (strcmp(ptr->status, "FAIL") == 0)
      {
        flag = 1;
        printf("\n");
        printf("Id: %d\n", ptr->id);
        printf("Name: %s\n", ptr->name);
        printf("Father's Name: %s\n", ptr->fatherName);
        printf("Age: %d\n", ptr->age);
        printf("Gender: %s\n", ptr->gender);
        printf("Address: %s\n", ptr->address);
        printf("Phone No: %s\n", ptr->phoneNo);
        printf("City: %s\n", ptr->city);
        printf("CNIC: %s\n", ptr->cnic);
        printf("Vehicle: %s\n", ptr->vehicle);
        printf("Status: %s\n", ptr->status);
        printf("------------------------------ \n");
        printf("\n");
      }
      ptr++;
    }
    if (flag == 0)
    {
      beep();
      red();
      printf("There is no data available at this time \n");
    }
  }
  clear();
}
void passCandReport(struct candidates *ptrCand)
{
  if (n == 0)
  {
    beep();
    red();
    printf("There is no data available at this time \n");
  }
  else
  {
    int flag = 0;
    green();
    struct candidates *ptr = ptrCand;
    for (int i = 0; i < n; i++)
    {
      if (strcmp(ptr->status, "PASS") == 0)
      {
        flag = 1;
        printf("\n");
        printf("Id: %d\n", ptr->id);
        printf("Name: %s\n", ptr->name);
        printf("Father's Name: %s\n", ptr->fatherName);
        printf("Age: %d\n", ptr->age);
        printf("Gender: %s\n", ptr->gender);
        printf("Address: %s\n", ptr->address);
        printf("Phone No: %s\n", ptr->phoneNo);
        printf("City: %s\n", ptr->city);
        printf("CNIC: %s\n", ptr->cnic);
        printf("Vehicle: %s\n", ptr->vehicle);
        printf("Status: %s\n", ptr->status);
        printf("------------------------------ \n");
        printf("\n");
      }
      ptr++;
    }
    if (flag == 0)
    {
      beep();
      red();
      printf("There is no Passed Candidate at the moment \n");
    }
  }
  clear();
}
void printScripts(struct candidates *ptrCand)
{
  char str[100];
  int flag = 0;
  printf("Enter the CNIC of the candidate: ");
  scanf("%s", str);
  struct candidates *ptr = ptrCand;
  for (int i = 0; i < n; i++)
  {
    if (strcmp(ptr->cnic, str) == 0)
    {

      flag = 1;
      // printf("%s",ptr->status);
      if (strcmp(ptr->status, "PASS") == 0)
      {
        FILE *f5 = fopen("Script.html", "w");
        fprintf(f5, "<html> <head></head> <body> <div> <h1> <center> License </center><h1/> <h3>ID:%d<h3/> <h3>Name: %s<h3/> <h3>Father Name: %s<h3/> <h3>Age: %d<h3/> <h3>Gender: %s<h3/> <h3>Address: %s</h3> <h3>Phone Number: %s<h3/> <h3>City: %s<h3/> <h3>CNIC: %s<h3/> <h3>Vehicle: %s<h3/> <h3>Status: %s<h3/> </div> <hr></body> </html>", ptr->id, ptr->name, ptr->fatherName, ptr->age, ptr->gender, ptr->address, ptr->phoneNo, ptr->city, ptr->cnic, ptr->vehicle, ptr->status);
        fclose(f5);
        green();
        printf("The candidate has passed the test \nYou can now check the script in the Directory");
        printf("\n");
        break;
      }
      else
      {
        red();
        printf("The candidate has failed the test \n");
      }
    }
  }
  if (flag == 0)
  {
    beep();
    red();
    printf("No record found \n");
    blue();
  }
  clear();
}
