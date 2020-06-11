#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

//物品数量
#define NUM  5
//背包容量
#define CAP  10
class KnapSack{
  public:
    int knapSack(int w[], int v[],const int size,const int C) {
        if (size == 0) {
            return 0;
        }

		dp.resize(size);
		for (int i =0 ; i < dp.size(); i++)
		{
			dp[i].resize(C+1);
		}
        //初始化第零行
        //仅考虑容量为C的背包放第0个物品的情况
        for (int i = 0; i < C+1; i++) {
            dp[0][i] = w[0] <= i ? v[0] : 0;
        }
		//填充其他行和列
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < C+1; j++) {
                dp[i][j] = dp[i - 1][j];//若背包装不下该物品，则最大价值不变
                if (w[i] <= j) {
					//不放入物品时达到的最大价值&放入该物品时达到的最大价值进行比较，取最大值
                    dp[i][j] = max(dp[i][j], v[i] + dp[i - 1][j - w[i]]);
                }
            }
        }
        return dp[size - 1][C];
    }

// private:
    vector<vector<int> > dp;
};

int main() 
{
//   int w[] = {2, 1, 3, 2};
//   int v[] = {12, 10, 20, 15};
  int w[NUM]={2,2,6,5,4};//重量
  int v[NUM]={6,3,5,4,6};//价值
  KnapSack  kp;
  cout<<"最大价值为： "<<kp.knapSack(w,v,NUM,CAP)<<endl;
  cout<<"动态规划表格如下：(从dp[0][0]起)"<<endl;
  for(int i=0;i<kp.dp.size();i++){
	for(int j=0;j<kp.dp[0].size();j++){
		cout<<setw(3)<<kp.dp[i][j];
	}
	cout<<endl;
  }
}