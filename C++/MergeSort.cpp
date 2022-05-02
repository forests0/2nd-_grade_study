#include<iostream>
using namespace std;
int sort[100];

int MergeSort(int list[], int left, int right) {
    if(left < right) {
        int mid = (left+right) / 2;
        MergeSort(list, left, mid);
        MergeSort(list, mid + 1, right);
        Merge(list, left, mid, right);
    }
}

void Merge(int list[], int left,int mid, int right) {
    int i,j,k,l;
    i=left;
    j=mid+1;
    k=left;
    while(i<=mid && j<=right)
    {
        if(list[i]<=list[j])
        {
            sort[k++]=list[i++];
        }
        else
        {
            sort[k++]=list[j++];
        }
    }
    if(i>mid)
    {
        for(l=j; l<=right; l++)
        {
            sort[k++]=list[l];
        }
    }
    else
    {
        for(l=i; l<=mid; l++)
        {
            sort[k++]=list[l];
        }
    }
    for(l=left; l<=right; l++)
    {
        list[l]=sort[l];
    }
    
}

int main() {
    int n;
    int lists[101];
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>lists[i];
    }

}