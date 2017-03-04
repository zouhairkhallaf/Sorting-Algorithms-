//This program is a templated simple sorting algorithms Insertion, Selection, and Bubble Sort.
//Tested on arrays of characters, strings, and integers.

#include <iostream>
using namespace std;

template <typename ItemType>
void INSERTION(ItemType A[], int N);
template <typename ItemType>
void SELECTION(ItemType A[], int N);
template <typename ItemType>
void BUBBLE(ItemType A[], int N);
template <typename ItemType>
void mySwap(ItemType A[], int i, int j);
template <typename ItemType>
void displayArray(ItemType A[], int N);

int main(){
    cout <<endl << "PROGRAM START"<<endl<<endl ;
    
    int A[] = {9,0,7,8,5,6,4,3,2,1,324,324,43,54,45,56,678,89,78,9,12349,80,9,39};
    char B[] = {'V','a','Y','C','I','G','g','s','f','v','p'};
    string C[] = {"Ibrahim","Fadoua","Elgavv","Ea","jilali","karim","ch3ibiya","daoudi","Elgarbouz","mourad","zohair"};
    
    int sizeOfa = sizeof(A)/sizeof(A[0]);
    int sizeOfb = sizeof(B)/sizeof(B[0]);
    int sizeOfc = sizeof(C)/sizeof(C[0]);

    //display arraybefore
    //sort
    //display array after
    
    cout <<endl << "PROGRAM ENDS" <<endl;
    return 0;
}
//------------------------SIMPLE SORTING ALGORITHMS----------------------------------

template <typename ItemType>
void INSERTION(ItemType A[], int N){
    for (int i=1; i<N; i++) {
        int k = i;
        while(k>0 && A[k]<A[k-1]){
            mySwap(A, k, k-1);
            k--;
        }
    }
}

template <typename ItemType>
void BUBBLE(ItemType A[], int N){
    bool bubble = true;
    int noSwapsCount = 0;
    while(bubble && (noSwapsCount != N-1))
    {
        bubble = false;
        noSwapsCount = 0;
        for (int i=0; i<N-1; i++) {
            if (A[i]>A[i+1]) {
                mySwap(A, i, i+1);
                bubble = true;
            }else{
                noSwapsCount ++;
            }
        }
    }
}

template <typename ItemType>
void SELECTION(ItemType A[], int N){
    for (int i=0; i<N; i++) {
        for (int j=i+1; j<N; j++) {
            if (A[i]>A[j]) {
                mySwap(A, i, j);
            }
        }
    }
}

//------------------------FASTER SORTING ALGORITHMS----------------------------------

template<typename ItemType>
void Quicksort(ItemType arr[], int left, int right)
{
    int i = left;
    int j = right;
    ItemType pivote = arr[(left+right)/2];
    while(i<=j)
    {
        while (arr[i] < pivote)
            i++;
        while (arr[j] > pivote)
            j--;
        if (i<=j)
        {
            mySwap(arr, i, j);
            i++;
            j--;
        }
    }
    if (left < j)
        Quicksort(arr,left,j);
    if (i < right)
        Quicksort(arr,i,right);
}

void merge(int theArray[], int first, int mid, int last){
    int tempArray[10];
    int first1 = first;     // Beginning of first subarray
    int last1 = mid;        // End of first subarray
    int first2 = mid + 1;   // Beginning of second subarray
    int last2 = last;       // End of second subarray
    int index = first1;     // Next available location in tempArray
    while ((first1 <= last1) && (first2 <= last2)){
        if (theArray[first1] <= theArray[first2]){
            tempArray[index] = theArray[first1];
            first1++;
        }else{
            tempArray[index] = theArray[first2];
            first2++;
        }
        index++;
    }
    while (first1 <= last1){
        tempArray[index] = theArray[first1];
        first1++;
        index++;
    }
    while (first2 <= last2){
        tempArray[index] = theArray[first2];
        first2++;
        index++;
    }
    for (index = first; index <= last; index++)
        theArray[index] = tempArray[index];
}

void RadixSort(){
    
}
//--------------------COMPARISION SORTING ALGORITHMS--------------------------


void HeapSort(){
    
}
void TreeSort(){
    
}

//----------------------------------------------------------------------------



template <typename ItemType>
void mySwap(ItemType A[], int i, int j){
    ItemType temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <typename ItemType>
void displayArray(ItemType A[], int N){
    cout << "[]={";
    for (int i=0; i<N; i++) {
        cout << A[i];
        if(i<=N-2)
            cout << ",";
    }
    cout <<"}"<<endl;
}

/* Complexity
Selection           : N^2  All
Insertion, Bubble	: Best case is O(N), but the rest is same as Selection
Merge, Heap         : O(N Log N) ALL
Quick Sort          : Worst O(N^2) rest same as Merge.
Radix Sort          : O(nk)
*/


