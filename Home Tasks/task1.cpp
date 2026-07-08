#include<iostream>

using namespace std;

class Matrix{
	
	private :
		
		int row;
		int col;
		int **data;
	
	public :
		
		Matrix ();
		Matrix ( const Matrix & );
		Matrix ( int , int );
		void setRow ( int );
		void setCol ( int );
		int getRow () const;
		int getCol () const;
		int& at ( const int r , const int c );
		void printMatrix() const;
		bool isIdentity() const;
		bool isRectangular() const;
		bool isDiagonal() const;
		bool isNullMatrix() const;
		bool isLowerTriangular() const;
		bool isUpperTriangular() const;
		bool isTriangular() const;
		
		Matrix getMatrixCopy() const;
		bool isEqual( const Matrix &m2 ) const;
		void reSize ( const int newrow, const int newcol );
		bool isSymmetric() const;
		bool isSkewSymmetric() const;
		
		~Matrix();
		
		Matrix Transpose() const;
		Matrix add ( const Matrix &m ) const;
		Matrix subtract ( const Matrix &m ) const;
		Matrix multiply ( const Matrix &m ) const;
		
};

Matrix::Matrix()
{
	row = 3;
	col = 3;
	data = new int *[row];	
	for ( int i = 0; i < row; i++ )
	{
		data[i] = new int [col];
	}
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			data[i][j] = 0; 
		}
	}
}

Matrix::~Matrix()
{
	for ( int i = 0; i < row; i++ )
	{
		delete[] data[i];
	}
	delete[] data;
	
	data = nullptr;
}

void Matrix::printMatrix() const 
{
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			cout << data[i][j] <<  "  ";
		}
		cout << endl;
	}
	
	
}

Matrix::Matrix( const Matrix &m )
{	
	row = m.row;
	col = m.col;
	
	data = new int *[row];	

	for ( int i = 0; i < row; i++ )
    {
        data[i] = new int [col];
        for ( int j = 0; j < col; j++ )
        {
            data[i][j] = m.data[i][j];
        }
    }
}

Matrix::Matrix( int r, int c )
{
	row = r;
	col = c;
	
	data = new int *[row];	
	
	for ( int i = 0; i < row; i++ )
    {
        data[i] = new int [col];
        for ( int j = 0; j < col; j++ )
        {
            data[i][j] = 0;
        }
    }	
}

void Matrix::setRow( int r )
{
	row = r;
	reSize( r, col );
}

void Matrix::setCol( int c )
{
	col = c;
	reSize( row, c );
} 

int Matrix::getRow() const 
{
	return row;
}

int Matrix::getCol() const 
{
	return col;
}

int& Matrix::at ( const int r , const int c )
{
	if ( r < 0 || r >= row || c < 0 || c >= col )
	{
		cout << "Index out of Range" << endl;
		exit(1);
	}
	
	return data[r][c];
}

bool Matrix::isIdentity() const 
{
	if ( row != col ) return false;
	
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			if ( i == j && data[i][j] != 1 )
			{
				return false;
			}
			if ( i != j && data[i][j] != 0 )
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isRectangular() const
{
	return row != col;
}

bool Matrix::isDiagonal() const 
{
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			if ( i != j && data[i][j] != 0 )
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isNullMatrix() const
{
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			if ( data[i][j] != 0 )
			{
				return false;
			}
		}
	}
	return true;	
} 

bool Matrix::isLowerTriangular() const 
{
	if ( row != col ) return false;
	
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			if ( i < j && data[i][j] != 0 )
			{
				return false;
			}
		}
	}
	return true;	
}

bool Matrix::isUpperTriangular() const 
{
	if ( row != col ) return false;
	
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			if ( i > j && data[i][j] != 0 )
			{
				return false;
			}
		}
	}
	return true;	
}

bool Matrix::isTriangular() const 
{
	if ( Matrix::isLowerTriangular() || Matrix::isUpperTriangular() )
	{
		return true;
	}
	else return false;
}

Matrix Matrix::getMatrixCopy() const 
{
    return *this; 
}

bool Matrix::isEqual( const Matrix &m2 ) const 
{
	if ( row != m2.row || col != m2.col ) return false;
	
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			if ( data[i][j] != m2.data[i][j] )
			{
				return false;
			}
		}
	}
	return true;	
}

void Matrix::reSize( const int newrow, const int newcol )
{
	for ( int i = 0; i < row; i++ )
	{
		delete[] data[i];
	}
	delete[] data;
	data = nullptr;
	
	row = newrow;
	col = newcol;
	data = new int *[row];	
	for ( int i = 0; i < row; i++ )
	{
		data[i] = new int [col];
	}
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			data[i][j] = 0; 
		}
	}	
}

Matrix Matrix::Transpose() const 
{
	Matrix t( col, row );
	
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			t.data[j][i] = data[i][j];

		}
	}
	return t;
}

Matrix Matrix::add ( const Matrix &m ) const
{
	
	if (row != m.row || col != m.col)
    {
        cout << "Matrix can't be added." << endl;
        return Matrix();
    }
	
	Matrix result( row, col );
	
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			result.data[i][j] = data[i][j] + m.data[i][j];
		}
	}
	return result;	
}

Matrix Matrix::subtract ( const Matrix &m ) const
{
	
	if (row != m.row || col != m.col)
    {
        cout << "Matrix can't be subtracted." << endl;
        return Matrix();
    }
	
	Matrix result( row, col );
	
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < col; j++ )
		{
			result.data[i][j] = data[i][j] - m.data[i][j];
		}
	}
	return result;	
}

Matrix Matrix::multiply ( const Matrix &m ) const
{
	
	if (col != m.row)
    {
        cout << "Matrix can't be multiplied." << endl;
        return Matrix();
    }
	
	Matrix result( row, m.col );
	
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = 0; j < m.col; j++ )
		{
			result.data[i][j] = 0;
	
			for ( int k = 0; k < col; k++ )
			{
				result.data[i][j] += data[i][k] * m.data[k][j];
			}
		}
	}
	return result;
}

bool Matrix::isSymmetric() const
{
	if ( row != col ) return false;
	
	for ( int i = 0; i < row; i++ )
	{
		for ( int j = i + 1; j < col; j++ )
		{
			if ( data[i][j] != data[j][i] )
			{
				return false;
			}
		}
	}
	return true;
}

bool Matrix::isSkewSymmetric() const
{
	if ( row != col ) return false;
	
	for ( int i = 0; i < row; i++ )
	{
		if ( data[i][i] != 0 )
		{
			return false;
		}
		for ( int j = 0; j < col; j++ )
		{
			if ( data[i][j] != -data[j][i] )
			{
				return false;
			}
		}
	}
	return true;
}

int main()
{
	Matrix m1,m2;
	m1.printMatrix();
	cout << endl; 
	cout << "No. of Rows : " << m1.getRow() << endl;
	cout << "No. of Cols : " << m1.getCol() << endl;
	cout << endl << endl;
	cout << "Index &at " << m1.at( 2, 2 ) << endl;
	cout << endl << endl;
	if ( m1.isIdentity() ) cout << "It is a Identity Matrix" << endl;
	else cout << "It is not a Identity Matrix" << endl;
	if ( m1.isDiagonal() ) cout << "It is a Diagonal Matrix" << endl;
	else cout << "It is not a Diagonal Matrix" << endl;
	cout << endl << endl;
	
	if ( m1.isNullMatrix() ) cout << "It is a Null Matrix" << endl;
	else cout << "It is not a Null Matrix" << endl;
	if ( m1.isLowerTriangular() ) cout << "It is a LowerTriangular Matrix" << endl;
	else cout << "It is not a LowerTriangular Matrix" << endl;
	if ( m1.isUpperTriangular() ) cout << "It is a UpperTriangular Matrix" << endl;
	else cout << "It is not a UpperTriangular Matrix" << endl;
	if ( m1.isTriangular() ) cout << "It is a Triangular Matrix" << endl;
	else cout << "It is not a Triangular Matrix" << endl;	
	cout << endl << endl;
	
	if ( m1.isEqual(m2) ) cout << "Matrix are Equal" << endl;
	else cout << "Matrix are not Eqaual" << endl;
	cout << endl << endl;
	
	m1.reSize(5,5);
	cout << "No. of Rows : " << m1.getRow() << endl;
	cout << "No. of Cols : " << m1.getCol() << endl;
	cout << endl;
	m1.printMatrix();
	cout << endl << endl;
	
	
	m2.at(0,0) = 1;
	m2.at(0,1) = 2;
	m2.at(0,2) = 3;
	m2.at(1,0) = 4;
	m2.at(1,1) = 5;
	m2.at(1,2) = 6;
	m2.at(2,0) = 7;
	m2.at(2,1) = 8;
	m2.at(2,2) = 9;

	Matrix m3(m2);  
	m3.printMatrix();
	cout << endl << endl;
	
	Matrix m4 = m2.Transpose();
	m4.printMatrix();
	cout << endl << endl;
	
	Matrix m5 = m2.add(m4);
	m5.printMatrix();
	cout << endl << endl;
	
	Matrix m6 = m2.subtract(m4);
	m6.printMatrix();
	cout << endl << endl;
	
	Matrix m7 = m5.multiply(m2);
	m7.printMatrix();
	cout << endl << endl;	

	
	if ( m7.isSymmetric() ) cout << "Matrix is Symmetric" << endl;
	else cout << "Matrix is not Symmetric" << endl;
	cout << endl << endl;
	
	if ( m6.isSkewSymmetric() ) cout << "Matrix is Skew-Symmetric" << endl;
	else cout << "Matrix is not Skew-Symmetric" << endl;
	cout << endl << endl;
	
	return 0;
}
