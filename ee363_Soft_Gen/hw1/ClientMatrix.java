/*
 * @purpose Demostrates usage of MatrixOps
 *
 * @author Evan Nguyen
 *
 * @modified Sep 20, 2019
*/
public class ClientMatrix
{
  public static void PrintArry(double[] smpl)
  {
    for(int i=0;i<3;i++)
    {
      System.out.println("row: "+i+"   val: "+smpl[i]);
    }
  }
  public static void Print2DArry(double[][] smpl)
  {
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        System.out.println("row: "+i+" col: "+j+"   val: "+smpl[i][j]);
      }
    }
  }
  public static void main(String[] args)
  {
    double[] vector1 = new double[]{9.0,2.0,7.0};
    double[] vector2 = new double[]{4.0,8.0,10.0};
    double[][] mat1 = new double[][]{ {1.0,0.0,1.0},{0.0,1.0,2.0},{0.0,0.0,0.0} };
    double[][] mat2 = new double[][]{ {3.0,5.0,0.0},{-1.0,0.0,1.0},{2.0,-1.0,0.0} };
    System.out.println("[start]");
    System.out.println("\n[vector1]");
    PrintArry(vector1);
    System.out.println("\n[vector2]");
    PrintArry(vector2);
    System.out.println("\n[matrix1]");
    Print2DArry(mat1);
    System.out.println("\n[matrix2]");
    Print2DArry(mat2);
    System.out.println("\n[Vector Dot Product]: " + MatrixOps.dot(vector1,vector2));
    System.out.println("\n[matrix-matrix]: using mult()");
    Print2DArry(MatrixOps.mult(mat1,mat2));
    System.out.println("\n[transpose matrix]: using transpose()");
    Print2DArry(MatrixOps.transpose(mat2));
    System.out.println("\n[matrix-vector]: using mult()");
    PrintArry(MatrixOps.mult(mat2,vector1));
    System.out.println("\n[vector-matrix]: using mult()");
    PrintArry(MatrixOps.mult(vector1,mat2));
    System.out.println("\n[done]");
  }
}
