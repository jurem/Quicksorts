import pandas as pd
import matplotlib
import matplotlib.pyplot as plt


# LIMIT_N = 100000


def load_df(filepath):
    # read_csv, read_table
    # df = pd.read_table(
    return pd.read_fwf(
        filepath,
        # sep='-',
        names=['n', 'cmps', 'moves', 'calls', 'statrep', 'time', 'timerep'],
        index_col=0,
        skiprows=[0],
    )


def plot_it(loc, desc, xlabel, ylabel, _, df_list):
    if loc is not None:
        plt.subplot(loc)
    plt.title(desc)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)

    # [(ns, df, label) for ns, df, label in df_list]
    new_df_list = df_list[:]
    # new_df_list = [([x for x in ns if x <= LIMIT_N], df, label) for ns, df, label in new_df_list]
    # new_df_list = [(ns, df[:len(ns)], label) for ns, df, label in new_df_list]

    # Set min and max
    xmax = max(max(ns) for ns, _, _ in new_df_list)
    plt.xlim(xmin=0, xmax=xmax * 1.05)
    ymax = max(max(df) for _, df, _ in new_df_list)
    plt.ylim(ymin=0, ymax=ymax * 1.05)

    for ns, df, label in new_df_list:
        plt.plot(ns, df, 'x', label=label, linestyle='-')
    plt.legend(loc='best')


def plot_them(loc, attr, xlabel, ylabel):
    plot_it(loc, "Quicksort", xlabel, ylabel, attr, [
        (df_hoare.index, df_hoare[attr], "Hoare"),
        (df_wirth.index, df_wirth[attr], "Wirth"),
        (df_lomuto.index, df_lomuto[attr], "Lomuto"),
        (df_sedgewick.index, df_sedgewick[attr], "Sedgewick"),
        (df_sedgewick_dualpivot.index, df_sedgewick_dualpivot[attr], "SedgewickDualPivot"),
        (df_yaro.index, df_yaro[attr], "Yaro"),
        (df_yaro_simple.index, df_yaro_simple[attr], "YaroSimple"),
        (df_tripartite_simple.index, df_tripartite_simple[attr], "TripartiteSimple"),
        (df_tripartite_bentley_mcilroy.index, df_tripartite_bentley_mcilroy[attr], "TripartiteBentleyMcIlroy"),
        (df_quicksort_3pivot.index, df_quicksort_3pivot[attr], "3-Pivot"),
    ])


def plot_them_and_save(attr, xlabel, ylabel, test_name, loc=None):
    plt.figure(figsize=(16, 9), dpi=80)
    plt.tight_layout()
    plot_them(loc, attr, xlabel, ylabel)
    plt.savefig(PLOT_SAVE_PATH + test_name + "-" + attr + ".pdf", format='pdf')

    code = "\\begin{figure}[h] " + \
           "  \center \includegraphics[width=1.1\\textwidth]{../Quicksorts/out-Plots/Random-calls.pdf} " + \
           "  \caption{Plot Caption}\label{plotLabel} " + \
           "\end{figure}"

    d = {
        'time': 'Čas izvajanja [ms]',
        'cmps': 'Št. primerjav',
        'moves': 'Št. zamenjav',
        'calls': 'Št. rekurzivnih klicev',
    }

    latex = code \
        .replace("Random-calls.pdf", test_name + "-" + attr + ".pdf") \
        .replace("Plot Caption", test_name + ", " + d[attr].replace("Št.", "Število").lower()) \
        .replace("plotLabel", test_name + "_" + attr)
    print(latex, file=PLOT_FILE)


if __name__ == '__main__':
    base_path = "../out-DESKTOP-EDJNGBD/"
    PLOT_SAVE_PATH = '../out-Plots/'
    PLOT_FILE = open(PLOT_SAVE_PATH + "plots-tex.txt", "w", encoding="utf-8")

    # Old (norm) with some seg faults
    dirs_old = [
        ("Random", base_path + "TR1-norm-G1Saw-1--G2Id-0-0-G3RandPerm0-0-r100-t1" + "/"),
        ("Duplicates", base_path + "TR1-norm-G1Saw-1-0.15-G2Id-0-0-G3RandPerm0-0-r100-t1" + "/"),
        ("AlmostSorted", base_path + "TR1-norm-G1Saw-1--G2Id-0-0-G3Swap0.01-0-r100-t1" + "/"),
    ]

    # Small
    dirs_small = [
        ("Random", base_path + "Random-small-G1Saw-1--G2Id-0-0-G3RandPerm0-0-r100-t1"),
        ("Duplicates", base_path + "Duplicates-small-G1Saw-1-0.15-G2Id-0-0-G3RandPerm0-0-r100-t1"),
        ("AlmostSorted", base_path + "AlmostSorted-small-G1Saw-1--G2Id-0-0-G3Swap0.01-0-r100-t1"),
    ]

    # Norm
    dirs_norm = [
        ("Random", base_path + "Random-norm-G1Saw-1--G2Id-0-0-G3RandPerm0-0-r100-t1"),
        ("Duplicates", base_path + "Duplicates-norm-G1Saw-1-0.15-G2Id-0-0-G3RandPerm0-0-r100-t1"),
        ("AlmostSorted", base_path + "AlmostSorted-norm-G1Saw-1--G2Id-0-0-G3Swap0.01-0-r100-t1"),
    ]

    dirs = dirs_norm

    # font = {'family': 'normal', 'weight': 'bold', 'size': 22}
    # matplotlib.rc('font', **font)
    matplotlib.rcParams.update({'font.size': 20})

    for test_name, path in dirs:
        df_hoare = load_df(path + "/" + "QuicksortHoare.csv")
        df_lomuto = load_df(path + "/" + "QuicksortLomuto.csv")
        df_sedgewick = load_df(path + "/" + "QuicksortSedgewick.csv")
        df_wirth = load_df(path + "/" + "QuicksortWirth.csv")
        df_yaro_simple = load_df(path + "/" + "QuicksortYaroSimple.csv")
        df_yaro = load_df(path + "/" + "QuicksortYaro.csv")
        df_sedgewick_dualpivot = load_df(path + "/" + "QuicksortSedgewickDualPivot.csv")
        df_tripartite_simple = load_df(path + "/" + "QuicksortTripartiteSimple.csv")
        df_tripartite_bentley_mcilroy = load_df(path + "/" + "QuicksortTripartiteBentleyMcIlroy.csv")
        df_quicksort_3pivot = load_df(path + "/" + "Quicksort3Pivot3.csv")

        xlabel = "Velikost tabele"
        if False:
            # plt.tight_layout()
            plt.figure()
            plot_them(221, 'time', xlabel, "Čas [ms]")
            plot_them(222, 'cmps', xlabel, "Št. primerjav")
            plot_them(223, 'moves', xlabel, "Št. premikov")
            plot_them(224, 'calls', xlabel, "Št. rekurzivnih klicev")
            plt.show()
        else:
            print("\subsection{" + test_name + "}", file=PLOT_FILE)
            plot_them_and_save('time', xlabel, "Čas [ms]", test_name)
            plot_them_and_save('cmps', xlabel, "Št. primerjav", test_name)
            plot_them_and_save('moves', xlabel, "Št. premikov", test_name)
            plot_them_and_save('calls', xlabel, "Št. rekurzivnih klicov", test_name)
            print("\clearpage", file=PLOT_FILE)
            print("\\newpage", file=PLOT_FILE)
            print(file=PLOT_FILE)
