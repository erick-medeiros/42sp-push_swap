#!/bin/bash/
ARG=$(ruby -e "puts (0..500).to_a.shuffle.join(' ')")
echo $ARG > arg.log
./push_swap $ARG > log.log
cat log.log | ./test/checker_linux $ARG
cat log.log | wc -l