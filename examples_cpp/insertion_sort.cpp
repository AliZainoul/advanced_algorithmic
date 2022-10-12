#include <iostream>

using std::cout;

// A utility function to print an array of size n
void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << '\n';
}
// Function to sort an array using insertion sort
void insertionSort(int arr[], int n) {
  int i{}, j{}, key{};
  for (i = 1; i < n; i++) {
    key = arr[i];
    j = i - 1;
    /*
      Move elements of arr[0..i-1], that are greater than key,
      to one position ahead of their current position
    */
    while (j >= 0 && arr[j] > key)
    {
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}
// Complexity : O(n^2)


// Driver code
int main()
{
  // Declaring a static array
  int arr[] = { 12, -22, 2, 3, 75 };

  // Common way to know the size of an array, there is better ways!
  int sizeArray = sizeof(arr) / sizeof(arr[0]);

  cout << " ------------------------ "      << '\n';
  cout << "My array before being sorted: "  << '\n';
  printArray(arr, sizeArray);
  cout << "Sorting..."                      << '\n';
  insertionSort(arr, sizeArray);
  cout << "My array sorted : "              << '\n';
  printArray(arr, sizeArray);
  cout << " ------------------------ "      << '\n';

  return 0;
}
