#!/bin/bash

read -p "Enter Serial"  serial
if [ -e  "$serial" ]; then
	mv $serial ./Done
fi
if [ $? ]; then
	if [ -a "./Done/$serial"]; then
		echo "File not exist"
	fi
fi
cd ~/uva
git add .
git status
git commit -am "$serial"
