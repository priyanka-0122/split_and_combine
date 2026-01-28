#include "defs.h"

// Splitting one file into multiple files
void split_file(int size, char *Output_file, FILE *Input_file) {
	int i, bytes_read = size;
	FILE *fptr = NULL;
	char *Outfile = NULL;

	// Allocate a buffer to hold the 'size' as the buffer capacity
	char *buffer = malloc(size);
	if (buffer == NULL) {
		perror("Malloc failed\n");
		exit(0);
	}

	if (fgetc(Input_file) == EOF) {
		perror("Can't split an empty file");
		exit(0);
	}

	// Move the position of the point to the start
	// of the Input_file
	fseek(Input_file, 0, SEEK_SET);

	for (i = 1; bytes_read == size; i++) {

		// Create new file and open it for writing
		Outfile = add_suffix(Output_file, i);
		fptr = fopen(Outfile, "w");
		if (fptr == NULL) {
			printf("Error opening file %s\n", Outfile);
			exit(0);
		}

		// Read the specified size from the Input_file to buffer
		bytes_read = fread(buffer, 1, size, Input_file);

		// Check to make sure not to create any empty file
		// or any file with just a new line
		if ((bytes_read == 0) ||
		    ((bytes_read == 1) && (buffer[bytes_read-1] == 10))) {
			remove(Outfile);
			break;
		}

		// Write the specified bytes_read from the buffer to fptr
		fwrite(buffer, 1, bytes_read, fptr);
		fclose(fptr);
	}
}
