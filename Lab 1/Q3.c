/*count the number of duplicate numbers in an array and also display the highest repeating number*/

#include<stdio.h>

int countDuplicate(int arr[],int n_08)
{
    int c_08 = 0;
    for(int i_08=0;i_08<n_08;i_08++){
        for(int j_08=i_08+1;j_08<n_08;j_08++){
            if(arr[i_08]==arr[j_08]){
                c_08++;
                break;
            }
        }
    }
    return c_08;
}

int maxElement(int arr[],int n_08){
    int c = 0,max=0;
    for(int i_08=0;i_08<n_08;i_08++){
        for(int j_08=i_08+1;j_08<n_08;j_08++){
            if(arr[i_08]==arr[j_08]){
                c++;
                if(max<c){
                    max = arr[j_08];
                }
            }
        }
    }
    return max;
}

int main(){
    int n,i,c=0;
    int arr[100];
    printf("Enter n:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Enter %d value: ",i+1);
        scanf("%d",&arr[i]);
    }
    int res = countDuplicate(arr,n);
    int res2 = maxElement(arr,n);
    printf("Total number of duplicate characters: %d\n",res);
    printf("Most repeating character: %d",res2);
    return 0;
}