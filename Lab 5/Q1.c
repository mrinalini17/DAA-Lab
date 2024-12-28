#include <stdio.h>
#include <stdlib.h>

#define MAX_STUDENTS 100

struct person{
    int id;
    char name[50];
    int age;
    int height;
    int weight;
};

void swap (struct person *x, struct person *y) {
    struct person temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify (struct person arr[], int n_08, int i_08) {

    int smallest = i_08;
    int left = 2 * i_08 + 1;
    int right = 2 * i_08 + 2;

    if (left < n_08 && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n_08 && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i_08) {
        swap(&arr[i_08], &arr[smallest]);
        minHeapify(arr, n_08, smallest);
    }
}

void maxHeapify (struct person arr[], int n_08, int i_08) {
    
    int largest = i_08;
    int left = 2 * i_08 + 1;
    int right = 2 * i_08 + 2;

    if (left < n_08 && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n_08 && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i_08) {
        swap(&arr[i_08], &arr[largest]);
        maxHeapify(arr, n_08, largest);
    }
}

int main() {

    struct person students[MAX_STUDENTS];
    int i_08, n_08 = 0;
    int choice;

    printf("Enter the number of persons : ");
    scanf("%d", &n_08);

    if (n_08 < 0 || n_08 > MAX_STUDENTS) {
        printf("Invalid number of persons!\n");
        return 1;
    }

    printf("Enter details for %d persons :\n", n_08);
    for (int i_08 = 0; i_08 < n_08; i_08++) {
        printf("Person %d :\n", i_08 + 1);
        printf("ID  : ");
        scanf("%d", &students[i_08].id);
        printf("Name : ");
        scanf("%s", students[i_08].name);
        printf("Age : ");
        scanf("%d", &students[i_08].age);
        printf("Height : ");
        scanf("%d", &students[i_08].height);
        printf("Weight : ");
        scanf("%d", &students[i_08].weight);
    }

    do {
        printf("\nMAIN MENU (HEAP SORT)\n");
        printf("\n1. Create a Min-heap based on age");
        printf("\n2. Create a Max-heap based on weight");
        printf("\n3. Display weight of the youngest person");
        printf("\n4. Insert a new person into the Min-heap");
        printf("\n5. Delete the oldest person");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (i_08 = n_08/2 - 1; i_08 >= 0; i_08--){
                    minHeapify(students, n_08, i_08);
                }
                printf("Min-Heap based on age created.\n");
                break;
            case 2:
                for (i_08 = n_08/2 - 1; i_08 >= 0; i_08--){
                    maxHeapify(students, n_08, i_08);
                }
                printf("Max-Heap based on weight created.\n");
                break;
            case 3:
                if (n_08 > 0) {
                    printf("Weight of the youngest person: %d\n", students[0].weight);
                } else {
                    printf("Heap is empty!\n");
                }
                break;
            case 4:
                if (n_08 < MAX_STUDENTS){
                    printf("Enter id, name, age, height, and weight : ");
                    scanf("%d %s %d %d %d", &students[n_08].id, students[n_08].name, &students[n_08].age, &students[n_08].height, &students[n_08].weight);
                    n_08++;
                    for (i_08 = n_08/2 - 1; i_08 >= 0; i_08--){
                        minHeapify(students, n_08, i_08);
                    }
                }
                else{
                    printf("Heap is full!\n");
                }
                break;
            case 5:
                if (n_08 > 0){
                    students[0] = students[n_08 - 1];
                    n_08--;
                    minHeapify(students, n_08, 0);
                }
                else{
                    printf("Heap is empty!\n");
                }
                break;
            case 6:
                printf("Exiting the program\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option\n");
        }
    }
    while (1);

    return 0;
}