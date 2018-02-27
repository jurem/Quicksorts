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

# Save args
SIZE=${@:$OPTIND:1}
GEN1=${@:$OPTIND+1:1}
GEN2=${@:$OPTIND+2:1}
GEN3=${@:$OPTIND+3:1}
P1=${@:$OPTIND+4:1}
MOD=${@:OPTIND+5:1}
P21=${@:$OPTIND+6:1}
P22=${@:$OPTIND+7:1}
P31=${@:$OPTIND+8:1}
P32=${@:$OPTIND+9:1}
REPEAT=${@:$OPTIND+10:1}
MAXTIME=${@:$OPTIND+11:1}

# Set default value if arg empty
if [[ -z "$SIZE" ]]; then SIZE="norm"; fi
if [[ -z "$GEN1" ]]; then GEN1="G1Rand"; fi
if [[ -z "$GEN2" ]]; then GEN2="G2Id"; fi
if [[ -z "$GEN3" ]]; then GEN3="G3Id"; fi
if [[ -z "$REPEAT" ]]; then REPEAT=100; fi
if [[ -z "$MAXTIME" ]]; then MAXTIME=1; fi
# echo "\"$SIZE\" \"$GEN1\" \"$GEN2\" \"$GEN3\" \"$REPEAT\" \"$MAXTIME\" | Verbose: \"$VERBOSE\" | Optind: \"$OPTIND\""; exit;

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
	    # Set missing arguments
	    if [[ -z "$P1" ]]; then
            #if [[ "G1Saw" -eq "$GEN1" ]]; then P1=1; else
	        #P1=${len};
	        P1="";
        else _P1=${P1}; fi
        if [[ -z "$MOD" ]]; then _MOD=${len};
        else
            if (( $(echo "$MOD < 1.0" | bc -l) )); then
                _MOD=$(echo "$MOD * $len" | bc -l)
            else
                _MOD=${MOD};
            fi
        fi
        if [[ -z "$P21" ]]; then _P21=""; else _P21=${P21}; fi
        if [[ -z "$P22" ]]; then _P22=""; else _P22=${P22}; fi
        if [[ -z "$P31" ]]; then _P31=${len}; else _P31=${P31}; fi
        if [[ -z "$P32" ]]; then _P32=""; else _P32=${P32}; fi
        # echo "$EXE $alg -l $len -s $RANDOM -r $REPEAT -t $MAXTIME -A $GEN1 -B $GEN2 -C $GEN3 -X $P1 -m $MOD -Y $P21 -Q $P22 -W $P31 -Z $P32"; exit 0;

		$EXE $alg -l $len -s $RANDOM -r $REPEAT -t $MAXTIME -A $GEN1 -B $GEN2 -C $GEN3 -X $_P1 -m $_MOD -Y $_P21 -Q $_P22 -W $_P31 -Z $_P32 # -v
		if     (( len < 10000)); then step=1000
		elif  (( len < 100000)); then step=10000
		elif (( len < 1000000)); then step=100000
		else                          step=1000000
		fi
		(( len += step ))
	done
}

ID="$SIZE"-"$GEN1"-"$P1"-"$MOD"-"$GEN2"-"$P21"-"$P22"-"$GEN3""$P31"-"$P32"-r"$REPEAT"-"t$MAXTIME"
repdir="$OUT/TR1-$ID"
mkdir -p "$repdir"

algs="QuicksortLomuto"
#algs=$(echo Quicksort{Lomuto,LomutoMoves})
#algs=$(echo Quicksort{Hoare,Hoare1,Wirth})
#algs=$(echo Quicksort{Sedgewick,SedgewickMoves,SedgewickSentinels})
#algs=$(echo Quicksort{Sin,SinSentinels})
#algs=$(echo Quicksort{YaroSimple,Yaro})
#algs=$(echo Quicksort3Pivot{0,1,2,3})

algs=$(echo Quicksort{Lomuto,LomutoMoves,Hoare,Hoare1,Wirth,Sedgewick,SedgewickMoves,SedgewickSentinels,Sin,SinSentinels,YaroSimple,Yaro,3Pivot0,3Pivot1,3Pivot2,3Pivot3})


echo "Test platform: $HOST"
echo "Test scenario: $(basename $repdir)"
for alg in $algs; do
	reportfile="$repdir/$alg.csv"
	echo -n "$(basename $reportfile) ... "
	test -f "$reportfile" && echo 'skipped' && continue || echo 'testing'
	do_one $alg | tee "$reportfile"
done
