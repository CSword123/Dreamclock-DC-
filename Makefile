TARGET = dreamClock

CC = gcc
SRC = dreamClock.c sprite.c logic.c
CFLAGS = -g -std=c2x -Wall -Werror
LDFLAGS = -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

all:
	$(CC) $(SRC) -o $(TARGET) $(CFLAGS) $(LDFLAGS)
clean:
	rm $(TARGET)
run:
	./$(TARGET)
