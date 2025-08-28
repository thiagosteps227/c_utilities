# C Cat Program with Unity Tests

This project is a simple re-implementation of the Unix `cat` command in C.  
It also includes **unit tests** written with the [Unity Test Framework](https://github.com/ThrowTheSwitch/Unity).

---

## Run you Cat command

### Read a file

```sh
gcc cat.c -o cat  # compiles the C program in cat.c and outputs the resulting executable to a file named cat

cat file1.txt  # create a file named file1.txt and this is how you need to run you command
```

### Read more than one file

```sh
gcc cat.c -o cat  

./cat file1 file2 ....
```

### Write to a file

```sh
gcc cat.c -o cat
./cat - file.txt # run this command, and following type a text, then the text you type will be saved to your file called file.txt
```
### Concatenates two files

```sh
gcc cat.c -o cat
./cat dest_file.txt - source_file.txt # run this command, and text in source_file.txt will be added to dest_file.txt
```
 
---

## Building

From the project root, run:

### Build the program
```sh
make cat
```

This creates an executable cat.
Run it with:

```bash
./cat somefile.txt
```
---

### Run the tests
```sh
make test
```

This builds the test runner (test_cat) and executes the unit tests.
Example output:

test_cat.c:28:test_print_file_with_existing_file:PASS
test_cat.c:43:test_print_file_with_nonexistent_file:PASS

-----------------------
2 Tests 0 Failures 0 Ignored
OK

### Clean build artifacts
```sh
make clean

```
Removes the cat and test_cat executables.

