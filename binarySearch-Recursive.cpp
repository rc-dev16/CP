/*
 * Binary Search - Recursive Implementation
 * This program implements binary search algorithm using recursive approach.
 * Binary search works on sorted arrays by repeatedly dividing the search interval in half.
 * Time Complexity: O(log n)
 * Space Complexity: O(log n) due to recursion stack
 */

#include<iostream>
using namespace std;

int binarySearch(int arr[],int start,int end,int key){
    if(start>end){
        return -1;
    }
   int mid=start+(end-start)/2;
   if(arr[mid]==key){
    return mid;
   }
   if (arr[mid]<key){
    return binarySearch(arr,mid+1,end,key);
   }
   else{
    return binarySearch(arr,start,mid-1,key);
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
    
    int key;
    cout<<"enter the key to search for"<<endl;
    cin>>key;

    int result=binarySearch(arr,0,n-1,key);

    if(result==-1){
        cout<<"key not found"<<endl;
    }
    else{
        cout<<"key found at index"<<result<<endl;
    }
    return 0;
}
