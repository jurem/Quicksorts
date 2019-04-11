#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "seq.h"


int arrayIndexOf(int a[], int n, int val) {
	for (int i = 0; i < n; i++)
		if (a[i] == val) return i;
	return -1;
}


void copyArray(int src[], int dst[], int len) {
	for (int i = 0; i < len; i++) dst[i] = src[i];
}


void printArray(int a[], int len) {
	for (int i = 0; i < len; i++) printf("%i ", a[i]);
	printf("\n");
}


void printArraySlice(int a[], int start, int end) {
	while (start <= end) printf("%i ", a[start++]);
	printf("\n");
}


int* readArray(int *length) {
    if (*length <= 0) *length = 1000;
    int* a = malloc(*length * sizeof(int));
    int count = 0;

    int val;
    while (scanf("%d", &val) > 0) {
        if (count >= *length) {
            *length *= 2;
            a = realloc(a, *length * sizeof(int));
        }
        a[count++] = val;
    }
    *length = count;
    return realloc(a, count * sizeof(int));
}


int checkArraySorted(int a[], int n) {
    for (int i = 0; i < n-1; i++)
        if (a[i] > a[i+1]) return i;
    return -1;
}


int cmpInt(const void *a, const void *b) {
	return *(const int*)a - *(const int *)b;
}


int cmpIntRev(const void *a, const void *b) {
	return *(const int*)b - *(const int *)a;
}


void printStrs(const char* strs[]) {
    for (int i = 0; strs[i] != NULL; i++) printf("%s ", strs[i]);
    printf("\n");
}


void printHints(const char* strs[], const char* hints[]) {
    for (int i = 0; strs[i] != NULL; i++) printf("\t%s\t%s\n", strs[i], hints[i]);
    printf("\n");
}


const char* form_strs[] = {
    "Rand", "Saw", "Twine", NULL
};
const char* form_hints[] = {
    "Random numbers.",
    "Saw pattern with a given slope.",
    "Random intertwining of two increasing sequences",
    NULL
};


const char* form2str(const form_t form) {
    return form_strs[form];
}


form_t str2form(const char* str) {
    for (int i = 0; form_strs[i] != NULL; i++)
        if (strcasecmp(form_strs[i], str) == 0) return (form_t)i;
    return -1;
}


void printForms() {
    printStrs(form_strs);
}


void printFormsHints() {
    printHints(form_strs, form_hints);
}


const char* deform_strs[] = { "Id", "Dither", "Bound", NULL };
const char* deform_hints[] = { "No deformation", "Dithering", "Bound", NULL };


const char* deform2str(const deform_t deform) {
    return deform_strs[deform];
}


deform_t str2deform(const char* str) {
    for (int i = 0; deform_strs[i] != NULL; i++)
        if (strcasecmp(deform_strs[i], str) == 0) return (deform_t)i;
    return -1;
}


void printDeforms() {
    printStrs(deform_strs);
}


const char* shape_strs[] = { "Pass", "Reverse", "Sort", "SortReverse", "Shuffle", "Jumble", NULL };


const char* shape2str(const shape_t shape) {
    return shape_strs[shape];
}


shape_t str2shape(const char* str) {
    for (int i = 0; shape_strs[i] != NULL; i++)
        if (strcasecmp(shape_strs[i], str) == 0) return (shape_t)i;
    return -1;
}


void printShapes() {
    printStrs(shape_strs);
}


void defaultGen(gen_t *gen) {
    gen->form = Rand;
    gen->range = 10;
    gen->offset = 0;
    gen->slope = 3;
    gen->deform = Id;
    gen->lo = 0;
    gen->hi = 10;
    gen->shape = Pass;
    gen->p1 = 0;
    gen->p2 = 1;
}


void generateSeq(int a[], int len, gen_t *gen) {
    // Stage 1: form numbers
    switch (gen->form) {
        case Rand:
            for (int i = 0; i < len; i++)
                a[i] = gen->offset + random() % gen->range;
            break;
        case Saw:
            for (int i = 0; i < len; i++)
                a[i] = gen->offset + (i * gen->slope) % gen->range;
            break;
        case Twine:
            for (int i = 0, j = 0, k = 1; i < len; i++)
                a[i] = gen->offset + ((random() % gen->slope) ? (j += 2) : (k += 2)) % gen->range;
            break;
    }
    // Stage 2: deform numbers
    switch (gen->deform) {
        case Id:
            break;
        case Dither:
            for (int i = 0; i < len; i++)
                a[i] += gen->lo + i % gen->hi;
            break;
        case Bound:
            for (int i = 0; i < len; i++)
                a[i] = i < gen->lo ? gen->lo : (i > gen->hi ? gen->hi : i);
            break;
    }
    // Stage 3: shape
    switch (gen->shape) {
        case Pass:
            break;
        case Reverse: {
            int b = gen->p1 * len;
            int e = gen->p2 * len;
            for (int i = b; i < (b + e) / 2; i++) swap(a, i, b+e-1-i);
            break;
        }
        case Sort:
            qsort(a, len, sizeof(int), cmpInt);
            break;
        case SortReverse:
            qsort(a, len, sizeof(int), cmpIntRev);
            break;
        case Shuffle: {
            int i = len;
            while (--i > 0) swap(a, i, random() % (len + 1));
            break;
        }
        case Jumble: {
            int k = (int)(gen->p1 * len);
            while (--k > 0)
                swap(a, random() % len, random() % len);
            break;
        }
        default:
            fprintf(stderr, "Wrong stage 3 generator pattern (%d).\n", gen->shape);
            exit(42);
    }
}

            // RAND PERM in SWAP P ni isto!
            // RAND PERM gre od konca in generira naključne permutacije z enako verjetnostjo
            // SWAP P pa naredi p naključnih zamenjav, kjer so ene bolj verjetne kod druge
            // SWAP P=n ni enako RAND PERM!

/*
To get Bentley's (Engineering ..) sequences:
sawtooth: -FSaw -Rm -O0 -P1
rand: -FRand -R$m -O0
stagger: -FSaw -R$n -O0 -P$((m+1))
plateau: -FSaw -R0 -O0 -P1 -DPlateau --lo=0 --hi=$m
shuffle: -FTwine -R0 -O0 -P$m

ReverseFront: -SReverse -B0 -E0.5
ReverseBack: -SReverse -B0.5 E1

*/
