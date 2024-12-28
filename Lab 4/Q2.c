//Aim of the program: Write a menu driven program to sort a list of elements in ascending order using Quick Sort 
//technique. Each choice for the input data has its own disc file.  A separate output file can be used for sorted 
//elements. After sorting display the content of the output file along with number of comparisons. Based on the 
//partitioning position for each recursive call, conclude the input scenario is either best-case partitioning or 
//worst-case partitioning. 

#include <stdio.h>
#include <stdlib.h>

int partition(int arr[], int low, int high, int *comparisons) {
    int pivot = arr[high];
    int i_08 = low - 1;

    for (int j_08 = low; j_08 < high; j_08++) {
        (*comparisons)++;
        if (arr[j_08] < pivot) {
            i_08++;
            int temp = arr[i_08];
            arr[i_08] = arr[j_08];
            arr[j_08] = temp;
        }
    }

    int temp = arr[i_08 + 1];
    arr[i_08 + 1] = arr[high];
    arr[high] = temp;

    return i_08 + 1;
}

int quicksort(int arr[], int low, int high, int *comparisons) {
    if (low < high) {
        int pivot_idx = partition(arr, low, high, comparisons);
        quicksort(arr, low, pivot_idx - 1, comparisons);
        quicksort(arr, pivot_idx + 1, high, comparisons);
    }
    return *comparisons;
}

void read_input(const char *file_name, int arr[], int n) {
    FILE *file = fopen(file_name, "r");
    if (file == NULL) {
        printf("Error opening file %s\n", file_name);
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}

void write_output(const char *file_name, int arr[], int n) {
    FILE *file = fopen(file_name, "w");
    if (file == NULL) {
        printf("Error creating file %s\n", file_name);
        exit(1);
    }

    for (int i_08 = 0; i_08 < n; i_08++) {
        fprintf(file, "%d ", arr[i_08]);
    }

    fclose(file);
}

int main() {
    printf("MAIN MENU (QUICK SORT)\n");
    printf("1. Ascending Data\n");
    printf("2. Descending Data\n");
    printf("3. Random Data\n");
    printf("4. EXIT\n");

    int option;
    printf("Enter option: ");
    scanf("%d", &option);

    int input_size = 0;
    const char *input_file;
    const char *output_file;

    if (option == 1) {
        input_file = "inAsce.dat";
        output_file = "outQuickAsce.dat";
    } else if (option == 2) {
        input_file = "inDesc.dat";
        output_file = "outQuickDesc.dat";
    } else if (option == 3) {
        input_file = "inRand.dat";
        output_file = "outQuickRand.dat";
    } else if (option == 4) {
        printf("Exiting...\n");
        return 0;
    } else {
        printf("Invalid option.\n");
        return 1;
    }

    FILE *input = fopen(input_file, "r");
    if (input == NULL) {
        printf("Error opening input file %s\n", input_file);
        return 1;
    }

    int num;
    while (fscanf(input, "%d", &num) != EOF) {
        input_size++;
    }

    fseek(input, 0, SEEK_SET);
    int *input_data = (int *)malloc(input_size * sizeof(int));
    for (int i_08 = 0; i_08 < input_size; i_08++) {
        fscanf(input, "%d", &input_data[i_08]);
    }
    fclose(input);

    printf("Before Sorting: ");
    for (int i_08 = 0; i_08 < input_size; i_08++) {
        printf("%d ", input_data[i_08]);
    }
    printf("\n");

    int comparisons = 0;
    quicksort(input_data, 0, input_size - 1, &comparisons);

    printf("After Sorting: ");
    for (int i_08 = 0; i_08 < input_size; i_08++) {
        printf("%d ", input_data[i_08]);
    }
    printf("\nNumber of Comparisons: %d\n", comparisons);

    if (comparisons == input_size - 1) {
        printf("Scenario: Worst-case\n");
    } else if (comparisons <= input_size / 2) {
        printf("Scenario: Best-case\n");
    } else {
        printf("Scenario: Intermediate-case\n");
    }

    write_output(output_file, input_data, input_size);

    free(input_data);

    return 0;
}