CC = gcc
CFLAGS = -Wall -Wextra
TARGET = storage

all: $(TARGET)

$(TARGET): storage.c
	$(CC) $(CFLAGS) -o $(TARGET) storage.c

clean:
	rm -f $(TARGET) data.json

.PHONY: all clean 