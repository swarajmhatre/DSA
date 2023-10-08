package Java;
import java.util.*;
public class palindrome {
    public static void main(String args[])
    {
        try (Scanner sc = new Scanner(System.in)) {
            int len,i;
            String str="",revstr="";
            System.out.println("Enter the String");
            str=sc.nextLine();
            len=str.length();
            for (i=len-1;i>=0;i--)
            {
                revstr=revstr+str.charAt(i);
            }
            if(str.equalsIgnoreCase(revstr)) 
            System.out.println(str+" is a Palindrome String");
            else
            System.out.println(str+" is not a Palindrome String");
        }
    }
    
}
