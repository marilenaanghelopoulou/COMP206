#!/bin/bash

if [ "$#" -ne 1 ]
then
	echo "Usage: "$0" name"
	exit 1
fi   

cd ~

name=$1 
if [ ! -d "project" ]; then
	mkdir project
fi 

cd project

if [ ! -d "cs206" ]; then 
	mkdir cs206
fi

cd cs206

if [  -d "$name" ]; then
	echo "This project name has already been used."
	exit 1
fi

mkdir -p $name/{archive,backup,docs,assets,database,source}
cd $name/source 

echo "#!/bin/bash" > backup.sh
echo "cp *.h *.c ../backup" >> backup.sh
chmod 755 backup.sh

echo "Your project directories have been created."
