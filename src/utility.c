#include <stdio.h>
#include <string.h>
#include "utility.h"

void print_file(const char* filename)
{
  FILE *file = fopen(filename, "r");
  if (file == NULL)
  {
    printf("Unable to open file %s \n", filename);
    return;
  }

  int ch; // should be int (not char) to safely compare with EOF
  while ((ch = fgetc(file)) != EOF)
  {
    putchar(ch);
  }

  fclose(file);
}

void write_to_file(const char* filename)
{
  FILE *file = fopen(filename, "w");
  if (file == NULL)
  {
    perror("fopen"); // prints the system error message
    printf("Unable to open file %s\n", filename);
    return;
  }

  int ch; // or char ch;
  while ((ch = getchar()) != EOF)
  {
    fputc(ch, file);
  }

  fclose(file);
}

void concatenate_files(const char* filename1, const char* filename2)
{
  FILE *file1 = fopen(filename1, "r+");
  if (file1 == NULL)
  {
    printf("Unable to open file %s\n", filename1);
    return;
  }

  FILE *file2 = fopen(filename2, "r");
  if (file2 == NULL)
  {
    printf("Unable to open file %s\n", filename2);
    fclose(file1);
    return;
  }

  // Move file pointer to the end of the first file
  fseek(file1, 0, SEEK_END);

  int ch;
  while ((ch = fgetc(file2)) != EOF)
  {
    fputc(ch, file1);
  }

  fclose(file1);
  fclose(file2);
}

void search_pattern_in_file(const char *filename, const char *pattern)
{
  FILE *fp = fopen(filename, "r");
  if (!fp)
  {
    perror("Error opening file");
    return;
  }

  char line[256];
  while (fgets(line, sizeof(line), fp))
  {
    // Print lines containing the pattern (like grep)
    if (strstr(line, pattern))
      printf("%s", line);
  }
  fclose(fp);
}