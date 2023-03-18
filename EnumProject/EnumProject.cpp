#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

enum KeyCodeType
{
    UpArrow,
    DownArrow,
    LeftArrow,
    RightArrow,
    Space = 32,
    Enter = 13,
    Esc = 27
};

void CStyleStringExample()
{


    std::cout << "Hello World!\n";

    int arr[10]{ 1, 2, 3, 4, 5 };

    char nameUser[50] = "Hello";

    cout << nameUser << "\n";

    char str[] = "Good by";

    for (int i = 0; i < 7; i++)
        nameUser[i] = str[i];
    nameUser[7] = '\0';

    cout << nameUser << "\n";

    char* dstr = new char;
    strcpy_s(dstr, strlen("Hello people") + 1, "Hello people");
    cout << dstr << "\n";

    strcat_s(dstr, strlen(dstr) + strlen(", good by people!") + 1, ", good by people!");
    cout << dstr << "\n";

    char name1[] = "Bob";
    char name2[] = "Joe";

    cout << strcmp(name2, name1) << "\n";
}

void UsersPrint(char* names[], int size)
{
    for (int i = 0; i < size; i++)
        cout << names[i] << "\n";
    cout << "\n";
}

void StrSwap(char*& strLeft, char*& strRight)
{
    char* temp = new char;
    strcpy(temp, strLeft);
    strcpy(strLeft, strRight);
    strcpy(strRight, temp);
}

bool StrCompare(char* strLeft, char* strRight)
{
    return strcmp(strLeft, strRight) < 0;
}

void StrSort()
{
    int size = 5;
    char** users = new char* [size];
    for (int i = 0; i < size; i++)
        users[i] = new char[10];
    strcpy_s(users[0], strlen("Tom") + 1, "Tom");
    strcpy_s(users[1], strlen("Joe") + 1, "Joe");
    strcpy_s(users[2], strlen("Sam") + 1, "Sam");
    strcpy_s(users[3], strlen("Leo") + 1, "Leo");
    strcpy_s(users[4], strlen("Jim") + 1, "Jim");

    UsersPrint(users, size);

    for (int i = 0; i < size; i++)
    {
        for (int j = size - 1; j > i; j--)
            if (StrCompare(users[j], users[j - 1]))
                StrSwap(users[j], users[j - 1]);
    }

    UsersPrint(users, size);
}

int CharCount(char* str, char symbol)
{
    int count{ 0 };
    char* find{ str };

    while ((find = strchr(find, symbol)) != nullptr)
    {
        count++;
        find++;
    }
    return count;
}
int SubStringCount(char* str, char* subStr)
{
    int count{ 0 };
    char* find{ str };

    while ((find = strstr(find, subStr)) != nullptr)
    {
        count++;
        find += strlen(subStr);
    }
    return count;
}

int main()
{
    /*KeyCodeType code;
    code = KeyCodeType::Enter;*/

    char str[] = "Hello world, hello people";

    char symbol = 'l';

    char* find = strchr(str, symbol);
    
    if(find)
        cout << find << "\n";

    cout << CharCount(str, symbol) << "\n";

    char subStr[] = "ll";

    find = strstr(str, subStr);

    if (find)
        cout << find << "\n";
}
