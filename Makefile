SRCS += main.c
SRCS += temp_functions.c
APPNAME += main

all:
	gcc $(SRCS) -o $(APPNAME)

clean:
	rm -f *.o $(APPNAME)

debug:
	gcc $(SRCS) -o $(APPNAME) -g -O0 -DDEBUG
