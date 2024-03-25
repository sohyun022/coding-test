import java.util.Scanner;

public class Main{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();

        long[] p = new long[100];

        p[0]=1;
        p[1]=1;
        p[2]=1;

        for(int i=3;i<100;i++){
            p[i]=p[i-3]+p[i-2];
        }

        int n;

        for(int i=0;i<t;i++){
            n = sc.nextInt();
            System.out.println(p[n-1]);
        }
    }
}