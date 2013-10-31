@echo off
gcc -o main.exe main.c diff.c
main.exe "test.txt" "test2.txt"
pause