main: main.o caesar.o vigenere.o decryption.o
	g++ -o main main.o caesar.o vigenere.o decryption.o
tests: tests.o caesar.o vigenere.o decryption.o
	g++ -o tests tests.o caesar.o vigenere.o decryption.o

test-ascii: test-ascii.o
	g++ -o test-ascii test-ascii.o

caesar.o: caesar.cpp caesar.h
	g++ -c -std=c++11 caesar.cpp

vigenere.o: vigenere.cpp vigenere.h

decryption.o: decryption.cpp decryption.h

main.o: main.cpp caesar.h vigenere.h decryption.h
	g++ -c -std=c++11 main.cpp

tests.o: tests.cpp doctest.h caesar.h vigenere.h decryption.h
	g++ -c -std=c++11 tests.cpp
clean:
	rm -f main.o caesar.o tests.o vigenere.o decryption.o tests a.out main
