#include "defs.h"

// Wrong set of argument passed
static void argv_error() {
	printf("Error\n");
	printf("Expected argument in the below format:\n");
	printf("./split_and_combine -m split -n <inputFile> -s <size> -p <prefix>\n");
	exit(1);
}

// Verify if two flags are passed simultaneously
static void check_format(char *optarg) {
	if (optarg[0] == '-')
		argv_error();
}

// Set the operation to be performed
static int set_operation(char *op_name) {
	if (!strcmp(op_name, "split"))
		return(SPLIT);
	else
		argv_error();
}

int main(int argc, char **argv) {
	int opt, size, operation;
	char *Outfile = NULL;
	FILE *Infile = NULL;

	if (argc < 7)
		argv_error();

	while ((opt = getopt(argc, argv, "m:n:s:p:")) != -1) {
		switch (opt) {
			case 'm':
				check_format(optarg);
				operation = set_operation(optarg);
				break;
			case 'n':
				check_format(optarg);
				Infile = fopen(optarg, "r");
				if (Infile == NULL) {
					printf("Error opening file: %s\n", optarg);
					exit(1);
				}
				break;
			case 's':
				check_format(optarg);
				size = atoi(optarg);
				break;
			case 'p':
				check_format(optarg);
				Outfile = optarg;
				break;
		}
	}
	if (Outfile == NULL)
		Outfile = "tmp";

	if (operation == SPLIT)
		split_file(size, Outfile, Infile);
}
