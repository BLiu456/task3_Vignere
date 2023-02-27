/*
    Name: Benjamin Liu
    Class: CS4600
    Assignment: Hw2 Task 3 - Vignere Cipher
    Description: An implementation of the Vignere Cipher. For simplicity the plaintext should contain only English letters and spaces.
    This program will only handle lower case letters, and upper case letters will be lower cased.
*/
#include <iostream>
#include <istream>
#include <string>
using namespace std;

int main()
{
    //Variable declarations here
    string plain, key, cipher;
   
    //Getting the key and plaintext from user
    cout << "Enter a key: ";
    getline(cin, key);
    cout << "Enter the plaintext: ";
    getline(cin, plain);

    //Check if the key and plaintext is valid
   for (int i = 0; i < key.length(); i++)
   {
        if (isalpha(key[i])) //Key can only contain characters in the English alphabet
        {
            continue;
        }
        //This is only reached if a character was not an alphabet
        cout << "Not a valid key." << endl;
        return 0;
   }
   
   for (int i = 0; i < plain.length(); i++)
   {
       if (isalpha(plain[i]) || isspace(plain[i]))
       {
           continue;
       }

       cout << "Please only include English letters and spaces in the plaintext." << endl;
       return 0;
   }

   //Creating the ciphertext
   int j = 0;
   for (int i = 0; i < plain.length(); i++)
   {
       if (isspace(plain[i]))
       {
           continue;
       }

       int shift = ((tolower(plain[i]) - 'a') + (tolower(key[j])) - 'a') % 26;
       cipher.push_back('a' + shift);

       j++;
       if (j >= key.length())
       {
           j = 0;
       }
   }

   cout << "Ciphertext: " << cipher << endl;
}


