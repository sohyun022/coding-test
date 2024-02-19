import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int[] dice= new int[3];

        int grt=0;

        int[] count = new int[7];

        for(int i=0;i<3;i++){
            dice[i]=scanner.nextInt();

            count[dice[i]]++;

            if(count[dice[i]]==3){
                System.out.println(10000+dice[i]*1000);
                System.exit(0);
            }

            if(dice[i]>grt)
                grt=dice[i];
        }

        for(int i=1;i<7;i++){
            if(count[i]==2){
                System.out.println(1000+i*100);
                System.exit(0);
            }
        }

        System.out.println(grt*100);

    }
}