
/*******************************************************************
** File: project1.cpp 
** Project: CMSC 202 Project 1, Spring 2021
** Author: Luke Gude
** Date: 02/13/2021
** Section: 10/12
** E-Mail: lgude1@umbc.edu
**
** Driver code for Word Guessing game for Project 1
*******************************************************************/

#include <iostream>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

int checker(string guess, char character)
{
    string word(1, character);
    int result = word.find(guess);
    if (result == 0)
    {
        return result;
    }
    else
    {
        return -1;
    }
}

int num_of_words()
{
    string line;
    ifstream myfile("words.txt");
    int number_of_lines = 0;
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            number_of_lines++;
        }
        myfile.close();
    }
    if (number_of_lines == 0)
    {
        cout << "File not found\n";
        return 0;
    }
    else
    {
        cout << "Your file was imported!\n";
        return number_of_lines;
    }
}

bool playAgain()
{
    char choice;
    cout << "Another game? y/n ";
    cin.clear();
    cin.ignore(256, '\n');
    cin >> choice;
    while (cin.fail() || choice != 'y' && choice != 'n')
    {
        cin.clear();
        cin.ignore(256, '\n');
        cout << "Please select y or n ";
        cin >> choice;
    }
    if (choice == 'y')
    {
        return true;
    }
    else if (choice == 'n')
    {
        cout << "Thanks for playing!\n";
        return false;
    }

    return false;
}

int hasGuessed(char letter_guessed[], string guess)
{
    string guessed_letters(letter_guessed);
    return guessed_letters.find(guess);
}

void playGame(int num_of_letters, string word)
{
    string underscore = string(word.size() - 1, '_');
    string guess;
    int letters_remain = num_of_letters;
    int bad_guesses = 6;
    char guessed_letters[26];
    int guessed_index = 0;
    do
    {
        bool lettersChanged = false;
        cout << letters_remain << " letters remain\n";
        cout << underscore << endl;
        cout << "What letter would you like to guess?\n";
        cin >> guess;
        while (cin.fail() || guess.size() > 1 || isdigit(guess[0]) || isupper(guess[0]))
        {
            cout << "Must be a single lowercase letter" << endl;
            cin.clear();
            cin.ignore(256, '\n');
            cin >> guess;
        }
        if (hasGuessed(guessed_letters, guess) == -1)
        {
            for (int i = 0; i < num_of_letters; i++)
            {
                if (checker(guess, word[i]) == 0)
                {
                    underscore[i] = guess[0];
                    letters_remain--;
                    lettersChanged = true;
                }
            }
            if (lettersChanged == false)
            {
                bad_guesses--;
                cout << "There is no " << guess << " in the puzzle\n";
                cout << "You have " << bad_guesses << " bad guesses left.\n";
                guessed_letters[guessed_index] = guess[0];
                guessed_index++;
            }
            else
            {
                guessed_letters[guessed_index] = guess[0];
                guessed_index++;
            }
        }
        else
        {
            bad_guesses--;
            cout << "You already guessed " << guess << endl;
            cout << "You have " << bad_guesses << " bad guesses left.\n";
        }
    } while (letters_remain > 0 && bad_guesses > 0);

    if (letters_remain == 0)
    {
        cout << "Congrats you won!\nThe correct word was: " << word << endl;
    }
    else if (bad_guesses == 0)
    {
        cout << "Sorry, you lost\nThe correct answer was: " << word << endl;
    }
}

string randomWordInList(int num_lines, int seed)
{
    ifstream myfile("words.txt");
    string word;
    srand(time(0));
    int randNum = (rand() % num_lines) + 1;
    for (int i = 0; i < randNum; i++)
    {
        getline(myfile, word);
    }
    return word;
}

int main()
{
    int seed = 0;
    bool tryAgain = true;
    while (tryAgain == true)
    {
        string word = randomWordInList(num_of_words(), seed);
        int word_length = word.length() - 1;
        // cout << word << endl;
        cout << "Welcome to the UMBC Word Guess\n";
        cout << num_of_words() << " words imported.\n";
        cout << "Ok. I am thinking of a word with " << word_length << " letters.\n";
        playGame(word_length, word);
        tryAgain = playAgain();
        seed++;
    }

    return 0;
}