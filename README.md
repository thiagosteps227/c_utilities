# C Cat Program with Unity Tests

This project is a simple re-implementation of the Unix `cat` command in C.  
It also includes **unit tests** written with the [Unity Test Framework](https://github.com/ThrowTheSwitch/Unity).

---

## Project Structure

project/
│
├─ Makefile # build instructions
│
├─ src/
│ ├─ cat.c # print_file() implementation
│ ├─ cat.h # header file
│ └─ main.c # program entry point
│
├─ tests/
│ └─ test_cat.c # Unity test cases
│
└─ Unity/
└─ src/ # Unity framework source files
├─ unity.c
├─ unity.h
└─ unity_internals.h

 
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
