import java.util.Scanner;
import java.lang.String;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        double n = sc.nextInt();

        int stick = 64;

        int count=0;

        while(true){
            if(n-stick>=0){
                count++;
                n-=stick;
            }
            if(n==0) break;
            stick >>= 1;

        }
        System.out.println(count);


    }
}