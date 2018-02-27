#!/bin/bash

../bench/bench.sh tiny G1Saw G2Id G3RandPerm 1 "" 0 0 0 0           # Random
../bench/bench.sh tiny G1Saw G2Id G3RandPerm 1 "0.15" 0 0 0 0       # Duplicates (85% of the same elements)
../bench/bench.sh tiny G1Saw G2Id G3Swap 1 "" 0 0 "0.01" 0          # Almost sorted (0.01 * n swaps)
