CC=clang

all:
	mkdir bin
	${CC} ./src/main.c -o ./bin/c_web_parser

static:
	mkdir bin
	${CC} ./src/main.c -o ./bin/c_web_parser

check:
	${CC} --version

distcheck:
	uname -a

clean:
	rm -rf ./bin
