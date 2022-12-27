#include "source.h"
void beep()
{
    Beep(600, 900);
}
void nameValidation(char *name)
{
    // if the number of words are less than 2, then it is invalid
    int i = 0;
    int num;
    int count = 1;
    while (name[i] != '\0')
    {
        if (name[i] == ' ')
        {
            count++;
        }
        if (name[i] >= '0' && name[i] <= '9')
        {
            num = 1;
        }
        i++;
    }
    if (count < 2 || num == 1)
    {
        beep();
        red();
        printf("Invalid Input\nGive proper information : ");
        scanf(" %[^\n]", name);
        nameValidation(name);
        green();
    }
}
void car()
{
    green();
    FILE *fp;
    fp = fopen("car.txt", "r");
    char ch;
    while ((ch = fgetc(fp)) != EOF)
    {
        printf("%c", ch);
    }
}
int countLetters(char *str)
{
    int i = 0;
    int count = 0;
    while (str[i] != '\0')
    {
        if (str[i] != '-')
        {
            count++;
        }
        i++;
    }
    return count;
}
void convertTitle(char *str)
{
    int i = 0;
    str[i] = toupper(str[i]);
    while (str[i] != '\0')
    {
        if (str[i] == ' ')
        {
            str[i + 1] = toupper(str[i + 1]);
        }
        else
        {
            str[i + 1] = tolower(str[i + 1]);
        }
        i++;
    }
}
void validateAddress(char *address)
{
    int i = 0;
    int count = 0;
    int valid = 1;
    int space = 0;
    while (address[i] != '\0')
    {
        if (address[i] >= '0' && address[i] <= '9')
        {
            count++;
        }
        if (address[i] >= 'a' && address[i] <= 'z' || address[i] >= 'A' && address[i] <= 'Z')
        {
            valid = 1;
        }
        if (address[i] == ' ')
        {
            space++;
        }
        i++;
    }
    if (count < 2 || valid == 0 || space < 2)
    {
        beep();
        red();
        printf("Invalid Input\nGive proper information : ");
        scanf(" %[^\n]", address);
        validateAddress(address);
        green();
    }
}
void validateCnic(char *cnic)
{
    int valid = 1;
    if (countLetters(cnic) != 13)
    {
        valid = 0;
    }
    for (int i = 0; i < 13; i++)
    {
        if (i == 5 || i == 13)
        {
            if (cnic[i] != '-')
            {
                valid = 0;
            }
        }
        else
        {
            if (cnic[i] < '0' || cnic[i] > '9')
            {
                valid = 0;
            }
        }
    }
    if (valid == 0)
    {
        beep();
        red();
        printf("Invalid Input\nGive proper information : ");
        scanf(" %[^\n]", cnic);
        validateCnic(cnic);
        green();
    }
}
void validatePhone(char *phone)
{
    int valid = 1;
    if (countLetters(phone) != 11)
    {
        valid = 0;
    }
    if (phone[0] != '0' || phone[1] != '3')
    {
        valid = 0;
    }
    int i = 0;
    while (phone[i] != '\0')
    {
        if (phone[i] >= 'a' && phone[i] <= 'z' || phone[i] >= 'A' && phone[i] <= 'Z')
        {
            valid = 0;
        }
        i++;
    }
    if (valid == 0)
    {
        beep();
        red();
        printf("Invalid Input\nGive proper information : ");
        scanf(" %[^\n]", phone);
        validatePhone(phone);
        green();
    }
}
void validateCity(char *city)
{
    int valid = 1;
    int i = 0;
    while (city[i] != '\0')
    {
        if (city[i] >= '0' && city[i] <= '9')
        {
            valid = 0;
        }
        i++;
    }
    if (valid == 0)
    {
        beep();
        red();
        printf("Invalid Input\nGive proper information : ");
        scanf(" %[^\n]", city);
        validateCity(city);
        green();
    }
}
void Print(char *str)
{
    // printf("")
    printf("\033[1;31m");
    printf("\n\n\t\t\t\t%c", 218); // upper-left corner
    for (int i = 1; i <= 20; i++)  // upper border lines
    {
        printf("%c", 196);
    }
    printf("%c\n", 191); // upper-right corner
    printf("\t\t\t\t%c", 179);
    printf("\033[1;33m");
    printf("%s", str); // left box line - text - rigfht box line
    printf("\033[0m");
    printf("\033[1;31m");
    printf("%c\n", 179);
    printf("\t\t\t\t%c", 192);    // lower-right corner
    for (int i = 1; i <= 20; i++) // lower box lines
    {
        printf("%c", 196);
    }
    printf("%c\n", 217); // lower-right lines
    printf("\033[0m");
}
void clear()
{
    system("pause");
    system("cls");
}
void clearScreen()
{
    system("cls");
}
void red()
{
    printf("\033[0;31m");
}
void yellow()
{
    printf("\033[0;33m");
}
void green()
{
    printf("\033[0;32m");
}
void blue()
{
    printf("\033[0;34m");
}
void purple()
{
    printf("\033[0;35m");
}
void cyan()
{
    printf("\033[0;36m");
}
void reset()
{
    printf("\033[0m");
}
