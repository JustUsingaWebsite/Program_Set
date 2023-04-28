#include <iostream>
#include "Pset_body.cpp"

using namespace std;

int main()
{
    int array[MySort::SIZE] = {100, 100, 100, 519, 37, 9999, 3, 1, 238};
    /*
        [][][][][][][][][][]
        [][][][][][][][][][]
        [][][][][][][][][][]
        [][][][][][][][][][]
        [][][][][][][][][][]
        [][][][][][][][][][]
        [][][][][][][][][][]
        [][][][][][][][][][]
        [][][][][][][][][][]
        [][][][][][][][][][]

        [][][]
    */

   std::cout << endl;
    std::cout<<"Original array elements: \n";

    for(int i = 0; i < MySort::SIZE; i++)
        std::cout<<std::setw( 5 ) << array[ i ];

    std::cout<<"\n\n";

//return 0; //break

    MySort sortObj;
    sortObj.sort(array);

    std::cout<<"\nArray elements in sorted order: \n";

    for(int i = 0; i < MySort::SIZE; i++)
        std::cout<<std::setw( 5 ) << array[ i ];

    std::cout<<"\n";
    //std::cin.get();

    return 0;
}
