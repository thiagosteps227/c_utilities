#ifndef UTILITY_H
#define UTILITY_H

// Expose only the function(s) you want to test
void print_file(const char* filename);
void write_to_file(const char* filename);
void concatenate_files(const char* filename1, const char* filename2);
void search_pattern_in_file(const char *filename, const char *pattern);

#endif
