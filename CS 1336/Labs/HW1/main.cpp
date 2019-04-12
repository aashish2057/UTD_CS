#include <iostream>

using namespace std;

int main()
{
    char space = ' ';
    char myChar;

    //Using character *
    myChar = '*';

    //Triangle pattern with character *
    cout << space << space << space << myChar << endl;
	cout << space << space << myChar << myChar << myChar << endl;
	cout << space << myChar << myChar << myChar << myChar << myChar << endl;
	cout << myChar << myChar << myChar << myChar << myChar << myChar << myChar << endl;

	//Spaces to separate the patterns
	cout << endl;
	cout << endl;

	//Rectangle pattern with character *
	cout << myChar << myChar << endl;
	cout << myChar << myChar << endl;
	cout << myChar << myChar << endl;

	//Spaces to separate the patterns
	cout << endl;
	cout << endl;

	//Using character $
	myChar = '$';


	//Triangle pattern with character $
	cout << space << space << space << myChar << endl;
	cout << space << space << myChar << myChar << myChar << endl;
	cout << space << myChar << myChar << myChar << myChar << myChar << endl;
	cout << myChar << myChar << myChar << myChar << myChar << myChar << myChar << endl;

	//Spaces to separate the patterns
	cout << endl;
	cout << endl;

	//Rectangle pattern with character $
	cout << myChar << myChar << endl;
	cout << myChar << myChar << endl;
	cout << myChar << myChar << endl;

    return 0;
}
