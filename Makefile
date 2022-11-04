CXXFLAGS = --coverage -g -O0
main: main.o caesar.o vigenere.o decrypt.o
	g++ -o main main.o caesar.o vigenere.o decrypt.o --coverage -g -O0

tests: tests.o caesar.o vigenere.o decrypt.o
	g++ -o tests tests.o caesar.o vigenere.o decrypt.o --coverage -g -O0

coverage: main tests
	gcovr 


caesar.o: caesar.cpp caesar.h

vigenere.o: vigenere.cpp  vigenere.h caesar.h

decrypt.o: decrypt.cpp decrypt.h caesar.h vigenere.h

main.o: main.cpp caesar.h vigenere.h

tests.o: tests.cpp doctest.h caesar.h vigenere.h

test-ascii: test-ascii.cpp
	g++ -o test-ascii test-ascii.cpp --coverage -g -O0

clean:
	rm -f *.o *.html *.gcda *.gcno *.css main tests
