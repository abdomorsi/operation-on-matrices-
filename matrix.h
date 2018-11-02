#ifndef MATRIX_H
#define MATRIX_H


class matrix
{
    public:
        matrix();
        // Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat2); // Add if same dimensions
matrix operator-  ( matrix mat2); // Sub if same dimensions
matrix operator*  ( matrix mat2); // Multi if col1 == row2
matrix operator+  ( int scalar);  // Add a scalar
matrix operator-  ( int scalar);  // Subtract a scalar
matrix operator*  ( int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= ( matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= ( matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= ( int scalar);   // change mat & return new matrix
matrix operator-= ( int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
friend istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
friend ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== ( matrix mat2);	// True if identical
bool   operator!= ( matrix mat2); 	// True if not same
bool   isSquare   ();  // True if square matrix
bool   isSymetric ();  // True if square and symmetric
bool   isIdentity ();  // True if square and identity
matrix transpose();    // Return new matrix with the transpose


    protected:

    private:
        int ** data;
        int row , col;
};

#endif // MATRIX_H
