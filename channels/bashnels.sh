#!/bin/sh

if [ $# -ne 2 ]; then
	echo "bashnels.sh OPERATION NAME"
	echo ""
	echo "OPERATION must be either 'send' or 'recv'"
	echo ""
	echo "the value is read from stdin/printed to stdout"
	exit 1;
fi

if [ "$1" = "send" ]; then
	cat /dev/stdin > /tmp/$2
	
	while true; do
		ls /tmp/$2 >/dev/null 2>&1 || exit 0
	done
fi

loop=1

while [ $loop -eq 1 ]; do
	ls /tmp/$2 >/dev/null 2>&1 && loop=2
done

cat /tmp/$2 && rm /tmp/$2
