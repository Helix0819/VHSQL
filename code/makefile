all:
	g++ main.cpp table.cpp file.cpp DB.cpp -I include/ -L lib/ -l sqlparser -g -o a -std=c++11
clean:
	rm a
install:
	cp ./lib/libsqlparser.so /usr/lib/
uninstall:
	rm /usr/lib/libsqlparser.so

