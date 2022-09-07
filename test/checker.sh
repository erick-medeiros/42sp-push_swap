#!/bin/bash/
ARG=$(ruby -e "puts (0..500).to_a.shuffle.join(' ')")
./push_swap $ARG | ./test/checker_linux $ARG