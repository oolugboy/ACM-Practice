import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;
import java.lang.*;
public class Main  {

    public static void main(String[] args) 
    {
        double total = 0;
        TreeMap<String, Double> trees = new TreeMap<String, Double>();
        Scanner getStuff = new Scanner(System.in);
        while(getStuff.hasNext())
        {
            String val = getStuff.nextLine();
            total++;
            if(trees.containsKey(val) == false)
            {
                trees.put(val, new Double(1));
            }
            else
            {
                trees.put(val, new  Double(trees.get(val).doubleValue() + 1));
            } 
        }
        Iterator<Map.Entry<String, Double>> it =
        trees.entrySet().iterator();
        while(it.hasNext())
        {
            Map.Entry<String, Double> curr = it.next();
            double pcent = ((curr.getValue().doubleValue()/(double)total) * (double)100);
            String percent = String.format("%.4f", pcent);
            System.out.println(curr.getKey() + " " + percent);

        } 
    }
}

