#include<stdio.h>

int findGCD(int a_08, int b)
{
    if (b == 0)
        return a_08;
    else
        return findGCD(b, a_08 % b);
}

int main(int argn, char const *argv[])
{
    FILE *fin_08, *fout_08; 
    int num1_08, num2_08;   
    fin_08 = fopen(argv[1], "r");
    fout_08 = fopen(argv[2], "w");
    for (int i = 0; i < 20; i++)
    {
        fscanf(fin_08, "%d", &num1_08);
        fscanf(fin_08, "%d", &num2_08);
        fprintf(fout_08, "The GCD of %d & %d is %d\n", num1_08, num2_08, findGCD(num1_08, num2_08));
    }
    return 0;
}
