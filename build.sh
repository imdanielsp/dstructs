#!/usr/bin/env bash

if [ $1 ]
then
    if [ $1 == "--build-tests" ]
    then
        echo "Building tests..."
        cmake -B./build/ -H.
        echo "Compiling tests..."
        make -C ./build/
        ./build/dstructs-test
        result=$?
    fi
else
    echo "No argument provided"
    exit 1
fi

if [ $2 ]
then
    if [ $2 == "--delete-build" ]
    then
        rm -r ./build/*
    else
        echo "Invalid argument for deletion"
    fi
fi
