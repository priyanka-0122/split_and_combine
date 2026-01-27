SRCS = main.c split.c misc.c

all:	$(SRCS)
	gcc $(SRCS) -o split_and_combine

clean:
	rm -rf a.out split_and_combine
