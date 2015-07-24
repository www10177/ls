#!/bin/bash

read -p "Serial?" serial
mkdir $serial
cd $serial
touch data.in
touch datal.out
vim 10361.c
