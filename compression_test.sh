#!/bin/bash
cd tests
for file in $(ls)
do
    ../antman/antman $file 2 > comp
    ../giantman/giantman comp 2 > decomp
    echo -ne "\e[31m$(diff -q $file decomp)"
done
rm comp decomp
echo -ne "\e[39m\nOK\n"
