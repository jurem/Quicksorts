#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <time.h>

#include "libs/common.h"
#include "libs/seq.h"
#include "libs/timer.h"
#include "libs/stat.h"
#include "libs/algs.h"

#define RUNALG
#include "common.h"


void doStat(int *a, int len) {
    int *t = malloc(len * sizeof(int));
    copyArray(a, t, len);
    stat_reset(&stat);
    stat_start(&stat);
    algstat(t, 0, len - 1);
    stat_stop(&stat);
    if (checkArraySorted(t, len) != -1) printf("ERR: %s\n", name);
    if (output_flag) printArray(t, len);
    free(t);
}


void doTime(int *a, int len) {
    int *t = malloc(len * sizeof(int));
    timer_reset(&timer);
    while (timer.repeats < maxRepeat && timer.timeTotal / CLOCKS_PER_SEC < maxTime) {
        copyArray(a, t, len);
        timer_start(&timer);
        algtime(t, 0, len - 1);
        timer_stop(&timer);
        if (checkArraySorted(t, len) != -1) printf("ERR: %s\n", name);
    }
    free(t);
}


int main(int argc, char * argv[]) {
    processArgs(argc, argv);
    if (verbose_flag) printSettings();

    int *a = readArray(&length);
    if (input_flag) printArray(a, length);
    doStat(a, length);
    doTime(a, length);
    free(a);

    printf("%9d ", length);
    printf("%10.0f %10.0f %10.0f %10lu", stat.averageCmps, stat.averageMoves, stat.averageCalls, stat.repeats);
    printf("%10.0f %10lu\n", timer_get_us(&timer), timer.repeats);

    return 0;
}