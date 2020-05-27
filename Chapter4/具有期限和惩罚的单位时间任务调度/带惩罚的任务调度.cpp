//用贪心算法的拟阵解决单处理器上带截止时间和惩罚的单位时间任务调度问题
#include <iostream>
#include <vector>
#include <map> 
#include <algorithm>
using namespace std;
const int Max=7;

typedef struct TASK{
public:	
	int id;
	int deadline;
	int w;
}TASK;

bool a_less_b(const TASK &a,const TASK &b)
{
	return a.deadline<b.deadline;
}
bool scheduleable(vector<TASK> &ref_task) //A是活动截止时间的集合，t是一个任务的截止时间，加入t后如果A中的所有元素都不会任务延迟，则认为A是独立的，返回真，可加 
{
	int w_sum=0;//最优调度下的总惩罚时间 
	vector<TASK> Sche_List;//独立任务集合
	vector<TASK> LateTask_list;
	if(Sche_List.empty()) Sche_List.push_back(ref_task[0]);
	int cnt=0;//迟任务数
	for(int i=1;i<Max;i++){//循环扫描任务列表，确定独立任务集合

		Sche_List.push_back(ref_task[i]);
		sort(Sche_List.begin(),Sche_List.end(),a_less_b);//按照截止时间升序排序
		for(int k=0;k!=Sche_List.size();k++){
			int temp=i-cnt;
			if(k+1>Sche_List[k].deadline){//任务完成时间是否在截止时间之前
				int min_w=Sche_List[i-cnt].w;
				for(int j=0;j!=Sche_List.size();j++){//找出最小惩罚
					if (Sche_List[j].w<min_w){
						min_w=Sche_List[j].w;
						temp=j;
					}
				}
				w_sum+=min_w;//总惩罚
				cnt++;//迟任务数	
				LateTask_list.push_back(*(Sche_List.begin()+temp));//迟任务集合			
				Sche_List.erase(Sche_List.begin()+temp);//删除最小惩罚的任务
				break;//因为每轮循环只有一个任务可能会被惩罚，所以找到之后，就可以退出本次循环，继续进行下次循环了
			}
		}
	}
	cout<<"独立任务集合： "<<endl;
	for(vector<TASK>::iterator it=Sche_List.begin();it!=Sche_List.end();it++)
		cout<<it->id<<" ";//在A集合中元素的调度方案，被拒绝的顺序任意 
	cout<<endl;
	cout<<"迟任务集合： "<<endl;
	for(vector<TASK>::iterator it=LateTask_list.begin();it!=LateTask_list.end();it++)
		cout<<it->id<<' ';
	cout<<endl;
	cout<<"总惩罚： "<<w_sum<<endl;
	return true;
} 
int main()
{
	// TASK  arr[7]={
	// 	{1,4,70},
	// 	{2,2,60},
	// 	{3,4,50},
	// 	{4,3,40},
	// 	{5,1,30},
	// 	{6,4,20},
	// 	{7,6,10},
	// };
	TASK  arr[7]={
		{1,4,0},
		{2,2,10},
		{3,4,20},
		{4,3,30},
		{5,1,40},
		{6,4,50},
		{7,6,60},
	};
	vector<TASK> task(arr,arr+Max);
	scheduleable(task);
}