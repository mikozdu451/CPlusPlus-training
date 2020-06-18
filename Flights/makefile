kompilator=g++
standard=-std=c++14
optymalizacja=-O3
errors=-pedantic-errors

debug=-g
#debug=

__ : main
	./main -t flights.txt
	./main -t flights.white
	./main -t flights.wrong
	./main -t flights.empty
	
	./main -t 


	valgrind --leak-check=yes ./main -t flights.txt

functions.o : functions.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^
main.o : main.cpp
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -c -o $@ $^

main : functions.o main.o 
	$(kompilator) $(standard) $(debug) $(optymalizacja) $(errors) -o $@ $^

