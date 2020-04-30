#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int CrossSum(int nums[],int left, int right, int mid)
{
     if (left == right) return nums[left];
     int leftSubSum=0;
     int leftMaxSum=nums[mid];
     for(int i=mid; i>=left; i--)
     {
         leftSubSum+=nums[i];
         leftMaxSum=leftMaxSum>=leftSubSum?leftMaxSum:leftSubSum;
     }
     int rightSubSum=0;
     int rightMaxSum=nums[mid+1];
     for(int i=mid+1; i<=right; i++)
     {
         rightSubSum+=nums[i];
         rightMaxSum=rightMaxSum>=rightSubSum?rightMaxSum:rightSubSum;
     }
     return leftMaxSum+rightMaxSum;
}

int fun(int nums[],int left, int right)
{
    if (left == right) return nums[left];

    int mid = (left + right) / 2;

    int leftSum = fun(nums, left, mid);
    int rightSum = fun(nums, mid + 1, right);
    int crossSum = CrossSum(nums, left, right, mid);

    int temp=leftSum>rightSum?leftSum:rightSum;
    return temp>crossSum?temp:crossSum;
}

int MaxSubArray(int nums[],int length)
{
    return fun(nums,0,length-1);
}

int main()
{
    int nums[9]={-2,1,-3,4,-1,2,1,-5,4};
    int maxSum=MaxSubArray(nums,9);
    cout<<"maxSum= "<<maxSum<<endl;

}