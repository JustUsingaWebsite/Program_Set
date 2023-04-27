/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;
int bucket[10][10] = {{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
int array[9];

void func_(int[], int);
void move_down(int[], int);
void collectValues(int[]);
void reset();

void print();

int main()
{
   
    int arr[9] = {229, 228, 227, 226, 225, 224, 223, 222, 221}; //100, 100, 100, 519, 37, 9999, 3, 1, 238
   /* func_(arr, 3);
    collectValues(arr);
    print();
    reset();
    print();
    return 0; */
    
    for (int currentDigit = 1; currentDigit  < 4; currentDigit++)
    {
        func_(arr, currentDigit);
        collectValues(arr);
        print();
        if (currentDigit != 4)
        {
           reset();
        }
        
    }
    
    //func_(arr, 4);
    //collectValues(arr);
    //print();
    //reset();
    //print();
    //return 0;
    
    for(int i=0; i<9; i++){
        cout << array[i] << " ";
    }

    return 0;
}

void reset(){
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
           bucket[i][j] = 0;
        }
        
    }
}

void collectValues(int a[]) {
    int index = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            if (bucket[i][j] != 0) {
                cout << bucket[i][j] << " ";
                array[index++] = bucket[i][j];
            }
        }
    }
    cout << endl;
}

void print(){
    for (int i = 0; i < 10; i++)
    {
        cout << bucket[i][0] << " " << bucket[i][1] << " " << bucket[i][2] << " " << bucket[i][3] << " " << bucket[i][4] << " -> bucket \n";
    }
    
    cout << "\n" << "-----------------------------------------------------------------------" << "\n";
}

void move_down(int a[], int size){
    memmove(&a[1], &a[0], sizeof(int)*(size-1));
    a[0] = 0;
}

void compare(int a[]){
    //change to a for loop
    int temp = a[0];
    int temp2;
    
    if (a[0] > a[1] && a[1] != 0){
        a[0] = a[1];
        a[1] = temp;
    }
    
    if (a[1] > a[2] && a[2] != 0){
        cout << "Asdada " << a[1];
        temp2 = a[1];
        a[1] = a[2];
        a[2] = temp2;
    }
}

void func_(int a[], int k){
    int rowNumber, divisor, columnNumber, newDivisor;
    divisor = pow(10, k); columnNumber = 0;
    
    for(int i=0; i<9; i++){
        rowNumber = (a[i] % divisor - a[i] % (divisor / 10)) / (divisor / 10);

        
        if(bucket[rowNumber][columnNumber] != 0){
            //if the bucket has a value at the first place we move down one place to make space
            // eg 1 [1][0] eg 2 [0][1]
            move_down(bucket[rowNumber], 10);

            // check if a is more than b then swap variables
            
            bucket[rowNumber][columnNumber] = a[i];
            
            compare(bucket[rowNumber]);

            //cout << "[" << bucket[i][columnNumber] << "] " ;

        } else { 
            
            bucket[rowNumber][columnNumber] = a[i];
        }
        
        
        
        
        
        
        //cout << rowNumber << "[" << a[i] << "] \n";
    }
    
    
}
