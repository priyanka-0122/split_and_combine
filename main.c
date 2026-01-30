#include "defs.h"

// Wrong set of argument passed
static void argv_error() {
	printf("Error\n");
	printf("Expected argument in the below format:\n");
	printf("./split_and_combine -m split -n <inputFile> -s <size> -p <prefix>\n");
	printf("./split_and_combine -m combine -a <f1> <f2> ... <f20> -o <outputFile>\n");
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
	else if (!strcmp(op_name, "combine"))
		return(COMBINE);
	else
		argv_error();
}

int main(int argc, char **argv) {
	int opt, size, operation, count;
	char *Input_file[BUFFER_SIZE];
	char *Outfile = NULL;
	FILE *Infile = NULL;

	while ((opt = getopt(argc, argv, "a:m:n:o:p:s:")) != -1) {
		switch (opt) {
			case 'a':
				check_format(optarg);
				count = 0;
				optind--;
				while ((argc != optind) && (*argv[optind] != '-')) {
					Input_file[count++] = argv[optind++];
				}
				break;
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
			case 'o':
				check_format(optarg);
				Outfile = optarg;
				break;
			case 'p':
				check_format(optarg);
				Outfile = optarg;
				break;
			case 's':
				check_format(optarg);
				size = atoi(optarg);
				break;
		}
	}

	if (((operation == SPLIT) && (argc < 7)) ||
	    ((operation == COMBINE) && (argc < 6)))
		argv_error();

	if (operation == SPLIT) {
		if (Outfile == NULL)
			Outfile = "tmp";
		split_file(size, Outfile, Infile);
	} else if (operation == COMBINE) {
		if (Outfile == NULL)
			Outfile = "tmp.txt";
		combine_files(count, Outfile, Input_file);
	}
}
