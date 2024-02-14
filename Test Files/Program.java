import java.util.Scanner;

class Example
{
    public static void main(String[] args)
    {
        TestClass.PrintSum(1,2);
        int val = ComplexTest(1.5f," test ");
        ComplexTest(0.4f, " e ");
        ComplexTest(3.5f, " def ");
        System.out.println(val);
    }
    public static int ComplexTest(float in1, String in2)
    {
        int val = (int)(in1 * 5);
        System.out.println("Complex Test:");
        for (int i = 0; i < 6; i++)
        {
            System.out.print(in1*i + " ");
            switch ((int)(in1*i))
            {
                default: System.out.println("default"); break;
                case 1: System.out.println(" 1 "); break;
                case 2: System.out.println(" 2 " + in2); break;
                case 3: System.out.println(" 3 " + in2 + in2); break;
                case 4: System.out.println(" 4 "); break;
                case 5: System.out.println(" 5 "); break;
                case 6: System.out.println(" 6 "); break;
                case 7: System.out.println(" 7 " + in2); break;
                case 8: System.out.println(" 8 " + in1 + in2); break;
                case 9: System.out.println(" 9 "); break;
            }
        }
        return (int)(in1 * val);
    }
}