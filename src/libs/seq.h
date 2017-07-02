#ifndef SEQUENCESS_H
#define SEQUENCES_H

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

void generateSeq(int a[], int len, int modulo, seq_t kind);

#endif
