CC=clang

all:
	mkdir -p libs
	mkdir -p bin
	${CC} -Wall -Werror -Wpedantic -std=c89 -g -I ./libs/ -I ./src/include -c ./src/html_table_parser/html_table_parser.c -o ./libs/html_table_parser.o
	ar rcs ./libs/html_table_parser.a ./libs/html_table_parser.o
	cd ..
	${CC} -Wall -Werror -Wpedantic -std=c89 -g -I ./libs/ -I ./src/include -I ./src/html_table_parser -c ./src/main.c -o ./libs/main.o
	${CC} -Wall -Werror -Wpedantic -std=c89 -g -o ./bin/html_table_parser ./libs/main.o ./libs/html_table_parser.a

memory_debug:
	mkdir -p libs
	mkdir -p bin
	${CC} -Wall -Werror -Wpedantic -D F_MEMORY_DEBUG -std=c89 -g -I ./libs/ -I ./src/include -c ./src/html_table_parser/html_table_parser.c -o ./libs/html_table_parser.o
	${CC} -Wall -Werror -Wpedantic -D F_MEMORY_DEBUG -std=c89 -g -I ./libs/ -I ./src/include -c ./src/memory_debug/memory_debug.c -o ./libs/memory_debug.o
	ar rcs ./libs/html_table_parser.a ./libs/html_table_parser.o
	ar rcs ./libs/memory_debug.a ./libs/memory_debug.o
	cd ..
	${CC} -Wall -Werror -Wpedantic -D F_MEMORY_DEBUG -std=c89 -g -I ./libs/ -I ./src/include -I ./src/html_table_parser -I ./src/memory_debug -c ./src/main.c -o ./libs/main.o
	${CC} -Wall -Werror -Wpedantic -D F_MEMORY_DEBUG -std=c89 -g -o ./bin/html_table_parser ./libs/main.o ./libs/html_table_parser.a ./libs/memory_debug.a

check:
	${CC} --version

distcheck:
	uname -a

bad_function_check:
	bash sh/bad_function_check.sh

format:
	find -name *.h -exec clang-format -i {} \;
	find -name *.c -exec clang-format -i {} \;

clean:
	rm -rf ./bin
	rm -rf ./libs
