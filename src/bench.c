#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>
#include <time.h>

#include "libs/common.h"
#include "libs/timer.h"
#include "libs/stat.h"
#include "libs/perms.h"
#include "libs/algs.h"

#define BENCH
#include "common.h"


void doTime() {
    srandom(use_seed ? seed : clock());
    int* a = malloc(length * sizeof(int));
    timer_reset(&timer);
    while (timer.repeats < maxRepeat && timer.timeTotal/CLOCKS_PER_SEC < maxTime) {
        generatePerm(a, length, modulo, perm);
        timer_start(&timer);
        algtime(a, 0, length - 1);
        timer_stop(&timer);
        if (checkArraySorted(a, length) != -1) printf("ERR: %s\n", name);
    }
    free(a);
}


void doStat() {
    if (perm != Rand) maxRepeat = 1;
    srandom(use_seed ? seed : clock());
    int* a = malloc(length * sizeof(int));
    timer_reset(&timer);
    stat_reset(&stat);
    while (timer.repeats < maxRepeat && timer.timeTotal/CLOCKS_PER_SEC < maxTime) {
        generatePerm(a, length, modulo, perm);
        stat_start(&stat);
        timer_start(&timer);
        algstat(a, 0, length - 1);
        timer_stop(&timer);
        stat_stop(&stat);
        if (checkArraySorted(a, length) != -1) printf("ERR: %s\n", name);
    }
    free(a);
}


int main(int argc, char * argv[]) {
    processArgs(argc, argv);
    if (verbose_flag) printSettings();

    doStat();
    doTime();

    printf("%9d ", length);
    printf("%10.0f %10.0f %10.0f %10lu", stat.averageCmps, stat.averageMoves, stat.averageCalls, stat.repeats);
    printf("%10.0f %10lu\n", timer_get_us(&timer), timer.repeats);

    return 0;
}