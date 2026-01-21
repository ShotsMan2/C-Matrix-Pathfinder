#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, j, satir, sutun, uygun, a, d, satira, sutuna, satirb, sutunb, k;

    srand(time(NULL));

    do
    {
        printf("n i 6 dan buyuk yazin.\n");
        printf("n i girin: ");
        scanf("%d", &n);

    } while (n <= 6);

    printf("\n");

    for (d = 0; d < 5; d++)
    {
        char matris[n][n], koyulacak;

        // Matrisi temizle
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                matris[i][j] = '_';
            }
        }

        // A ve B noktalarını yerleştir
        do
        {
            uygun = 1;

            satira = rand() % n;
            sutuna = rand() % n;
            matris[satira][sutuna] = 'A';

            satirb = rand() % n;
            sutunb = rand() % n;
            matris[satirb][sutunb] = 'B';

            int satirfarki = satira - satirb;
            if (satirfarki < 0) satirfarki *= -1;

            int sutunfarki = sutuna - sutunb;
            if (sutunfarki < 0) sutunfarki *= -1;

            int manhattan = sutunfarki + satirfarki;

            if (manhattan < 4)
            {
                uygun = 0;
                matris[satira][sutuna] = '_';
                matris[satirb][sutunb] = '_';
            }

        } while (uygun == 0);

        // Engelleri (X) ve Boşlukları (O) yerleştir
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if (matris[i][j] != '_') continue;

                a = rand() % 2;
                if (a == 0) koyulacak = 'O';
                else koyulacak = 'X';

                if (koyulacak == 'X')
                {
                    if (j >= 2 && matris[i][j - 1] == 'X' && matris[i][j - 2] == 'X')
                        koyulacak = 'O';
                    else if (i >= 2 && matris[i - 1][j] == 'X' && matris[i - 2][j] == 'X')
                        koyulacak = 'O';
                }
                matris[i][j] = koyulacak;
            }
        }

        // İlk haritayı yazdır
        printf("%d. Deneme Haritasi:\n", d+1);
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                printf("%c ", matris[i][j]);
            }
            printf("\n");
        }
        printf("\n");

        // YOL BULMA ALGORİTMASI DEĞİŞKENLERİ
        int yolx[n * n];
        int yoly[n * n];
        int top = 0;

        int ziyaret[n][n];
        // YENİ: Adım sayılarını tutacak integer matris
        int adimlar[n][n];

        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                ziyaret[i][j] = 0;
                adimlar[i][j] = 0; // Adımları sıfırla
            }
        }

        yolx[top] = satira;
        yoly[top] = sutuna;
        ziyaret[satira][sutuna] = 1;

        int hedefbulundu = 0;
        int adimsayisi = 0; // A noktası 0. adım

        int xyon[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int yyon[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        while (top >= 0)
        {
            int suankix = yolx[top];
            int suankiy = yoly[top];

            if (suankix == satirb && suankiy == sutunb)
            {
                hedefbulundu = 1;
                break;
            }

            // DÜZELTME: Sayıyı karakter matrisine değil, sayı matrisine kaydet
            if (matris[suankix][suankiy] != 'A' && matris[suankix][suankiy] != 'B')
            {
                adimlar[suankix][suankiy] = adimsayisi;
            }

            int yolbulundu = 0;

            for (k = 0; k < 8; k++)
            {
                int yenix = suankix + xyon[k];
                int yeniy = suankiy + yyon[k];

                if (yenix >= 0 && yenix < n && yeniy >= 0 && yeniy < n)
                {
                    if (ziyaret[yenix][yeniy] == 0 && (matris[yenix][yeniy] == 'O' || matris[yenix][yeniy] == 'B'))
                    {
                        top++;
                        yolx[top] = yenix;
                        yoly[top] = yeniy;

                        ziyaret[yenix][yeniy] = 1;
                        adimsayisi++;

                        yolbulundu = 1;
                        break;
                    }
                }
            }

            // DÜZELTME: Geri adım atarken (Backtracking)
            if (yolbulundu == 0)
            {
                // Yanlış yola girilen sayıyı sil ki ekranda sadece doğru yol kalsın
                if (matris[suankix][suankiy] != 'A' && matris[suankix][suankiy] != 'B')
                {
                    adimlar[suankix][suankiy] = 0;
                }

                top--;
                adimsayisi--;
            }
        }

        if (hedefbulundu == 1)
        {
            printf("Hedef Bulundu! Iste Yol:\n");
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    // Eğer burası bir yol ise (A veya B değilse ve adım sayısı varsa)
                    if (matris[i][j] != 'A' && matris[i][j] != 'B' && adimlar[i][j] > 0)
                    {
                        // %3d ile 3 haneli yer ayır (hizalama için)
                        printf("%3d ", adimlar[i][j]);
                    }
                    else
                    {
                        // Sayı yoksa normal harfi bas ama hizalamayı bozma
                        // %c'nin yanına boşluklar koyarak sayı genişliğine eşitledik
                        printf(" %c  ", matris[i][j]);
                    }
                }
                printf("\n");
            }
            break; // Döngüden çık
        }
        else
        {
            printf("Haritada yol bulunamadi.\n");
        }
    }

    if (d == 5)
    {
        printf("5 denemede de uygun yol bulunamadi.\n");
    }

    return 0;
}
