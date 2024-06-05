#include<stdio.h>

struct min_max{
    int min;
    int max;
};


struct min_max getMinMax(int arr[], int l, int r) {
    struct min_max minmax,minmaxLeft,minmaxRight;
    int m;



    if(l == r){
        minmax.min=arr[l];
        minmax.max=arr[l];
        return minmax;
    }

    while(r==l+1){
        if(arr[r]>arr[l]){
            minmax.min=arr[l];
            minmax.max=arr[r];
        } else {
            minmax.min=arr[r];
            minmax.max=arr[l];
        }
        return minmax;
    }


    m=(l+r)/2;
    minmaxLeft=getMinMax(arr,l,m);
    minmaxRight=getMinMax(arr,m+1,r);

    if(minmaxLeft.min<minmaxRight.min){
        minmax.min=minmaxLeft.min;
    } else {
        minmax.min=minmaxRight.min;
    }

    if(minmaxLeft.max>minmaxRight.max){
        minmax.max=minmaxLeft.max;
    } else {
        minmax.max=minmaxRight.max;
    }

    return minmax;


}

int main(void) {
    int arr[]={11,9,5,4,50,99};
    int n=sizeof(arr)/sizeof(arr[0]);
    int left=0;
    int right=n-1;

    struct min_max minmax=getMinMax(arr,left,right);

    printf("minimum : %d\n", minmax.min);
    printf("maximum : %d", minmax.max);

    return 0;
}