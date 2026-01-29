SRCS = main.c split.c misc.c

all:	$(SRCS)
	gcc $(SRCS) -o split_and_combine

split_text:
	./split_and_combine -m split -n tests/text.txt -s 5 -p char

split_num:
	./split_and_combine -m split -n tests/num.txt -s 4

split_empty:
	./split_and_combine -m split -n tests/empty.txt -s 2

clean:
	rm -rf a.out split_and_combine
