#Landon Kirk 2019

CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g -fstandalone-debug
FINAL=-O2

mut: mut.h mut.cpp
	@ mkdir -p bin
	$(CXX) $(FINAL) mut.cpp -o ./bin/mutTest.out

debugMut: mut.h mut.cpp
	@ mkdir -p bin
	$(CXX) $(DEBUG) mut.cpp -o ./bin/mutTest.out