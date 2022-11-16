#include <iostream>
#include <vector>
using namespace std;

// void heapify(vector<int> a, int n, int i) {

//   // Initialize largest as root
//   int largest = i;

//   // left = 2*i + 1
//   int l = 2 * i + 1;

//   // right = 2*i + 2
//   int r = 2 * i + 2;

//   // If left child is larger than root
//   if (l < n && a[l] > a[largest])
//     largest = l;

//   // If right child is larger than largest
//   // so far
//   if (r < n && a[r] > a[largest])
//     largest = r;

//   // If largest is not root
//   if (largest != i) {
//     swap(a[i], a[largest]);

//     // Recursively heapify the affected
//     // sub-tree
//     heapify(a, n, largest);
//   }
// }

// void heapsort(vector<int> &a) {
//   int n = a.size();
//   // Build heap (rearrange array)
//   for (int i = n / 2 - 1; i >= 0; i--)
//     heapify(a, n, i);

//   // One by one extract an element
//   // from heap
//   for (int i = n - 1; i > 0; i--) {

//     // Move current root to end
//     swap(a[0], a[i]);

//     // call max heapify on the reduced heap
//     heapify(a, i, 0);
//   }
// }

// int main() {
//   vector<int> a = {12, 11, 13, 5, 6, 7};
//   heapsort(a);

//   for (int i = 0; i < a.size(); i++) {
//     cout << a[i] << " ";
//   }
//   cout << endl;
// }

void heapify(int arr[], int N, int i)
{
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int l = 2 * i + 1;
 
    // right = 2*i + 2
    int r = 2 * i + 2;
 
    // If left child is larger than root
    if (l < N && arr[l] > arr[largest])
        largest = l;
 
    // If right child is larger than largest
    // so far
    if (r < N && arr[r] > arr[largest])
        largest = r;
 
    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
 
    // Build heap (rearrange array)
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);
 
    // One by one extract an element
    // from heap
    for (int i = N - 1; i > 0; i--) {
 
        // Move current root to end
        swap(arr[0], arr[i]);
 
        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}
 
// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}
 
// Driver's code
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int N = sizeof(arr) / sizeof(arr[0]);
 
    // Function call
    heapSort(arr, N);
 
    cout << "Sorted array is \n";
    printArray(arr, N);
}
