#include <stdio.h>
#include <stdlib.h>

typedef struct CiftBaglantiliListe
{
    int veri;
    struct CiftBaglantiliListe * sonraki;
    struct CiftBaglantiliListe * onceki;
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
    pYeniEleman->onceki = NULL;

    if(pEleman == NULL)
        return pYeniEleman;

    while(pEleman->sonraki != NULL)
        pEleman = pEleman->sonraki;

    pEleman->sonraki = pYeniEleman;
    pYeniEleman->onceki = pEleman;

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

Liste * TekSiradakiElemanlariSil(Liste * pListe)
{
    if(pListe == NULL)
    {
        printf("Liste bostur.. \n");
        return pListe;
    }

    Liste * pTemp = pListe;

    int sira = 1;

    while(pTemp != NULL)
    {
        if(sira % 2 == 1)
        {
            if(pTemp->onceki != NULL)
                pTemp->onceki->sonraki = pTemp->sonraki;
            else
                pListe = pListe->sonraki;

            if(pTemp->sonraki != NULL)
                pTemp->sonraki->onceki = pTemp->onceki;
        }

        sira++;

        pTemp = pTemp->sonraki;
    }

    return pListe;
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

    pListe = TekSiradakiElemanlariSil(pListe);

    ListeyiYazdir(pListe);

    return 0;
}

/*	Ekran Çıktısı:

Listenin elemanlari : 35 43 25 12 6
Listenin elemanlari : 43 12

*/