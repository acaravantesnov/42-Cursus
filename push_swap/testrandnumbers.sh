#!/bin/bash

ARG=$(seq -300 300 | sort -R | tail -n 5)
echo $ARG
#./push_swap $ARG | ./checker $ARG
./push_swap $ARG | wc -l