/*
 * Bubble Sort Implementation
 * This program implements bubble sort algorithm.
 * Bubble sort repeatedly steps through the list, compares adjacent elements and swaps them if they are in the wrong order.
 * Time Complexity: O(n^2) in worst and average case, O(n) in best case (already sorted)
 * Space Complexity: O(1)
 */

#include<iostream>
using namespace std;

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
            }
        }
    }
}

int main(){
    int n;
    cout<<"enter the size of the array"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements of the array"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    bubbleSort(arr,n);
    cout<<"sorted array is"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}
