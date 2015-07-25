#!/bin/bash

read -p "Enter Serial "  serial
mv "$serial" ./Done
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
