// Program: Assignment 1 - Problem 0
// Purpose: Operator overloading for matrices
// Author:  Suhail Hany -Abdelrahman Morsy  - Shahesta Alkady
// Date:    8 October 2018
// Version: 1.0

#include <iostream>
#include <iomanip>
#include "matrix.h"

using namespace std;

// A structure to store a matrix
struct matrix
{
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

// Already implemented
void createMatrix (int row, int col, int num[], matrix& mat);

// Student #1 with the smallest ID (e.g., 20170080)
// All these operations return a new matrix with the calculation result
matrix operator+  (matrix mat1, matrix mat2); // Add if same dimensions
matrix operator-  (matrix mat1, matrix mat2); // Sub if same dimensions
matrix operator*  (matrix mat1, matrix mat2); // Multi if col1 == row2
matrix operator+  (matrix mat1, int scalar);  // Add a scalar
matrix operator-  (matrix mat1, int scalar);  // Subtract a scalar
matrix operator*  (matrix mat1, int scalar);  // Multiple by scalar

// Student #2 with the middle ID (e.g., 20170082)
// The last operator >> takes an istream and a matrix and return the
// the same istream so it is possible to cascade input like
// cin >> matrix1 >> matrix2 << endl;
matrix operator+= (matrix& mat1, matrix mat2); // mat1 changes & return
// new matrix with the sum
matrix operator-= (matrix& mat1, matrix mat2); // mat1 changes + return new
// matrix with difference
matrix operator+= (matrix& mat, int scalar);   // change mat & return new matrix
matrix operator-= (matrix& mat, int scalar);   // change mat & return new matrix
void   operator++ (matrix& mat);   	// Add 1 to each element ++mat
void   operator-- (matrix& mat);    	// Sub 1 from each element --mat
istream& operator>> (istream& in, matrix& mat);
// Input matrix like this (dim 2 x 3) cin >> 2 3 4 6 8 9 12 123
// and return istream to allow cascading input

//Student #3 with the biggest ID (e.g., 20170089)
ostream& operator<< (ostream& out, matrix mat);
// Print matrix  as follows (2 x 3)			4	 6 	  8
// and return ostream to cascade printing	9	12  	123
bool   operator== (matrix mat1, matrix mat2);	// True if identical
bool   operator!= (matrix mat1, matrix mat2); 	// True if not same
bool   isSquare   (matrix mat);  // True if square matrix
bool   isSymetric (matrix mat);  // True if square and symmetric
bool   isIdentity (matrix mat);  // True if square and identity
matrix transpose(matrix mat);    // Return new matrix with the transpose

//__________________________________________

int main()
{
    int data1 [] = {1,2,3,4,5,6,7,8};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100};
    matrix mat4;
    int row,col;
    matrix mat1, mat2, mat3;
    createMatrix (4, 2, data1, mat1);
    createMatrix (2, 3, data2, mat2);
    createMatrix (4, 2, data3, mat3);
    int choice , scaler;
    while(1)
    {
        cout << "Do you want to enter a matrix ?" << endl
             << "1- Yes" << endl
             << "2- No" << endl;
        cin >> choice;
        if(choice == 1)
        {
            cout << "Which matrix do you want to insert " << endl
                 << "1- Mat1" << endl
                 << "2- Mat2" << endl;
            cin >> choice;
            if(choice == 1)
                cin >> mat1;
            else if(choice == 2)
                cin >> mat2;
            else
                cout << "wrong input" << endl;
        }
        cout << "What do you want to do today ? " << endl
             << "1- Mat1 + Mat2 " << endl
             << "2- Mat1 - Mat2 " << endl
             << "3- Mat1 * Mat2 " << endl
             << "4- Mat1 + scaler " << endl
             << "5- Mat1 - scaler " << endl
             << "6- Mat1 * scaler " << endl
             << "7- Mat1 += Mat2" << endl
             << "8- Mat1 -= Mat2" << endl
             << "9- Mat1 ++ " << endl
             << "10- Mat1 --" << endl
             << "11- Print Mat1" << endl
             << "12- Mat1 == Mat2" << endl
             << "13- Mat1 != Mat2" << endl
             << "14- is Mat1 Square ? " << endl
             << "15- is Mat1 Symmetric ?" << endl
             << "16- is Mat1 identity ?" << endl
             << "17- Matrix transpose " << endl << endl;

             cin >> choice;

             if(choice == 1)                    // Mat1 + Mat2
                cout << mat1+mat2 << endl;

             else if(choice == 2)              // Mat1 - Mat2
                cout << mat1-mat2 << endl;

             else if(choice == 3)              // Mat1 * Mat2
             {
                 if(mat1.col == mat2.row)
                    cout << mat1*mat2 << endl;
                 else
                    cout << "Can't Multiply " << endl;
             }

             else if(choice == 4)             // Mat1 + scaler
             {
                 cout << "Enter the scaler " << endl;
                 cin >> scaler;
                 cout << mat1 + scaler << endl;
             }

             else if(choice == 5)           // Mat1 - scaler
             {
                 cout << "Enter the scaler " << endl;
                 cin >> scaler;
                 cout << mat1 - scaler << endl;
             }

             else if(choice == 6)          // Mat1 * scaler
             {
                 cout << "Enter the scaler " << endl;
                 cin >> scaler;
                 cout << mat1 * scaler << endl;
             }

             else if(choice == 7)         // mat1 += mat2
                 cout << (mat1 += mat2) << endl;

             else if(choice == 8)        // mat1 -= mat2
                cout << (mat1 -= mat2) << endl;

             else if(choice == 9)       // mat1 ++
             {
                 ++mat1;
                 cout << mat1 << endl;
             }

             else if(choice == 10)     // mat1 --
             {
                 --mat1;
                 cout << mat1;
             }

             else if(choice == 11)     // Print mat1
                cout << mat1 << endl;

             else if(choice == 12)    // mat1 == mat2
                if(mat1 == mat2)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

             else if( choice == 13)   // mat1 != mat2
                if(mat1 != mat2)
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

            else if(choice == 14)      // is Mat1 square
                if(isSquare(mat1))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

            else if(choice == 15)         // is mat1 symmetric
                if(isSymetric(mat1))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

            else if(choice == 16)        // is mat1 Identity
                if(isIdentity(mat1))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;

            else if(choice == 17)       // transpose mat1
                cout << transpose(mat1) << endl;

            else
                cout << "Wrong Input" << endl;



    }
    return 0;
}

//__________________________________________
// Takes an array of data and stores in matrix according
// to rows and columns
void createMatrix (int row, int col, int num[], matrix& mat)
{
    mat.row = row;
    mat.col = col;
    mat.data = new int* [row];

    for (int i = 0; i < row; i++)
        mat.data[i] = new int [col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            mat.data[i][j] = num[i * col + j];
}

// Takes two matrices then adding elements of the same index
matrix operator+ (matrix mat1,matrix mat2)
{
    matrix mat3;
    int* data3 = new int[mat1.row * mat1.col];
    createMatrix(mat1.row,mat1.col,data3,mat3);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat3.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
        }
    }
    return mat3;
}

// Takes two matrices then subtracting  elements of the same index
matrix operator- (matrix mat1,matrix mat2)
{
    matrix mat3;
    int* data3 = new int[mat1.row * mat1.col];
    createMatrix(mat1.row,mat1.col,data3,mat3);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat3.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
        }
    }
    return mat3;
}

/* takes two matrices then multiplying them by multiplying rows by each column
   The output matrix dimensions are mat1.row * mat2.col
   each elements of the output matrix came from adding the multiplied elements of a row by elements of a column  */

matrix operator* (matrix mat1,matrix mat2)
{
    matrix mat3;
    int* data3 = new int[mat1.row * mat2.col];
    createMatrix(mat1.row,mat2.col,data3,mat3);
    for(int i = 0;i < mat3.row;i++)             // mat3.row == mat1.row
    {
        for(int j = 0;j < mat3.col;j++)         // mat3.col == mat2.col
        {
            int sum = 0;
            for(int k = 0;k < mat1.col;k++)     // loop for adding the multiplied elements
            {

                  sum +=  mat1.data[i][k] * mat2.data[k][j];

            }
            mat3.data[i][j] = sum;
        }
    }
    return mat3;
}

// takes a matrix and a scaler then adding the scaler to  each element of the matrix
matrix operator+ (matrix mat1,int scaler)
{
    matrix mat3;
    int* data3 = new int[mat1.row * mat1.col];
    createMatrix(mat1.row,mat1.col,data3,mat3);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat3.data[i][j]=mat1.data[i][j]+scaler;
        }
    }
    return mat3;
}

// takes a matrix and a scaler then subtracting  the scaler from  each element of the matrix
matrix operator- (matrix mat1,int scaler)
{
    matrix mat3;
    int* data3 = new int[mat1.row * mat1.col];
    createMatrix(mat1.row,mat1.col,data3,mat3);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat3.data[i][j]=mat1.data[i][j]-scaler;
        }
    }
    return mat3;
}

// takes a matrix and a scaler then multiplying  the scaler to  each element of the matrix
matrix operator* (matrix mat1,int scaler)
{
    matrix mat3;
    int* data3 = new int[mat1.row * mat1.col];
    createMatrix(mat1.row,mat1.col,data3,mat3);
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat3.data[i][j]=mat1.data[i][j]*scaler;
        }
    }
    return mat3;
}

// takes two matrices then adding each element of mat2 to the corresponding elements of mat1
matrix operator+= (matrix& mat1,matrix mat2)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]+mat2.data[i][j];
        }
    }
    return mat1;
}

// takes two matrices then subtracting  each element of mat2 from the corresponding elements of mat1
matrix operator-= (matrix& mat1,matrix mat2)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-mat2.data[i][j];
        }
    }
    return mat1;
}

// takes a matrix and a scaler then adding the scaler to each elements of mat1
matrix operator+= (matrix& mat1,int scaler)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]+scaler;
        }
    }
    return mat1;
}

//takes a matrix and a scaler then subtracting the scaler from each element
matrix operator-= (matrix& mat1,int scaler)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-scaler;
        }
    }
    return mat1;
}

// takes a matrix then adding 1 to each element
void operator++ (matrix& mat1)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]+1;
        }
    }

}

// takes a matrix then subtracting 1 from each element
void operator-- (matrix& mat1)
{
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            mat1.data[i][j]=mat1.data[i][j]-1;
        }
    }

}

//takes two matrices then checks if the are the same by checking each element from mat1 to its corresponding in mat2
bool operator==(matrix mat1,matrix mat2)
{
    bool is_identical=true;
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(mat1.data[i][j]!=mat2.data[i][j])
            {
                is_identical=false;
                break;
            }
        }
    }
    if(is_identical)
        return true;
    else
        return false;
}

//takes two matrices then checks if they are not the same by checking each element from mat1 to its corresponding in mat2
bool operator!=(matrix mat1,matrix mat2)
{
    bool is_identical=true;
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(mat1.data[i][j]!=mat2.data[i][j])
            {
                is_identical=false;
                break;
            }
        }
    }
    if(!is_identical)
        return true;
    else
        return false;
}

// takes a matrix then checks if it is square by comparing dimensions
bool isSquare (matrix mat1)
{
    if(mat1.row==mat1.col)
    {
        return true;
    }
    else
        return false;
}

// takes a matrix then checks the symmetry by comparing the original matrix to its transpose
bool isSymetric (matrix mat1)
{
    if(!isSquare(mat1) || transpose(mat1) != mat1)
        return false;
    return true;

}

// takes a matrix then checks if it is identity by checking if the main diagonal is ones and the rest are zeroes
bool isIdentity(matrix mat1)
{
    if(!isSquare(mat1))
        return false;
    for(int i=0; i<mat1.row; i++)
    {
        for(int j=0; j<mat1.col; j++)
        {
            if(i==j&&mat1.data[i][j]!=1)
            {
                return false;
            }
            else if(i!=j&&mat1.data[i][j]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

// takes a ostream object like cout and a matrix then printing each element of the matrix
ostream& operator<<(ostream& out,matrix mat3)
{
    for(int i=0; i<mat3.row; i++)
    {
        for(int j=0; j<mat3.col; j++)
        {
            out<<mat3.data[i][j]<<" ";
        }
        out<<endl;
    }
    return out;
}

// takes istream object like cin and a matrix by taking  the dimensions of a matrix then inserting each element
istream& operator>>(istream& in,matrix& mat3)
{
    in>>mat3.row>>mat3.col;
    int *data = new int[mat3.row*mat3.col];
    createMatrix(mat3.row,mat3.col,data, mat3);
    for(int i=0; i<mat3.row; i++)
    {
        for(int j=0; j<mat3.col; j++)
        {
            in>>mat3.data[i][j];
        }

    }
    return in;
}

// takes a matrix then returning its transpose by reversing the dimensions
matrix transpose(matrix mat)
{
    matrix mat2;
    createMatrix(mat.col,mat.row,mat.data[0],mat2);
    for(int i = 0; i < mat2.row; i++)
        for(int j = 0; j < mat2.col; j++)
            mat2.data[i][j] = mat.data[j][i];
    return mat2;
}

