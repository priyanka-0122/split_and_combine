SRCS = main.c split.c combine.c misc.c

all:	$(SRCS)
	gcc $(SRCS) -o split_and_combine

split_text:
	./split_and_combine -m split -n tests/text.txt -s 5 -p char

split_num:
	./split_and_combine -m split -n tests/num.txt -s 4

split_empty:
	./split_and_combine -m split -n tests/empty.txt -s 2

combine_all:
	./split_and_combine -m combine -a tests/num.txt tests/text.txt tests/val.txt -o new.txt

combine_one:
	./split_and_combine -m combine -a tests/num.txt -o new.txt

clean:
	rm -rf a.out split_and_combine
