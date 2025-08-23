CC = gcc
CFLAGS = -Wall -Wextra -Isrc -IUnity/src
SRC = src/cat.c
UNITY = Unity/src/unity.c

# Build the actual program
cat: src/main.c $(SRC)
	$(CC) $(CFLAGS) -o cat src/main.c $(SRC)

# Build and run the tests
test: tests/test_cat.c $(SRC) $(UNITY)
	$(CC) $(CFLAGS) -o test_cat tests/test_cat.c $(SRC) $(UNITY)
	./test_cat

# Clean build artifacts
clean:
	rm -f cat test_cat
