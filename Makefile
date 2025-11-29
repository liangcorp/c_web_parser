CC=clang

all:
	mkdir -p libs
	mkdir -p bin
	${CC} -Wall -Werror -Wpedantic -g -I ./libs/ -I ./src/include -c ./src/html_table_parser/html_table_parser.c -o ./libs/html_table_parser.o
	ar rcs ./libs/html_table_parser.a ./libs/html_table_parser.o
	cd ..
	${CC} -Wall -Werror -Wpedantic -g -I ./libs/ -I ./src/include -I ./src/html_table_parser -c ./src/main.c -o ./libs/main.o
	${CC} -Wall -Werror -Wpedantic -g -o ./bin/html_table_parser ./libs/main.o ./libs/html_table_parser.a

debug:
	mkdir -p libs
	mkdir -p bin
	${CC} -fsanitize=address -Wall -Werror -Wpedantic -g -I ./libs/ -I ./src/include -c ./src/html_table_parser/html_table_parser.c -o ./libs/html_table_parser.o
	ar rcs ./libs/html_table_parser.a ./libs/html_table_parser.o
	cd ..
	${CC} -fsanitize=address -Wall -Werror -Wpedantic -g -I ./libs/ -I ./src/include -I ./src/html_table_parser -c ./src/main.c -o ./libs/main.o
	${CC} -fsanitize=address -Wall -Werror -Wpedantic -g -o ./bin/html_table_parser ./libs/main.o ./libs/html_table_parser.a

static:
	mkdir bin
	${CC} ./src/main.c -o ./bin/c_web_parser

check:
	${CC} --version

distcheck:
	uname -a

format:
	find -name *.h -exec clang-format -i {} \;
	find -name *.c -exec clang-format -i {} \;

clean:
	rm -rf ./bin
	rm -rf ./libs
