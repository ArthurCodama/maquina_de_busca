CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++14 -ggdb

all: bin/main

clear:
	rm -rf bin/*.o

teste: bin/teste
	./bin/teste
#/////////////////////////////////////////////////
#				Buscador
#/////////////////////////////////////////////////
bin/busca.o: bin/indiceInvertido.o bin/vetor.o src/Busca.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/indiceInvertido.o: bin/documento.o src/IndiceInvertido.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/documento.o: src/Documento.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/vetor.o: bin/documento.o src/Vetor.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/util.o: bin/documento.o src/Util.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/main: bin/busca.o bin/util.o bin/documento.o bin/indiceInvertido.o bin/documento.o bin/vetor.o src/main.cpp
	$(CXX) $(CXX_FLAGS) $^ -o $@

#/////////////////////////////////////////////////
#				Teste
#/////////////////////////////////////////////////
bin/busca_teste.o: bin/busca.o src/Busca.teste.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/indiceInvertido_teste.o: bin/indiceInvertido.o src/IndiceInvertido.teste.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

bin/documento_teste.o: bin/documento.o src/Documento.teste.cpp
	$(CXX) $(CXX_FLAGS) -c $^ -o $@

#bin/teste: bin/documento_teste.o bin/indiceInvertido_teste.o bin/busca_teste.o
#	$(CXX) $(CXX_FLAGS) -I include/ -I $^ -o $@