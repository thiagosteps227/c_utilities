#include "unity.h"
#include "cat.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Helper to capture stdout
static char *capture_stdout(const char *filename)
{
  FILE *original_stdout = stdout;
  FILE *temp = tmpfile();
  if (!temp)
    return NULL;
  stdout = temp;

  print_file(filename);

  fflush(temp);
  stdout = original_stdout;

  fseek(temp, 0, SEEK_END);
  long size = ftell(temp);
  fseek(temp, 0, SEEK_SET);

  char *buffer = malloc(size + 1);
  fread(buffer, 1, size, temp);
  buffer[size] = '\0';
  fclose(temp);

  return buffer;
}

void setUp(void) {}
void tearDown(void) {}

void test_print_file_with_existing_file(void)
{
  const char *filename = "test_input.txt";
  FILE *f = fopen(filename, "w");
  fputs("Hello, world!\n", f);
  fclose(f);

  char *output = capture_stdout(filename);
  TEST_ASSERT_NOT_NULL(output);
  TEST_ASSERT_EQUAL_STRING("Hello, world!\n", output);

  free(output);
  remove(filename);
}

void test_print_file_with_more_than_one_file(void)
{
  const char *filename_1 = "test_input1.txt";
  FILE *f_1 = fopen(filename_1, "w");
  fputs("Hello, world once!\n", f_1);
  fclose(f_1);

  const char *filename_2 = "test_input2.txt";
  FILE *f_2 = fopen(filename_2, "w");
  fputs("Hello, world twice!\n", f_2);
  fclose(f_2);

  char *output_once = capture_stdout(filename_1);
  TEST_ASSERT_NOT_NULL(output_once);
  TEST_ASSERT_EQUAL_STRING("Hello, world once!\n", output_once);

  char *output_twice = capture_stdout(filename_2);
  TEST_ASSERT_NOT_NULL(output_twice);
  TEST_ASSERT_EQUAL_STRING("Hello, world twice!\n", output_twice);

  free(output_once);
  free(output_twice);
  remove(filename_1);
  remove(filename_2);
}

void test_print_file_with_nonexistent_file(void)
{
  char *output = capture_stdout("no_such_file.txt");

  char expected[128];
  snprintf(expected, sizeof(expected), "Unable to open file %s \n", "no_such_file.txt");
  TEST_ASSERT_EQUAL_STRING(expected, output);

  free(output);
}

// 🆕 New Test for write_to_file
void test_write_to_file_should_create_and_write_file(void)
{
  const char *outfile = "test_written.txt";

  // Prepare fake stdin data
  FILE *temp_in = fopen("temp_stdin.txt", "w");
  fputs("Line1\nLine2\n", temp_in);
  fclose(temp_in);

  // Redirect stdin to read from our temp file
  freopen("temp_stdin.txt", "r", stdin);

  // Call function under test
  write_to_file(outfile);

  // Restore stdin
#ifdef _WIN32
  freopen("CON", "r", stdin);
#else
  freopen("/dev/tty", "r", stdin);
#endif

  // Verify file contents
  FILE *check = fopen(outfile, "r");
  TEST_ASSERT_NOT_NULL(check);

  char buffer[256] = {0};
  fread(buffer, 1, sizeof(buffer) - 1, check);
  fclose(check);

  TEST_ASSERT_EQUAL_STRING("Line1\nLine2\n", buffer);

  // Clean up
  remove(outfile);
  remove("temp_stdin.txt");
}

void test_concatenate_files(void)
{
  const char *filename1 = "test_concat1.txt";
  const char *filename2 = "test_concat2.txt";

  // Create first file with some text
  FILE *f1 = fopen(filename1, "w");
  fputs("Hello, ", f1);
  fclose(f1);

  // Create second file with some text
  FILE *f2 = fopen(filename2, "w");
  fputs("world!\n", f2);
  fclose(f2);

  // Call function under test
  concatenate_files(filename1, filename2);

  // Read back file1 and check contents
  FILE *check = fopen(filename1, "r");
  TEST_ASSERT_NOT_NULL(check);

  char buffer[256];
  size_t bytes = fread(buffer, 1, sizeof(buffer) - 1, check);
  buffer[bytes] = '\0';
  fclose(check);

  // Verify concatenated content
  TEST_ASSERT_EQUAL_STRING("Hello, world!\n", buffer);

  // Clean up
  remove(filename1);
  remove(filename2);
}

int main(void)
{
  UNITY_BEGIN();
  RUN_TEST(test_print_file_with_existing_file);
  RUN_TEST(test_print_file_with_more_than_one_file);
  RUN_TEST(test_print_file_with_nonexistent_file);
  RUN_TEST(test_write_to_file_should_create_and_write_file);
  RUN_TEST(test_concatenate_files);
  return UNITY_END();
}
