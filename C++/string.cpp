
/*Input Format

You are given two strings, a and b, separated by a new line. Each string will consist of lower case Latin characters ('a'-'z').

Output Format

In the first line print two space-separated integers, representing the length of a and b respectively.
In the second line print the string produced by concatenating a and  b (a+b).
In the third line print two strings separated by a space,  and .  and  are the same as  and , respectively, except that their first characters are swapped.*/


//code
#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
   string a, b;
    cin >> a >> b;
    
    cout << a.length() << ' ' << b.length() << endl;
    
    cout << a + b << endl;
    
    swap( a[0], b[0] );
    cout << a << ' ' <<  b << endl;
    
    return 0;
    return 0;
}
