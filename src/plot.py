import pandas as pd
import matplotlib.pyplot as plt


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


def plot_it(loc, desc, xlabel, ylabel, df_list):
    if loc is not None:
        plt.subplot(loc)
    plt.title(desc)
    plt.xlabel(xlabel)
    plt.ylabel(ylabel)

    for ns, df, label in df_list:
        plt.plot(ns, df, 'x', label=label, linestyle='-')
    plt.legend(loc='best')


def plot_them(loc, attr, xlabel, ylabel):
    plot_it(loc, "Quicksort", xlabel, ylabel, [
        (df_hoare.index, df_hoare[attr], "Hoare"),
        (df_wirth.index, df_wirth[attr], "Wirth"),
        (df_lomuto.index, df_lomuto[attr], "Lomuto"),
        (df_sedgewick.index, df_sedgewick[attr], "Sedgewick"),
        (df_yaro.index, df_yaro[attr], "Yaro"),
        (df_yaro_simple.index, df_yaro_simple[attr], "YaroSimple"),
    ])


def plot_them_and_save(attr, xlabel, ylabel, test_name, loc=None):
    plt.figure(figsize=(16, 9), dpi=80)
    # plt.tight_layout()
    plot_them(loc, attr, xlabel, ylabel)
    plt.savefig(PLOT_SAVE_PATH + test_name + "-" + attr + ".png", format='png')


if __name__ == '__main__':
    base_path = "../out-DESKTOP-EDJNGBD/"
    dirs = [
        ("Tiny", base_path + "tiny--r10-t5/"),
        ("Norm", base_path + "norm--r100-t1/"),
    ]

    for test_name, path in dirs:
        df_hoare = load_df(path + "QuicksortHoare.csv")
        df_lomuto = load_df(path + "QuicksortLomuto.csv")
        df_sedgewick = load_df(path + "QuicksortSedgewick.csv")
        df_wirth = load_df(path + "QuicksortWirth.csv")
        df_yaro_simple = load_df(path + "QuicksortYaroSimple.csv")
        df_yaro = load_df(path + "QuicksortYaro.csv")

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
            PLOT_SAVE_PATH = '../out-Plots/'
            plot_them_and_save('time', xlabel, "Čas [ms]", test_name)
            plot_them_and_save('cmps', xlabel, "Št. primerjav", test_name)
            plot_them_and_save('moves', xlabel, "Št. premikov", test_name)
            plot_them_and_save('calls', xlabel, "Št. rekurzivnih klicov", test_name)
