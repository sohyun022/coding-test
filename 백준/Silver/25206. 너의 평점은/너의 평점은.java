import java.util.Scanner;
class Score{
    String lecture;
    double hour;
    String str;
    double score;
}

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Score[] scr = new Score[20];

        double sum1=0.0;
        double sum2=0.0;

        for(int i=0;i<20;i++){
            scr[i]= new Score();
            scr[i].lecture=sc.next();
            scr[i].hour=sc.nextFloat();
            scr[i].str=sc.next();

            switch(scr[i].str){
                case"A0": scr[i].score=4.0; break;
                case"A+": scr[i].score=4.5; break;
                case"B+": scr[i].score=3.5; break;
                case"B0": scr[i].score=3.0; break;
                case"C+": scr[i].score=2.5; break;
                case"C0": scr[i].score=2.0; break;
                case"D+": scr[i].score=1.5; break;
                case"D0": scr[i].score=1.0; break;
                case"F": scr[i].score=0.0; break;
            }

            if(!scr[i].str.equals("P")){
                sum1+=(scr[i].hour)*(scr[i].score);
                sum2+=scr[i].hour;
            }

        }

        System.out.println(sum1/sum2);

    }
}