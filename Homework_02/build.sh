# #!/bin/bash

# # Set the name of the C++ file
# SOURCE_FILE="Task_01.cpp"

# # Set the output executable file name
# OUTPUT_FILE="Task_01"

# # Compile the C++ file
# g++ -o $OUTPUT_FILE $SOURCE_FILE

# # Check if compilation was successful
# if [ $? -eq 0 ]; then
#     echo "Compilation successful. Running the program..."
#     # Run the executable
#     ./$OUTPUT_FILE
# else
#     echo "Compilation failed. Please check your code for errors."
# fi


#!/bin/bash

# Array of source files
SOURCE_FILES=("Task_01.cpp" "Task_02.cpp" "Task_03.cpp")

# Loop through each source file
for SOURCE_FILE in "${SOURCE_FILES[@]}"; do
    # Extract the base name of the file (without extension) to use as the output file name
    OUTPUT_FILE="${SOURCE_FILE%.cpp}"
    
    # Compile the source file
    g++ -o $OUTPUT_FILE $SOURCE_FILE
    
    # Check if the compilation was successful
    if [ $? -eq 0 ]; then
        echo "Compilation of $SOURCE_FILE successful. Running the program $OUTPUT_FILE..."
        # Run the executable
        ./$OUTPUT_FILE
        echo "Finished running $OUTPUT_FILE"
    else
        echo "Compilation of $SOURCE_FILE failed. Please check your code for errors."
    fi
done
