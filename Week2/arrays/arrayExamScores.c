/*
 * Tony Caelum
 * 3 September 22, ZZEN9216
 * A program to get information about an array of exam scores
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define ARRAY_SIZE 100

int min(int array[], int arraySize);
int max(int array[], int arraySize);
float average(int array[], int arraySize);
int numHDScores(int array[], int arraySize);
int numDNScores(int array[], int arraySize);
int numCRScores(int array[], int arraySize);
int numPScores(int array[], int arraySize);
int numFScores(int array[], int arraySize);
void printExamScoreStats(int array[], int arraySize);
void printStatsToFile(
    int minScore, int maxScore, float avgScore,
    int numHD, int numDN, int numCR, int numP, int numF
);

int main(int argc, char** argv) {
    // Note: you do not need to change any code in main
    // This code in main:
    // - seeds the 'rand()' function (for random values each time)
    // - creates the array
    // - opens the text file (for printing the random scores to)
    // - fills the array with random values [0 - 100]
    // - prints each array value into the text file
    // - prints the exam score stats

    srand(time(NULL));
    int intArray[ARRAY_SIZE];
    FILE* scoresFile = fopen("examScores.txt", "w");
    int index = 0;
    while (index < ARRAY_SIZE) {
        intArray[index] = (rand() % 101);
        fprintf(scoresFile, "%d\n", intArray[index]);
        index = index + 1;
    }
    fclose(scoresFile);

    printExamScoreStats(intArray, ARRAY_SIZE);

    printf("\n");
    return EXIT_SUCCESS;
}

// prints the Exam score statistics to the terminal, and into a txt file
void printExamScoreStats(int array[], int arraySize) {
    // variables for the exam statistics -
    // each is assigned -1 to begin with so that:
    // * you can easily see if there are any errors (common practice)
    // * you can compile and run your code at any point without issues
    int minScore = -1;
    int maxScore = -1;
    float averageScore = -1;
    int numHD = -1;
    int numDN = -1;
    int numCR = -1;
    int numP = -1;
    int numF = -1;

    minScore = min(array, arraySize);
    // Step 7: WRITE YOUR CODE HERE
    maxScore = max(array, arraySize);
    averageScore = average(array, arraySize);

    numHD = numHDScores(array, arraySize);
    numDN = numDNScores(array, arraySize);
    // Step 10: WRITE YOUR CODE HERE
    numCR = numCRScores(array, arraySize);
    numP = numPScores(array, arraySize);
    numF = numFScores(array, arraySize);

    printf("Array of student scores:\n");
    int index = 0;
    // Step 3: WRITE YOUR CODE HERE
    while (index < arraySize) {
        if (index == arraySize - 1) {
            printf("%d", array[index]);
        } else {
            printf("%d, ", array[index]);
        }
        index = index + 1;
    }

    printf("\n\n");

    printf("Exam score statistics:\n");
    printf("Minimum score: %d\n", minScore);
    // Step 8: WRITE YOUR CODE HERE
    printf("Maximum score: %d\n", maxScore);
    printf("Average score: %0.2f\n", averageScore);

    printf(
        "Number of students that achieved High Distinction: %d\n",
        numHD
    );
    printf(
        "Number of students that achieved Distinction: %d\n",
        numDN
    );
    printf(
        "Number of students that achieved Credit: %d\n",
        numCR
    );
    printf("Number of students that achieved Pass: %d\n", numP);
    printf("Number of students that achieved Fail: %d\n", numF);

    printStatsToFile(
        minScore, maxScore, averageScore,
        numHD, numDN, numCR, numP, numF
    );
}

// returns the minimum value in the array
int min(int array[], int arraySize) {
    int minValue = array[0];
    int index = 0;
    while (index < arraySize) {
        if (array[index] < minValue) {
            minValue = array[index];
        }
        index = index + 1;
    }

    return minValue;
}

// returns the maximum value in the array
int max(int array[], int arraySize) {
    // Step 4: WRITE YOUR CODE HERE
    int maxValue = 0;
    int index = 0;
    while (index < arraySize) {
        if (array[index] > maxValue) {
            maxValue = array[index];
        }
        index = index + 1;
    }

    return maxValue;
}

// returns the average value of the elements in the array
float average(int array[], int arraySize) {
    float avg = 0;
    int sumTotal = 0;
    int index = 0;
    // Step 6: WRITE YOUR CODE HERE
    while (index < arraySize) {
        sumTotal = sumTotal + array[index];
        index = index + 1;
    }

    // to avoid "integer division" calculating 'avg'
    avg = sumTotal / (float)arraySize;
    return avg;
}

// returns the number of scores between 85 and 100 (inclusive)
int numHDScores(int array[], int arraySize) {
    int scoreCountHD = 0;
    int index = 0;
    while (index < arraySize) {
        if (array[index] >= 85) {
            scoreCountHD = scoreCountHD + 1;
        }
        index = index + 1;
    }
    return scoreCountHD;
}

// returns the number of scores between 75 and 84 (inclusive)
int numDNScores(int array[], int arraySize) {
    int scoreCountDN = 0;
    int index = 0;
    while (index < arraySize) {
        if (array[index] >= 75 && array[index] <= 84) {
            scoreCountDN = scoreCountDN + 1;
        }
        index = index + 1;
    }
    return scoreCountDN;
}

// returns the number of scores between 65 and 74 (inclusive)
int numCRScores(int array[], int arraySize) {
    int scoreCountCR = 0;
    int index = 0;
    while (index < arraySize) {
        if (array[index] >= 65 && array[index] <= 74) {
            scoreCountCR = scoreCountCR + 1;
        }
        index = index + 1;
    }

    return scoreCountCR;
}

// returns the number of scores between 50 and 64 (inclusive)
int numPScores(int array[], int arraySize) {
    int scoreCountP = 0;
    int index = 0;
    while (index < arraySize) {
        if (array[index] >= 50 && array[index] <= 64) {
            scoreCountP = scoreCountP + 1;
        }
        index = index + 1;
    }

    return scoreCountP;
}

// returns the number of scores between 0 and 49 (inclusive)
int numFScores(int array[], int arraySize) {
    int scoreCountF = 0;
    int index = 0;
    while (index < arraySize) {
        if (array[index] >= 0 && array[index] <= 49) {
            scoreCountF = scoreCountF + 1;
        }
        index = index + 1;
    }

    return scoreCountF;
}

/*
 * prints the exam score statistics to the "examStats.txt" file
 * for auto-marking
 * Note: do not change any code in this function
 */
void printStatsToFile(
    int minScore, int maxScore, float avgScore,
    int numHD, int numDN, int numCR, int numP, int numF
) {
    FILE* statsfile;
    statsfile = fopen("examStats.txt", "w");
    fprintf(statsfile, "%d\n", minScore);
    fprintf(statsfile, "%d\n", maxScore);
    fprintf(statsfile, "%f\n", avgScore);
    fprintf(statsfile, "%d\n", numHD);
    fprintf(statsfile, "%d\n", numDN);
    fprintf(statsfile, "%d\n", numCR);
    fprintf(statsfile, "%d\n", numP);
    fprintf(statsfile, "%d\n", numF);
    fclose(statsfile);
}
