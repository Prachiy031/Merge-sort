#include <stdio.h>

void MergeS(int [],int,int);
void Merge(int a[],int,int,int);

void main()
{
    int n,b,e;
    b=0;
    printf("Enter array size ");
    scanf("%d",&n);
    int a[n];
    e=n-1;
   
    printf("Enter array elements : ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
   
    MergeS(a,b,e);
    printf("Sorted array : ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
}

void MergeS(int a[],int b,int e)
{
    int mid;
    if(b<e)
    {
        mid=(b+e)/2;
        MergeS(a,b,mid);
        MergeS(a,mid+1,e);
        Merge(a,b,mid,e);
    }
}

void Merge(int a[],int b,int mid,int e)
{
    int i,j,k;
    int n1=mid-b+1;
    int n2=e-mid;
    int left[n1],right[n2];
    for(i=0;i<n1;i++)
    {
        left[i]=a[b+i];
    }
    for(j=0;j<n2;j++)
    {
        right[j]=a[mid+1+j];
    }
    i=0;
    j=0;
    k=b;
    while(i<n1 && j<n2)
    {
        if(left[i]>right[j])
        {
            a[k]=right[j];
            k++;
            j++;
        }
        else{
            a[k]=left[i];
            k++;
            i++;
        }
    }
    while(i<n1)
    {
        a[k]=left[i];
        k++;
        i++;
    }
    while(j<n2)
    {
        a[k]=right[j];
        k++;
        j++;
    }
}
