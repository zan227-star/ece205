#include <cmath>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

vector<double> readScores(const string & filename) // Function to read the file of the name given
{
    vector<double> scores;
    ifstream inputFile(filename); // Finding and readin the filename

    double score;
    while(inputFile >> score) //
    {
        scores.push_back(score); //
    }
    
    inputFile.close(); // Cloing the selected file

    return scores;
}

double cal_avg( const vector<double> & scores)
{
    // Calculating the average of the scores
    double sum = 0.0;
    double avg;
    for (double score : scores)
    {
        sum += score;
    }
    
    avg = sum / scores.size();
    return avg;
    
}

double cal_stdDev(const vector<double> & scores, double average)
{
    double sum_of_squaredDif = 0.0;

    for (double score : scores)
    {
        double difference = score - average; 
        sum_of_squaredDif += pow(difference, 2.0);
    }

    return sqrt(sum_of_squaredDif / scores.size());
}

void outputResult(double average, double stdDev)
{
    ofstream outputFile("output.txt"); // Making an output file for the score calulations

    outputFile.setf(ios::fixed);
    outputFile.setf(ios::showpoint);
    outputFile.precision(2);

    outputFile << "Average of Test Scores: " << average <<endl;
    outputFile << "Standard Deviation of Test Scores: " << stdDev << endl;

    outputFile.close(); // Closing the file
    
    cout <<"\nResult have been printed in output.txt" << endl;

}

int main ()
{
    // A list calling to the different functions to do
    vector<double> scores = readScores("score.txt");
    double average = cal_avg(scores);
    double stdDev = cal_stdDev(scores, average);
    outputResult(average, stdDev);
    return 0;
}