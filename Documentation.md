### DataSet class

The DataSet class holds game of life cell data for a single step of the simulation. Data is sorted by rows and columns, and each cell can either be on or off. 

#### Organization of the Data

Data is stored by row and column but stored internally in a single vector. For this and future examples, a simple 2 row, 2 column DataSet is featured.

>
    row 0 column 0,  
    row 0 column 1,  
    row 1 column 0,  
    row 1 column 1  


Which would look like the following in table form:

>
    row 0 column 0, row 0 column 1  
    row 1 column 0, row 1 column 1  

Thus the index of row r and column c in the vector is given by c(r+1).

#### Member Variables

- number of rows, Must be 1 or greater.
- number of columns, Must be 1 or greater.
- cells, Contains the cell data as a Vector. To access individual cells, prefer using GetCell().

#### Member Functions

- Constructor, takes number of rows and columns and creates a blank DataSet where all cells are blank.
- Copy Constructor
- Get and Set for number of rows and number of columns
- Get for cells, which returns a const vector.
- GetCell, which takes a row and column and returns the value of the cell at that row and column. 
- SetCell, which sets the value of a cell at the given row and column.
- ToggleCell, which inverts the value of the cell at the given row and column.