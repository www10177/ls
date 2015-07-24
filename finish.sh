#!/bin/bash

read -p "Enter Serial "  serial
if [ -e  "~/uva/$serial" ]; then
	mv "~/uva/$serial" ./Done
else
	if [ -d "~/uva/Done/$serial" ]; then
		echo "File not exist"
		exit 1
	else 
		echo "already in done"
		sleep 1
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
