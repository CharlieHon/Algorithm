#include<cstdio>
/**
 * @brief 
 * 10 a
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa
 */
int main()
{
    int col, row;
    char a;
    scanf("%d %c", &col, &a);
    row = col * 0.5;
    for(int i=0; i<row; ++i){
        if(i == 0 || i == row-1){
            for(int j=0; j<col; ++j){
                printf("%c", a);
                if(j == col-1)
                    printf("\n");
            }
        }
        else{
            for(int j=0; j<col; ++j){
                if(j == 0){
                    printf("%c", a);
                }
                else if(j == col-1){
                    printf("%c\n", a);
                }
                else{
                    printf(" ");
                }
            }
        }
    }
    return 0;
}