# split_and_combine
Implementing a custom split and combine command-line utility in C to replicate core Linux manual functionalities. It allows users to split a file into smaller chunks and later recombine them into a single file.

## Usage

### Split a File
	./split_and_combine -m split -n <inputFile> -s <size> -p <prefix>

### Combine Files
	./split_and_combine -m combine -a <f1> <f2> ... <f20> -o <outputFile>

## Command-Line Options

### Common Flags

* **`-m`**
  Specifies the operation mode.

  * `split` → Split a file into smaller parts
  * `combine` → Combine multiple files into one

### Split Mode Flags

* **`-n`**
  Specifies the name of the input file to be split.

* **`-s`**
  Specifies the size (in bytes) of each split file.

* **`-p`**
  Specifies the prefix used when naming the split output files.

### Combine Mode Flags

* **`-a`**
  Indicates that the following arguments are the names of files to be combined.

* **`-o`**
  Specifies the name of the output file generated after combining.


## Examples

### Splitting a File

./split_and_combine -m split -n largefile.txt -s 10 -p part_

This command splits `largefile.txt` into 10 byte chunks named `part_1.txt`, `part_2.txt`, etc.

### Combining Files

./split_and_combine -m combine -a part_1 part_2 part_3 -o combined.txt

This command combines the specified files into `combined.txt`.
