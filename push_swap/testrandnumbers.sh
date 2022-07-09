#!/bin/bash

ARG=$(seq -3000 3000 | sort -R | tail -n 5000)
#ARG="2 1 0"
echo $ARG
./push_swap $ARG | ./checker $ARG
#./push_swap $ARG | wc -l