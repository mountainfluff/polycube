# Define the compiler and the target executable
CC = gcc
TARGET = cube

# Rule to build the target executable
$(TARGET): main.o
	$(CC) main.o -o $(TARGET) -lGL -lglut -lGLU

# Rule to build the object file
main.o: main.c
	$(CC) -c main.c

# Rule to clean up the build files
clean:
	rm -f $(TARGET) main.o
