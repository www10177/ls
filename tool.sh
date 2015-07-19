#!/bin/bash

function add(){
read -p "Please enter data..." raw 
#IFS = "-"
#export IFS
#for $data do 
##statements
#done
cat list.dat &> /dev/null
if [ "$?" == "1" ]; then
	echo "$raw" > list.dat
else
	echo $raw > .temp1
	cat  .temp1 list.dat > .temp2
	cat .temp2 | sort -n > list.dat
	rm .temp* > /dev/null
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
	read -p "Press any button to continue enter" -t 1 control 
	while [ "$?" == "0" ]; do
		add
		read -p "Press any button to continue enter" -t 1 control 
	done
elif [[ "$menu" -eq "2" ]]; then
	browse
elif [[ "$menu" -eq "3" ]]; then
	exit 0
fi
exit 0
