#include <iostream>
using namespace std;

//Function to find value of Roman numeral
int Value(char rome)
{
    if (rome == 'I')
        return 1;
    else if (rome == 'V')
        return 5;
    else if (rome == 'X')
        return 10;
    else if (rome == 'L')
        return 50;
    else if (rome == 'C')
        return 100;
    else if (rome == 'D')
        return 500;
    else if (rome == 'M')
        return 1000;
    else
        return -1;
}

//Function to convert Roman numeral to integer value
int Convert(string &str)
{
    int val = 0;

    //Traverse the roman numeral
    for (int i = 0; i < str.length(); i++)
    {
        int num1 = Value(str[i]);

        if (i + 1 < str.length())
        {
            int num2 = Value(str[i + 1]);

            if (num1 >= num2)
            {
                val = val + num1;
            }
            else
            {
                val = val + num2 - num1;
                i += 1;
            }

        }
        else
        {
            val = val + num1;
        }
    }

    return val;
}

//Main function
int main()
{
    //Enter roman numeral
    string str;
    cout << "Enter a roman numeral: ";
    cin >> str;

    cout << "Integer form of " << str << " is " << Convert(str) << endl;

    return 0;
}

/*

Enter a roman numeral: XIX
Integer form of XIX is 19

*/
