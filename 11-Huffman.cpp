#include<iostream>
#include<stdio.h>
#include<stdlib.h>  
#include<string>
using namespace std;
int num[26];    //存放个字母出现的次数
char str[50];
 
typedef struct{         //哈夫曼树的结构体
	char ch;
	int weight;              //权值
    int parent,lchild,rchild;
}htnode,*huffmanTree;
typedef char **hfmcode;
 
void Select(huffmanTree &HT,int n,int *p1,int *p2) //Select函数，选出HT树到n为止，权值最小且parent为-1的2个节点
{
	int i,j,x,y;
    for(j=0;j<n;++j){
		if(HT[j].parent==-1)
		{
		x=j;break;
		}
 
	}
    for(i=j+1;i<n;++i){
		if(HT[i].weight<HT[x].weight&&HT[i].parent==-1)
		{
		x=i;                  //选出最小的节点
		}
	}
 
    for(j=0;j<n;++j) {
		if(HT[j].parent==-1&&x!=j)
		{
			y=j;break;
		}
	}
 
    for(i=j+1;i<n;++i)
	{
		if(HT[i].weight<HT[y].weight&&HT[i].parent==-1&&x!=i)
		{
			y=i;                  //选出次小的节点
		}
	}
    if(x>y){
		*p1=y;
    	*p2=x;
	}
    else{
		*p1=x;
		*p2=y;
	}
}
 
void hfmcoding(huffmanTree &HT,hfmcode &HC,int w[],int n) //构建哈夫曼树HT，并求出n个字符的哈夫曼编码HC
{
	int i,start,c,f,m;
	int p1,p2;
	char *cd;
	if(n<=1){
       return;
	}
    m=2*n-1;
    HT=(huffmanTree)malloc((m+1)*sizeof(htnode));
 
    for(i=0;i<n;++i)            //初始化n个叶子结点
	{
		HT[i].ch=str[i];
		HT[i].weight=w[i];
		HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
	}
 
    for(;i<m;++i)        //初始化其余的结点
	{
		HT[i].weight=-1;
        HT[i].parent=-1;
		HT[i].lchild=-1;
		HT[i].rchild=-1;
	}
 
    for(i=n;i<m;++i)        //建立哈夫曼树
	{
		Select(HT,i,&p1,&p2);
		HT[p1].parent=i;HT[p2].parent=i;
		HT[i].lchild=p1;HT[i].rchild=p2;
		HT[i].weight=HT[p1].weight+HT[p2].weight;
	}
	HC=(hfmcode)malloc((n+1)*sizeof(char *));
	cd=(char *)malloc(n*sizeof(char));
	cd[n-1]='\0';
	for(i=0;i<n;++i)              //给n个字符编码
	{
		start=n-1;
		for(c=i,f=HT[i].parent;f!=-1;c=f,f=HT[f].parent)
		{
			if(HT[f].lchild==c)
			{
				cd[--start]='0';
			}
			else{
				cd[--start]='1';
			}
		}
		HC[i]=(char*)malloc((n-start)*sizeof(char));
		strcpy(HC[i],&cd[start]);
	}
	free(cd);
}
 
void main()
{
	int i,j,t=-1;
	huffmanTree HT;
    hfmcode HC;
    int w[50];
    string data;//也可以用数组，但是用数组要给定数组的大小，数组长度的表示为strlen(data)
	string str1;
    int index=-1,n=0;
	char c;
    //cout<<"请输入字符串: ";
    //cin>>data;//输入字符串
	data = "Chapter Graphs surveys the most important graph processing problems  including depth-first search breadth first search minimum spanning trees and shortest paths";
    for( i=0;i<data.length();i++) {
		if(data[i]>='a'&&data[i]<='z')
           index=data[i]-'a';
        else if(data[i]>='A'&&data[i]<='Z')
            index=data[i]-'A';
        if(index!=-1)
			num[index]++;
            index=-1;
	}
    cout<<"各个字母出现的次数分别为:"<<endl;
    for( j=0;j<26;j++)//输出
	{
		if(num[j]!=0)
		{
			n++;t++;
			c='a'+j;
			w[t]=num[j];//把个字母出现的次数复制到数组w中，作为每个叶子节点的权值
        	str[t]=c;
            cout<<c<<" : "<<num[j]<<endl;
		}
	}
    hfmcoding(HT,HC,w,n);
    cout<<"各字母对应的哈夫曼编码分别为："<<endl;
    for(i=0;i<n;++i)
	{
		cout<<HT[i].ch<<":"<<HC[i]<<endl;
	}
	int k=2*n-2;
	cout<<"请输入二进制码: ";
	cin>>str1;
	cout<<"对应字母为: ";
	for(i=0;i<str1.length();i++)
	{
		
		if(str1[i]=='0')
		{
			k=HT[k].lchild;
			if(HT[k].lchild==-1&&HT[k].rchild==-1)
			{
				cout<<HT[k].ch;
				k=2*n-2;
			}
		}
		else if(str1[i]=='1')
		{
			k=HT[k].rchild;
			if(HT[k].lchild==-1&&HT[k].rchild==-1)
			{
				cout<<HT[k].ch;
				k=2*n-2;
			}
		}
 
	}
	cout<<endl;
  
}
