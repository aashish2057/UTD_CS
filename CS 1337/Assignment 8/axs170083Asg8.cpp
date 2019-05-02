#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/*
    Program - Linear insertion sort
    Input - user input data through file, ask for file name
    Linear insertion - if empty create new node, if not empty find two elements where the previous is smaller
    extra requirements - dynamically allocate everything
    print - traverse the list, print each number one per line, after printing delete list and ask again
    Author - Aashish Sharma
    Date - 4/22/2019
    netID - axs170083
    class - CS1337.009
*/
struct ListNode
{
    double value;
    struct ListNode *next;
};

ListNode *head;

void insertionSort(double num) // takes values from read file and performs insertion sort on linked list
{
    ListNode *newNode; // creat a new node
    ListNode *nodePtr; // nodeptr used to move through the linked list
    ListNode *previousNode = nullptr; // variable to keep track of previous node

    // Create new node with num from file
    newNode = new ListNode;
    newNode->value = num;

    if(!head) // here the list is empty
    {
        head = newNode; // insert the value in the top of the linked list
        newNode->next = nullptr;
    }
    else // if list isn't empty
    {
        nodePtr = head; // start from top of linked list
        previousNode = nullptr;
        while(nodePtr != nullptr && nodePtr->value < num) // keep traversing through the list until you find a value greater than num, insert the node right before
        {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr) // num goes to top of list
        {
            head = newNode; // insert at the top of the list
            newNode->next = nodePtr;
        }
        else // insert after the previous num from file
        {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

void input(string &filename) // get file name from user
{
    cout << "Enter Filename: ";
    cin >> filename;
}

int readFile(string filename, int &count) // read in data from file
{
    ifstream inputFile;
    inputFile.open(filename); // open file
    double num; // variable to get values from file
    bool valid = true; // variable for file not found errors
    if(inputFile)
    {
        while(inputFile >> num) // parse through file for values
        {
            insertionSort(num); // send values to insertion sort function
            count++;
        }
    }
    else // file isn't found inform user
    {
        cout << "File not Found" << endl;
        valid = false;
    }
    inputFile.close(); // close file
    return valid;
}

void display(int count)
{
    ListNode *nodePtr;

    nodePtr = head;
    while(nodePtr)
    {
        cout << nodePtr->value << endl;
        nodePtr = nodePtr->next;
    }
    cout << "Elements in List: " << count << endl;
}

void clearList() // clear linked-list before reading in next file
{
    ListNode *nodePtr; // nodeptr used to move through the linked list
    ListNode *nextNode; // variable to keep track of next node

    nodePtr = head; // start at head
    
    while(nodePtr != nullptr) // until you parse through the entire list
    {
        nextNode = nodePtr->next;
        delete nodePtr;
        nodePtr = nextNode;
    }
}

int main()
{
    string filename;
    bool valid = true;
    int count = 0;
    while(valid) // while user doesn't enter asterisk
    {
        input(filename); // get file name from user
        if(filename.at(0) == '*') // users enters asterisk to exit program
        {
            valid = false;
        }
        else
        {
            valid = readFile(filename, count); // read in data from file
            if(valid)
            {
                display(count); // display lists
                clearList(); // clear data from list
            }
        }
    }
}