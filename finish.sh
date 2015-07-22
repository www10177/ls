#!/bin/bash

read -p "Enter Serial "  serial
if [ -e  "$serial" ]; then
	mv $serial ./Done
fi
if [ $? ]; then
	if [ !  -e "./Done/$serial"  ]; then
		echo "File not exist"
		exit 1
	fi
fi
cd ~/uva
git add .
git status
read -p "Y/N" YN
if [  "$YN" == "y" ]; then
	git commit -am "$serial"
	git status
else
	echo "Did not commit"
	exit 0
fi
