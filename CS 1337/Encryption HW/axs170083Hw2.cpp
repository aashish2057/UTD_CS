#include <iostream>
#include <cstring>

using namespace std;

/*
    Problem - Encrypt and Decrypt string from user
    Input - User given input
    Conditions - must support string up to 200 chracters
    Author - Aashish Sharma
    netID - axs170083
    Class - CS 1337.009
    Date Started - 2/23/19
*/
void input(char string[201]) // get input from user and assign to char array
{
    cout << "Enter string to be encrypted: ";
    cin.getline(string, 201); // get string from user
}

void encryption(char string[201]) // encrypts the string given by the user
{
    int x = 1;
    for(int i = 0; i < strlen(string); i++)
    {
        string[i] += x; // adds 1 to first values, 2 to second and so on
        x++;
        if(x == 11) // resets addition after 10 has been added
        {
            x = 1;
        }
    }
    //cout << "Encrypted String is: " << string << endl;
}

void decryption(char string[201]) // decrypts the encrypted string
{
    int x = 1;
    for(int i = 0; i < strlen(string); i++)
    {
        string[i] -= x; // subtracts 1 from first value, 2 from second and so on
        x++;
        if(x == 11) // resets after 10 has been subtracted
        {
            x = 1;
        }
    }
    //cout << "Decrypted String is: " << string << endl;
}

int main()
{
    char string[201]; 
    bool valid = true;

    while(valid) // stops asking user for input if first character is *
    {
        input(string); // get input
        if(string[0] == '*')
        {
            valid = false;
        }
        else
        {
            encryption(string); // encrypt user string
            cout << "Encrypted String is: " << string << endl;
            decryption(string); // decrypt user string
            cout << "Decrypted String is: " << string << endl;
        }  
       //cout << string << endl;
    }
}

