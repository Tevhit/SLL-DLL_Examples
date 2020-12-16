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

Liste * ListeninSonundakiElemaniCikar(Liste * pListe)
{
    if(pListe == NULL)
    {
        printf("The list is empty \n");
        return;
    }

    Liste * once = NULL;
    Liste * simdi = pListe;

    while(simdi->sonraki != NULL)
    {
        once = simdi;
        simdi = simdi->sonraki;
    }

    once->sonraki = NULL;
    free(simdi);

    return pListe;
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

    pListe = ListeninSonundakiElemaniCikar(pListe);
    ListeyiYazdir(pListe);

    return 0;
}

/*	Ekran Çıktısı:

Listenin elemanlari : 1 2 3 4 5
Listenin elemanlari : 1 2 3 4

*/