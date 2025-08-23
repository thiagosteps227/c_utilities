#include <stdio.h>
#include <string.h>
#include "cat.h" // include the declaration of print_file

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    // Print usage information if no filenames are
    // provided
    printf("Usage: %s filename1 [filename2 ...]\n",
           argv[0]);
    return 1;
  }

  for (int i = 1; i < argc; ++i)
  {
    if (strcmp(argv[i], "-") == 0)
    {
      // If the argument is "-", write to the
      // specified file
      write_to_file(argv[++i]);
    }
    else if (i + 1 < argc && strcmp(argv[i + 1], "-") == 0)
    {
      // If the next argument is "-", concatenate the
      // two specified files
      concatenate_files(argv[i], argv[i + 2]);
      i += 2;
    }
    else
    {
      // Print the contents of the file
      printf("%s :\n", argv[i]);
      print_file(argv[i]);
      printf("\n");
    }
  }
  return 0;
}