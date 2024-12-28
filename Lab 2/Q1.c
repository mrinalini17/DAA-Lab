#include<stdio.h>
#include<stdlib.h>

int binary_conversion(int num)
{
    if (num == 0)
    {
        return 0;
    }
    else
    {
        return (num % 2) + 10 * binary_conversion(num / 2);
    }
}

int main(int argn, char const *argv[])
{
    printf("%d %s %s ", atoi(argv[1]), argv[2], argv[3]);
    FILE *f_08, *fout_08;  
    int num_08;           
    f_08 = fopen(argv[2], "r"); 
    fout_08 = fopen(argv[3], "a");

    for (int i = 0; i < atoi(argv[1]); i++)
    {
        fscanf(f_08, "%d", &num_08);
        fprintf(fout_08, "The Binary of %d is %d\n", num_08, binary_conversion(num_08));
    }

    return 0;
}