// uloha10-1.c -- Tibor Dulovec, 15.1.2021 13:32

#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    int theArray[n + 1][n];
    int done[n];
    int poradie[n];
    //for pre riadky
    for (int i = 0; i < n; ++i) {
        //for pre stlpce
        for (int j = 0; j < n; ++j) {
            scanf("%d ", &theArray[j][i]);
        }
        scanf(" %d\n", &theArray[n][i]);
    }



    // prechadzanie stlpcov
    for (int i = 0; i < n; ++i) {
        // Hladanie uz v pohode riadka
        int goodRow;
        for (int j = 0; j < n; ++j) {
            if (done[j] != 1 && theArray[i][j] == 1) {
                done[j] = 1;
                poradie[i] = j;
                goodRow = j;
                break;
            }
        }

        // hladanie jednotiek
        for (int j = 0; j < n; ++j) {
            if (theArray[i][j] == 1) {
                if (j != goodRow) {
                    for (int k = 0; k <= n; ++k) {
                        // printf("%d/", theArray[k][j]);
                        theArray[k][j] = (theArray[k][j] + theArray[k][goodRow]) % 2;
                        // printf("%d ", theArray[k][j]);
                    }
                    // printf("\n");

                }
            }
        }
    }
    //tu uz mam tu krasu, teraz to zoradit
    for (int L = 0; L < n; ++L) {
//        printf("%d ", poradie[L] );
    }
    // printf("\n");

    for (int L = 0; L < n; ++L) {
        printf("%d ", theArray[n][poradie[L]] );
    }
//0/0-0
//1/1=0
//2/4-0

    // printf("\n");
    // for (int m = 0; m < n; ++m) {
    //     for (int L = 0; L <= n; ++L) {
    //         printf("%d ", theArray[L][m]);
    //     }
    //     printf("\n");
    // }

    return 0;
}