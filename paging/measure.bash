#!/bin/bash

set -ue

if [ ! -e ./plb ]; then
    echo "No plb file" >&2
    exit 1
fi

if [ -e ./log ]; then
    mv ./log ./log.bak
fi

# for numpage in $(seq 0 10 1000);do
for numpage in $(seq 1 10 | awk '{print 2 ^ $i}');do
    ./plb $numpage >> log
done
