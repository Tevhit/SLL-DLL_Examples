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

Liste * IstenilenSiradakiElemaniSil(Liste * pListe, int silinecekSira)
{
    if(pListe == NULL)
    {
        printf("Liste bostur.. \n");
        return pListe;
    }

    Liste * pTemp = pListe;

    int sayac = 1;

    while(pTemp != NULL)
    {
        if(sayac == silinecekSira)
        {
            if(pTemp->onceki != NULL)
                pTemp->onceki->sonraki = pTemp->sonraki;
            else
                pListe = pListe->sonraki;

            if(pTemp->sonraki != NULL)
                pTemp->sonraki->onceki = pTemp->onceki;
        }
        pTemp = pTemp->sonraki;

        sayac++;
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

    int silinecekSira;
    printf("Listeden silmek istediginiz elemanin sirasini giriniz : ");
    scanf("%d", &silinecekSira);

    pListe = IstenilenSiradakiElemaniSil(pListe, silinecekSira);

    ListeyiYazdir(pListe);

    return 0;
}

/*	Ekran Çıktısı:

Listenin elemanlari : 14 26 4 43 19
Listeden silmek istediginiz elemanin sirasini giriniz : 2
Listenin elemanlari : 14 4 43 19

*/