#include<cstdio>

void Hanoi(int n, char a, char b, char c)
{
    if(n == 1) {
        printf("%c->%c\n", a, c);
    }
    else if(n == 2){
        printf("%c->%c\n", a, b);
        printf("%c->%c\n", a, c);
        printf("%c->%c\n", b, c);
    }
    else{
        Hanoi(n-1, a, c, b);
        printf("%c->%c\n", a, c);
        Hanoi(n-1, b, a, c);
    }

}

int main()
{
    int n;
    scanf("%d", &n);
    Hanoi(n, 'a', 'b', 'c');
    return 0;
}