//
// 8/14/20
//

#include <stdio.h>
#include <stdlib.h>

// count(*array[]): Counts the number of elements in a given array. A one-element array would return 1.

char ccount(char list[]) {
    char total;
    for (int n = 0, step = 1; step != 0; n++) {
        if (!*(list + n)) {
            step = 0;
            total = n;
        }
    }
    return total;
}

int icount(int *list[]) {
    int total;
    for (int n = 0, step = 1; step !=0 ; n++) {
        if (!*(list + n)) {
            step = 0;
            total = n;
        }
    }
    return total;
}

double dcount(double *list[]) {
    double total;
    for (int n = 0, step = 1; step !=0; n++) {
        if (!*(list + n)) {
            step = 0;
            total = n;
        }
    }
    return total;
}

long lcount(long *list[]) {
    long total;
    for (int n = 0, step = 1; step !=0; n++) {
        if (!*(list + n)) {
            step = 0;
            total = n;
        }
    }
    return total;
}

// arraycp(l1[],l2[]): Copies the values of array l2[] to array l1[].

void carraycp(char l1[], char l2[]) {
    for (int n; n < ccount(l2); n++) {
        *(l2 + n) = *(l1 + n);
    }
}
void iarraycp(int l1[], int l2[]) {
    for (int n; n < icount(&l2); n++) { // & may be incorrect
        *(l2 + n) = *(l1 + n);
    }
}
void darraycp(double l1[], double l2[]) {
    for (int n; n < dcount(&l2); n++) { // & may be incorrect
        *(l2 + n) = *(l1 + n);
    }
}
void larraycp(long l1[], long l2[]) {
    for (int n; n < lcount(&l2); n++) { // & may be incorrect
        *(l2 + n) = *(l1 + n);
    }
}

/*
char caat(char l[],int i) {
    return *(l + i);
}

char iaat(int l[],int i) {
    return *(l + i);
}
char daat(double l[],int i) {
    return *(l + i);
}
char laat(long l[],int i) {
    return *(l + i);
}
*/
