#include <stdio.h>

void knapsack(int n,float weight[],float profit[],float capacity){
    float x[20];
    float mb=0;//max-benefit
    int i,y=capacity;

    for(i=0;i<n;i++){
        x[i]=0.0;
    }
    for( i=0;i<n;i++){
        if(weight[i]>y){
            break;
        }else{
            x[i]=1.0;
            mb=mb+profit[i];
            y=y-weight[i];
        }
    }
    if(i<n) {
        x[i] = y / weight[i];
        mb = mb + (x[i] * profit[i]);
    }
    printf("The results are:");
    for(i=0;i<n;i++){
        printf("%f\n",x[i]);
    }
    printf("The maximum benefit is %f:",mb);


}

int main(void) {
    float weight[20],profit[20],ratio[20],capacity;
    int n;
    float temp;

    printf("Enter number of objects:\n");
    scanf("%d",&n);

    printf("Enter weight and profit of each object:\n");
    for(int i=0;i<n;i++){
        scanf("%f %f",&weight[i],&profit[i]);
    }

    printf("Enter the capacity of bag:\n");
    scanf("%f",&capacity);

    for(int i=0;i<n;i++){
        ratio[i]=profit[i]/weight[i];
    }

    for(int i=0;i<n;i++) {
        for (int j = i + 1; j < n; j++) {
            if(ratio[i]<ratio[j]){
                temp=ratio[j];
                ratio[j]=ratio[i];
                ratio[i]=temp;

                temp=weight[j];
                weight[j]=weight[i];
                weight[i]=temp;

                temp=profit[j];
                profit[j]=profit[i];
                profit[i]=temp;
            }

        }
    }

    knapsack(n,weight,profit,capacity);
    return 0;
}