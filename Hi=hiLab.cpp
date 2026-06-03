//Christopher Hercules
//Purpose: Write a function that allows case-insensitive comparison of two strings

#include <iostream>
#include <string>
#include <cassert>
using namespace std;

int strcmp_case_insensitive(const string& str1, const string& str2)
{
    int i = 0;

    while(i < str1.length() && i < str2.length())
    {
        char c1 = tolower((unsigned char)str1[i]);
        char c2 = tolower((unsigned char)str2[i]);

        if (c1 < c2)
        {
            return -1;
        }

        if (c1 > c2)
        {
            return 1;
        }

        i++;
    }

    // what returns based on length
    if (str1.length() < str2.length())
    {
        return -1;
    }

    if (str1.length() > str2.length())
    {
        return 1;
    }
    
    return 0;

}

int main()
{
    // equal testS
    assert(strcmp_case_insensitive("hello", "hello") == 0);
    assert(strcmp_case_insensitive("HELLO", "hello") == 0);

    // less test
    assert(strcmp_case_insensitive("hello", "worlds") < 0);
    assert(strcmp_case_insensitive("abc", "abcd") < 0);

    // greater test
    assert(strcmp_case_insensitive("worlds", "hello") > 0);
    assert(strcmp_case_insensitive("abcd", "abc") > 0);

    cout << "All tests passed!" << endl;

    cout << "String one vs string two: " << strcmp_case_insensitive("String one", "string two") << endl;
    cout << "String one vs string one: " << strcmp_case_insensitive("String one", "string one") << endl;
    cout << "String two vs string one: " << strcmp_case_insensitive("String two", "String one") << endl;

    return 0;
}
