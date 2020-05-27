#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
using namespace std;
 
typedef struct Activity{
	int s;
	int f;
}Activity;
 
bool a_less_b(const Activity &a,const Activity &b)
{
	return a.f<b.f;
}
 
vector< vector<int> > Optimal_ActivitySelect(Activity *a,int n)
{
	vector< vector<int> > Result;    //存储可能的多个最佳调度方案
	vector<Activity> act;//存储活动
 
	for(int i=0;i<n;i++)
		act.push_back(a[i]);
	sort(act.begin(),act.end(),a_less_b);   //按活动结束时间f的升序排序
	
	for(int i=0;i<n;i++){ //第一层循环，为了找到可能的多个最佳调度方案
		vector<int> temp;
		int k=i;
		temp.push_back(k+1);//vector下标开始是0，任务下标开始是1
        //sort升序排序之后，第1个任务(act[0])必然是第1个包含在最大活动集合中。
        //然后循环从任务2(act[1])开始
		for(int m=k+1; m<n ; m++)//第二层循环，找到最佳调度方案
			if(act[m].s >= act[k].f){
				temp.push_back(m+1);
				k=m;
			}	
		Result.push_back(temp);//存放一次结果
		if(temp.size()!=Result[0].size())
			Result.erase(Result.end()-1);
	}
	
    return Result;
}
void Print_Optimal_Scheduling_scheme(vector< vector<int> > r)
{
	for(int i=0;i<r.size();i++){
		vector<int> temp;
		temp=r[i];
		cout<<"The solution "<<i+1<<" :";
		for(int j=0;j<temp.size();j++)
			cout<<temp[j]<<"   ";
		cout<<endl;
	}
}
int main()
{
	Activity a[]={{1,4},{3,5},{0,6},{5,7},{3,9},{5,9},{6,10},{8,11},{8,12},{2,14},{12,16}};
	int n=sizeof(a)/sizeof(Activity);
 
	vector< vector<int> > Result; //存储可能的多个最佳调度方案
	Result=Optimal_ActivitySelect(a,n);
	cout<<"The laregest activity set is:"<<endl;
	Print_Optimal_Scheduling_scheme(Result);
	return 0;
}