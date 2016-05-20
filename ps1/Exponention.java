import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Exponention
{

    public static void main(String[] args) 
    {
        Scanner input = new Scanner(System.in);
        while(input.hasNext())
        {
            BigDecimal a = new BigDecimal("" + input.nextFloat() + "");
            int b = input.nextInt();
            BigDecimal res = a.pow(b);
           // System.err.println(" The res " + res.toPlainString());
            String resStr = res.toPlainString();
            String fin = "";
            boolean lead = true;
            int pointInd = 0;
            for(int i = 0; i < resStr.length(); i++)
            {
                if((int)resStr.charAt(i) != 48)
                {
                    lead = false;
                }
                if((int)resStr.charAt(i) != 48 || lead == false)
                {
                    if((int)resStr.charAt(i) == 46)
                    {
                        pointInd = i;
                        //System.err.println(" The pointInd " + pointInd);
                        break;
                    }
                    fin += resStr.charAt(i);
                }
            }
            String rightHalf = "";
            boolean trail = true;
            boolean isInt = true;
            for(int i = (resStr.length() - 1); i >= pointInd; i--)
            {
                if(i == pointInd)
                {
                    if(isInt == false)
                    {
                        rightHalf = "." + rightHalf;
                    }
                }
                else
                {
                    if((int)resStr.charAt(i) != 48)
                    {   
                        isInt = false;
                        trail = false;
                    }
                    if((int)resStr.charAt(i) != 48 || trail == false)
                    {
                        rightHalf = resStr.charAt(i) + rightHalf; 
                    }
                }
            }
            fin += rightHalf;
            System.out.println(fin);
        }
    }
}
