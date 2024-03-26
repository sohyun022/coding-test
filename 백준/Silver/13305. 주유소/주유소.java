
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        long[] city = new long[100001];
        long[] road = new long[100000];

        long cost = 0;

        for (int i = 0; i < n - 1; i++) {
            road[i] = sc.nextLong();
        }

        for (int i = 0; i < n; i++) {
            city[i] = sc.nextLong();
        }

        long min = city[0];

        for (int i = 0; i < n; i++) {
            if (city[i] < min)
                min = city[i];
            cost += min * road[i];
        }

        System.out.println(cost);

    }
}