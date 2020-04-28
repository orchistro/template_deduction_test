.PHONY: all clean

all: foo

SRCS := $(shell find . -name '*.cpp')
OBJS := $(SRCS:.cpp=.o)

foo: $(OBJS)
	$(CXX) -o $@ $^ -lstdc++ -Wall -Werror

%.o: %.cpp
	$(CXX) -std=c++17 -c -g -O0 -Wall -o $@ $<

clean:
	rm -rf foo *.o

