CC = gcc
CFLAGS = -Wall -Wextra -Isrc -IUnity/src
SRC = src/utility.c
UNITY = Unity/src/unity.c

# Build the actual program
utility: src/main.c $(SRC)
	$(CC) $(CFLAGS) -o utility src/main.c $(SRC)

# Build and run the tests
test: tests/test_utility.c $(SRC) $(UNITY)
	$(CC) $(CFLAGS) -o test_utility tests/test_utility.c $(SRC) $(UNITY)
	./test_utility

# Clean build artifacts
clean:
	rm -f utility test_utility
