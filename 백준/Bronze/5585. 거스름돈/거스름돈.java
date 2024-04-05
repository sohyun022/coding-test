import java.util.Scanner;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int price;
        price=sc.nextInt();

        int remain=1000-price;

        int[] coin={500,100,50,10,5,1};

        int count=0;

        for(int c: coin){

            if(remain/c>0){
                count+=remain/c;
                remain%=c;
            }

            if(remain==0) {
                System.out.println(count);
                break;
            }


        }
            sc.close();

        }


}