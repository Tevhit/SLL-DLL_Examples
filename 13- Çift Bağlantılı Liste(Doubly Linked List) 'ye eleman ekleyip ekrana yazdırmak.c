#include <stdio.h>
#include <stdlib.h>

typedef struct CiftBaglantiliListe
{
    int veri;
    struct Liste * sonraki;
    struct Liste * onceki;
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

int main()
{
    Liste * pListe = NULL;

    int i;
    for(i = 0; i < 5; i++)
    {
        pListe = ListeninSonunaElemanEkle(pListe, i + 1);
    }

    ListeyiYazdir(pListe);

    return 0;
}


/*	Ekran Çıktısı:

Listenin elemanlari : 1 2 3 4 5

*/