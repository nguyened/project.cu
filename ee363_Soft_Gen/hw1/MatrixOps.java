/* EE363 - HW1 - MatrixOps class
 * Evan Nguyen CE
 * Paul Schmid SE
 */
public class MatrixOps
{
  static double dot(double[] x, double[] y)
  {
    double result = 0;
    for(int i = 0; i<3; i++)
    {
      result += x[i]*y[i];
    }
    return result;
  }
  static double[][] mult(double[][] a, double[][] b)
  {
    // matirices must be compatible, A columns = B rows
    // answer column size = B column size
    // answer rows size = A row size
    int arrySizeRow = a.length;
    int arrySizeCol = b[0].length;
    int arrySizeColA = a[0].length;
    double[][] result = new double[arrySizeRow][arrySizeCol]; // initialized to zero
    for(int i = 0; i<arrySizeRow; i++)
    {
      for(int j = 0; j<arrySizeColA; j++)
      {
        for(int k = 0; k<arrySizeCol; k++)
        {
          if(j>0)
          {
            result[i][k] += a[i][j]*b[j][k];
          } else
            {
              result[i][k] = a[i][j]*b[j][k];
            }
        }
      }
    }
    return result;
  }
  static double[][] transpose(double[][] a)
  {
    int arrySizeRow = a.length;
    int arrySizeCol = a[0].length;
    int maxLength;
    if(arrySizeRow>arrySizeCol)
    {
      maxLength = arrySizeRow;
    } else if(arrySizeRow<arrySizeCol)
      {
        maxLength = arrySizeCol;
      } else
        {
          maxLength = arrySizeRow;
        }
    double[][] tempArry = new double[maxLength][maxLength];
    for(int i = 0; i<arrySizeRow; i++)
    {
      for(int j = 0; j<arrySizeCol; j++)
      {
        tempArry[j][i] = a[i][j];
      }
    }
    // flip
    int resultArrySizeRow = arrySizeCol;
    int resultArrySizeCol = arrySizeRow;
    double[][] result = new double[resultArrySizeRow][resultArrySizeCol];
    for(int i = 0; i<resultArrySizeRow; i++)
    {
      for(int j = 0; j<resultArrySizeCol; j++)
      {
        result[i][j] = tempArry[i][j];
      }
    }
    return result;
  }
  // matrix-vector product
  static double[] mult(double[][] a, double[] x)
  {
    //     where A columns = X rows
    //     answer column size = X column size = 1
    //     answer rows size = A row size
    int arrySizeRow = a.length;
    int arrySizeColA = a[0].length;
    double[] result = new double[arrySizeRow];
    for(int i = 0; i<arrySizeRow; i++)
    {
      for(int j = 0; j<arrySizeColA; j++)
      {
        result[i] +=  a[i][j]*x[i];
      }
    }
    return result;
  }
  // vector-matrix product
  static double[] mult(double[] y, double[][] a)
  {
    //     where A columns = Y rows
    //     answer column size = Y column size = 1
    //     answer rows size = A row size
    int arrySizeRow = a.length;
    int arrySizeColA = a[0].length;
    double[] result = new double[arrySizeRow];
    for(int i = 0; i<arrySizeRow; i++)
    {
      for(int j = 0; j<arrySizeColA; j++)
      {
        result[i] +=  a[i][j]*y[i];
      }
    }
    return result;
  }
}
