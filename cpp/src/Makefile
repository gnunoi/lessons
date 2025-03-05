MAKEFLAGS = --keep-going
CXX = clang++
CXXFLAGS = -Wall -Wextra
SRCS = $(wildcard *.cpp)
EXECUTABLES = $(SRCS:.cpp=)
EXE = $(SRCS:.cpp=.exe)
DSYM = $(SRCS:.cpp=.dSYM)

.PHONY: all clean c

all: $(EXECUTABLES)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	@rm -f $(EXECUTABLES) $(EXE)
	@rm -rf $(DSYM)

c:clean

