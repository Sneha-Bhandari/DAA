#include <stdio.h>


void merge( int a[],int l,int mid,int r){
    int n1=mid-l+1;
    int n2= r-mid;

    int leftArray[n1],rightArray[n2];


    for(int i=0;i<n1;i++)
    {
        leftArray[i]=a[l+i];
    }

    for(int j=0;j<n2;j++)
    {
        rightArray[j]=a[mid+j+1];
    }

    int i=0;
    int j=0;
    int k=l;

    while(i<n1 && j<n2)
    {
        if(leftArray[i]>= rightArray[j])
        {
            a[k]=leftArray[i];
            i++;
        }else {
            a[k] = rightArray[j];
            j++;

        }
        k++;
    }
    while(i<n1){
        a[k]=leftArray[i];
        i++;
        k++;
    }

    while(j<n2){
        a[k]=rightArray[j];
        j++;
        k++;
    }

}

void mergeSort(int a[],int l,int r){
    if(l<r) {
        int mid = l + (r - l) / 2;

        mergeSort(a, l, mid);
        mergeSort(a, mid + 1, r);

        merge(a, l, mid, r);
    }
}

void printArray(int a[],int size) {

    for (int m = 0; m <size; m++) {
        printf("%d\t", a[m]);
    }

}

int main(void) {
    int arr[]={4,7,2,5,1,9,8,6, 3};
    int size=sizeof(arr)/sizeof(arr[0]);
    int l=0;
    int r=size-1;

    printf("\nUnsorted array:\n");
    printArray(arr,size);

    mergeSort(arr,l,r);

    printf("\nSorted array in Descending order:\n");
    printArray(arr,size);
    return 0;
}