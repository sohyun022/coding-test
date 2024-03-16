#include <iostream>
int main() {
    int a,b;
    std :: cin >>a>>b;

    int reverse_a[3]={};
    int reverse_b[3]={};

    for(int i=0;i<3;i++){
        reverse_a[i]=a%10;
        a/=10;
        reverse_b[i]=b%10;
        b/=10;
    }
    
    int A=reverse_a[0]*100+reverse_a[1]*10+reverse_a[2];
    int B=reverse_b[0]*100+reverse_b[1]*10+reverse_b[2];

    int result=A>B?A:B;
    
    std:: cout << result;

    return 0;
}
