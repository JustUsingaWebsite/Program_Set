
#pragma once

class MySort
{
private:
    int determineMaximumDigits(int[], int);
    void distributeValues(int[], int);
    void collectValues(int[]);
    void resetBucket();
    void printBucket();

public:
    MySort();
    static const int SIZE = 9;
    int bucket[10][SIZE + 1];
    int array[SIZE + 1];
    void sort(int[]);
};
