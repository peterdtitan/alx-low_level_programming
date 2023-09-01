#!/bin/bash
# Get a list of all C source files in the current directory
c_files=$(ls *.c 2>/dev/null)

# Check if there are any C source files
if [ -z "$c_files" ]; then
    echo "No C source files (*.c) found in the current directory."
    exit 1
fi

# Compile each C source file into an object file
for file in $c_files; do
    gcc -c "$file"
done

# Create the static library from all the object files
object_files=$(ls *.o)
ar -rcs libmy.a $object_files

# Clean up the object files
rm -f $object_files

echo "Static library libmy.a created."
