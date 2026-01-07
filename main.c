#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n,i,j,satir,sutun,uygun,a,d,satira,sutuna,satirb,sutunb,k;

    srand(time(NULL));

    do{
        printf("n i 6 dan buyuk yazin.\n");
        printf("n i girin ");
        scanf("%d",&n);

    }while(n<=6);

    printf("\n");

    for(d=0;d<5;d++){
        char matris[n][n],koyulacak;

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            matris[i][j]='_';
        }
    }

    do{
        uygun=1;

        satira=rand()%n;
        sutuna=rand()%n;

        matris[satira][sutuna]='A';

        satirb=rand()%n;
        sutunb=rand()%n;

        matris[satirb][sutunb]='B';

        int satirfarki=satira-satirb;
        if(satirfarki<0){
            satirfarki*=-1;
        }

        int sutunfarki=sutuna-sutunb;
        if(sutunfarki<0){
            sutunfarki*=-1;
        }

        int manhattan=sutunfarki+satirfarki;

        if(manhattan<4){
            uygun=0;
            matris[satira][sutuna]='_';
            matris[satirb][sutunb]='_';
        }

    }while(uygun==0);

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(matris[i][j]!='_'){
                continue;
            }
            a=rand()%2;
            if(a==0){
                koyulacak='O';
            }
            else{
                koyulacak='X';
            }

            if(koyulacak=='X'){
                if(j>=2 && matris[i][j-1]=='X' && matris[i][j-2]=='X'){
                    koyulacak='O';
                }
                else if(i>=2 && matris[i-1][j]=='X' && matris[i-2][j]=='X'){
                    koyulacak='O';
                }
            }

            matris[i][j]=koyulacak;

        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("%c ",matris[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    int yolx[n*n];
    int yoly[n*n];
    int top=0;

    int ziyaret[n][n];
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            ziyaret[i][j]=0;
        }
    }

    yolx[top]=satira;
    yoly[top]=sutuna;
    ziyaret[satira][sutuna]=1;

    int hedefbulundu=0;
    int adimsayisi=0;

    int xyon[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int yyon[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    while(top>=0){
        int suankix=yolx[top];
        int suankiy=yoly[top];

        if(suankix==satirb && suankiy==sutunb){
            hedefbulundu=1;
            break;
        }

        if(matris[suankix][suankiy]!='A' && matris[suankix][suankiy]!='B'){
            matris[suankix][suankiy]=(adimsayisi%10)+'0';
        }
        int yolbulundu=0;

        for(k=0;k<8;k++){
            int yenix=suankix+xyon[k];
            int yeniy=suankiy+yyon[k];

            if(yenix>=0 && yenix<n && yeniy>=0 && yeniy<n){
                if(ziyaret[yenix][yeniy]==0 && (matris[yenix][yeniy]=='O' || matris[yenix][yeniy]=='B')){

                    top++;
                    yolx[top]=yenix;
                    yoly[top]=yeniy;

                    ziyaret[yenix][yeniy]=1;
                    adimsayisi++;

                    yolbulundu=1;
                    break;
                }

            }
        }
        if(yolbulundu==0){
            top--;
            adimsayisi--;
        }
    }

    if(hedefbulundu==1){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                printf("%c ",matris[i][j]);
            }
            printf("\n");
        }
        break;
    }
    else{
        printf("haritada yol bulunamadi.\n");
    }

    }

    if(d==5){
        printf("5 denemede de uygun yol bulunamadı.\n");
    }





    return 0;
}
