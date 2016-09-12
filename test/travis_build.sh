#!/usr/bin/env bash
echo "Compiling unit tests..."

#! Current folder test/
cmake -B/home/travis/build/dsantosp12/build/ -H/home/travis/build/dsantosp12/

make -C /home/travis/build/dsantosp12/build/

echo "Running uni tests..."
/home/travis/build/dsantosp12/build/dstructs-test
result=$?

echo "Unit tests exit code: $result"

if [ $1 ]
then
    if [ $1 == "--delete-build" ]
    then
        rm -r ../build/*
    fi
fi

exit $result