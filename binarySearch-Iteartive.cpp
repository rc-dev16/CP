/*
 * Binary Search - Iterative Implementation
 * This program implements binary search algorithm using iterative approach.
 * Binary search works on sorted arrays by repeatedly dividing the search interval in half.
 * Time Complexity: O(log n)
 * Space Complexity: O(1)
 */

#include<iostream>
using namespace std;

int binartsearch(int arr[],int size, int key){
    int start=0;
    int end=size-1;

    int mid=start+(end-start)/2;

    while(start<=end){
        if(arr[mid]==key){
            return mid;
        }
        if(arr[mid]<key){
            start=mid+1;
        }
        else{
            end=mid-1;
        }
        mid=start+(end-start)/2;
    }
    return -1;
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

    int key;
    cout<<"enter the key to search for"<<endl;
    cin>>key;

    int result=binartsearch(arr,n,key);

    if(result==-1){
        cout<<"key not found"<<endl;
    }
    else{
        cout<<"key found at index"<<result<<endl;
    }

    return 0;
}