CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb

all: bin/main #bin/teste

clean:
	del /S "\bin\*.o"

main: bin/main
	clear
	./bin/main

teste: bin/teste
	clear
	./bin/teste

bin/busca.o: src/Busca.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/indiceInvertido.o: src/IndiceInvertido.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/documento.o: src/Documento.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/vetor.o: src/Vetor.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/util.o: src/Util.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/main: bin/busca.o bin/util.o bin/documento.o bin/indiceInvertido.o bin/documento.o bin/vetor.o src/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/teste: bin/util.o src/teste/teste.cpp src/teste/teste_util.cpp
	$(CXX) $(CXX_FLAGS) -I include/ -I src/ $^ -o $@