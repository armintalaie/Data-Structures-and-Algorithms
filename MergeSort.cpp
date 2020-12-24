#include <iostream>
#include <stdlib.h>

using namespace std;

/**
 * merges two arrays into a sorted array.
 *
 * merges both arrays by comparing each element from both arrays 
 * and storing them
 *
 * @param array array of integers to be sorted
 * @param lo starting index of array
 * @param hi last index of array + 1
 */
void stitch(int array[], int lo, int hi)
{
    // array size of 1
    if (hi - lo < 1)
        return;

    int leftIndex = lo;
    int rightIndex = (lo + hi) / 2;

    // boundary points for left and right
    int leftLast = (lo + hi) / 2;
    int rightLast = hi;

    // temporary array to store merge
    int placeHolder[hi - lo];

    // fills placeHolder in incfeasing order of the elements of arrays
    for (int i = 0; i < hi - lo; i++)
    {
        if (leftIndex < leftLast)
        {
            if (rightIndex < rightLast &&
                array[rightIndex] < array[leftIndex])
            {
                placeHolder[i] = array[rightIndex];
                rightIndex++;
                continue;
            }

            placeHolder[i] = array[leftIndex];
            leftIndex++;
        }
        else
        {
            placeHolder[i] = array[rightIndex];
            rightIndex++;
        }
    }

    // replaces original array with sorted placeHolder
    for (int i = 0; i < hi - lo; i++)
    {
        array[i + lo] = placeHolder[i];
    }
}

/**
 * sorts array by using mergeSort.
 *
 * partitons the array from the middle recursively
 * and call stitch to sort the partitions
 *
 * @param array array of integers to be sorted
 * @param lo starting index of array
 * @param hi last index of array + 1
 */
void partition(int array[], int lo, int hi)
{

    // if we can split, we partition again
    if (hi - lo > 1)
    {
        partition(array, lo, (lo + hi) / 2);
        partition(array, (lo + hi) / 2, hi);
    }

    // merge our partition
    stitch(array, lo, hi);
}

// running example of mergeSort
int main()
{
    int size = 10;
    int arr[] = {3, 6, 1, 7, 9, 2, 4, 5, 10, 8};

    // print unsorted array
    cout << "unsorted array:\t";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;

    // call mergesort
    partition(arr, 0, size);

    // print sorted array
    cout << "sorted array:\t";
    for (int i = 0; i < size; ++i)
        cout << arr[i] << " ";
    cout << endl;
}
