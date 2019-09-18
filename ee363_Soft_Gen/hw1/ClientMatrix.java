/*
 * @purpose Demostrates usage of MatrixOps
 *
 * @author Evan Nguyen
 *
 * @modified Sep 18, 2019
*/
public class ClientMatrix
{
  public static void main(String[] args)
  {
    System.out.println("[start]");
    double[] vector1 = new double[]{-6.0,8.0,0.0};
    double[] vector2 = new double[]{5.0,12.0,0.0};
    System.out.println(MatrixOps.dot(vector1,vector2));
    System.out.println("[done]");
  }
}
