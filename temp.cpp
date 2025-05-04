#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();

    for(int i = 0 ; i < n;i++){
        int minIndex = i;
        for(int i = j ; j <n;j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(i != minIndex){
            swap(arr[i],arr[minIndex]);
        }
    }
}

void printArray(vector<int>&arr){
    for(int i = 0 ; i < arr.size();i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {2,1,4,3,7,9};
    cout<<"Array Before it sorted : "<<endl;
    printArray(arr);

    selectionSort(arr)

    cout<<"Array After it sorted : "<<endl;
    printArray(arr);
    return 0;
}
