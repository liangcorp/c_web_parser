CC=clang

all:
	mkdir bin
	${CC} ./src/main.c -o ./bin/c_web_parser

static:
	mkdir bin
	${CC} ./src/main.c -o ./bin/c_web_parser

clean:
	rm -rf ./bin
