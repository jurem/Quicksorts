#ifndef SEQ_H
#define SEQ_H

// **************** Array handling

inline void swap(int a[], int i, int j) {
    int t = a[i]; a[i] = a[j]; a[j] = t;
}

int arrayIndexOf(int a[], int len, int val);

void copyArray(int src[], int dst[], int len);

void printArray(int a[], int len);

void printArraySlice(int a[], int start, int end);

int* readArray(int *length);

int checkArraySorted(int a[], int n);

void printStrs(const char* strs[]);

// **************** Sequence generator: formation phase

typedef enum form_t {
    Rand, Saw, Twine
} form_t;

form_t str2form(const char *str);

const char* form2str(const form_t form);

void printForms();

void printFormsHints();

// **************** Sequence generator: deformation phase

typedef enum deform_t {
    Id, Dither, Bound
} deform_t;

deform_t str2deform(const char *str);

const char* deform2str(const deform_t gen);

void printDeforms();

// **************** Sequence generator: shaping phase

typedef enum shape_t {
    Pass,
    Reverse,
    Sort,
    SortReverse,
    Shuffle,
    Jumble
} shape_t;

shape_t str2shape(const char *str);

const char* shape2str(const shape_t shape);

void printShapes();

// **************** Sequence generator

typedef struct gen_t {
    // formation
    form_t form;
    int range;
    int offset;
    int slope;
    // deformation
    deform_t deform;
    int lo;
    int hi;
    //
    shape_t shape;
    double p1;
    double p2;
} gen_t;


void defaultGen(gen_t *gen);

void generateSeq(int a[], int len, gen_t *gen);


// sequence kinds

typedef enum seq_t {
    None1,
    Rand1,
    Zig1, ZigRev1, ZigRevFront1, ZigRevBack1,
    Sort1, SortRev1,
    Dither1
} seq_t;

#endif
