#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 100

typedef struct {
    int exp;
    float coef;
} poly;

poly terms[MAX_TERMS];
int avail = 0;

void Attach(float coef, int exp);
void padd(int startx, int finishx, int starty, int finishy, int *startd, int *finishd);
int COMPARE(int x_exp, int y_exp);

void Attach(float coef, int exp) {
    if (avail >= MAX_TERMS) {
        printf("too many terms");
        exit(1);
    }
    terms[avail].coef = coef;
    terms[avail++].exp = exp;
}

int COMPARE(int x_exp, int y_exp) {
    if (x_exp < y_exp)
        return -1;
    else if (x_exp == y_exp)
        return 0;
    else
        return 1;
}

void padd(int startx, int finishx, int starty, int finishy, int *startd, int *finishd) {
    float coef_add = 0;
    *startd = avail;
    while (startx <= finishx && starty <= finishy) {
        switch (COMPARE(terms[startx].exp, terms[starty].exp)) {
            case -1:
                Attach(terms[starty].coef, terms[starty].exp);
                starty++;
                break;
            case 0:
                coef_add = terms[startx].coef + terms[starty].coef;
                if (coef_add)
                    Attach(coef_add, terms[startx].exp);
                startx++;
                starty++;
                break;
            case 1:
                Attach(terms[startx].coef, terms[startx].exp);
                startx++;
                break;
        }
    }
    for (; startx <= finishx; startx++)
        Attach(terms[startx].coef, terms[startx].exp);
    for (; starty <= finishy; starty++)
        Attach(terms[starty].coef, terms[starty].exp);
    *finishd = avail - 1;
}

int main() {
    // 多項式 A: 3x^4 + 2x^2 + 1
    Attach(3, 4);
    Attach(2, 2);
    Attach(1, 0);
    int startA = 0, finishA = avail - 1;

    // 多項式 B: 4x^3 + 2x^2 + 5
    Attach(4, 3);
    Attach(2, 2);
    Attach(5, 0);
    int startB = finishA + 1, finishB = avail - 1;

    // 加總結果 D = A + B
    int startD, finishD;
    padd(startA, finishA, startB, finishB, &startD, &finishD);

    printf("多項式 A + B = ");
    for (int i = startD; i <= finishD; i++) {
        printf("%.1fx^%d", terms[i].coef, terms[i].exp);
        if (i < finishD) printf(" + ");
    }
    printf("\n");

    return 0;
}
