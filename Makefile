all:
	gcc px.c -o px -lcurl
	sudo mv px /usr/local/bin/
