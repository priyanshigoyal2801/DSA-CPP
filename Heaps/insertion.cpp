#include<iostream>
// #include<bits/stdc++.h>
using namespace std;
class heap{
int arr[100];
int size;
public:
heap(){
    arr[0]=-1;
    size=0;
}
void insert(int val){
    size+=1;
    int index=size;
    arr[index]=val;
    while(index>1){
        int parent=index/2;
        if(arr[parent]<arr[index]){
            swap(arr[parent],arr[index]);
            index=parent;
        }
        else
        return;
    }
}
void print(){
    for(int i=1; i<=size;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}
void Delete(){
    if(size==0){
        cout<<"nothing to delete";
        return;
    }
    //first node is last node
arr[1]=arr[size];
//remove last node
size--;
int i=1;
//taking root to correct position
while(i<= size){
    int left=2*i;
    int right=2*i+1;
    if(left<size && arr[i]<arr[left]){

    
    swap(arr[i],arr[left]);
    i=left;
    }
   else if(right<size && arr[i]<arr[right]){
    swap(arr[i],arr[right]);
    i=right;
   }
    else
    return;
}
}

};
//0 based indexing
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<= n&& arr[largest]<arr[left])
    largest=left;
    if(right <= n && arr[largest]<arr[right])
    largest=right;
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[], int n){
    int size = n;
    while(size>1){
        swap(arr[size],arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main(){
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.Delete();
    h.print();
    int arr[6]={-1,70,9,55,45,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    cout<<"printing...";
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;
    heapSort(arr,n);
    cout<<"printing after heap sort"<<endl;
    for(int i=1;i<=n;i++){
        cout<<arr[i]<<" ";
    }cout<<endl;

}