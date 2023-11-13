#!/bin/bash

g++ bad.cpp -o bad.exe
g++ ok.cpp -o ok.exe

# for i in $(seq 1 5)
# do
#     echo "====== Test Case ${i} ======"
#     cp hello${i}.in hello.in
#     ./a.out
#     cat hello.out
# done

for T in $(seq 1 100)
do
    echo Testcase $T
    # ./gen
    echo "100 200" > in.txt

    diff -q \
        <(timeout 1 ./ok.exe < in.txt) \
        <(timeout 1 ./bad.exe < in.txt)
    if [[ $? != 0 ]]
    then
        echo 'Error!'
        cp in.txt error-$T.txt
    fi
done