CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra

all: examheap

examheap: examheap.cpp heap.cpp
	$(CXX) $(CXXFLAGS) examheap.cpp heap.cpp -o examheap

clean:
	rm -f examheap
