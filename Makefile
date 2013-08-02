CXXC = g++
CFLAGS = -Wall -O3 

EXE=Solution1 Solution2 Solution3 Solution4

all: $(EXE)

Solution1: Problem1.cpp Problem.h
  $(CXXC) $(CFLAGS) Problem1.cpp -o Solution1 -lm
Solution2: Problem2.cpp Problem.h
	$(CXXC) $(CFLAGS) Problem2.cpp -o Solution2 -lm
Solution3: Problem3.cpp Problem.h
	$(CXXC) $(CFLAGS) Problem3.cpp -o Solution3 -lm
Solution4: Problem4.cpp Problem.h
	$(CXXC) $(CFLAGS) Problem4.cpp -o Solution4 -lm

clean:
	rm -f *~ *.o $(EXE)
