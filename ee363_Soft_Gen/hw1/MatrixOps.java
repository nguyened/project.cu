

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
  };
  static double[][] mult(double[][] a, double[][] b)
  {
    // matirices must be compatible, A columns = B rows
    // answer column size = B column size
    // answer rows size = A row size
    double[][] result = new double[3][3]; // initialized to zero
    for(int i = 0; i<3; i++)
    {
      for(int j = 0; j<3; j++)
      {
        for(int k = 0; k<3; k++)
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
  };
  // static double[][] transpose(double[][] a)
  // {
  //   return;
  // };
  // static double[] mult(double[][] a, double[] x)
  // {
  //   return;
  // };
  // static double[] mult(double[] y, double[][] a)
  // {
  //   return;
  // };
}
