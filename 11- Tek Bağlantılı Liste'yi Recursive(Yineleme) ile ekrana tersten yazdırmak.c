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

void ListeyiTerstenYazdir(Liste * pListe)
{
    if(pListe)
    {
        ListeyiYazdir(pListe->sonraki);
        printf("%d ", pListe->veri);
    }
}

int main()
{
    Liste * pListe = NULL;

    int i;
    for(i = 0; i < 5; i++)
    {
        pListe = ListeninSonunaElemanEkle(pListe, i + 1);
    }

    printf("Recursive -ozyineleme- ile tersten yazdirilmis liste : \n");
    ListeyiTerstenYazdir(pListe);

    return 0;
}

/*	Ekran Çıktısı:

Recursive -ozyineleme- ile tersten yazdirilmis liste :
5 4 3 2 1

*/