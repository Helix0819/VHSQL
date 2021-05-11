all:
	g++ src/example.cpp -I include/ -L lib/ -l sqlparser -o example -std=c++11
clean:
	rm example
install:
	cp ./lib/libsqlparser.so /usr/lib/
uninstall:
	rm /usr/lib/libsqlparser.so