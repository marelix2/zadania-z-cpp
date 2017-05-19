#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Collection {
    int  elno;
    int *elements;
};
void AddToCollection(Collection &col, int element) {
    // Insert your code here
    if(col.elno == 0){
        col.elno++;
    col.elements = new int[1];
    col.elements[0] = element;
    }
    else
    {
       col.elno++;
       int *a = col.elements;
       //delete[] col.elements;
       col.elements = new int[col.elno];

       for(int i = 0; i < col.elno-1 ; i++) col.elements[i] = a[i];

       col.elements[col.elno - 1] = element;
       delete[] a;


    }

}

void PrintCollection(Collection col) {
 cout << "[ ";
 for(int i = 0; i < col.elno; i++)
     cout << col.elements[i] << " ";
 cout << "]" << endl;
}


int main(void) {
        Collection collection = { 0, NULL };
     int elems;
     cout << "How many elements? ";
     cin >> elems;

     srand(time(NULL));

     for(int i = 0; i < elems; i++)   AddToCollection(collection, rand() % 100 + 1);
     PrintCollection(collection);
     delete[] collection.elements;
     return 0;

 }
