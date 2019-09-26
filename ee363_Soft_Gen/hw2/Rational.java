/*
 * @purpose EE363 - HW2 - Rational
 * @authors Evan Nguyen CE , Paul Schmid SE
 * @modified Sep 25, 2019
*/
public class Rational
{
  public static int[] Radd(int a,int b,int c,int d)
  {
    int[] result = new int[2];
    result[0] = a+c;
    result[1] = 0; //testing
    return result;
  }
  public static void main(String[] args)
  {
    System.out.println("[start]\n");
    int n1=5, d1=6, n2=3, d2=4;
    int[] output = new int[2];
    output = Radd(n1,d1,n2,d2);
    System.out.println("r1: "+n1+"/"+d1+"\nr2: "+n2+"/"+d2);
    System.out.println("r1 + r2: "+output[0]+"/"+output[1]);
    System.out.println("\n[done]");
  }
}
