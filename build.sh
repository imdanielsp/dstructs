#!/usr/bin/env bash

if [ $1 ]
then
    if [ $1 == "run-tests" ]
    then
        echo "Building tests..."
        cd ./test/
        cmake -B./build/ -H.
        echo "Compiling tests..."
        make -C ./build/
        ./build/dstructs-test
        result=$?
    fi
    if [ $1 == "build" ]
    then
	echo "Building main..."
	cd ./src/
	cmake -B./build/ -H.
	echo "Compiling..."
	make -C ./build/
	result=$?
    fi
	if [ $1 == "clean" ]
    then
        rm -r ./src/build/*
        rm -r ./test/build/*
    fi
fi
