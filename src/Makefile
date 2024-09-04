CC = gcc -std=c11 -Wall -Werror -Wextra 
# CC = gcc
LDLIBS = -lcheck -lm -lpthread -lsubunit 
GCOV = -fprofile-arcs -ftest-coverage -lgcov

all: rebuild

rebuild: clean s21_string.a

clean:
	rm -f test *.info *.gcno *.gcda *.o *.a *.log
	rm -rf *-html

c:
	rm -f *.gcno *.gcda *.o *.info

s21_string.a:
	$(CC) -c s21_*.c
	ar rcs $@ s21_*.o
	ranlib s21_string.a

s21_string_test.a:
	$(CC) $(GCOV) -c s21_*.c
	ar rcs $@ s21_*.o
	ranlib s21_string_test.a

test: ./tests/*.c s21_string_test.a
	$(CC) $(GCOV) -o $@ $^ $(LDLIBS)
	chmod +x $@
	./test

gcov_report: test
	lcov --capture --directory . --output-file coverage.info
	genhtml coverage.info --output-directory coverage-html
	make c
	xdg-open coverage-html/index.html

val_check: test c
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes -s --log-file="valgrind.log" ./test
	# valgrind --tool=memcheck --leak-check=yes --track-origins=yes --log-file="valgrind.log" ./test
	make c

cl_check:
	cp ../materials/linters/.clang-format ../src/
	clang-format -n tests/*.c tests/*.h *.c *.h
	rm -rf .clang-format

cl:
	cp ../materials/linters/.clang-format ../src/
	clang-format -i tests/*.c tests/*.h *.c *.h
	rm -rf .clang-format