#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;


void startRandomNumber ()
{
    srand(time(0));
}

int getRandomNumber (int min, int max) // Function to generate a random number between min and max
{
    return min + (rand() % (max - min + 1));
}

bool isNumberSelected(const vector<int> & selected, int number) // Function to check if a number is alright selected
{
    for (int num : selected)
    {
        if (num == number)
        {
            return true;
        }
    }
    return false;
}

vector<int> selectWinners(int totalFinalists, int numberOfWinners) // Function to select the random winners
{
    vector<int> winners;

    while (winners.size() < numberOfWinners)
    {
        int randomNum = getRandomNumber(1, totalFinalists);

        if(!isNumberSelected(winners, randomNum))
        {
            winners.push_back(randomNum);
        }
    }

    sort(winners.begin(), winners.end());

    return winners;
}

void displayWinners(const vector<int>& winners)
{
    for (size_t i = 0; i < winners.size(); i++) {
        cout << "  Winner " << (i + 1) << ": Finalist #" << winners[i] << endl;
    }
}

int main ()
{
    const int numberFinalists = 25;
    const int numberWinners = 4;

    startRandomNumber();

    vector<int> winners = selectWinners(numberFinalists, numberWinners);

    displayWinners(winners);    

    return 0;
}