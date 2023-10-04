package Java;
import java.util.Scanner;
public class calculator {
    public static void main(String args[])
    {
        try (Scanner sc = new Scanner(System.in)) {
            int num1,num2;
            System.out.println("Enter the numbers:");
            num1 = sc.nextInt();
            num2 = sc.nextInt();
            System.out.println("Enter the operator (+,-,*,/):");
            char opr=sc.next().charAt(0);
            int ans=0;
            switch (opr) 
            {
            case '+':
                ans=num1+num2;;
                break;
            case '-':
                ans=num1-num2;
                break;
            case '*':
                ans=num1*num2;
                break;
            case '/':
                ans=num1/num2;
                break;
            default:
                System.out.println("Wrong input");
            }
 
            System.out.println("The final result:");
            System.out.println(num1+" "+opr+" "+num2+" = "+ans);
        }
    }
    }
