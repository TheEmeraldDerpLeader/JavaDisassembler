import java.util.Scanner;

class TestClass
{
    public static void PrintSum(int a, int b)
    {
        Printer.PrintSum(a,b);
    }
}

class Printer
{
    public static void PrintSum(int a, int b)
    {
        System.out.println("Sum is " + (a+b));
    }

    public int Test(int a)
    {
        if (a < 4)
            return 0;
        else
            return 1;
    }
}