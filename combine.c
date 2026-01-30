#include "defs.h"

// Merging multiple files into a single file
void combine_files(int file_count, char *Outfile, char **Input_file) {
	FILE *Outfptr = NULL, *Infptr = NULL;

	// Allocate a buffer to hold the BUFFER_SIZE as the buffer capacity
	char *buffer = malloc(BUFFER_SIZE);
	if (buffer == NULL) {
		perror("Malloc failed\n");
		exit(0);
	}

	if (file_count == 1) {
		perror("Minimum 2 files to passed for combining");
		exit(0);
	}

	// Create a new file and open it for writing
	Outfptr = fopen(Outfile, "w");
	if (Outfptr == NULL) {
		printf("Error opening file %s\n", Outfile);
		exit(0);
	}

	for (int i = 0; file_count > i; i++) {
		int bytes_read = BUFFER_SIZE;

		// Open the Input_file for reading
		Infptr = fopen(Input_file[i], "r");
		if (Infptr == NULL) {
			printf("Error opening file %s\n", Input_file[i]);
			exit(0);
		}

		while (bytes_read == BUFFER_SIZE) {

			// Read the BUFFER_SIZE from the Input fptr to buffer
			bytes_read = fread(buffer, 1, BUFFER_SIZE, Infptr);

			// Write the specified bytes_read from the buffer to Outfptr
			fwrite(buffer, 1, bytes_read, Outfptr);
		}
		fclose(Infptr);
	}
	fclose(Outfptr);
}
