
#include "mysort.h"
#include <cmath>
#include <iostream>

using namespace std;

MySort::MySort()
{
    resetBucket();
}

void MySort::printBucket()
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << bucket[i][j] << " ";
            if (j == 9) {
                cout << " -> bucket \n";
            }
        }
    }

    cout << "---------------------------------------- \n";
}

void MySort::resetBucket()
{
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            bucket[i][j] = 0;
        }
    }
}

void MySort::collectValues(int a[])
{
    //loop thru all buckets and if data is not equal to zero
    // then assign that data to data in unsorted array

    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (bucket[i][j] != 0) {
                a[index++] = bucket[i][j];
            }
        }
    }
}

int MySort::determineMaximumDigits(int arr[], int v)
{
    // suggest the first value is the biggest
    // loop and check for bigger value then change

    int largestvalue = arr[0];

    for (int i = 0; i < v; i++) {
        if (arr[i] > largestvalue) {
            largestvalue = arr[i];
        }
    }

    // create new int
    // create a loop to keep dividing by 10
    // index created int thru the loop to plus 1
    // break loop at less than 0 and return created int

    int digitcount = 0;

    while (largestvalue > 0) {
        largestvalue = largestvalue / 10;
        digitcount++;
    }

    return digitcount;
}

void MySort::sort(int a[])
{
    // get the max digits
    // reset the bucket incase values are in there
    // create a loop to loop max digits amount of times
    // distrute, collect then reset but if we reach max digits break

    int totalDigits = determineMaximumDigits(a, SIZE);
    resetBucket();

    for (int currentDigit = 1; currentDigit < totalDigits; currentDigit++) {
        distributeValues(a, currentDigit);
        collectValues(a);
        printBucket();
        if (currentDigit != totalDigits) {
            resetBucket();
        } else {
        }
    }
}

void MySort::distributeValues(int a[], int k)
{
    // make row, column, divisor
    // set divisor to 10 to the power of the parameter passed
    // create loop and set first value in row to plus 1 to show the amout inside the row
    // find column position
    // set position found with row and column to the value in unsorted array
    //print bucket to see what's happening

    int rowNumber, divisor, columnNumber;
    divisor = pow(10, k);
    columnNumber = 0;

    for (int i = 0; i < SIZE; i++) {
        rowNumber = (a[i] % divisor - a[i] % (divisor / 10)) / (divisor / 10);

        bucket[rowNumber][0] += 1;
        columnNumber = bucket[rowNumber][0];
        bucket[rowNumber][columnNumber] = a[i];
        printBucket();
        continue;
    }
}
