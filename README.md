# Group Check
GroupCheck is an experimental C++ project intended to parse [Cayley tables](https://en.wikipedia.org/wiki/Cayley_table) and return useful information, primarily whether or not it defines a [group](https://en.wikipedia.org/wiki/Group_(mathematics)). It is mainly an educational project to allow exploration into algorithims in [computer algebra](https://en.wikipedia.org/wiki/Computer_algebra) (specifically group theory).

# Usage
Included in the repository is ```GroupCheck.exe```, which can be used in the command line with a single argument: a filename containing a Cayley table encoded in CSV format (formatting expectations are explained in the Assumptions section).

```.\GroupCheck.exe [filename]```

Usage in a non-Windows environment requires cloning the repository and compiling the project manually.

# Assumptions
It is assumed that the file passed in is formatted as a CSV. Formatting your Cayley tables in spreadsheet software such as Google sheets makes this very simple. It is also assumed that the row labels and column labels are in identical order. Properly formatted examples are contained in the ```examples``` directory.

In its current state, the program also assumes that the Cayley table already defines a [magma](https://en.wikipedia.org/wiki/Magma_(algebra)), which is to say that all entries in the Cayley table must also be one of the labels (the binary operation must be closed).

# Examples 

The repository contains 3 examples for testing and clarity regarding formatting.

- ```V4.csv``` is a Cayley table defining the [Klein four-group](https://en.wikipedia.org/wiki/Klein_four-group), an abelian group.
- ```S3.csv``` is a Cayley table defining the [symmetric group on 3 elements](https://groupprops.subwiki.org/wiki/Symmetric_group:S3), a non-abelian group.
- ```LatinSquare.csv``` is a Cayley table defining a [loop that is not a group](https://en.wikipedia.org/wiki/Quasigroup#Loops), which is also a 5 by 5 [Latin square](https://en.wikipedia.org/wiki/Small_Latin_squares_and_quasigroups#Order_5).

# Future Goals

- Checks for other algebraic properties, such as commutativity, cancellation property, and divisbility, as well as identifying the structures defined by these properties.
- Implementation of algorithims for checking associativity, such as this [randomized algorithm](https://doi.org/10.1137/S0097539797325387) by Rajagopalan and Schulman. 
