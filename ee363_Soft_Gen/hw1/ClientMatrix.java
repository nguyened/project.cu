/*
 * @purpose EE363 - HW1 - Demostrates usage of MatrixOps
 * Evan Nguyen CE
 * Paul Schmid SE
 * @modified Sep 20, 2019
*/
public class ClientMatrix
{
  public static void PrintArry(double[] smpl)
  {
    int arrySizeRow = smpl.length;
    for(int i=0;i<arrySizeRow;i++)
    {
      System.out.println("row: "+i+"   val: "+smpl[i]);
    }
  }
  public static void Print2DArry(double[][] smpl)
  {
    int arrySizeRow = smpl.length;
    int arrySizeCol = smpl[0].length;
    for(int i=0;i<arrySizeRow;i++)
    {
      for(int j=0;j<arrySizeCol;j++)
      {
        System.out.println("row: "+i+" col: "+j+"   val: "+smpl[i][j]);
      }
    }
  }
  public static void main(String[] args)
  {
    double[] vector1 = new double[]{9.0,2.0,7.0};
    double[] vector2 = new double[]{4.0,8.0,10.0};
    double[][] mat3x3 = new double[][]{ {3.0,5.0,0.0},{-1.0,0.0,1.0},{2.0,-1.0,0.0} };
    double[][] mat3x2 = new double[][]{ {1.0,2.5},{3.1,1.0},{1.0,2.0} };
    System.out.println("[start]");
    System.out.println("\n[vector 1]");
    PrintArry(vector1);
    System.out.println("\n[vector 2]");
    PrintArry(vector2);
    System.out.println("\n[matrix (3x3)]");
    Print2DArry(mat3x3);
    System.out.println("\n[matrix (3x2)]");
    Print2DArry(mat3x2);
    System.out.println("\n[Vector Dot Product]: " + MatrixOps.dot(vector1,vector2));
    System.out.println("\n[matrix - matrix]: using mult()");
    Print2DArry(MatrixOps.mult(mat3x3,mat3x2));
    System.out.println("\n[transpose matrix 3x2]: using transpose()");
    Print2DArry(MatrixOps.transpose(mat3x2));
    System.out.println("\n[matrix 3x3 - vector 1]: using mult()");
    PrintArry(MatrixOps.mult(mat3x3,vector1));
    System.out.println("\n[vector 1 - matrix 3x3]: using mult()");
    PrintArry(MatrixOps.mult(vector1,mat3x3));
    System.out.println("\n[done]");
  }
}
