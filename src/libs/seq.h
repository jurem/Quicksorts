#ifndef SEQ_H
#define SEQ_H

// array handling

inline void swap(int a[], int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t;
}

int arrayIndexOf(int a[], int len, int val);

void copyArray(int src[], int dst[], int len);

void printArray(int a[], int len);

void printArraySlice(int a[], int start, int end);

int* readArray(int *length);

int checkArraySorted(int a[], int n);

// sequence kinds

typedef enum seq_t {
    None,
    Rand,
    Zig, ZigRev, ZigRevFront, ZigRevBack,
    Sort, SortRev,
    Dither
} seq_t;

seq_t str2seq(const char *str);

const char* seq2str(const seq_t seq);

void printSequences(const char *prefix);

// void generateSeq(int a[], int len, int modulo, seq_t kind);

// Generators

typedef enum gen1_t {
    G1None,
    G1Rand,
    G1Saw,
    G1Shuffle
} gen1_t;

typedef enum gen2_t {
    G2None,
    G2Id,
    G2Dither,         //
    G2Plateau         //
} gen2_t;

typedef enum gen3_t {
    G3None,
    G3Id,
    G3Reverse,
    G3ReverseFront,   // Reverse first p elements
    G3ReverseBack,    // Reverse last p elements
    G3Sort,
    G3RandPerm,       // Make p random permutations
    G3Swap            // Make p random exchanges
} gen3_t;

gen1_t str2gen1_t(const char *str);
gen2_t str2gen2_t(const char *str);
gen3_t str2gen3_t(const char *str);

const char* gen1_t2str(const gen1_t gen);
const char* gen2_t2str(const gen2_t gen);
const char* gen3_t2str(const gen3_t gen);

void generateSeq(int a[], int len, int modulo, gen1_t gen1_type, gen2_t gen2_type, gen3_t gen3_type, int p1, int p21, int p22, double p31, double p32);

#endif
