CC = g++
CFLAGS = -std=c++11 -Wall

SRCS = museum.cpp
OBJS = $(SRCS:*.cpp=.o)
TARGET = museum

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f $(OBJS) $(TARGET)

