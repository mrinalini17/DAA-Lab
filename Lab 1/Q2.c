/*find the prefix sum of an array arr[] size n*/

#include<stdio.h>

int main(){
    int i_08,n_08;
    int arr[100],prefixSum[100];
    printf("Enter value of n: ");
    scanf("%d",&n_08);
    for(i_08=0;i_08<n_08;i_08++){
        printf("Enter %d value: ",i_08+1);
        scanf("%d",&arr[i_08]);
    }
    printf("\nInput: ");
    for(i_08=0;i_08<n_08;i_08++){
        printf("%d ",arr[i_08]);
    }
    prefixSum[0] = arr[0];
    printf("\nOutput: ");
    for(i_08=0;i_08<n_08;i_08++){
        prefixSum[i_08+1]=prefixSum[i_08]+arr[i_08+1];
    }
    for(i_08=0;i_08<n_08;i_08++){
        printf("%d ",prefixSum[i_08]);
    }
    return 0;
}