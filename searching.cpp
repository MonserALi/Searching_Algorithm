#include<bits/stdc++.h>

using namespace std;
void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}

void insertionSort(int arr[], int n)
{
    for(int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i-1;

        while(key < arr[j] && j >= 0)
        {
            swap(&arr[j], &arr[j+1]);
            j--;
        }
    }
    //cout << "Sorted with Insertion Sort" << endl;
}

void printArray(int arr[], int n)
{
    for(int i=0; i < n; i++)
    {
        cout << i << ": " << arr[i] << endl;
    }
}

int linearSearch(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i]==key)
        {
            return i;
        }
    }
    return -1;
}

int binarySearch(int arr[], int n, int key)
{
    int left = 0;
    int right = n;
    int mid;
    while(left <= right)
    {
        mid = (left + right)/2;

        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] > key)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return -1;
}

int interpolationSearch(int arr[], int n, int key)
{
    int low = 0, high = n ;

    while (low <= high)
    {
        if (low == high)
        {
            if (arr[low] == key) return low;
            return -1;
        }
        int pos = low + (((high - low) / (arr[high] - arr[low])) * (key - arr[low]));

        if (arr[pos] == key)
            return pos;

        if (arr[pos] < key)
            low = pos + 1;
        else
            high = pos - 1;
    }
    return -1;
}


int main()
{

    int n,key;
    cout<<"Enter size : ";
    cin>>n;

    int arr[n];
    cout<<"Enter array elements : ";
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout << "What are you looking for? : ";
    cin >> key;

    int flag;
    //flag = linearSearch(arr, n, key);
    //flag = binarySearch(arr,n-1, key);
    flag = interpolationSearch(arr, n-1, key);
    if(flag < 0)
    {
        cout << "The item doesn't exist in the array!" << endl;
    }
    else
    {
        cout << "The item found at the " << flag+1 << "th position." << endl;
    }

    return 0;
}
