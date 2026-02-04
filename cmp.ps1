mkdir .\build
mkdir .\run
gcc -c parser.c -o build\parser.o
g++ main.cpp build\parser.o -o .\run\parser.exe