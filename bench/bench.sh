#!/bin/bash

# 			  start ...		   stop		   step
# tiny		  1 000 ...      10 000	      1 000
# small		 10 000 ...     100 000      10 000
# norm		100 000 ...   1 000 000	    100 000
# big     1 000 000 ...  10 000 000   1 000 000
# huge   10 000 000 ... 100 000 000  10 000 000
#
# Bigger test includes all smaller ones.

EXE=../bin/bench

h=$(hostname)
HOST=${h%%.*}
OUT="../out-$HOST/"

SIZE=${1:-norm}
SEQ=${2:-rand}
REPEAT=${3:-100}
MAXTIME=${4:-1}

case $SIZE in
	tiny)	MAXLEN=10000 ;;
	small)	MAXLEN=100000 ;;
	norm)	MAXLEN=1000000 ;;
	big)	MAXLEN=10000000 ;;
	huge)	MAXLEN=100000000 ;;
esac


function do_one {
	local alg
	alg=$1

	len=1000
	RANDOM=42
	echo '        n      cmps      moves      calls    statrep      time    timerep'
	while (( len <= MAXLEN )); do
		$EXE -k $SEQ -l $len -s $RANDOM -r $REPEAT -t $MAXTIME $alg
		if     (( len < 10000)); then step=1000
		elif  (( len < 100000)); then step=10000
		elif (( len < 1000000)); then step=100000
		else                          step=1000000
		fi
		(( len += step ))
	done
}

repdir="$OUT/$SIZE-$SEQ-r$REPEAT-t$MAXTIME"
mkdir -p "$repdir"

#algs=$(echo Quicksort{Lomuto,LomutoMoves})
#algs=$(echo Quicksort{Hoare,Hoare1,Wirth})
#algs=$(echo Quicksort{Sedgewick,SedgewickMoves,SedgewickSentinels})
#algs=$(echo Quicksort{Sin,SinSentinels})
algs=$(echo Quicksort{YaroSimple,Yaro})
#algs=$(echo Quicksort3Pivot{0,1,2,3})


echo "Test platform: $HOST"
echo "Test scenario: $(basename $repdir)"
for alg in $algs; do
	reportfile="$repdir/$alg.csv"
	echo -n "$(basename $reportfile) ... "
	test -f "$reportfile" && echo 'skipped' && continue || echo 'testing'
	do_one $alg | tee "$reportfile"
done
