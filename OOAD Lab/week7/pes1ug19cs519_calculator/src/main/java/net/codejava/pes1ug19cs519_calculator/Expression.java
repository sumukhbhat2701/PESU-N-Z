/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package net.codejava.pes1ug19cs519_calculator;

/**
 *
 * @author sumukhbhat2701 - PES1UG19CS519
 * Model
 */
public class Expression {
    String op;
    String op1;
    String op2;
    String res;
    
    public Expression(String opx, String op1x, String op2x)
    {
        op = opx;
        op1 = op1x;
        op2 = op2x;
    }
    public int gcd(int a, int b)
    {
        if (a == 0)
          return b;
        if (b == 0)
          return a;
      
        // base case
        if (a == b)
            return a;
      
        // a is greater
        if (a > b)
            return gcd(a-b, b);
        return gcd(a, b-a);
    }
    public String calculate()
    {
        double x = Double.parseDouble(op1);
        double y = Double.parseDouble(op2);
        if(op.equals("+"))
        {
            res = String.valueOf(x+y);
        }
        else if(op.equals("-"))
        {
            res = String.valueOf(x-y);
        }
        else if(op.equals("*"))
        {
            res = String.valueOf(x*y);
        }
        else if(op.equals("/"))
        {
            if(y!=0)
                res = String.valueOf(x/y);
            else 
                res = "Infinity";
        }
        else if(op.equals("gcd"))
        {
            res = String.valueOf(gcd((int)x, (int)y));
        }
        else if(op.equals("lcm"))
        {
            int lcm = (int)((int)x / gcd((int)x, (int)y)) * (int)y;
            res = String.valueOf(lcm);
        }
        else
        {
            res = "Incorrect operator/operator";
        }
        return res;
    }
}