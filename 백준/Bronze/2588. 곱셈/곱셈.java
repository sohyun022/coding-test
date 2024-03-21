import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int a = sc.nextInt();
        int b = sc.nextInt();

        int x= a*b;

        for(int i=0;i<3;i++){
            System.out.println(a*(b%10));
            b/=10;
        }

        System.out.println(x);


    }

}