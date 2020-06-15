#include<iostream>
#include<algorithm>
#include<stdio.h> 
#include<string.h>
#include<cmath>

using namespace std;
const int CIRCLENUM = 10;
double x[200];//存放每个圆的x轴位置
double r[200];//存放每个圆的半径
double circleSeq[200];//存放最短圆序列的半径
int minLen = 999999;//存放最短圆排序长度

double calCircleCenter(int n){//计算圆心坐标 
	double maxx = 0;
	for(int i = 1;i < n;i++){
		int num = x[i] + 2.0 * sqrt(r[i] * r[n]);
		if(num > maxx)
			maxx = num;
	} 
	return maxx; 
}

void calCircleSortLength(){//计算圆排列的总长度
	double low = 99999,high = 0;
	for(int i = 1;i <= CIRCLENUM;i++){
		if(x[i] - r[i] < low){
			low = x[i] - r[i];
		}
		if(x[i] + r[i] > high){
			high = x[i] + r[i];
		}
	} 
	if(high-low < minLen){
		minLen = high - low;
		for(int i = 1;i <= CIRCLENUM;i++){
			circleSeq[i] = r[i];
		}
	}
}

void findCircleSort(int n){//查找圆排序
	if(n==CIRCLENUM + 1){
		calCircleSortLength();
	} 
	for(int i = n;i <= CIRCLENUM;i++){
		swap(r[n],r[i]);
		double center = calCircleCenter(n);//获取圆当前的横坐标
		x[n] = center;
		findCircleSort(n + 1);//向下继续搜索
		swap(r[n],r[i]);//回溯 
	}
}

int main(int argc,const char*argv[]){
	r[1] = 1,r[2] = 1,r[3] = 2,r[4]=9,r[5]=14,r[6]=5,r[7]=4,r[8]=6,r[9]=10,r[10]=11;//初始化半径
	findCircleSort(1);
	printf("最小排列长度的圆排序：\n");
	for(int i = 1;i <= CIRCLENUM;i++){//输出最短圆序列
		printf("%f ",circleSeq[i]); 
	} 
	printf("\n");
	return 0 ;
}
