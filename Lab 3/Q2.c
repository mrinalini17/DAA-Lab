#include<stdio.h>

int menu()
{
    printf("\n\nMAIN MENU (INSERTION SORT)\n1. Ascending Data\n2. Descending Data\n3. Random Data\n4. ERROR (EXIT)");
    printf("\nEnter Choice: ");
    int choice_08;
    scanf("%d",&choice_08);
    return choice_08;
}
void bawCase(int res_08,int size_08)
{
    if(res_08==0)
        printf("\nBest Case!");
    else
    {
        printf("\nWorst Case!");
    }
}

int insertionSort(int arr[], int n_08)
{
    int comp_08=0;
    int i_08, key, j_08;
    for (i_08 = 1; i_08 < n_08; i_08++)
    {
        key = arr[i_08];
        j_08 = i_08 - 1;
        while (j_08 >= 0 && arr[j_08] > key)
        {
            comp_08++;
            arr[j_08 + 1] = arr[j_08];
            j_08 = j_08 - 1;
        }
        arr[j_08 + 1] = key;
    }
    return comp_08;
}


void ascSort()
{
    int size=7;
    FILE *fin,*fout;
    fin=fopen("inAsce.dat","r");
    int arr[size];
    printf("\nBefore Sorting: ");
    for(int i=0;i<size;i++){
        fscanf(fin,"%d",&arr[i]);
        printf("%d ",arr[i]);
    }
    int res=insertionSort(arr,size);
    fout=fopen("outInsAsce.dat","w");
    printf("\nAfter Sorting: ");
    for(int i_08=0;i_08<size;i_08++){
        fprintf(fout,"%d ",arr[i_08]);
        printf("%d ",arr[i_08]);
    }
    printf("\nNumber of Comparisions: %d",res);
    bawCase(res,size);
    fclose(fout);
    fclose(fin);

}

void ranSort()
{
    int size=7;
    FILE *fin,*fout;
    fin=fopen("inRand.dat","r");
    int arr[size];
    printf("\nBefore Sorting: ");
    for(int i_08=0;i_08<size;i_08++){
        fscanf(fin,"%d",&arr[i_08]);
        printf("%d ",arr[i_08]);
    }
    int res=insertionSort(arr,size);
    fout=fopen("outInsRand.dat","w");
    printf("\nAfter Sorting: ");
    for(int i_08=0;i_08<size;i_08++){
        fprintf(fout,"%d ",arr[i_08]);
        printf("%d ",arr[i_08]);
    }
    printf("\nNumber of Comparisions: %d",res);
    bawCase(res,size);
    fclose(fout);
    fclose(fin);
}

void desSort()
{
    int size=7;
    FILE *fin,*fout;
    fin=fopen("inDesc.dat","r");
    int arr[size];
    printf("\nBefore Sorting: ");
    for(int i_08=0;i_08<size;i_08++){
        fscanf(fin,"%d",&arr[i_08]);
        printf("%d ",arr[i_08]);
    }
    int res = insertionSort(arr,size);
    fout=fopen("outInsDesc.dat","w");
    printf("\nAfter Sorting: ");
    for(int i_08=0;i_08<size;i_08++){
        fprintf(fout,"%d ",arr[i_08]);
        printf("%d ",arr[i_08]);
    }
    printf("\nNumber of Comparisions: %d",res);
    bawCase(res,size);
    fclose(fout);
    fclose(fin);
}

int main()
{
    while(1)
    {
        switch (menu())
        {
        case 1:ascSort();
            break;
        case 2:desSort();
            break;
        case 3:ranSort();
            break;
        default:return 0;
        }
    }
    return 0;
}