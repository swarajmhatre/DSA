package Java;

import java.util.*;
class fibo
{
    public static void main(String[] args)
     {
        int n,a=0,b=1,i=0;
        try (Scanner sc = new Scanner(System.in)) {
            System.out.println("Enter the length of the series");
            n=sc.nextInt();
        }
        while (i<n)
        {
            System.out.print(a+" ");
            int sum=a+b;
            a=b;
            b=sum;
            i++;
        }
    }
}