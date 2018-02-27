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


const char* sequences[] = {
    "None",
    "Rand",
    "Zig", "ZigRev", "ZigRevFront", "ZigRevBack",
    "Sort", "SortRev",
    "Dither",
    NULL
};


seq_t str2seq(const char* str) {
    for (int i = 0; sequences[i] != NULL; i++)
        if (strcasecmp(sequences[i], str) == 0) return (seq_t)i;
    return None;
}


const char* seq2str(const seq_t seq) {
    return sequences[seq];
}


void printSequences(const char *prefix) {
    printf("%s", prefix);
    for (seq_t i = Rand; i <= Dither; i++) printf("%s ", seq2str(i));
    printf("\n");
}


int cmpInt(const void *a, const void *b) {
	return *(const int*)a - *(const int *)b;
}


int cmpIntRev(const void *a, const void *b) {
	return *(const int*)b - *(const int *)a;
}


const char* generators1[] = { "G1None", "G1Rand", "G1Saw", "G1Shuffle", NULL };
const char* generators2[] = { "G2None", "G2Id", "G2Dither", "G2Plateau", NULL };
const char* generators3[] = { "G3None", "G3Id", "G3Reverse", "G3ReverseFront", "G3ReverseBack", "G3Sort", "G3RandPerm", "G3Swap", NULL };

void generateSeq(int a[], int len, int modulo, gen1_t gen1_type, gen2_t gen2_type, gen3_t gen3_type, int p1, int p21, int p22, double p31, double p32) {

    // Stage 1
    switch (gen1_type) {
        case G1Rand:
            for (int i = 0; i < len; i++) a[i] = random() % modulo;
            // int j = len; while (--j > 0) swap(a, j, random() % (j + 1));
            break;
        case G1Saw:
            for (int i = 0; i < len; i++) a[i] = (i * p1) % modulo;
            break;
        case G1Shuffle:
            for (int i = 0, j = 0, k = 1; i < len; i++) a[i] = random() % modulo ? (j += 2) : (k += 2);
            break;
        default:
            fprintf(stderr, "Wrong stage 1 generator pattern (%d).\n", gen1_type);
            exit(42);
    }

    // Stage 2
    switch (gen2_type) {
        case G2Id:
            break;
        case G2Plateau:
            for (int i = 0; i < len; i++) a[i] += i < p21 ? p21 : (i > p22 ? p22 : i);
            break;
        case G2Dither:
            for (int i = 0; i < len; i++) a[i] += i % p21;
            break;
        default:
            fprintf(stderr, "Wrong stage 2 generator pattern (%d).\n", gen2_type);
            exit(42);
    }

    // Stage 3
    switch (gen3_type) {
        case G3Id:
            break;
        case G3Reverse:
            for (int i = p31 * len; i < p32 * len; i++) swap(a, i, len-1-i);
            break;
        /*case G3ReverseFront:
            for (int i = 0; i < len / 4; i++) swap(a, i, len/2-i);
            break;
        case G3ReverseBack:
            for (int i = 0; i < len / 4; i++) swap(a, len/2+i, len-i);
            break;*/
        case G3Sort:
            qsort(a, len, sizeof(int), cmpInt);
            break;
        // TODO Add SortReversed
        // case SortRev:
        //    qsort(a, len, sizeof(int), cmpIntRev);
        //    break;
        case G3RandPerm:
            // RAND PERM in SWAP P ni isto!
            // RAND PERM gre od konca in generira naključne permutacije z enako verjetnostjo
            // SWAP P pa naredi p naključnih zamenjav, kjer so ene bolj verjetne kod druge
            // SWAP P=n ni enako RAND PERM!
            while (--len > 0) swap(a, len, random() % (len + 1));
            break;
        case G3Swap:
            // TODO Naredi p_31 random swap-ov!
            break;
        default:
            fprintf(stderr, "Wrong stage 3 generator pattern (%d).\n", gen3_type);
            exit(42);
    }
}

gen1_t str2gen1_t(const char* str) {
    for (int i = 0; generators1[i] != NULL; i++)
        if (strcasecmp(generators1[i], str) == 0) return (gen1_t)i;
    return G1None;
}

gen2_t str2gen2_t(const char* str) {
    for (int i = 0; generators2[i] != NULL; i++)
        if (strcasecmp(generators2[i], str) == 0) return (gen2_t)i;
    return G2None;
}

gen3_t str2gen3_t(const char* str) {
    for (int i = 0; generators3[i] != NULL; i++)
        if (strcasecmp(generators3[i], str) == 0) return (gen3_t)i;
    return G3None;
}

const char* gen1_t2str(const gen1_t gen) {
    return generators1[gen];
}

const char* gen2_t2str(const gen2_t gen) {
    return generators2[gen];
}

const char* gen3_t2str(const gen3_t gen) {
    return generators3[gen];
}
