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

Liste * ListedekiCiftSiradakiElemanlariSil(Liste * pListe)
{
    int sayac = 1;
    Liste * once = NULL;
    Liste * simdiki = pListe;

    while(simdiki != NULL)
    {
        if(sayac % 2 == 0)
        {
            if(once == NULL)
                pListe = simdiki->sonraki;
            else if(simdiki != NULL)
                once->sonraki = simdiki->sonraki;
        }
        sayac++;

        once = simdiki;
        simdiki = simdiki->sonraki;
    }
    return pListe;
}

int main()
{
    Liste * pListe = NULL;

    int i;
    for(i = 0; i < 10; i++)
    {
        pListe = ListeninSonunaElemanEkle(pListe, i + 1);
    }
    ListeyiYazdir(pListe);

    pListe = ListedekiCiftSiradakiElemanlariSil(pListe);
    ListeyiYazdir(pListe);

    return 0;
}

/*	Ekran Çıktısı:

Listenin elemanlari : 1 2 3 4 5 6 7 8 9 10
Listenin elemanlari : 1 3 5 7 9

*/