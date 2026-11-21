#include <cstdlib>
#include <ctime>
#include <iostream>
using namespace std;

int main()
{
    const int SIZE = 5;
    const int DIGIT_VALUES = 10;
    int winningDigits[SIZE];
    int player[SIZE];
    int matches = 0;

    // Seed once so runs started at different times can get different draws.
    srand(static_cast<unsigned int>(time(nullptr)));

    for (int index = 0; index < SIZE; index++)
    {
        winningDigits[index] = rand() % DIGIT_VALUES;
    }

    cout << "Enter five digits from 0 to 9, separated by spaces:" << endl;
    for (int index = 0; index < SIZE; index++)
    {
        cin >> player[index];
    }

    for (int index = 0; index < SIZE; index++)
    {
        if (winningDigits[index] == player[index])
        {
            matches++;
        }
    }

    cout << "Winning digits:";
    for (int index = 0; index < SIZE; index++)
    {
        cout << ' ' << winningDigits[index];
    }
    cout << endl;

    cout << "Player digits:";
    for (int index = 0; index < SIZE; index++)
    {
        cout << ' ' << player[index];
    }
    cout << endl;

    cout << "Matches: " << matches << endl;
    return 0;
}
