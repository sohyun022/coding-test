import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int[] equ1 = new int[3];
        int[] equ2 = new int[3];

        for (int i = 0; i < 3; i++) {
            equ1[i] = sc.nextInt();
        }
        for (int i = 0; i < 3; i++) {
            equ2[i] = sc.nextInt();
        }

        int x = 0;
        int y = 0;

        for(int i=-999;i<1000;i++) {
            for (int j = -999; j < 1000; j++) {
                if (equ1[0] * i + equ1[1] * j == equ1[2] && equ2[0] * i + equ2[1] * j == equ2[2]) {
                    x = i;
                    y = j;
                    break;
                }
            }
        }

        System.out.println(x + " " + y);
    }
}

