#include "matrix.h"

matrix::matrix(int row , int col , int data1[])
{
    data = new int* [row];
    for(int i = 0;i < row;i++)
    {
        data[i] = new int [col];
    }

    for(int i = 0;i < row;i++)
        for(int j = 0;j < col;j++)
            data[i][j] = data1[i* row + j];

}

matrix :: matrix operator+ (matrix mat2)
{

    int* data3 = new int[mat1.row * mat1.col];

    matrix mat3(mat2.row,mat2.col,data3);

    for(int i=0; i< this -> row; i++)
    {
        for(int j=0; j<mat2.col; j++)
        {
            mat3.data[i][j]= this -> data[i][j]+mat2.data[i][j];
        }
    }
    return mat3;
}

// Takes two matrices then subtracting  elements of the same index
matrix :: matrix operator+ (matrix mat2)
{

    int* data3 = new int[mat1.row * mat1.col];

    matrix mat3(mat2.row,mat2.col,data3);

    for(int i=0; i< this -> row; i++)
    {
        for(int j=0; j<mat2.col; j++)
        {
            mat3.data[i][j]= this -> data[i][j] - mat2.data[i][j];
        }
    }
    return mat3;
}
/* takes two matrices then multiplying them by multiplying rows by each column
   The output matrix dimensions are mat1.row * mat2.col
   each elements of the output matrix came from adding the multiplied elements of a row by elements of a column  */

matrix operator* (matrix mat2)
{
    int* data3 = new int[this - > row * mat2.col];
    matrix mat3(this - > row , mat2.col,data3);
    for(int i = 0;i < mat3.row;i++)             // mat3.row == mat1.row
    {
        for(int j = 0;j < mat3.col;j++)         // mat3.col == mat2.col
        {
            int sum = 0;
            for(int k = 0;k < this -> col;k++)     // loop for adding the multiplied elements
            {

                  sum +=  this - > data[i][k] * mat2.data[k][j];

            }
            mat3.data[i][j] = sum;
        }
    }
    return mat3;
}

// takes a matrix and a scaler then adding the scaler to  each element of the matrix
matrix operator+ (int scaler)
{
    int* data3 = new int[this -> row * this -> col];
    matrix mat3;
    for(int i=0; i<this -> row; i++)
    {
        for(int j=0; j<this -> col; j++)
        {
            mat3.data[i][j]=this -> data[i][j]+scaler;
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


