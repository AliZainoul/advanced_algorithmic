public class matrix {

  // Members
  private int size;
  private double[][] matrix;

  // Constructors
  // Default Constructor
  public matrix(){}

  // Size Constructor
  public matrix(int _size){
    this.size = _size;
    double[][] result = new double[_size][_size];
    for(int i = 0; i< this.getSize(); i++)
      for(int j = 0; j< this.getSize(); j++)
        result[i][j] = 0;
    this.setMatrix(result);
  }

  // Copy Constructor
  public matrix(matrix _matrix){
    this.size = _matrix.getSize();
    this.matrix = _matrix.getMatrix();
  }

  // Size / same value Constructor
  public matrix(int _size, double _value){
    this.size = _size;
    this.matrix = fillwithvalue(_size, _value);
  }

  public double[][] fillwithvalue(int _size, double _value){
    double[][] m = new double[_size][_size];
    for(int i = 0; i< _size; i++){
      for(int j = 0; j< _size; j++){
        m[i][j] = _value;
      }
    }
    return m;
  }


  // Helpers
  public void printMatrix(){
    for(int i = 0; i< this.getSize(); i++){
      for(int j = 0; j< this.getSize(); j++){
        System.out.print(this.matrix[i][j]+ " ");
      }
      System.out.println();
    }
    System.out.println();
  }

  // Methods

  // Getters
  public int getSize() {
    return size;
  }
  public double[][] getMatrix() {
    return matrix;
  }

  // Setters
  public void setSize(int _size) {
    this.size = _size;
  }
  public void setMatrix(double[][] _matrix) {
    this.matrix = _matrix;
  }

  // Pure methods

  // Adding element-wise two matrices
  public matrix add(matrix _matrix){
    int size = _matrix.getSize();
    matrix result = new matrix(size, 0);
    double [][] C = new double[size][size];
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
        C[i][j] = this.matrix[i][j] + _matrix.matrix[i][j];
    result.setMatrix(C);
    return result;
  }

  // Substracting element-wise two matrices
  public matrix sub(matrix _matrix){
    int size = _matrix.getSize();
    matrix result = new matrix(size, 0);
    double [][] C = new double[size][size];
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
        C[i][j] = this.matrix[i][j] - _matrix.matrix[i][j];
    result.setMatrix(C);
    return result;
  }

  // Naive product of two matrices
  public matrix product(matrix _matrix){
    int size = _matrix.getSize();
    matrix result = new matrix(size, 0);
    double C[][]  = new double[size][size];
    for(int i=0;i<size;++i){
      for(int j=0;j<size;++j){
        C[i][j]=0;
        for(int k=0;k<size;++k){
          C[i][j] += this.matrix[i][k]*_matrix.matrix[k][j];
        }
      }
    }
    result.setMatrix(C);
    return result;
  }

  public matrix scalarProduct (double scalar){
    int size = this.getSize();
    matrix result = new matrix(size, 0);
    double C[][] = new double[size][size];
    for (int i = 0; i < size; ++i)
      for (int j = 0; j < size; ++j)
      C[i][j] = scalar * this.matrix[i][j];
    result.setMatrix(C);
    return result;
  }

  // Method to split the original matrix into child ones
  public void split(matrix P, int beg1, int beg2){
    // Iterating over elements of 2D matrix
    // using nested for loops
    // Outer loop for rows
    for (int i1 = 0, i2 = beg1; i1 < (this.getMatrix()).length; i1++, i2++)
      // Inner loop for columns
      for (int j1 = 0, j2 = beg2; j1 < (this.getMatrix()).length; j1++, j2++)
        (this.getMatrix())[i1][j1] = (P.getMatrix())[i2][j2];
  }

  // Method to join child matrixes into parent one
  public void join(matrix C, int beg1, int beg2){
    // Iterating over elements of 2D matrix
    // using nested for loops
    // Outer loop for rows
    for (int i1 = 0, i2 = beg1; i1 < C.getSize(); i1++, i2++)
      // Inner loop for columns
      for (int j1 = 0, j2 = beg2; j1 < C.getSize(); j1++, j2++)
        (this.getMatrix())[i2][j2] = (C.getMatrix())[i1][j1];
  }


  // Core Strassen's Method

  /*
    name: method of class matrix
    input: an instance of class matrix (object) _matrix
    output: instance of class matrix (object)
    usage: matrix resultMatrix = new matrix(matrix1.productStrassen(matrix2));
    // calls the copy constructor
  */
  public matrix productStrassen(matrix _matrix){
    int size = this.getSize();
    matrix result = new matrix(size);
    double[][] resultingMatrix = new double[size][size];

    // If size == 1 we return the resulting product of the scalars
    // matrix1[0][0] and matrix2[0][0]
    if(size == 1)
    {
      resultingMatrix[0][0] = this.matrix[0][0] * _matrix.matrix[0][0];
      result.setMatrix(resultingMatrix);
    }
    if(size % 2 == 0)
    {
    // Splitting the 2 matrixes of sizexsize
    // into 8 smaller ones of (size/2)x(size/2)

      // Splitting the first matrix of sizexsize
      // into 4 smaller ones of (size/2)x(size/2)
      matrix A11 = new matrix(size/2);
      matrix A12 = new matrix(size/2);
      matrix A21 = new matrix(size/2);
      matrix A22 = new matrix(size/2);

      // Splitting the second matrix of sizexsize
      // into 4 smaller ones of (size/2)x(size/2)
      matrix B11 = new matrix(size/2);
      matrix B12 = new matrix(size/2);
      matrix B21 = new matrix(size/2);
      matrix B22 = new matrix(size/2);


      // Inserting elements into matrix
      // Inserting elements of matrix 1
      A11.split(this, 0     , 0      );
      A12.split(this, 0     , size/2 );
      A21.split(this, size/2, 0      );
      A22.split(this, size/2, size/2 );
      // Inserting elements of matrix 2
      B11.split(_matrix, 0     , 0      );
      B12.split(_matrix, 0     , size/2 );
      B21.split(_matrix, size/2, 0      );
      B22.split(_matrix, size/2, size/2 );


      // M1:= (A12-A22)×(B21+B22)
      matrix M1 = (A12.sub(A22)).product(B21.add(B22));
      // M2:= (A11+A22)×(B11+B22)
      matrix M2 = (A11.add(A22)).product(B11.add(B22));
      // M3:= (A11−A21)×(B11+B12)
      matrix M3 = (A11.sub(A21)).product(B11.add(B12));
      // M4:= (A11+A12)×B22
      matrix M4 = (A11.add(A12)).product(B22);
      // M5:= A11(B12-B22)
      matrix M5 = (A11).product(B12.sub(B22));
      // M6:= A22(B21-B11)
      matrix M6 = (A22).product(B21.sub(B11));
      // M7:= (A21+A22)B11
      matrix M7 = (A21.add(A22)).product(B11);

      // C11:= M1 + M2 - M4 + M6
      matrix C11 = ((M1.add(M2)).sub(M4)).add(M6);
      // C12:= M4 + M5
      matrix C12 = M4.add(M5);
      // C21:= M6 + M7
      matrix C21 = M6.add(M7);
      // C22:= M2 - M3 + M5 - M7
      matrix C22 = ((M2.sub(M3)).add(M5)).sub(M7);



      /*
      // M1:= (A11+A22)×(B11+B22)
      matrix M1 = (A11.add(A22)).product(B11.add(B22));
      // M2:= (A21+A22)×(B11)
      matrix M2 = (A21.add(A22)).product(B11);
      // M3:= (A11)×(B12-B22)
      matrix M3 = (A11).product(B12.sub(B22));
      // M4:= (A22)×(B21 - B11)
      matrix M4 = (A22).product(B21.sub(B11));
      // M5:= (A11+A12)(B22)
      matrix M5 = (A11).add(A12).product(B22);
      // M6:= (A21-A11)(B11+B12)
      matrix M6 = ((A21).sub(A11)).product(B11.add(B12));
      // M7:= (A12-A22)(B21+B22)
      matrix M7 = (A12.sub(A22)).product(B21.add(B22));

      // C11:= M1 + M4 - M5 + M7
      matrix C11 = ((M1.add(M4)).sub(M5)).add(M7);
      // C12:= M3 + M5
      matrix C12 = M3.add(M5);
      // C21:= M2 + M4
      matrix C21 = M2.add(M4);
      // C22:= M1 - M2 + M3 - M6
      matrix C22 = ((M1.sub(M2)).add(M3)).sub(M6);
      */



      // Joining elements
      result.join(C11, 0, 0);
      result.join(C12, 0, size / 2);
      result.join(C21, size / 2, 0);
      result.join(C22, size / 2, size / 2);
      return result;
    }

    // return the resulting matrix
    else
    {
      // Treat case n odd
      // Answer: assume that size is even, ie: size <-- size+1
      //         where elements of the last line and last column are zeroes
      return result;
    }
  }


  // Find n s.t. totalTimepS <= startTimenP.
  // Answer: n large enough

  // Main
  public static void main(String[] args){
    //TEST
    matrix m1 = new matrix(999, 2);
    matrix m2 = new matrix(999, 3);

    long startTimepS = System.nanoTime();
    matrix m3 = new matrix(m1.productStrassen(m2));
    long endTimepS = System.nanoTime();
    long totalTimepS = startTimepS - endTimepS;
    System.out.println("totalTimepS" + totalTimepS);

    long startTimenP = System.nanoTime();
    matrix m4 = new matrix(m1.product(m2));
    long endTimenP = System.nanoTime();
    long totalTimenP = startTimenP - endTimenP;
    System.out.println("totalTimenP" + totalTimenP);

    /*
    System.out.println("Printing matrix m1: ");
    System.out.println("----------------------");
    (m1).printMatrix();

    System.out.println("Printing matrix m2: ");
    System.out.println("----------------------");
    (m2).printMatrix();

    System.out.println("Printing matrix m3: ");
    System.out.println("----------productStrassen----------");
    (m3).printMatrix();

    System.out.println("Printing matrix m4: ");
    System.out.println("----------naiveProduct----------");
    (m4).printMatrix();
    */

  }
}
