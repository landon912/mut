#Landon Kirk 2019

CXX=clang++ $(CXXFLAGS)
DEBUG=-Wall -g -fstandalone-debug
FINAL=-O2

.SUFFIXES: .o .cpp

OFILES = mut.o objs/rect.o objs/matrix/matrix2x2.o objs/matrix/matrix4x4.o objs/vector/vector2.o \
	objs/vector/vector3.o objs/vector/vector4.o

mut: $(OFILES)
	@ mkdir -p bin
	$(CXX) $(FINAL) $(OFILES) -o ./bin/mutTest.out

debugMut: $(OFILES)
	@ mkdir -p bin
	$(CXX) $(DEBUG) $(OFILES) -o ./bin/mutTest.out

clean:
	find . -type f -name '*.o' -delete