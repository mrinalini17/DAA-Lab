/*Write a function to ROTATE_right_00(p1, p2 ) right_00 an array for first p2
elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p &
q. Parameter p1 be the starting address of the array and p2 be the number of elements to be
rotated. */

#include <stdio.h>

void rotate(int arr[], int k_08, int n_08)
{
    int temp_08 = arr[k_08 - 1];
    for (int i_08 = k_08 - 1; i_08 > 0; i_08--)
    {
        arr[i_08] = arr[i_08 - 1];
    }
    arr[0] = temp_08;

    printf("\nRotated array: ");
    for (int i_08 = 0; i_08 < n_08; i_08++)
    {
        printf("%d ", arr[i_08]);
    }
}

int main()
{
    int n_08;
    int k_08;
    // size input
    printf("Enter size of array: ");
    scanf("%d", &n_08);
    int arr[n_08];

    // elements input
    printf("\nenter elements: ");
    for (int i_08 = 0; i_08 < n_08; i_08++)
    {
        scanf("%d", &arr[i_08]);
    }
    // index till which rotation will occur
    printf("Enter no. of elements to be rotated: ");
    scanf("%d", &k_08);

    printf("\nOriginal array: ");
    for (int i_08 = 0; i_08 < n_08; i_08++)
    {
        printf("%d ", arr[i_08]);
    }

    rotate(arr, k_08, n_08);

    return 0;
}