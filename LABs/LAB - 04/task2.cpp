#include<iostream>
#include<string>

using namespace std;

struct matrix{
	
	int **data;
	int rows;
	int cols;
	
};

void createMatrix( const int &rows, const int &cols, matrix &m1 )
{
	m1.rows = rows;
	m1.cols = cols;
	
	m1.data = new int *[rows];
	
	for ( int i = 0; i < rows; i++ )
	{
		m1.data[i] = new int [cols];
	}
	
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			m1.data[i][j] = 0;
		}
	}
}

void freeMatrix ( matrix &m1 )
{
	if (!m1.data) return;
	
	for ( int i = 0; i < m1.rows; i++ )
	{
		delete [] m1.data[i];
	}
	delete [] m1.data;
	
	m1.data = nullptr;
	cout << "Matrix has been successfully deleted." << endl;
}

void printMatrix ( const  matrix &m1 )
{
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			cout << m1.data[i][j] << " ";
		}
		cout << endl;
	}
}

bool isEqual( const matrix &m1 , const matrix &m2 )
{
	if ( m1.rows != m2.rows || m1.cols != m2.cols ) return false;
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			if ( m1.data[i][j] != m2.data[i][j] )
			{
				return false;
			}
		}
	}
	return true;
}

matrix add ( const matrix &m1, const matrix &m2 )
{
	matrix result;
	if ( m1.rows != m2.rows || m1.cols != m2.cols )
	{
		cout << "Matrix can't be added." << endl;
		result.rows = 0;
		result.cols = 0;
		result.data = nullptr;
		return result; 
	}
	const int rows = m1.rows;
	const int cols = m1.cols;
	createMatrix( rows, cols, result );
	
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			result.data[i][j] = m1.data[i][j] +  m2.data[i][j];
		}
	}
	cout << "Matrix are added." << endl;
	
	return result;
}

matrix subtract ( const matrix &m1, const matrix &m2 )
{
	matrix result;
	if ( m1.rows != m2.rows || m1.cols != m2.cols )
	{
		cout << "Matrix can't be subtracted." << endl;
		result.rows = 0;
		result.cols = 0;
		result.data = nullptr;
		return result; 
	}
	const int rows = m1.rows;
	const int cols = m1.cols;
	createMatrix( rows, cols, result );
	
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			result.data[i][j] = m1.data[i][j] - m2.data[i][j];
		}
	}
	cout << "Matrix are subtracted." << endl;
	
	return result;
}

bool isNullMatrix ( const matrix &m1 )
{
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			if ( m1.data[i][j] != 0 )
			{
				return false;
			}
		}
	}
	return true;	
}

bool isIdentity ( const matrix &m1 )
{
	if ( m1.rows != m1.cols ) return false;
	
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			if ( ( i == j && m1.data[i][j] != 1 ) || ( i != j && m1.data[i][j] != 0 ) )
			{
				return false;
			}
		}
	}
	return true;
}

bool isRectangular ( const matrix &m1 )
{
	if ( m1.rows != m1.cols ) return true;
	
	return false;
}

bool isDiagonal ( const matrix &m1 )
{
	if ( m1.rows != m1.cols ) return false;

	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			if ( i != j && m1.data[i][j] != 0 )
			{
				return false;
			}
		}
	}
	return true;
}

matrix getMatrixCopy ( const matrix &m1 )
{
	matrix copy;
	const int rows = m1.rows;
	const int cols = m1.cols;
	
	createMatrix ( rows, cols, copy );
	
	for ( int i = 0; i < rows; i++ )
	{
		for ( int j = 0; j < cols; j++ )
		{
			copy.data[i][j] = m1.data[i][j];
		}
	}
	cout << "Matrix - copy has been successfully created." << endl;
	return copy;
}

matrix Transpose ( const matrix &m1 )
{
	matrix transpose;
	const int rows = m1.rows;
	const int cols = m1.cols;
	
	createMatrix ( cols, rows, transpose );
	
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			transpose.data[j][i] = m1.data[i][j];
		}
	}	
	return transpose;	
}

bool isSymmetric ( const matrix &m1 )
{
	if ( m1.rows != m1.cols ) return false;
	matrix transpose = Transpose ( m1 );
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			if ( transpose.data[i][j] != m1.data[i][j] )
			{
				return false;
			}
		}
	}
	freeMatrix ( transpose );	
	return true;
}

bool isSkewSymmetric ( const matrix &m1 )
{
    if ( m1.rows != m1.cols ) return false;

    for ( int i = 0; i < m1.rows; i++ )
    {
        for ( int j = 0; j < m1.cols; j++ )
        {
            if ( m1.data[i][j] != -m1.data[j][i] )
            {
            	return false;
            }
        }
    }
    return true;
}

matrix multiply ( const matrix &m1, const matrix &m2 )
{
	matrix result;
	if ( m1.cols != m2.rows )
	{
		cout << "Matrix can't be multiplied." << endl;
		
		result.rows = 0;
        result.cols = 0;
        result.data = nullptr;
        return result;
	}
	if ( m1.cols == m2.rows )
	{
		createMatrix( m1.rows, m2.cols, result );
		for ( int i = 0; i < result.rows; i++ )
		{
			for ( int j = 0; j < result.cols; j++ )
			{
				result.data[i][j] = 0;
			}
		}
	}
	
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m2.cols; j++ )
		{
			for ( int k = 0; k < m1.cols; k++ )
			{
				result.data[i][j] += m1.data[i][k] * m2.data[k][j];
			}
		}
	}
	return result;
}

int at ( const matrix &m1 , const int &r , const int &c )
{
    if (r < 0 || r >= m1.rows || c < 0 || c >= m1.cols)
    {
        cout << "Index out of bounds." << endl;
        return -1;
    }	
    return m1.data[r][c];
}

bool isLowerTriangular ( const matrix &m1 )
{
	if ( m1.rows != m1.cols ) return false;

	bool flag = true;
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			if ( m1.data[i][j] != 0 && i < j )
			{
				flag = false;
			}
		}
	}
	return flag;
}

bool isUpperTriangular ( const matrix &m1 )
{
	if ( m1.rows != m1.cols ) return false;

	bool flag = true;
	for ( int i = 0; i < m1.rows; i++ )
	{
		for ( int j = 0; j < m1.cols; j++ )
		{
			if ( m1.data[i][j] != 0 && i > j )
			{
				flag = false;
			}
		}
	}
	return flag;
}

bool isTriangular ( const matrix &m1 )
{
	if ( isLowerTriangular ( m1 ) || isUpperTriangular ( m1 ) )
	{
		return true;
	}
	return false;
}

void reSize ( matrix &m1, const int &newrow, const int &newcol )
{
	matrix temp;
    createMatrix(newrow, newcol, temp);

    freeMatrix(m1);

    m1.rows = temp.rows;
    m1.cols = temp.cols;
    m1.data = temp.data;

    temp.data = nullptr;
	
	printMatrix ( m1 );
}

int main()
{
	matrix m1,m2;
	const int rows = 4;
	const int cols = 5;
	
	
	createMatrix( rows, cols, m1 );
	createMatrix( rows, cols, m2 );
	
	printMatrix( m1 );
	cout << endl;
	
	if ( isEqual( m1 , m2) ) cout << "Matrix are equal." << endl;
	else cout << "Matrix are not equal." << endl;
	cout << endl;
	if ( isNullMatrix ( m1 ) ) cout << "Matrix is null - Matrix." << endl;
	else cout << "Matrix is not a null - Matrix." << endl;
	cout << endl;
	
	if ( isIdentity ( m1 ) ) cout << "Matrix is a Identity - Matrix." << endl;
	else cout << "Matrix is not a Identity - Matrix." << endl;
	cout << endl;
	
	if ( isRectangular ( m1 ) ) cout << "Matrix is a Rectangular - Matrix." << endl;
	else cout << "Matrix is not a Rectangular - Matrix." << endl;
	cout << endl;
	
	if ( isDiagonal ( m1 )  ) cout << "Matrix is a Diagonal - Matrix." << endl;
	else cout << "Matrix is not a Diagonal - Matrix." << endl;
	cout << endl;
	
	getMatrixCopy ( m1 );
	cout << endl;
	
	add ( m1, m2);
	cout << endl;
	
	subtract ( m1, m2);
	cout << endl;
	
	Transpose ( m1 );
	cout << endl;
	
	if ( isSymmetric ( m1 ) ) cout << "Matrix is a Symmetric - Matrix." << endl;
	else cout << "Matrix is not a Symmetric - Matrix." << endl;
	cout << endl;
	
	if ( isSkewSymmetric ( m1 ) ) cout << "Matrix is a Skew-Symmetric - Matrix." << endl;
	else cout << "Matrix is not a Skew-Symmetric - Matrix." << endl;
	cout << endl;
	
	multiply ( m1, m2 );
	cout << endl;
	
	at(m1, 3, 3);
	cout << endl;
	
	if ( isLowerTriangular ( m1 ) ) cout << "Matrix is a Lower-Triangular - Matrix." << endl;
	else cout << "Matrix is not a Lower-Triangular - Matrix." << endl;
	cout << endl;
	
	if ( isUpperTriangular ( m1 ) ) cout << "Matrix is Upper-Triangular - Matrix." << endl;
	else cout << "Matrix is not a Upper-Triangular - Matrix." << endl;
	cout << endl;
	
	if ( isTriangular ( m1 ) ) cout << "Matrix is Triangular - Matrix." << endl;
	else cout << "Matrix is not a Triangular - Matrix." << endl;
	cout << endl;
	
	reSize ( m1, 5, 6 );
	cout << endl;
	
	freeMatrix( m1 );
	freeMatrix( m2 );
	
	return 0;
}