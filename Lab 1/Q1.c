/*find the second largest and second smallest in an array*/

#include<stdio.h>
int main(){
    int n_08,i_08,j_08,temp;
    int arr[100];
    printf("Enter n value: ");
    scanf("%d",&n_08);
    for(i_08=0;i_08<n_08;i_08++){
        printf("Enter %d element: ",i_08+1);
        scanf("%d",&arr[i_08]);
    }
    for(i_08=0;i_08<n_08;i_08++){
        for(j_08=i_08+1;j_08<n_08;j_08++){
            if(arr[i_08]<arr[j_08])
            {
                temp = arr[i_08];
                arr[i_08] = arr[j_08];
                arr[j_08] = temp;
            }
        }
    }
    printf("Sorted array: ");
    for(i_08=0;i_08<n_08;i_08++){
        printf("%d ",arr[i_08]);
    }
    printf("\nThe second smallest element is %d\n",arr[n_08-2]);
    printf("The second largest element is %d",arr[1]);
    return 0;
}