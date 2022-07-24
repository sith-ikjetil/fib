#!/bin/bash
#: Title       : build-release.sh
#: Date        : 2022-07-24
#: Author      : Kjetil Kristoffer Solberg <post@ikjetil.no>
#: Version     : 1.0
#: Description : Builds fib.
echo "Building fib ..."
echo "> using release build < "

g++ fib.cpp --std=c++17 -o fib
if [[ $? -eq 0 ]]
then
    echo "> fib build ok"
else
    echo "> fib build error"
fi

echo "> build process complete <"


