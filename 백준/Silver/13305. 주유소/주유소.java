import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int[] city = new int[100001];
        int[] road = new int[100000];

        long cost = 0;

        for (int i = 0; i < n - 1; i++) {
            road[i] = sc.nextInt();
        }

        for (int i = 0; i < n; i++) {
            city[i] = sc.nextInt();
        }

        int min = city[0];

        for (int i = 0; i <= n; i++) {
            if (city[i] < min)
                min = city[i];
            cost += (long)min * road[i];
        }

        System.out.println(cost);

    }
}