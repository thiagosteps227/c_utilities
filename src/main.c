#include <stdio.h>
#include <string.h>
#include "utility.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
  {
    printf("Usage:\n");
    printf("  %s cat <files...>\n", argv[0]);
    printf("  %s search <filename> <pattern>\n", argv[0]);
    return 1;
  }

  if (strcmp(argv[1], "cat") == 0)
  {
    if (argc < 3)
    {
      printf("Usage: %s cat filename1 [filename2 ...]\n", argv[0]);
      return 1;
    }

    for (int i = 2; i < argc; ++i)
    {
      if (strcmp(argv[i], "-") == 0)
      {
        write_to_file(argv[++i]);
      }
      else if (i + 1 < argc && strcmp(argv[i + 1], "-") == 0)
      {
        concatenate_files(argv[i], argv[i + 2]);
        i += 2;
      }
      else
      {
        printf("%s:\n", argv[i]);
        print_file(argv[i]);
        printf("\n");
      }
    }
  }
  else if (strcmp(argv[1], "search") == 0)
  {
    if (argc != 4)
    {
      printf("Usage: %s search <filename> <pattern>\n", argv[0]);
      return 1;
    }
    search_pattern_in_file(argv[2], argv[3]);
  }
  else
  {
    printf("Unknown command: %s\n", argv[1]);
    printf("Usage:\n");
    printf("  %s cat <files...>\n", argv[0]);
    printf("  %s search <filename> <pattern>\n", argv[0]);
    return 1;
  }

  return 0;
}
