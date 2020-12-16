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

Liste * ListedenIstenilenElemaniRecursiveSil(Liste * pListe, int silinecekEleman)
{
    if(pListe == NULL)
    {
        printf("Liste bostur.. \n");
        return pListe;
    }

    Liste * pElemanListe;

    if(pListe->veri == silinecekEleman)
    {
        pElemanListe = pListe->sonraki;
        free(pListe);
        return pElemanListe;
    }
    else
    {
        pListe->sonraki = ListedenIstenilenElemaniRecursiveSil(pListe->sonraki, silinecekEleman);
        return pListe;
    }
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

    pListe = ListedenIstenilenElemaniRecursiveSil(pListe, 8);
    ListeyiYazdir(pListe);

    return 0;
}

/*	Ekran Çıktısı:

Listenin elemanlari : 1 2 3 4 5 6 7 8 9 10
Listenin elemanlari : 1 2 3 4 5 6 7 9 10

*/