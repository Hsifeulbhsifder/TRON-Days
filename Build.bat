@echo off

set SRC=TwoAxis6d

g++ -std=gnu++11 %SRC%.cpp -o %SRC% -g -Wall

rem Call %SRC%