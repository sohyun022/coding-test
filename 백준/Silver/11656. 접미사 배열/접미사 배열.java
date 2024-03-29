import java.util.Arrays;
import java.util.Scanner;
import java.lang.String;
public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        String S = sc.nextLine();

        String[] str = new String[S.length()];

        int length=S.length();


        for(int i=0;i<length;i++){
            str[i]=S.substring(i);
        }

        Arrays.sort(str);

        for(int i=0;i<length;i++){
            System.out.println(str[i]);
        }
    }
}