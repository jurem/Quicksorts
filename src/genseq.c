//  Created by Jurij Mihelič on 26. 03. 13.
//  Copyright (c) 2013 Jurij Mihelič. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <getopt.h>

#include "libs/seq.h"

#define GENSEQ
#include "common.h"

int main(int argc, char *argv[]) {
    processArgs(argc, argv);
    if (verbose_flag) printSettings();

    srandom(use_seed ? seed : clock());

    int* a = (int*)malloc(length * sizeof(int));
    generateSeq(a, length, modulo, gen1, gen2, gen3, parameter1, parameter21, parameter22, parameter3);
    printArray(a, length);
    free(a);

    return 0;
}
