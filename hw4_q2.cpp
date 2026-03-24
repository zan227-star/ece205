#include <iostream>
using namespace std;

void readScores(double scores[], int size)
{
    cout << "What are the judges' scores:" << endl;

    for (int i = 0; i < size; i++)
    {
        cout << "Judge [" << i + 1 << "]: ";
        cin >> scores[i];

        while (scores[i] > 10 || scores[i] < 0)
        {
        cout << "Score must be between 0 and 10: ";
        cin >> scores[i];
        }
    }

}

double scoreHighest(double scores[], int size)
{
    int highestscore = 0;

    for(int i = 1; i < size; i++)
    {
        if(scores[i] < scores[highestscore])
        {
            highestscore = i;
        }
    }

    return highestscore;
}

double scoreLowest(double scores[], int size)
{
    int lowestscore = 0;

    for(int i = 1; i < size; i++)
    {
        if(scores[i] > scores[lowestscore])
        {
            lowestscore = i;
        }
    }

    return lowestscore;
}

double scoreCal(double scores[], int size, double difficulty)
{
    int lowestscore = scoreLowest(scores, size);
    int highestscore = scoreHighest(scores, size);

    cout << "Highest Score: " << scores[highestscore] << endl;
    cout << "Lowest Score: " << scores[lowestscore] << endl;

    double sum = 0;
    for (int i = 0; i < size; i++)
    {
        if (i != highestscore && i != lowestscore)
        {
            sum += scores[i];
        }
    }

    return sum * difficulty * 0.6;
}

int main()
{
    const int judges = 7;
    double scores[judges];
    double difficulty;

    cout << "What is the difficulty of the dive: ";
    cin >> difficulty;

    if (difficulty < 1.2 || difficulty > 3.8) //Checking the range
    {
        cout << "The difficulty is between 1.2 and 3.8. So what is the difficulty of the dive: ";
        cin >> difficulty;
    }

    readScores(scores, judges);

    double finalscore = scoreCal(scores, judges, difficulty);

    cout << "Diver's Final Score: " << finalscore;

    return 0;
}