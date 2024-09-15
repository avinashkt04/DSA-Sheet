#include <iostream>

using namespace std;

char tolowerCase(char ch)
{
    if ((ch >= 'a' && ch <= 'z') || ch >= 0 && ch <= 9)
    {
        return ch;
    }
    else
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
}

bool palindromeCheck(char *name, int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        if (tolowerCase(name[s]) != tolowerCase(name[e]))
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

int getLength(char *name)
{
    int count = 0;
    for (int i = 0; name[i] != '\0'; i++)
    {
        count++;
    }

    return count;
}

void reverseString(char *name, int n)
{
    int s = 0;
    int e = n - 1;
    while (s < e)
    {
        // char temp = name[s];
        // name[s] = name[e];
        // name[e] = temp;
        // s++;
        // e--;
        swap(name[s++], name[e--]);
    }
}

char getMaxiOccChar(string str)
{
    int count[26] = {0};

    // Create array count for each element in the string
    for (int i = 0; i < str.length(); i++)
    {
        int number = 0;
        number = str[i] - 'a';
        count[number]++;
    }

    // Find maxi occ character
    int maxi = -1, ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (maxi < count[i])
        {
            ans = i;
            maxi = count[i];
        }
    }

    char finalAns = ans + 'a';
    return finalAns;
}

int main()
{
    char name[20];
    cout << "Enter your name: ";
    cin >> name;

    cout << "Your name is: " << name << endl;

    cout << "Length: " << getLength(name) << endl;

    reverseString(name, getLength(name));

    cout << "Reverse String: " << name << endl;

    cout << "Palindrome or not: " << palindromeCheck(name, getLength(name)) << endl;

    cout << "Character is: " << tolowerCase('C') << endl;
    cout << "Character is: " << tolowerCase('a') << endl;

    /*
        string str;
        cout << "Enter a string: ";
        cin >> str;

        cout << "Final ans: " << getMaxiOccChar(str);
    */

    /*

    // cin cannot read a line, it terminates on space, tab and enter.
    // we can use two methods to read a line
    // 1. cin.getline(str, len)
    // 2. getline(cin, str);

    // Method 1
    // char str[100];
    // cout << "Enter a line: ";
    // cin.getline(str, 100);

    // cout << str;

    // Method 2
    string str;
    cout << "Enter a line: ";
    getline(cin, str);

    cout << str;

     */

    return 0;
}

/*
#include <iostream>
using namespace std;

// Function to reverse a substring within a string
void reverseWord(string &str, int start, int end) {
    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

int main() {
    string str = "My name is avinash thakur";
    int n = str.length();
    int start = 0;

    for (int i = 0; i <= n; i++) {
        if (i == n || str[i] == ' ') {
            // Reverse the word between 'start' and 'i-1'
            reverseWord(str, start, i - 1);
            start = i + 1;  // Move the start to the next word
        }
    }

    cout << str << endl;  // Output the final reversed string

    return 0;
}
*/
