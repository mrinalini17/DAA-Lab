//Write a program to find out the Longest Common Subsequence of two given strings. Calculate length of the LCS.
#include <stdio.h>
#include <string.h>

int max(int a_08, int b_08) {
    return (a_08 > b_08) ? a_08 : b_08;
}

void findLCS(char* str1, char* str2) {
    int m = strlen(str1);
    int n = strlen(str2);

    
    int LCS[m + 1][n + 1];

    for (int i_08 = 0; i_08 <= m; i_08++) {
        for (int j_08 = 0; j_08 <= n; j_08++) {
            if (i_08 == 0 || j_08 == 0)
                LCS[i_08][j_08] = 0;
            else if (str1[i_08 - 1] == str2[j_08 - 1])
                LCS[i_08][j_08] = LCS[i_08 - 1][j_08 - 1] + 1;
            else
                LCS[i_08][j_08] = max(LCS[i_08 - 1][j_08], LCS[i_08][j_08 - 1]);
        }
    }

    int lcsLength = LCS[m][n];
    char lcs[lcsLength + 1];
    lcs[lcsLength] = '\0';

    int i_08 = m, j_08 = n;
    while (i_08 > 0 && j_08 > 0) {
        if (str1[i_08 - 1] == str2[j_08 - 1]) {
            lcs[lcsLength - 1] = str1[i_08 - 1];
            i_08--;
            j_08--;
            lcsLength--;
        } else if (LCS[i_08 - 1][j_08] > LCS[i_08][j_08 - 1]) {
            i_08--;
        } else {
            j_08--;
        }
    }

    printf("LCS: %s\n", lcs);
    printf("LCS length: %d\n", strlen(lcs));
}

int main() {
    char str1[] = "10010101";
    char str2[] = "010110110";

    findLCS(str1, str2);

    return 0;
}
