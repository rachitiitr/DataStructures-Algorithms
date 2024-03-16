#!/bin/bash

# Get the root directory of the Git repository
GIT_ROOT=$(git rev-parse --show-toplevel)

function enter() {
    mkdir -p $GIT_ROOT/CodeforcesContestRunner;
    cd $GIT_ROOT/CodeforcesContestRunner;
    cp $GIT_ROOT/Library/Miscellanious/template2024.cpp a.cpp
    cp $GIT_ROOT/Library/Miscellanious/template2024.cpp b.cpp
    cp $GIT_ROOT/Library/Miscellanious/template2024.cpp c.cpp
    cp $GIT_ROOT/Library/Miscellanious/template2024.cpp d.cpp
    cp $GIT_ROOT/Library/Miscellanious/template2024.cpp e.cpp
    echo '' > in.txt
}

function build() {
    problem=$1
    g++ -std=c++20 $problem.cpp -o run_$problem -isystem $GIT_ROOT/Library/Utils
}

function run() {
    problem=$1
    ./run_$problem
}

function runtxt() {
    problem=$1
    ./run_$problem < in.txt
}