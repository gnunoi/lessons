MAKEFLAGS = --keep-going
CXX = clang++
CXXFLAGS = -Wall -Wextra
SRCS = $(wildcard *.cpp)
EXE_UNIX = $(SRCS:.cpp=)
EXE_WINDOWS = $(SRCS:.cpp=.exe)
DSYM = $(SRCS:.cpp=.dSYM)

.PHONY: all clean c

all: $(EXE_UNIX)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

clean:
	@rm -f $(EXE_UNIX) $(EXE_WINDOWS)
	@rm -rf $(DSYM)

c:clean

