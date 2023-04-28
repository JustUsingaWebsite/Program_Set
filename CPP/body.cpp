#include "Pset_Header.h"
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void MySort::printBucket(){
   for (int i = 0; i < 10; i++)
    {
        cout << bucket[i][0] << " " << bucket[i][1] << " " << bucket[i][2] << " " << bucket[i][3] << " " << bucket[i][4] << " -> bucket \n";
    }
    
    cout << "\n" << "-----------------------------------------------------------------------" << "\n";
    
        

    std::cout<<"\n";
    //std::cin.get();
}

void MySort::resetBucket(){

    for (int i = 0; i < 10; i++)
    {
        for (int ii = 0; ii < 10; ii++)
        {
            bucket[i][ii] = 0;
        }
        
    }
    
}

void MySort::collectValues(int a[]){

   int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 1; j < 10; j++) {
            if (bucket[i][j] != 0) {
                cout << bucket[i][j] << " ";
                a[index++] = bucket[i][j];
            }
        }
    }
    cout << endl;
   
}

int MySort::determineMaximumDigits(int arr[], int v){

int largestvalue = arr[0];

    for (int i = 0; i < v; i++)
    {
       if(arr[i] > largestvalue){largestvalue = arr[i];}
    }

int digitcount = 0;

    while (largestvalue > 0)
    {
        largestvalue = largestvalue /10;
        digitcount++;
    }
    
    cout << "max number: " << digitcount << endl;
    return digitcount;
}

void MySort::sort(int a[]){
    
    int totalDigits = determineMaximumDigits(a , SIZE);
    resetBucket();

    for (int currentDigit = 1; currentDigit  < totalDigits; currentDigit++)
    {
       distributeValues(a, currentDigit);
       collectValues(a);
       printBucket();
       if(currentDigit != totalDigits)
       {
        resetBucket();
       } else
       {
        
       }
       
    }
    

}

void move_down(int a[], int size){
    memmove(&a[2], &a[1], sizeof(int)*(size-1));
    a[1] = 0;
}

void compare(int a[]){
    //change to a for loop
    int temp = a[1];
    int temp2;
    
    if (a[1] > a[2] && a[2] != 0){
        a[1] = a[2];
        a[2] = temp;
    }
    
    if (a[2] > a[3] && a[3] != 0){
        cout << "Asdada " << a[2];
        temp2 = a[2];
        a[2] = a[3]; 
        a[3] = temp2;
    }
}


void MySort::distributeValues(int a[], int k){

    int rowNumber, divisor, columnNumber, newDivisor;
    divisor = pow(10, k); 
    columnNumber = 0;
    
    for(int i=0; i<9; i++){
        rowNumber = (a[i] % divisor - a[i] % (divisor / 10)) / (divisor / 10);

        
        if(bucket[rowNumber][columnNumber] != 0){
            //if the bucket has a value at the first place we move down one place to make space
            // eg 1 [1][0] eg 2 [0][1]
            move_down(bucket[rowNumber], 10);

            // check if a is more than b then swap variables
            bucket[rowNumber][columnNumber + 1] = a[i];
            compare(bucket[rowNumber]);
            bucket[rowNumber][0]++;

            //cout << "[" << bucket[i][columnNumber] << "] " ;

        } else { 
            
            bucket[rowNumber][columnNumber + 1] = a[i];
            bucket[rowNumber][0]++;
        }
        
        
        
        
        
        
        //cout << rowNumber << "[" << a[i] << "] \n";
    }

 
} /**/

/*void MySort::distributeValues(int a[], int k){
    int rowNumber, divisor, columnNumber;
    divisor = pow(10, k);
    int counts[10] = {0}; // initialize counts to 0

    // Loop through each value in the unsorted array
    for (int i = 0; i < SIZE; i++) {
        // Calculate the appropriate row based on the current divisor and count
        int count = ++counts[(a[i] % divisor) / (divisor / 10)];
        rowNumber = (a[i] % divisor - a[i] % (divisor / 10)) / (divisor / 10) + count - 1;
        
        // Calculate the appropriate column based on the current count in the row
        columnNumber = bucket[rowNumber][0] + 1;
        
        // Store the value in the appropriate location in the bucket array
        bucket[rowNumber][columnNumber] = a[i];
        
        // Increment the count in the row
        bucket[rowNumber][0]++;
    }
}*/
