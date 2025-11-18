# Lecture 1 code
First part of the Assigment for lecture 1.

To run this code just type "make" into the terminal.
The executable files will be removed automatically afterwards.

## Contents
AnalyseData.cpp: \
This is the main file and will be used to call the functiosn within the CustomFunctions file.

CustomFunctions.cpp: \
This file contains custom functions. 
- ReadData: reads an input data file and fill vectors x and y to be used later.
- Printer: prints a specified number of lines from the data file to the terminal.
- magnitudes: Calculates the magnitude of the x and y variables outputing it as a vector of magnitudes.
- BestFit: Calculates the line of best fit for the data using the least squares method. Outputs to equation to the terminal and text file.
- Chi_squared: Calculates the $\Chi^{2}$ value for the line of best fit.

CustomFunctions.h: \
Header file corresponding to the CustomFunctions.cpp file.
