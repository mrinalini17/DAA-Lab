//Aim of the program: Write a menu driven program to sort list of array elements using Merge Sort technique 
//and calculate the execution time only to sort the elements.  Count the number of comparisons.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int arr[], int left, int mid, int right, long long int *comparisons) {
    int i_08, j_08, k_08;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i_08 = 0; i_08 < n1; i_08++)
        L[i_08] = arr[left + i_08];
    for (j_08 = 0; j_08 < n2; j_08++)
        R[j_08] = arr[mid + 1 + j_08];

    i_08 = 0;
    j_08 = 0;
    k_08 = left;

    while (i_08 < n1 && j_08 < n2) {
        (*comparisons)++;
        if(L[i_08] <= R[j_08]){
            arr[k_08] = L[i_08];
            i_08++;
        }else{
            arr[k_08] = R[j_08];
            j_08++;
        }
        k_08++;
    }

    while (i_08 < n1) {
        arr[k_08] = L[i_08];
        i_08++;
        k_08++;
    }

    while (j_08 < n2) {
        arr[k_08] = R[j_08];
        j_08++;
        k_08++;
    }
}

void merge_sort(int arr[], int left, int right, long long int *comparisons){
    if (left < right){
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid, comparisons);
        merge_sort(arr, mid + 1, right, comparisons);

        merge(arr, left, mid, right, comparisons);
    }
}

void read_input_file(char *filename, int arr[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    *size = 0;
    while (fscanf(file, "%d", &arr[*size]) != EOF) {
        (*size)++;
    }

    fclose(file);
}

void write_output_file(char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

int main() {
    printf("MAIN MENU (MERGE SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");

    int option;
    printf("Enter option: ");
    scanf("%d", &option);

    char *input_filename, *output_filename;

    if (option == 1) {
        input_filename = "inAsce.dat";
        output_filename = "outMergeAsce.dat";
    } else if (option == 2) {
        input_filename = "inDesc.dat";
        output_filename = "outMergeDesc.dat";
    } else if (option == 3) {
        input_filename = "inRand.dat";
        output_filename = "outMergeRand.dat";
    } else if (option == 4) {
        printf("Exiting...\n");
        return 0;
    } else {
        printf("Invalid option!\n");
        return 1;
    }

    int arr[500];
    int size;
    read_input_file(input_filename, arr, &size);

    printf("Before Sorting: ");
    for (int i_08 = 0; i_08 < size; i_08++) {
        printf("%d ", arr[i_08]);
    }
    printf("\n");

    long long int comparisons = 0;

    clock_t start_time = clock();

    merge_sort(arr, 0, size - 1, &comparisons);

    clock_t end_time = clock();
    long long int execution_time = (end_time - start_time) * 1000000000 / CLOCKS_PER_SEC;

    printf("After Sorting: ");
    for (int i_08 = 0; i_08 < size; i_08++) {
        printf("%d ", arr[i_08]);
    }
    printf("\n");

    printf("Number of Comparisons: %lld\n", comparisons);
    printf("Execution Time: %lld nanoseconds\n", execution_time);

    write_output_file(output_filename, arr, size);

    return 0;
}