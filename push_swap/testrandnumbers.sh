#!/bin/bash

ARG=$(seq -300 300 | sort -R | tail -n 500)
#ARG="2 1 0"
echo $ARG
./push_swap $ARG | ./checker $ARG
#./push_swap $ARG | wc -l