OBJDIR=objs

# Compile for CPU
cpu: CXX = g++ -m64 -std=c++11
cpu: CXXFLAGS = -I. -O3 -Wall -fopenmp -Wno-unknown-pragmas

.PHONY: clean

clean:
		/bin/rm -rf $(OBJDIR) *~
