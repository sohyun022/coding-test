import java.util.Scanner;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String word;
        word = sc.nextLine();
        int l=word.length();

        for(int i=0;i<l;i++){
            if(word.charAt(i)!=word.charAt(l-1-i)){
                System.out.println("0");
                System.exit(0);
            }
        }
        System.out.println("1");

    }
}