#include<stdio.h>?
void setData(int a[],int n)//��ʼ������
{
	int i; 
	printf("������%d������Ԫ��ֵ��\n",n);
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
}
void sort(int a[],int n)//ð������
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
int localData(int a[],int value)//����value�������е�λ��
{
	int i=0;
	while(a[i]!=value)
		i++;
	return i;
}
void copyData(int a[],int d[],int n)//������d���Ƶ�����a
{
	int i;
	for(i=0;i<n;i++)
		a[i]=d[i];
}

int divisionRecursion(int a[],int n,int k)//���εݹ飬���kСԪ��,nΪ����a��Ԫ�ظ���
{
	if(n<=6)//����ֵ��Ϊ6
	{
		sort(a,n);
		return a[k-1];
	}else{
		int b[10],c[10],d[50];
		int i=0,j=0,t=0;
		while(i<n)//��ԭ����ֳ�ÿ��5����<5����Ԫ�ص����飬
		{//����ÿ�������ֱ�ȡ�����������c�У��ٶ�����c����
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
		else//��k����c��������a�е�λ�ã��������ڴ������ֵ��������d�У������Ƶ�a���ٽ��еݹ�
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
	printf("����������Ԫ�ظ���n��ֵ��");
	scanf("%d",&n);
	setData(a,n);//��ʼ������
	printf("������k��");
	scanf("%d",&k);
	value=divisionRecursion(a,n,k);
	printf("����ĵ�%dСԪ���ǣ�%d\n",k,value);
}
