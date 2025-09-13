# C Utililties Program with Unity Tests

This project is a simple re-implementation of the Unix `cat` and `grep` command in C.  
It also includes **unit tests** written with the [Unity Test Framework](https://github.com/ThrowTheSwitch/Unity).

---

## Run you Cat command

### Read a file

```sh
gcc utility.c -o utility # compiles the C program in utility.c and outputs the resulting executable to a file named utility

cat file1.txt  # create a file named file1.txt and this is how you need to run you command
```

### Read more than one file

```sh
gcc cat.c -o cat  

./utility file1 file2 ....
```

### Write to a file

```sh
gcc cat.c -o cat
./utility - file.txt # run this command, and following type a text, then the text you type will be saved to your file called file.txt
```
### Concatenates two files

```sh
gcc utility.c -o utility
./utility dest_file.txt - source_file.txt # run this command, and text in source_file.txt will be added to dest_file.txt
```

### Search pattern in a file (grep)

```sh
make utility

# create a file in the root and name it file.txt
# type any string in the file.txt - in this directory we have 'find the pattern in this file using my search command' 
# written in the file

./utility search file.txt pattern # and it should work
 
---

## Building

From the project root, run:

### Build the program
```sh
make utility
```

This creates an executable cat.
Run it with:

```bash
./utility somefile.txt
```
---

### Run the tests
```sh
make test
```

This builds the test runner (test_utility) and executes the unit tests.
Example output:

test_utility.c:28:test_print_file_with_existing_file:PASS
test_utility.c:43:test_print_file_with_nonexistent_file:PASS

-----------------------
2 Tests 0 Failures 0 Ignored
OK

### Clean build artifacts
```sh
make clean

```
Removes the utility and test_utility executables.

