CC = gcc
CFLAGS = -Wall -Wextra
TARGET = lugbar

DEPS = src/utils/list.h src/email.h src/load_fileitem.h src/validation.h
OBJ = src/utils/list.o src/email.o src/load_fileitem.o src/validation.o src/main.o

all: build

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJ)
	$(CC) -o $(TARGET) $^ $(CFLAGS)
	
.PHONY: clean

clean:
	rm -f $(OBJ) lugbar *~

install: build
	mkdir -p /etc/lugbar
	curl https://raw.githubusercontent.com/Roma2Lug-Projects/Lugbar/main/item.txt -o /etc/lugbar/item.txt
	cp lugbar /usr/local/bin/
	chmod u+x /usr/local/bin/lugbar

uninstall:
	rm -rf /usr/local/bin/lugbar
	rm -rf /etc/lugbar/item.txt