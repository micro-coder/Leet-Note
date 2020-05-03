#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int Partition(int arr[], int low, int high){
    int pivot_key=arr[low];//临时存储基准值
    while(low<high){
        while (low<high && arr[high]>=pivot_key)  --high;
        arr[low]=arr[high];
        while (low<high && arr[low]<=pivot_key)  ++low;
        arr[high]=arr[low];
    }
    arr[low]=pivot_key;//把基准值放到最后准确的位置
    return low;
}
void QuickSort(int arr[], int low, int high){
    int pivot;
    if(low<high){
        pivot=Partition(arr,low,high);
        QuickSort(arr,low,pivot-1);
        QuickSort(arr, pivot+1,high);
    }
}

int main(){
    int arr[9]={-2,1,-3,4,-1,2,1,-5,4};
    QuickSort(arr,0,8);
    cout<<"快速排序结果= "<<endl;
    for (char i = 0; i < 9; i++){
        cout<<arr[i]<<'\t';
    }
    cout<<endl;
    return 0;
}