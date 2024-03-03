rootdir = $(realpath .)

CXX = g++

FRAMEWORKS = -framework SDL2 -framework SDL2_image
LC_RPATH = -Wl,-rpath,$(rootdir)/frameworks

CXXFLAGS = -Wall -F $(rootdir)/frameworks
LDFLAGS = $(FRAMEWORKS) -F $(rootdir)/frameworks $(LC_RPATH)

run: all
	./main

all: main

main: main.o
	$(CXX) main.o -o main $(LDFLAGS)

main.o:
	$(CXX) $(CXXFLAGS) -c ./src/main.cpp -o main.o

clean:
	rm main.o main
