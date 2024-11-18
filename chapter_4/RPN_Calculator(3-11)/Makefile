CC = gcc
CFLAGS = -Wall -g
LDFLAGS = -lm
TARGET = calc
SOURCES = main.c getop.c getch.c stack.c
OBJECTS = $(SOURCES:.c=.o)

all: $(TARGET) clean-objects

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean-objects:
	rm -f $(OBJECTS)
clean:
	rm -f $(TARGET) $(OBJECTS)
