#include <iostream>
using namespace std;
//二分查找  返回位置标号  
int binarySearch(int list[],int left,int right,int number){
    if(list==NULL)
        return -1;
    int index=0;
    int mid=(right+left)/2;
    if(left>right){
        return -1;
    }
    if(number==list[mid]){
        index=mid;
        return index;
    }else if(number>list[mid]){
        binarySearch(list,mid+1,right,number);
    }else{
        binarySearch(list,left,mid-1,number);
    }
}

//顺序查找 
int seqSearch(int list[],int number){
    if(list==NULL)
        return -1;
    int index=0;
	while(list[index]){
		if(list[index] == number){
			return index;
		}else{
			index++;
		}
	}
    return -1;
}

int main(){
    int a[]={1,3,5,7,9,11,14,16,17,20,78,135,615};
    int left = 0;
    int right = sizeof(a)/sizeof(a[0])-1;
    int index1 =binarySearch(a,left,right,88);
    cout<<"j = "<<(index1+1)<<endl;
    int index2 = seqSearch(a,78);
    cout<<"j = "<<(index2+1)<<endl;
    return 0;
}
