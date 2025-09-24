all: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	#use comentario se necessario

compile: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp
	
testa_velha: 	testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	
test: testa_velha	
	./testa_velha
	
cpplint: testa_velha.cpp   velha.cpp velha.hpp
	cpplint   --exclude=catch.hpp  *.*
	
gcov: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	gcov *.cpp	
	 
debug: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -g -c velha.cpp
	g++ -std=c++11 -Wall  -g velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha
	
	
cppcheck: testa_velha.cpp   velha.cpp velha.hpp
	cppcheck  --enable=warning .

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_velha


clean:
	rm -rf *.o *.exe *.gc* testa_velha 

commit_tests: testa_velha
	# 1. Create a variable with the current timestamp (e.g., 20250924_112723)
	$(eval TIMESTAMP = $(shell date +'%Y%m%d_%H%M%S'))
	# 2. Define the log filename using the timestamp
	$(eval LOG_FILE = test_results_$(TIMESTAMP).log)
	# 3. Run tests, creating a uniquely named log file (e.g., test_results_20250924_112723.log)
	-./testa_velha > $(LOG_FILE)
	# 4. Add the new, specific log file to Git
	git add $(LOG_FILE)
 
	
	
