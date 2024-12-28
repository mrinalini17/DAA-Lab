/*Write a program to find the maximum profit nearest to but not
exceeding the given knapsack capacity using the Fractional Knapsack algorithm.
Notes# Declare a structure ITEM having data members item_id, item_profit, item_weight and
profit_weight_ratio. Apply heap sort technique to sort the items in non-increasing order,
according to their profit /weight.*/


#include <stdio.h>

struct Item
{
    int item_id;
    double item_profit;
    double item_weight;
    double profit_weight_ratio;
};

void swap(struct Item *a_08, struct Item *b_08)
{
    struct Item temp = *a_08;
    *a_08 = *b_08;
    *b_08 = temp;
}

void heapify(struct Item arr[], int n_08, int i_08)
{
    int largest = i_08;
    int left = (2 * i_08) + 1;
    int right = (2 * i_08) + 2;

    if (left < n_08 && arr[left].profit_weight_ratio < arr[largest].profit_weight_ratio)
    {
        largest = left;
    }

    if (right < n_08 && arr[right].profit_weight_ratio < arr[largest].profit_weight_ratio)
    {
        largest = right;
    }

    if (largest != i_08)
    {
        swap(&arr[i_08], &arr[largest]);
        heapify(arr, n_08, largest);
    }
}

void build_min_heap(struct Item arr[], int n_08)
{
    for (int i_08 = n_08 / 2 - 1; i_08 >= 0; i_08--)
    {
        heapify(arr, n_08, i_08);
    }

    for (int i_08 = n_08 - 1; i_08 >= 0; i_08--)
    {
        swap(&arr[0], &arr[i_08]);
        heapify(arr, i_08, 0);
    }
}

void knapsack(struct Item items[], int n_08, double capacity)
{
    double taken_amounts[n_08];
    int i_08;
    int weight=0;

    for (int i_08 = 0; i_08 < n_08; i_08++)
    {
        taken_amounts[i_08] = 0;
    }


    for(int i_08=0;i_08<n_08;i_08++)
    {
        if(weight+items[i_08].item_weight<=capacity)
        {
            taken_amounts[i_08]=1;
            weight+=items[i_08].item_weight;
        }
        else
        {
            taken_amounts[i_08] = (capacity - weight)/items[i_08].item_weight;
            weight=capacity;
            break;
        }
    }

    double total_profit=0;

    for(int i_08=0;i_08<n_08;i_08++)
    {
        total_profit+=items[i_08].item_profit * taken_amounts[i_08];
        // printf("\nMaximum profit: %.6lf", total_profit);
    }


    printf("\nI No. Profit Weight  p/w    Amount to be taken\n");
    for (i_08 = 0; i_08 < n_08; i_08++)
    {
        printf("%d     %.1lf   %.1lf    %.2lf   %.6lf\n", items[i_08].item_id + 1, items[i_08].item_profit, items[i_08].item_weight, items[i_08].profit_weight_ratio, taken_amounts[i_08]);
    }

    printf("\nMaximum profit: %.6lf", total_profit);
}

int main()
{
    int n_08;
    int i;

    printf("Enter the number of items : ");
    scanf("%d", &n_08);

    struct Item items[n_08];

    for (i = 0; i < n_08; i++)
    {
        printf("Enter the profit and weight of item no %d : ", i + 1);
        scanf("%lf %lf", &items[i].item_profit, &items[i].item_weight);
        items[i].item_id = i;
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_weight;
    }

    double capacity_08;

    printf("Enter the capacity of knapsack : ");
    scanf("%lf", &capacity_08);
    
    printf("\nI No. Profit Weight  p/w    \n");
    for (int i = 0; i < n_08; i++)
    {
        printf("%d     %.1lf   %.1lf    %.6lf \n", items[i].item_id + 1, items[i].item_profit, items[i].item_weight, items[i].profit_weight_ratio);
    }

    
    build_min_heap(items, n_08);

    printf("\nI No. Profit Weight  p/w    \n");
    for (int i = 0; i < n_08; i++)
    {
        printf("%d     %.1lf   %.1lf    %.6lf \n", items[i].item_id + 1, items[i].item_profit, items[i].item_weight, items[i].profit_weight_ratio);
    }

    knapsack(items, n_08, capacity_08);

    return 0;
}