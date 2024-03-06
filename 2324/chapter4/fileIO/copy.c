#include <stdio.h>
#include <cs50.h>

int main (int argc, string argv[])
{
  // Verify correct usage
  if (argc != 3)
  {
    printf("Usage: ./copy <input file> <output file>\n");
    return 1;
  }

  // Create a file pointer to the source file, argv[1] for reading
  FILE *source = fopen(argv[1], "r");

  // If the file doesn't exist, (the FILE pointer is NULL) print an error message and exit by returning 1
if (source == NULL)
{
  return 1;
}

  // Create a file pointer to the destination file, argv[2], for writing
FILE *destination = fopen(argv[2], "w");

  // If the pointer is NULL, print an error, close the soruce file, and exit
if (destination == NULL)
{
  printf("could not open %s for writing", argv[2]);
  fclose(source);
  return 1;
}
  // Read the contents of the source file one character at a time, and write to the destination file
  char c = fgetc(source);
  while (c != EOF)
  {
    fprintf(destination, "%c", c);
    c = fgetc(source);
  }

  // Close both the source and destination files
fclose(source);
fclose(destination);

return 0;

}
