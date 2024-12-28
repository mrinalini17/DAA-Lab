//Write a program to implement Binary Search to give the position of
//leftmost appearance of the element in the array being searched. Display the number of
//comparisons made while searching.

#include <stdio.h>

int binary_search(int a[], int n_8, int search_8, int *compar) {
    int l_8 = 0, r_8 = n_8 - 1, position_8 = -1;
    
    while (l_8 <= r_8) {
        int m_8 = l_8 + (r_8 - l_8) / 2;
        (*compar)++;
        
        if (a[m_8] == search_8){
            position_8 = m_8;
            r_8 = m_8 - 1;  

        } 
        else if (a[m_8] < search_8){
            l_8 = m_8 + 1;
        } 
        else{
            r_8 = m_8 - 1;
        }
    }
    return position_8;
}

int main() {

    int n_8,search_8;
    printf("\nEnter array size: ");
    scanf("%d",&n_8);
    int a[n_8],compar=0;

    printf("Enter %d array integers with spaces: ",n_8);
    
    for(int i_8=0;i_8<n_8;i_8++){
        scanf("%d",&a[i_8]);
    }

    printf("Enter number to be searched: ");
    scanf("%d",&search_8);

    int position_8 = binary_search(a, n_8, search_8, &compar);

    if (position_8 != -1) {
        printf("\n%d found at index position %d\n", search_8, position_8);
    }
    
    printf("Number of comparisons: %d\n", compar);
    return 0;
}