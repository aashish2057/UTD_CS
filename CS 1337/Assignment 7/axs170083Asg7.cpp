#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

/*
    Problem - program that determines if input string is a palindrome
    Input - user input, string class
    Conditions - punctuation and space don't count, capital is the same as lower case
*/
void input(string &s) // get user input
{
    cout << "Enter a string: ";
    getline(cin, s);
}

string lower(string s) // convert all characters to lowercase, as capital and lower are the same thign
{
    string s1;
    for(int i = 0; i < s.length(); i++) // convert everything to lower case
    {
        s1 += tolower(s[i]);
    }
    return s1;
}

void spaces(string &s1) // remove all spaces from string as they don't matter
{   
    for(int i = 0; i < s1.length()-1; i++)
    {
        if(s1[i] == ' ')
        {
            s1.erase(i--, 1);
        }
    }
}

void punctuation(string &s1) // remove all punctuation from string as they don't matter
{
    for(int i = 0; i < s1.length()-1; i++)
    {
        if(ispunct(s1[i]))
        {
            s1.erase(i--, 1);
        }
    }
}

bool isPalindrome(string s1)
{
    
}

void print(string s, string s1) // print to user
{
    cout << s << endl;
    cout << s1 << endl;
}

int main()
{
    string s;
    string s1;
    bool valid = true;
    while(valid)
    {
        input(s); // get input from user
        if(s == "*")
        {
            valid = false;
        }
        else
        {
            s1 = lower(s); // convert everything to lower
            spaces(s1); // removes all spaces in string
            punctuation(s1); // remove all punctuation from string
            print(s, s1);
        }
    }
}