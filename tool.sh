#!/bin/bash

function add(){
read -p "Please enter data..." raw 
cat list.dat &> /dev/null
if [ "$?" == "1" ]; then
	echo "$raw" > list.dat
else
	echo $raw > .temp1
	cat  .temp1 list.dat > .temp2
	cat .temp2 | sort -n > list.dat
	rm .temp* > /dev/null
	raw=${raw%% - *}
	if [  "$?" == "1" ]; then
		echo "create folder ERROR"
	else 
		mkdir $raw
		cd $raw
		touch data.in data.out
		touch "$raw.c"
		cd $raw
	fi
fi
}

function browse(){
echo "1 for show all"
echo "2 for query"
read -p "Please enter instruction..." ins
if [[ "$ins" == "1" ]]; then
	echo "************************"
	cat list.dat
	echo "************************"
	echo -n "total problem : "
	cat list.dat | wc -l
else
	read -p "please enter key word    " key
	echo
	cat list.dat | grep  --color=auto --exclude-dir={.bzr,.cvs,.git,.hg,.svn} $key
	if [ "$?" -eq "1" ]; then
		echo "Did not find the key word"
		echo "Show all the list"
		echo "************************"
		cat list.dat
		echo "************************"
	fi
fi
}

echo "1 for add new problem"
echo "2 for browse of query"
echo "3 for exit"
read -p "Please enter instruction..." menu
if [[ "$menu" == "1" ]]; then
	add
elif [[ "$menu" -eq "2" ]]; then
	browse
elif [[ "$menu" -eq "3" ]]; then
	exit 0
fi
exit 0
