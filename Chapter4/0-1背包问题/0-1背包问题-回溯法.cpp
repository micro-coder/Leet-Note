#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>

using namespace std;

#define N 100

struct Goods{
int wight;//物品重量
int value;//物品价值
};

int n,bestValue,cv,cw,C;//物品数量，价值最大，当前价值，当前重量，背包容量
int X[N],cx[N];//最终存储状态，当前存储状态
struct Goods goods[N];

int BackTrack(int i){
    if(i > n-1){
        if(bestValue < cv){
            for(int k = 0; k < n; k++)
                X[k] = cx[k];//存储最优路径
            bestValue = cv;
        }
        return bestValue;
    }
    if(cw + goods[i].wight <= C){//进入左子树
        cw += goods[i].wight;
        cv += goods[i].value;
        cx[i] = 1;//装入背包
        BackTrack(i+1);
        cw -= goods[i].wight;
        cv -= goods[i].value;//回溯，进入右子树
    }
    cx[i] = 0;//不装入背包
    BackTrack(i+1);
    return bestValue;
}

bool m(struct Goods a, struct Goods b){
    return (a.value/a.wight) > (b.value/b.wight);
}

int KnapSack3(int n, struct Goods a[], int C,int x[]){
    memset(x,0,sizeof(x));
    sort(a,a+n,m);//将各物品按单位重量价值降序排列
    BackTrack(0);
    return bestValue;
}
int main()
{
    printf("物品种类n：");
    scanf("%d",&n);
    printf("背包容量C：");
    scanf("%d",&C);
    for(int i = 0; i < n; i++){
        printf("物品%d的重量w[%d]及其价值v[%d]：",i+1,i+1,i+1);
        scanf("%d%d",&goods[i].wight,&goods[i].value);
    }
    int sum3 = KnapSack3(n,goods,C,X);
    cout<<"回溯法求解0/1背包问题:\nX=[";
    for(int i = 0; i < n; i++)
        cout << X[i] <<" ";//输出所求X[n]矩阵
	cout<<"]   装入总价值"<<sum3<<endl;
	cout<<"排序后的物品价值数组是：\nvalue=[";
    for(int i = 0; i < n; i++)
        cout<<goods[i].value<<" "; 
	cout<<"]"<<endl;  
	cout<<"排序后的物品重量数组是：\nweight=[";	 
    for(int i = 0; i < n; i++)
        cout<<goods[i].wight<<" ";   
	cout<<"]"<<endl;
    return 0;
}