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

Liste * IstenilenElemaniSil(Liste * pListe, int silinecekSayi)
{
    if(pListe == NULL)
    {
        printf("Liste bostur.. \n");
        return pListe;
    }

    int silinmeDurum = 0;

    Liste * pTemp = pListe;

    while(pTemp != NULL)
    {
        if(pTemp->veri == silinecekSayi)
        {
            if(pTemp->onceki != NULL)
                pTemp->onceki->sonraki = pTemp->sonraki;
            else
                pListe = pListe->sonraki;

            if(pTemp->sonraki != NULL)
                pTemp->sonraki->onceki = pTemp->onceki;

            silinmeDurum++;
        }
        pTemp = pTemp->sonraki;
    }

    if(silinmeDurum != 0)
        printf("%d tane %d sayisi listeden silindi..\n", silinmeDurum, silinecekSayi);
    else
        printf("%d sayisi listede bulunamadi..\n", silinecekSayi);

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

    int silinecekEleman;
    printf("Listeden silmek istediginiz elemani giriniz : ");
    scanf("%d", &silinecekEleman);

    pListe = IstenilenElemaniSil(pListe, silinecekEleman);

    ListeyiYazdir(pListe);

    return 0;
}


/*	Ekran Çıktısı:

Listenin elemanlari : 14 26 4 43 4
Listeden silmek istediginiz elemani giriniz : 4
2 tane 4 sayisi listeden silindi..
Listenin elemanlari : 14 26 43

*/