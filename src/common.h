#if defined(GENSEQ) || defined(BENCH)
// input array
seq_t seq = Rand;		// random sequence
int modulo = 0;   		// zero means same as length
int use_seed = 0;  		// seed (default) or given seed
int seed;
gen1_t gen1;
gen2_t gen2;
gen3_t gen3;
int parameter1;
int parameter21;
int parameter22;
int parameter3;
#endif
int length = 1000;		// length of sequence / pre-reserved space

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


// command-line long options
struct option options[] = {
#if defined(GENSEQ) || defined(BENCH)
    {"kind",    required_argument, 0, 'k'},
    {"modulo",  required_argument, 0, 'm'},
    {"seed",    required_argument, 0, 's'},
    {"gen1",    required_argument, 0, 'A'},
    {"gen2",    required_argument, 0, 'B'},
    {"gen3",    required_argument, 0, 'C'},
    {"p1",      required_argument, 0, 'X'},
    {"p21",     required_argument, 0, 'Y'},
    {"p22",     required_argument, 0, 'Q'},
    {"p3",      required_argument, 0, 'Z'},
#endif
#if defined(RUNALG) || defined(BENCH)
    {"repeat",  required_argument, 0, 'r'},
    {"time",    required_argument, 0, 't'},
#endif
#ifdef RUNALG
    {"input",   no_argument, &input_flag, 1},
    {"output",  no_argument, &output_flag, 1},
#endif
    {"length",  required_argument, 0, 'l'},
    {"verbose", no_argument, &verbose_flag, 1},
    {"help",    no_argument, &help_flag, 1},
    {0, 0, 0, 0}
};


// command-line short options
#ifdef GENSEQ
#define SHORTOPT "hvl:k:m:s:A:B:C:X:Y:Q:Z:"
#endif
#ifdef RUNALG
#define SHORTOPT "hviol:r:t:"
#endif
#ifdef BENCH
#define SHORTOPT "hvl:k:m:s:r:t:A:B:C:X:Y:Q:Z:"
#endif


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
#if defined(GENSEQ) || defined(BENCH)
    printf("  -k seq, --kind seq\n\tInput sequence kind.\n");
    printSequences("\tseq: ");
#endif
    printf("  -l len, --length len\n\tLength of input sequence.\n");
#if defined(GENSEQ) || defined(BENCH)
    printf("  -m mod, --modulo mod\n\tRange of values is from 0 to mod-1.\n\tIf mod is zero than the same as the length.\n");
    printf("  -s num, --seed num\n\tSeed for the random number generator.\n");
#endif
#if defined(RUNALG) || defined(BENCH)
    printf("  -r num, --repeat num\n\tMax number of repeates.\n");
    printf("  -t sec, --time sec\n\tMax benchmark time.\n");
#endif
#if defined(RUNALG)
    printf("  -i, --input\n\tPrint input array.\n");
    printf("  -o, --output\n\tPrint output array.\n");
#endif
    printf("  -v, --verbose\n\tPrint settings.\n");
    printf("  -h, --help\n\tPrint short help.\n");
}


void printSettings() {
#if defined(GENSEQ) || defined(BENCH)
    printf("Input:   length=%d, modulo=%d", length, modulo);
    if (use_seed) printf(", seed=%d", seed); else printf(", seed=rnd");
    printf(", (%s-%d) (%s-%d-%d) (%s-%d)", gen1_t2str(gen1), parameter1, gen2_t2str(gen2), parameter21, parameter22, gen3_t2str(gen3), parameter3);
    printf("\n");
#endif
#if defined(RUNALG) || defined(BENCH)
    printf("Bench: maxRepeat=%d, maxTime=%d", maxRepeat, maxTime);
    printf("\n");
#endif
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
#if defined(GENSEQ) || defined(BENCH)
            case 'k':
                seq = str2seq(optarg);
                break;
            case 'm':
                modulo = atoi(optarg);
                break;
            case 's':
                seed = atoi(optarg);
                use_seed = 1;
                break;

            case 'A': // gen1
                gen1 = str2gen1_t(optarg);
                break;
            case 'B': // gen2
                gen2 = str2gen2_t(optarg);
                break;
            case 'C': // gen3
                gen3 = str2gen3_t(optarg);
                break;

            case 'X': // p1
                parameter1 = atoi(optarg);
                break;
            case 'Y': // p21
                parameter21 = atoi(optarg);
                break;
            case 'Q': // p22
                parameter22 = atoi(optarg);
                break;
            case 'Z': // p3
                parameter3 = atoi(optarg);
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
            case 'l':
                length = atoi(optarg); 
                break;
			case 'v':
                verbose_flag = 1;
                break;
			case 'h':
				help_flag = 1;
                break;
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
    if (modulo <= 0) modulo = length;
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