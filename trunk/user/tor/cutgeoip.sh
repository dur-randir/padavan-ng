#!/bin/bash

# Коды стран через "|" без пробелов
country="FR|BE|NL|RU|UA"

files="geoip geoip6"


for f in $files
do
	test -f $f.full || mv $f $f.full
	grep -E "$country" $f.full >$f
done
