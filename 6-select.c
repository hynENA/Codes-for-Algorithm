#include<stdio.h>?
void setData(int a[],int n)//初始化数组
{
	int i; 
	printf("请输入%d个数组元素值：\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void sort(int a[],int n)//冒泡排序
{
	int i,j;
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++)
		{
			if(a[i]>a[j])
			{
			int k=a[i];
			a[i]=a[j];
			a[j]=k;
			}
		}
}
int localData(int a[],int value)//返回value在数组中的位置
{
	int i=0;
	while(a[i]!=value)
		i++;
	return i;
}
void copyData(int a[],int d[],int n)//将数组d复制到数组a
{
	int i;
	for(i=0;i<n;i++)
		a[i]=d[i];
}

int divisionRecursion(int a[],int n,int k)//分治递归，求第k小元素,n为数组a的元素个数
{
	if(n<=6)//将阀值设为6
	{
		sort(a,n);
		return a[k-1];
	}else{
		int b[10],c[10],d[50];
		int i=0,j=0,t=0;
		while(i<n)//将原数组分成每组5（或<5）个元素的数组，
		{//并对每组排序后分别取中项存于数组c中，再对数组c排序
			b[j++]=a[i++];
			if(i%5==0||i==n)
			{
				sort(b,j);
				c[t++]=b[j/2];
				j=0;
			}
		}
		sort(c,t);
		if(k==localData(a,c[t/2]))
			return c[t/2];
		else if(k<localData(a,c[t/2]))
		{
			int i=0,j=0;
			while(i<n)
			{
				if(a[i]<c[t/2])
					d[j++]=a[i];
				i++;
			}
			n=j;
			copyData(a,d,j);
			return divisionRecursion(a,n,k);
		}
		else//若k大于c的中项在a中的位置，则抽出大于此中项的值存于数组d中，并复制到a，再进行递归
		{
			int i=0,j=0;
			while(i<n)
			{
				if(a[i]>c[t/2])
					d[j++]=a[i];
				i++;
			}
			k=k-n+j;
			n=j;
			copyData(a,d,j);
			return divisionRecursion(a,n,k);
		}
	}
}	
void main()
{
	int a[50],n,k,value;
	printf("请输入数组元素个数n的值：");
	scanf("%d",&n);
	setData(a,n);//初始化数组
	printf("请输入k：");
	scanf("%d",&k);
	value=divisionRecursion(a,n,k);
	printf("数组的第%d小元素是：%d\n",k,value);
}
