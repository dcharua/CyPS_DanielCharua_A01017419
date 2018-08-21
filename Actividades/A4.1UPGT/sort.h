#include <iostream>

using namespace std;

class Sort{
public:
  virtual void sort(int arr[], int n) = 0;
  void print(int arr[], int n){
    for (int i=0; i < n; i++)
      cout << arr[i]<< endl;
  }
};

class Child1 : public Sort{
public:
  void sort(int arr[], int n){
    cout << "bubble sort"<<endl;
    int i, j;
    for (i = 0; i < n-1; i++)
       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
  }
  void swap(int *xp, int *yp){
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
  }
};

class Child2 : public Sort{
public:
  void sort(int arr[], int n){
  cout << "insertion sort"<<endl;
   int i, key, j;
   for (i = 1; i < n; i++){
       key = arr[i];
       j = i-1;
       while (j >= 0 && arr[j] > key){
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
     }
  }
};

class Child3 : public Sort{
public:
  void sort(int arr[], int n){
    // Find the maximum number to know number of digits
    int m = getMax(arr, n);

    // Do counting sort for every digit. Note that instead
    // of passing digit number, exp is passed. exp is 10^i
    // where i is current digit number
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
  }

  int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n]; // output array
    int i, count[10] = {0};

    // Store count of occurrences in count[]
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    // Change count[i] so that count[i] now contains actual
    //  position of this digit in output[]
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array
    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }

    // Copy the output array to arr[], so that arr[] now
    // contains sorted numbers according to current digit
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

};
