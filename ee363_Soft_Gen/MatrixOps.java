

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
  // static double[][] mult(double[][] a, double[][] b)
  // {
  //   return;
  // };
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
