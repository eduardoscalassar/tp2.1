# Define um timestamp que será usado por todos os alvos nesta execução
TIMESTAMP := $(shell date +'%Y%m%d_%H%M%S')

all: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	./testa_velha

compile: testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha

velha.o : velha.cpp velha.hpp
	g++ -std=c++11 -Wall -c velha.cpp
	
testa_velha:    testa_velha.cpp   velha.cpp velha.hpp velha.o
	g++ -std=c++11 -Wall velha.o testa_velha.cpp -o testa_velha
	
test: testa_velha   
	./testa_velha
	
cpplint: testa_velha.cpp   velha.cpp velha.hpp
	# Redireciona a saída de erro (2>) para um arquivo de relatório com timestamp
	cpplint --exclude=catch.hpp *.* 2> cpplint_report_$(TIMESTAMP).log
	
gcov: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage -c velha.cpp
	g++ -std=c++11 -Wall -fprofile-arcs -ftest-coverage velha.o testa_velha.cpp -o testa_velha
	./testa_velha
	# Redireciona a saída padrão (>) do resumo para um arquivo de relatório
	gcov *.cpp > gcov_report_$(TIMESTAMP).log
	 
debug: testa_velha.cpp   velha.cpp velha.hpp 
	g++ -std=c++11 -Wall -g -c velha.cpp
	g++ -std=c++11 -Wall  -g velha.o testa_velha.cpp -o testa_velha
	gdb testa_velha
	
cppcheck: testa_velha.cpp   velha.cpp velha.hpp
	# Redireciona a saída de erro (2>) para um arquivo de relatório com timestamp
	cppcheck --enable=warning . 2> cppcheck_report_$(TIMESTAMP).log

valgrind: testa_velha
	valgrind --leak-check=yes --log-file=valgrind.rpt testa_velha

clean:
	rm -rf *.o *.exe *.gc* testa_velha 

commit_tests: testa_velha
	$(eval TIMESTAMP = $(shell date +'%Y%m%d_%H%M%S'))
	$(eval LOG_FILE = test_results_$(TIMESTAMP).log)
	-./testa_velha > $(LOG_FILE)
	git add $(LOG_FILE)
	git commit -m "chore: Add test results from $(TIMESTAMP)"
	git push