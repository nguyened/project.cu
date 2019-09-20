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
      System.out.println("Result: row: "+i+" val: "+smpl[i]);
    }
  }
  public static void Print2DArry(double[][] smpl)
  {
    for(int i=0;i<3;i++)
    {
      for(int j=0;j<3;j++)
      {
        System.out.println("Result: row: "+i+" col: "+j+" val: "+smpl[i][j]);
      }
    }
  }
  public static void main(String[] args)
  {
    System.out.println("[start]");
    double[] vector1 = new double[]{9.0,2.0,7.0};
    double[] vector2 = new double[]{4.0,8.0,10.0};
    double[][] mat1 = new double[][]{ {1.0,0.0,1.0},{0.0,1.0,2.0},{0.0,0.0,0.0} };
    double[][] mat2 = new double[][]{ {3.0,5.0,0.0},{-1.0,0.0,1.0},{2.0,-1.0,0.0} };
    System.out.println("Dot: " + MatrixOps.dot(vector1,vector2));
    Print2DArry(MatrixOps.mult(mat1,mat2));
    System.out.println("[transpose]");
    Print2DArry(MatrixOps.transpose(mat2));
    System.out.println("[m-v]");
    PrintArry(MatrixOps.mult(mat2,vector1));
    System.out.println("[v-m]");
    PrintArry(MatrixOps.mult(vector1,mat2));
    System.out.println("[done]");
  }
}
