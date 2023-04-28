#ifndef PSET_HEADER_H_
#define PSET_HEADER_H_



class MySort
{
private: int determineMaximumDigits(int[], int);
private: void distributeValues(int[], int);
private: void collectValues(int[]);
private: void resetBucket();
private: void printBucket();
   
public: MySort();
public: ~MySort();
public: static const int SIZE = 9;
public: int bucket[10][SIZE + 1]; // {{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0}};
public: int array[SIZE + 1];
public: void sort(int[]);
};

MySort::MySort()
{
    resetBucket();
}

MySort::~MySort()
{
}





#endif /* !PSET_HEADER_H_ */
