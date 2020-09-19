#Abstract

This repository contains different versions of programs to search solutions for the "peg solitaire" game. Please use the internet, if you are not familiar with peg solitaire. These programs are used to explain how to find solutions by depth/breadth first search and backtracking.
The solutions are developed with C++ on a Windows system using Visual Studio. Migration to Linux should be simple. But there is a "Windows-Only" functionality for printing the peg-solitaire board to console - coloring the last move - that has to be replaces.

## Solutions

### Clean Solution

The clean solution is the initial solution, simple to read, slow, but by far fast enough to find a soltuion for the classic "Englisch Board" by using depth first search.

### Faster Solution

The faster soltuion uses bit-boards to search faster

### Bit Board only Solution

The Bit Board only solution removes all "non - bitboard" code to be even faster

### Fastest Solution

The Fastest soltuion contains tricky bitmapping to find a solution - it is no longer easy to read and understand, but 10 times faster than the clean solution

### Cach Solution

This Solution uses caches to show that caching improves the search speed much more than any program speed improvement. Now we are even able to solve peg-solitaire with a French Board

### Breadth first search

This Solution introduces Breadth First Search to evaluate which French Peg Solitaire start positions have solutions
