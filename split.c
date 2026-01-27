#include "defs.h"

// Splitting one file into multiple files
void split_file(int size, char *Output_file, FILE *Input_file) {
	int ch, i, written, prev_ch;
	FILE *fptr = NULL;
	char *Outfile = NULL;

	ch = fgetc(Input_file);
	if (ch == EOF)
		perror("Can't split an empty file");

	for (i = 1; ch != EOF; i++) {
		// Create new file and write to them
		Outfile = add_suffix(Output_file, i);
		fptr = fopen(Outfile, "w");
		if (fptr == NULL)
			printf("Error opening file %s\n", Outfile);

		written = 0;
		for (int j = 0; ((ch != EOF) && (j < size)); j++) {
			written = 1;

			// Write to the respective file
			fputc(ch, fptr);
			prev_ch = ch;

			// And fetch the next character
			ch = fgetc(Input_file);

			// Check to make sure not to create any empty file
			if ((j == 0) && (prev_ch == 10) && (ch == EOF))
				written = 0;
		}
		if (written == 0) {
			remove(Outfile);
			break;
		}
		fclose(fptr);
	}	
}
