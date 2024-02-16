# Name of the executable file
TARGET = megaphone

# Compiler to use
CC = g++

# Compilation flags
CFLAGS = -Wall -Werror -Wextra -std=c++98

# Default command
all: $(TARGET)

# Rule to build the target
$(TARGET): $(TARGET).cpp
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).cpp

# Command to clean compiled files
clean:
	rm -f $(TARGET)

