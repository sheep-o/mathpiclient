CC := g++
CFLAGS := -Wall -std=c++20
TARGET := client

LIBPATHS :=
LIBS := 

SRCS := $(wildcard *.cpp)
OBJS := $(patsubst %.cpp, %.o, $(SRCS))

all: $(TARGET)
$(TARGET): $(OBJS)
	$(CC) $(LIBPATHS) $(LIBS) $(shell pkg-config --libs opencv4) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) $(shell pkg-config --cflags opencv4) -c $<
clean:
	rm -rf $(TARGET) *.o
all: run
run: $(TARGET)
	./$(TARGET)
