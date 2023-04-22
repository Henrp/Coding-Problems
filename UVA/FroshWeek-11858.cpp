#include <bits/stdc++.h>
using namespace std;
 
 int ans = 0;
// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
 
        // Last i elements are already
        // in place
        for (j = 0; j < n - i-1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]); ans++;
}
 
// Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
 
// Driver code
int main()
{
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++){
        int a; cin >> a;
        arr[i] = a;
    }

    bubbleSort(arr, n);
    cout << ans;
}