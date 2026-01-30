#include "defs.h"

// Add the suffix at the end of the file name
char *add_suffix(char *filename, int fileno) {
        int len = strlen(filename) + 7;  
        char *str = malloc(len);

	snprintf(str, len, "%s%d.txt", filename, fileno);
    
        return (str);
}
