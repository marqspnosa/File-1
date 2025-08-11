#include <stdio.h>
#include <stdlib.h>

#define MIN_SCORES 2
#define MAX_SCORES 10

int main(int argc, char *argv[])
{
    int scoreTable[MAX_SCORES];
    int nbrOfScores = 0; 
    int minimumScore;
    int maximumScore;
    double averageScore;

    if (argc == 1)
        nbrOfScores = parseCommandLine(argc, argv);
    else
    {
        printf("How many scores : %d\n", MIN_SCORES, MAX_SCORES);
        scanf("%d, &nbrOfScores");
    }
    
    if (nbrOfScores < MIN_SCORES || nbrOfScores > MAX_SCORES)
    {
        printf("ERROR: The number of scores must be between %d and %d\n", MIN_SCORES , MAX_SCORES); 
    }
    else
    {
        readScores(scoreTable, nbrOfScores);
        displayScoreTable(scoreTable, nbrOfScores);

        minimumScore = findMinimumScore(scoreTable, nbrOfScores);
        maximumScore = findMaximumScore(scoreTable, nbrOfScores);
        averageScore = calculateAverageScore(scoreTable, nbrOfScores);

        displayStatisticsReport(minimumScore, maximumScore, averageScore);
    }
    return 0;
}

int parseCommandLine(int argc, char *argv[])
{
    return atoi(argv[1]);
}

void readScores(int table[], int scoreCount)
{
    for(int i = 0; i < scoreCount; i++)
    {
        scanf("%d", &table[i]);
    }
}

void displayScoreTable(int table[], int scoreCount)
{
    printf("Contents of the score table:");
    for (int i = 0; i < scoreCount; i++)
    {
        printf(" ", table[i]);
    }
    printf("")
}

int findMinimumScore(int table[], int scoreCount)
{
    int minimumScore = table[0];
    for (int i = 1; i < scoreCount; i++)
    {
        if(table[i] < minimumScore)
            minimumScore = table[i];
    }
    return minimumScore;
}

int findMaximumScore(int table[], int scoreCount)
{
    int maximumScore = table[0];

    for (int i = 1; i < scoreCount; i++)
    {
        if (table[i] > maximumScore)
            maximumScore = table[i];
    }
    return maximumScore;
}

double calculateAverageScore(int table[], int scoreCount)
{
    double sum = 0;
    double average = 0;

    for (int i = 0; i < scoreCount; i++)
    {
        sum = sum + table[i];
    }
    return sum / scoreCount;
}

void displayStatisticsReport(int minScore, int maxScore, double avgScore)
{
    printf("*** Statistics Report *** ");
    printf();
    printf("Maximum Minimum Average");
    printf("-------  ------- -------- ")
    printf()
    printf("%7d %7d %7.f\n", minScore, maxScore, avgScore);
}



