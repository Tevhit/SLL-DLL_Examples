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

int ListedekiEnBuyukEleman(Liste * pListe)
{
    int enBuyukEleman = pListe->veri;

    pListe = pListe->sonraki;

    while(pListe != NULL)
    {
        if(pListe->veri > enBuyukEleman)
        {
            enBuyukEleman = pListe->veri;
        }
        pListe = pListe->sonraki;
    }

    return enBuyukEleman;
}

int ListedekiEnKucukEleman(Liste * pListe)
{
    int enBuyukEleman = pListe->veri;

    pListe = pListe->sonraki;

    while(pListe != NULL)
    {
        if(pListe->veri < enBuyukEleman)
        {
            enBuyukEleman = pListe->veri;
        }
        pListe = pListe->sonraki;
    }

    return enBuyukEleman;
}

int main()
{
    srand(time(NULL));
    Liste * pListe = NULL;

    int sayi;
    int i;
    for(i = 0; i < 5; i++)
    {
        sayi = rand() % 50 + 1;
        pListe = ListeninSonunaElemanEkle(pListe, sayi);
    }

    ListeyiYazdir(pListe);

    int enBuyukEleman = ListedekiEnBuyukEleman(pListe);
    printf("Listedeki en buyuk eleman = %d \n", enBuyukEleman);

    int enKucukEleman = ListedekiEnKucukEleman(pListe);
    printf("Listedeki en kucuk eleman = %d \n", enKucukEleman);

    return 0;
}

/*	Ekran Çıktısı:

Listenin elemanlari : 25 31 32 47 19
Listedeki en buyuk eleman : 47
Listedeki en kucuk eleman 19

*/