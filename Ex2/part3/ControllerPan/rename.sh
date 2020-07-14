#!/bin/bash
echo Renaming .c files to .cpp files. 
echo Please copy .cpp files into your TERRA project.

for file in project/fmu/sources/CPP/*.c
do
  mv "$file" "${file%.c}.cpp"
done

