import java.io.*;
import java.util.HashSet;
import java.util.Set;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
//        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        

        int t = Integer.parseInt(bf.readLine());

        String num;

        String S;


        for(int i=0;i<t;i++){

            Set <String> diary = new HashSet<>();
            StringBuilder sb = new StringBuilder();
            
            int n = Integer.parseInt(bf.readLine());
            S = bf.readLine();

            StringTokenizer st = new StringTokenizer(S);
            for (int j = 0; j < n; j++) {
                num = st.nextToken();
                diary.add(num);
            }

            int m = Integer.parseInt(bf.readLine());

            S= bf.readLine();
            StringTokenizer ss = new StringTokenizer(S);

            for (int j = 0; j < m; j++){
                num=ss.nextToken();
                if(diary.contains(num))
                    sb.append("1\n");

                else
                    sb.append("0\n");

            }
            System.out.print(sb);

        }

    }
}