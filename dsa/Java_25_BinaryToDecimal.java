package com.company;
import java.util.*;
public class Java_25_BinaryToDecimal
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the Binary Number : ");
        long n = sc.nextLong();
        long r = 0;
        double k = 0;
        double q = 2.0;
        long sum = 0;
        long m = 0;
        while (n != 0)
        {
            r = n % 10;
            n = n / 10;
            m = (long)Math.pow(q,k);
            sum = sum + r*m;
            k++;
        }
        System.out.println("Decimal Representation is : " + sum);
    }
}

