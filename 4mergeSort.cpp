#include <iostream>
using namespace std;

void mergearray(int a[], int first, int mid, int last, int temp[])
{
   int i = first, j = mid + 1;
   int m = mid,   n = last;
   int k = 0;

   while (i <= m && j <= n)
   {
       if (a[i] <= a[j])
           temp[k++] = a[i++];
       else
           temp[k++] = a[j++];
   }

   while (i <= m)
       temp[k++] = a[i++];

   while (j <= n)
       temp[k++] = a[j++];

   for (i = 0; i < k; i++)
       a[first + i] = temp[i];//对first-last排序
}

void mergesort(int a[], int first, int last, int temp[])
{
   if (first < last)
   {
     
       int mid = (first + last) / 2;
       
       mergesort(a, first, mid, temp);    //使左边有序
       
       mergesort(a, mid + 1, last, temp); //使右边有序
       
       mergearray(a, first, mid, last, temp); //再将二个有序数列合并
   }
}




int main()
{
    int a[]={31,59,16,95,34,67,38,97};
    int length=sizeof(a)/sizeof(a[0]);
    int temp[length];
    mergesort(a,0,length-1,temp);
    for(int i=0;i<length;i++)
        cout<<a[i]<<endl;
    return 0;
}

