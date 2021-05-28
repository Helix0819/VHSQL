all:
	g++ code/main.cpp code/table.cpp code/file.cpp code/DB.cpp -I code/include/ -L code/lib/ -l sqlparser -g -o main -std=c++11
clean:
	rm main
install:
	cp code/lib/libsqlparser.a /usr/lib/
uninstall:
	rm /usr/lib/libsqlparser.a

