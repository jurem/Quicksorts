//  Created by Jurij Mihelič on 26. 03. 13.
//  Copyright (c) 2013 Jurij Mihelič. All rights reserved.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <getopt.h>

#include "libs/perms.h"

#define GENPERM
#include "common.h"

int main(int argc, char *argv[]) {
    processArgs(argc, argv);
    if (verbose_flag) printSettings();

    srandom(use_seed ? seed : clock());

    int* a = (int*)malloc(length * sizeof(int));
    generatePerm(a, length, modulo, perm);
    printArray(a, length);
    free(a);

    return 0;
}
