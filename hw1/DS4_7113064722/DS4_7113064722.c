#include <stdio.h>
#include <stdlib.h>

#define MAX 10000

typedef struct {
    int pid;
    int arrival;
    int burst;
    int priority;
    int remaining;
    int finish;
    int done;
} proc;

int cmp(const void* a, const void* b) {
    proc* x = (proc*)a;
    proc* y = (proc*)b;
    return x->finish - y->finish;
}

int main() {
    FILE* in = fopen("test4.txt", "r");
    FILE* out = fopen("output4.txt", "w");
    if (in == NULL || out == NULL) {
        printf("File open failed.\n");
        return 1;
    }

    int t;
    fscanf(in, "%d", &t);

    while (t--) {
        int n;
        fscanf(in, "%d", &n);
        proc list[MAX];

        for (int i = 0; i < n; i++) {
            fscanf(in, "%d %d %d %d", &list[i].pid, &list[i].arrival, &list[i].burst, &list[i].priority);
            list[i].remaining = list[i].burst;
            list[i].done = 0;
            list[i].finish = 0;
        }

        int time = 0;
        int finished = 0;
        while (finished < n) {
            int pick = -1;
            for (int i = 0; i < n; i++) {
                if (list[i].arrival <= time && list[i].remaining > 0) {
                    if (pick == -1 || list[i].priority > list[pick].priority ||
                        (list[i].priority == list[pick].priority && list[i].arrival < list[pick].arrival)) {
                        pick = i;
                    }
                }
            }

            if (pick != -1) {
                list[pick].remaining--;
                if (list[pick].remaining == 0) {
                    list[pick].finish = time + 1;
                    list[pick].done = 1;
                    finished++;
                }
            }

            time++;
        }

        qsort(list, n, sizeof(proc), cmp);

        for (int i = 0; i < n; i++) {
            fprintf(out, "%d %d\n", list[i].pid, list[i].finish);
        }
    }

    fclose(in);
    fclose(out);
    return 0;
}
