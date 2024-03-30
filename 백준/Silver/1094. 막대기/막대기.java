import java.lang.Math;
import java.util.Scanner;
import java.lang.String;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        double n = sc.nextInt();

        int i=6;
        int count = 0;

        while(true){
            if(n-Math.pow(2,i)>=0){
                count++;
                n-=Math.pow(2,i);
            }
            i--;
            if(n==0)
                break;
        }

        System.out.println(count);


    }
}