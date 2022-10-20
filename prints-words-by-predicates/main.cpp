#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
bool is_oval(char k)
{
    char mas_with_letters_to_find[6] = { 'a','e','i','o','u','y' };
    for (int j = 0; j < 6; j++)
    {

        if (tolower(k) == mas_with_letters_to_find[j])return true;
    }
    return false;
}
void consonants(char string_to_analize[256])
{
    int counter = 0;
    for (int i = 0; i < sizeof(string_to_analize); i++)
    {

        if (string_to_analize[i] == ' ' || string_to_analize[i] == 0)
        {
            for (int j = 0; j < 6; j++)
            {
                if (is_oval(string_to_analize[i - 1]))
                {
                    break;
                }
                else
                {
                    for (int c = i - counter; c < i; c++)
                    {
                        cout << string_to_analize[c];
                    }
                    cout << endl;
                    break;
                }

            }
            counter = 0;
        }
        counter++;
    }
    int counters = 0;
    for (int i = 0; i < sizeof(string_to_analize); i++)
    {

        if (string_to_analize[i] == ' ' || string_to_analize[i] == 0)
        {
            for (int j = 0; j < 6; j++)
            {
                if (is_oval(string_to_analize[i - 1]))
                {
                    for (int c = i - counters; c < i; c++)
                    {
                        cout << string_to_analize[c];
                    }
                    cout << endl;
                    break;
                }

            }
            counters = 0;
        }
        counters++;
    }
}

int main()
{
    char string_to_analize[256];
    cin.getline(string_to_analize, sizeof(string_to_analize), '\n');
    consonants(string_to_analize);
}
