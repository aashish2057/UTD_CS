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

void fix(string &s1) // remove all spaces from string as they don't matter
{   
    for(int i = 0; i < s1.length()-1; i++) // go through loop
    {
        if(s1[i] == ' ' || ispunct(s1[i]) || ispunct(s1[s1.length()-1])) // if there is a space, or punctuation or punctuation on last character
        {
            s1.erase(i--, 1); // erase that character
        }
    }
}

bool isPalindrome(string s1) // determine if string is a palindrome recursively
{
    int len = s1.length(); // get length of string
    if(len == 1) // if length of string is 1, it is palindrome
    {
        return true;
    }
    // took me a while to figure this out, but when there is an even number of characters such as dd, and first is last, I can't have it go through the function again, because the string would just be empty, so this works.
    else if(s1[0] == s1[len-1] && len == 2)
    {
        return true;
    }
    else if(s1[0] == s1[len-1]) // first character is equal to last character
    {
        s1 = s1.substr(1, len-2); // remove first and last character
        return isPalindrome(s1); // recursive loop, that goes and checks if first and last are same again
    }
    else
    {
        return false; // not a palindrome if first character is not equal to last character
    }
}

void print(string s, bool test) // print to user 
{
    if(test == true) // if string is palindrome, inform user
    {
        cout << "String " << s << " is a palindrome" << endl;
    }
    else // inform user string is not palindrome
    {
        cout << "String " << s << " is not a palindrome" << endl;
    }
}

int main()
{
    string s;
    string s1;
    bool valid = true;
    bool test = false;
    while(valid) // continue asking user for string
    {
        input(s); // get input from user
        if(s == "*") // if user enter '*' end program
        {
            valid = false;
        }
        else
        {
            s1 = lower(s); // convert everything to lower
            fix(s1); // removes all spaces and punctuation from string
            test = isPalindrome(s1); // determine if string is palindrome
            print(s, test); // inform user if string is palindrome or not
        }
    }
}