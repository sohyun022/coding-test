#include <iostream>
int main() {
    int t;
    std :: cin >>t;

    for(int i=0;i<t;i++){
        int score[80]={};
        int sum=0;
        char ox[80]="";
        int count=0;

        std :: cin >> ox;

        for(int j=0;ox[j]!='\0';j++) {
            if (ox[j] == 'O') {
                count++;
            }
            else {
                count=0;
            }
            score[j]=count;
            sum += score[j];
        }

        std::cout << sum << std::endl;
    }


    return 0;
}
