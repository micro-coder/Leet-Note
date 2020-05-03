#include <iostream>
#include <new>
using namespace std;

void CountSort(int *arr,int len,int max, int min){
    int *count=new int[max-min+1];//计数数组
    int *Result=new int[len];//存放排序后的结果
    int index;
    for (int i =0; i <=max-min; i++){//初始化
        count[i]=0;
    }
    for(int i=0; i<len;i++){//计算arr[i]元素出现的个数
        count[arr[i]-min]++;
    }
    for(int i=1; i<=max-min; i++){
        count[i]+=count[i-1];
    }

    for (int i = len-1; i >= 0; i--){
        index=count[arr[i]-min]-1;
        Result[index]=arr[i];
        count[arr[i]-min]--;
    }
    cout<<"计数排序后的结果= "<<endl;
    for(int i=0;i<len;i++){
        cout<<Result[i]<<'\t';
    }
    
    cout<<endl;
    delete [] count;
    delete [] Result;
}

int main(){
    int arr[10]={95,94,91,98,99,90,99,93,91,92};
    CountSort(arr,10,99,90);
}