void printUsage(const char *app_name) {
    // Usage
#if defined(RUNALG) || defined(BENCH)
    printf("Usage: %s alg\n", app_name);
    printAlgs("  alg: ");
#else
    printf("Usage: %s\n", app_name);
#endif
    // Options
    printf("\nOptions:\n");
    printf("  -v, --verbose\n\tPrint settings.\n");
    printf("  -h, --help\n\tPrint short help.\n");

#if defined(GENSEQ) || defined(BENCH)
    printf("  -s num, --seed num\n\tSeed for the random number generator.\n");
    printf("  -l num, --length num\n\tSequence length (default 100).\n");
    printf("\nFormation phase options:\n");
    printf("  -F form, --form form\n");
    printf("\tGenerated numbers are in a range [offset, offset + range).\n");
    printf("\tForm of a generated sequence: ");
    printForms();
    printFormsHints();
    printf("  -R num, --range num\n\tRange of the generated values is from 0 to rng-1.\n\tZero sets it to the length.\n");
    printf("  -O num, --offset num\n\tOffset of the range. Can be negative,\n");
    printf("  -P num, --slope num\n\tSlope of the Saw pattern.\n");
    // parameter 1
    printf("\nDeformation phase options:\n");
    printf("  -D deform, --deform deform\n\tDeform of a generated sequence: ");
    printDeforms();
    printf("  -L num, --lo num\n\tLower bound in the deform phase.\n");
    printf("  -H num, --hi num\n\tUpper bound in the deform phase.\n");
    // p1
    // p2
    printf("\nShaping phase options:\n");
    printf("  -S shape, --shape shape\n\tShape of the generated sequence: ");
    printShapes();
    printf("  -B num, --begin num \n\tTODO\n");
    printf("  -E num, --end num\n\tTODO.\n");
#endif
#if defined(GENSEQ) || defined(BENCH)
    printf("  -K seq, --kind seq\n\tInput sequence kind.\n");
#endif
#if defined(RUNALG) || defined(BENCH)
    printf("\nBenchmark options:\n");
    printf("  -r num, --repeat num\n\tMax number of repeates.\n");
    printf("  -t sec, --time sec\n\tMax benchmark time.\n");
#endif
#if defined(RUNALG)
    printf("  -i, --input\n\tPrint input array.\n");
    printf("  -o, --output\n\tPrint output array.\n");
#endif
}


// **************** Input sequence properties
int length = 100;       // length of sequence / pre-reserved space
#if defined(GENSEQ) || defined(BENCH)
int use_seed = 0;       // seed (default) or given seed
int seed;
gen_t gen;
#endif

#if defined(RUNALG) || defined(BENCH)
// benchmark
int maxRepeat = 100;
int maxTime = 1;
timer_t timer;
stat_t stat;

// algorithm
char* name;
SortFun algtime;
SortFun algstat;
#endif

#ifdef RUNALG
int input_flag = 0;
int output_flag = 0;
#endif

// other
int verbose_flag = 0;
int help_flag = 0;


void printSettings() {
#if defined(GENSEQ) || defined(BENCH)
    printf("Input:   length=%d, modulo=%d", length, gen.range);
    if (use_seed) printf(", seed=%d", seed); else printf(", seed=rnd");
//    printf(", (%s-%d) (%s-%d-%d) (%s-%f-%f)", form2str(gen.form), gen.slope, deform2str(gen.deform), parameter21, parameter22, shape2str(shape), parameter31, parameter32);
    printf("\n");
#endif
#if defined(RUNALG) || defined(BENCH)
    printf("Bench: maxRepeat=%d, maxTime=%d", maxRepeat, maxTime);
    printf("\n");
#endif
}


// **************** Command-line options and arguments handling

// command-line long options
struct option options[] = {
    {"length",      required_argument, 0, 'l'},
#if defined(GENSEQ) || defined(BENCH)
    // formation
    {"form",        required_argument, 0, 'F'},
    {"range",       required_argument, 0, 'R'},
    {"offset",      required_argument, 0, 'O'},
    {"slope",       required_argument, 0, 'P'},

    {"seed",        required_argument, 0, 's'},
    // deformation
    {"deform",      required_argument, 0, 'D'},
    {"lo",          required_argument, 0, 'L'},
    {"hi",          required_argument, 0, 'H'},
    // shaping
    {"shape",       required_argument, 0, 'S'},
    {"begin",       required_argument, 0, 'B'},
    {"end",         required_argument, 0, 'E'},
    // predefined sequence kinds
    {"kind",        required_argument, 0, 'K'},
#endif
#if defined(RUNALG) || defined(BENCH)
    {"repeat",      required_argument, 0, 'r'},
    {"time",        required_argument, 0, 't'},
#endif
#ifdef RUNALG
    {"input",       no_argument, &input_flag, 1},
    {"output",      no_argument, &output_flag, 1},
#endif
    {"verbose",     no_argument, &verbose_flag, 1},
    {"help",        no_argument, &help_flag, 1},
    {0, 0, 0, 0}
};


// command-line short options
#ifdef GENSEQ
#define SHORTOPT "hvl:F:R:O:P:s:D:L:H:S:B:E:K:"
#endif
#ifdef RUNALG
#define SHORTOPT "hviol:r:t:"
#endif
#ifdef BENCH
#define SHORTOPT "hvl:F:R:O:P:s:D:L:H:S:B:E:K:r:t:"
#endif


void die(int status, const char* msg) {
    fprintf(stderr, "%s\n", msg);
    exit(status);
}


void dieArg(int status, const char* fmt, const char* msg) {
    fprintf(stderr, fmt, msg);
    exit(status);
}


void processArgs(int argc, char* argv[]) {
    while (1) {
        int option_index = 0;
        int opt = getopt_long(argc, argv, SHORTOPT, options, &option_index);
        if (opt == -1) break;
        switch (opt) {
            case 0:
                if (options[option_index].flag != 0) break;
                break;
            case 'v':
                verbose_flag = 1;
                break;
            case 'h':
                help_flag = 1;
                break;
            case 'l':
                length = atoi(optarg);
                break;
            // case 'G':
            //     gen.form = str2form(optarg);
            //     if ((int)gen.form < 0) dieArg(1, "Invalid form specified: '%s'.\n", optarg);
            //     break;
#if defined(GENSEQ) || defined(BENCH)
            case 's':
                seed = atoi(optarg);
                use_seed = 1;
                break;
            // form
            case 'F':
                gen.form = str2form(optarg);
                if ((int)gen.form < 0) dieArg(1, "Invalid form specified: '%s'.\n", optarg);
                break;
            case 'R':
                gen.range = atoi(optarg);
                break;
            case 'O':
                gen.offset = atoi(optarg);
                break;
            case 'P':
                gen.slope = atoi(optarg);
                break;
            // deform
            case 'D':
                gen.deform = str2deform(optarg);
                if ((int)gen.deform < 0) dieArg(1, "Invalid deform specified: '%s'.\n", optarg);
                break;
            case 'L':
                gen.lo = atoi(optarg);
                break;
            case 'H':
                gen.hi = atoi(optarg);
                break;
            // shape
            case 'S':
                gen.shape = str2shape(optarg);
                if ((int)gen.shape < 0) dieArg(1, "Invalid shape specified: '%s'.\n", optarg);
                break;
            case 'B': // p31
                gen.p1 = atof(optarg);
                break;
            case 'E': // p32
                gen.p2 = atof(optarg);
                break;
#endif
#if defined(RUNALG) || defined(BENCH)
            case 'r':
                maxRepeat = atoi(optarg);
                break;
            case 't':
                maxTime = atoi(optarg);
                break;
#endif
#if defined(RUNALG)
			case 'i':
                input_flag = 1;
                break;
			case 'o':
                output_flag = 1;
                break;
#endif                
            case '?':
                exit(3);
                break;
            default:
                abort();
        }
    }

    if (help_flag) {
        printUsage(argv[0]);
        exit(0);
    }

#if defined(GENSEQ) || defined(BENCH)
    if (gen.range <= 0) gen.range = length;
#endif

    if (optind < argc) {
#if defined(RUNALG) || defined(BENCH)
        name = argv[optind];
        const SortInfo* si = findAlg(name);
        if (si == NULL) {
            fprintf(stderr, "Unknown sorting algorithm '%s'.\n", name);
            exit(2);
        }
        algtime = si->funtime;
        algstat = si->funstat;
    } else {
#endif    	
        printUsage(argv[0]);
        exit(1);
    }

}