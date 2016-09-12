#!/usr/bin/env bash
echo "Compiling unit tests..."

#! Current folder test/
cmake -B../build/ -H../

make -C ../build/

echo "Running uni tests..."
../build/dstructs-test
result=$?
ls
echo "Unit tests exit code: $result"

if [ $1 ]
then
    if [ $1 == "--delete-build" ]
    then
        rm -r ../build/*
    fi
fi

exit $result