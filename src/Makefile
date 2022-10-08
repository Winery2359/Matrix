CFLAGS = -Wall -Wextra -Werror -std=c++17
SYS = $(shell uname)
CC = g++

ifeq ($(SYS), Linux)
    LFLAGS = -lpthread -lgtest 
else
    LFLAGS = -lgtest
endif

all: clean build

build: s21_matrix_oop.a

s21_matrix_oop.a: s21_matrix_oop.o
	ar rcs $@ $^
	cp $@ lib$@

s21_matrix_oop.o:
	$(CC) -c s21_matrix_oop.cpp

test: s21_matrix_oop.a
	$(CC) -o test test.cpp -L. -ls21_matrix_oop $(LFLAGS) $(CFLAGS)
	./test

clean:
	rm -rf test *.gcda *.gcno coverage.info .clang-format valgrind.txt gcov_report *.a *.o

gtest_install:
	sudo apt install clang-format

style:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.cpp

cppcheck:
	cppcheck --enable=all --suppress=missingInclude --suppress=unusedFunction *.cpp

leaks:
ifeq ($(SYS), Linux)
	valgrind --log-file="valgrind.txt" --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --leak-resolution=med -s ./test
else
	CK_FORK=no leaks -atExit -- ./test
endif

gcov_report:
	$(CC) --coverage -o test test.cpp s21_matrix_oop.cpp $(LFLAGS) $(CFLAGS)
	./test
	lcov --no-external --capture --directory ./ --output-file coverage.info
	genhtml coverage.info --output-directory gcov_report
	browse ./gcov_report/index.html

.PHONY: gcov_report test