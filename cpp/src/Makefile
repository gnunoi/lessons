MAKEFLAGS = --keep-going
CXX = clang++
CXXFLAGS = -Wall -Wextra
SRCS = $(wildcard *.cpp)
EXECUTABLES = $(SRCS:.cpp=)
DSYM = $(SRCS:.cpp=.dSYM)

.PHONY: all clean c

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	rm -f $(EXECUTABLES)
	rm -rf $(DSYM)

c:clean

