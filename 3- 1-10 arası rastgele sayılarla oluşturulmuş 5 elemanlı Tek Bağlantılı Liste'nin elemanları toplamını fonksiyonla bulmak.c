#include <stdio.h>
#include <stdlib.h>

typedef struct TekBaglantiliListe
{
    int veri;
    struct Liste * sonraki;
} Liste;

Liste * ListeninSonunaElemanEkle(Liste * pListe, int eklenecekEleman)
{
    Liste * pEleman = pListe;

    Liste * pYeniEleman = malloc(sizeof(Liste));
    if(pYeniEleman == NULL)
    {
        printf("Bellekte yer ayrilmaya izin verilmedi \n");
        exit(1);
    }

    pYeniEleman->veri = eklenecekEleman;
    pYeniEleman->sonraki = NULL;

    if(pEleman == NULL)
        return pYeniEleman;

    while(pEleman->sonraki != NULL)
        pEleman = pEleman->sonraki;

    pEleman->sonraki = pYeniEleman;

    return pListe;
}

void ListeyiYazdir(Liste * pListe)
{
    if(pListe == NULL)
    {
        printf("Liste bostur.. \n");
        return;
    }

    printf("Listenin elemanlari : ");

    while(pListe != NULL)
    {
        printf("%d ", pListe->veri);
        pListe = pListe->sonraki;
    }
    printf("\n");
}

int ListedekiElemanlarinToplami(Liste * pListe)
{
    int toplam = 0;

    while(pListe != NULL)
    {
        toplam = toplam + pListe->veri;
        pListe = pListe->sonraki;
    }

    return toplam;
}

int main()
{
    srand(time(NULL));
    Liste * pListe = NULL;

    int sayi;
    int i;
    for(i = 0; i < 5; i++)
    {
        sayi = rand() % 10 + 1;
        pListe = ListeninSonunaElemanEkle(pListe, sayi);
    }

    ListeyiYazdir(pListe);

    int elemanlarToplami = ListedekiElemanlarinToplami(pListe);
    printf("Listedeki elemanlarin toplami = %d \n", elemanlarToplami);

    return 0;
}

/*	Ekran Çıktısı:

Listenin elemanlari : 6 4 8 1 1
Listedeki elemanlarin toplami = 20

*/