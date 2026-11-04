#!/bin/sh
# Test eqntott and compare output

# Simple AND case
../src/eqntott and.eqn > and-1.pla
git diff --no-index expected/and-1.pla and-1.pla

# -l argument
../src/eqntott -l and.eqn > and-2.pla
git diff --no-index expected/and-2.pla and-2.pla

# -.S argument
../src/eqntott -.S and.eqn > and-3.pla
git diff --no-index expected/and-3.pla and-3.pla

# Half adder example
../src/eqntott -l half_adder.eqn > half_adder-1.pla
git diff --no-index expected/half_adder-1.pla  half_adder-1.pla

# key argument test
../src/eqntott -.lhptv half_adder.eqn > half_adder-2.pla 2>&1
git diff --no-index expected/half_adder-2.pla half_adder-2.pla

# -s argument
../src/eqntott -l -s s.eqn > s.pla
git diff --no-index expected/s.pla s.pla

# -f argument
../src/eqntott -l -f f.eqn > f.pla
git diff --no-index expected/f.pla f.pla

# No reduction
../src/eqntott -l reduce.eqn > reduce-1.pla
git diff --no-index expected/reduce-1.pla reduce-1.pla

# -r argument
../src/eqntott -l -r reduce.eqn > reduce-2.pla
git diff --no-index expected/reduce-2.pla reduce-2.pla

# Test C preprocessor
../src/eqntott -l xor.eqn > xor.pla
git diff --no-index expected/xor.pla xor.pla

# Test C preprocessor
../src/eqntott -l odd_parity_bit.eqn > odd_parity_bit.pla
git diff --no-index expected/odd_parity_bit.pla odd_parity_bit.pla

# 74181 ALU examples
time ../src/eqntott -l -s ALU74181.eqn > ALU74181.pla
git diff --no-index expected/ALU74181.pla ALU74181.pla

time ../src/eqntott -l -s -r ALU74181.eqn > ALU74181-r.pla
git diff --no-index expected/ALU74181-r.pla ALU74181-r.pla

time ../src/eqntott -l -s ALU74181_internal_PG.eqn > ALU74181_internal_PG.pla
git diff --no-index expected/ALU74181_internal_PG.pla ALU74181_internal_PG.pla

time ../src/eqntott -l -s -r ALU74181_internal_PG.eqn > ALU74181_internal_PG-r.pla
git diff --no-index expected/ALU74181_internal_PG-r.pla ALU74181_internal_PG-r.pla

time ../src/eqntott -l -r ALU74181_part_1.eqn > ALU74181_part_1.pla
git diff --no-index expected/ALU74181_part_1.pla ALU74181_part_1.pla

time ../src/eqntott -l -s -r ALU74181_part_2.eqn > ALU74181_part_2.pla
git diff --no-index expected/ALU74181_part_2.pla ALU74181_part_2.pla
