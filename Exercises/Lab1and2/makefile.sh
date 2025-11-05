#!/bin/bash

#Makefile that compiles AnalyseData with the CustomFunctions files
#runs the exectuble and deletes it after it has run

g++ -w AnalyseData.cpp CustomFunctions.cpp -o run

./run

rm run