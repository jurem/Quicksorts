#ifndef PERMS_H
#define PERMS_H

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

// permutation kinds

typedef enum perm_t {
    None,
    Rand,
    Zig, ZigRev, ZigRevFront, ZigRevBack,
    Sort, SortRev,
    Dither
} perm_t;

perm_t str2perm(const char *str);

const char* perm2str(const perm_t perm);

void printPerms(const char *prefix);

void generatePerm(int a[], int len, int modulo, perm_t kind);

#endif
