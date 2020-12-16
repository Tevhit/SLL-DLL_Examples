#include <stdio.h>
#include <stdlib.h>

typedef struct CiftBaglantiliListe
{
    int veri;
    struct Liste * sonraki;
    struct Liste * onceki;
} Liste;

Liste * ListeninBasinaElemanEkle(Liste * pListe, int eklenecekEleman)
{
    Liste * pYeniEleman = malloc(sizeof(Liste));
    if(pYeniEleman == NULL)
    {
        printf("Bellekte yer ayrilmaya izin verilmedi \n");
        exit(1);
    }

    pYeniEleman->veri = eklenecekEleman;
    pYeniEleman->sonraki = pListe;
    pYeniEleman->onceki = NULL;

    return pYeniEleman;
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
        pListe = ListeninBasinaElemanEkle(pListe, i + 1);
    }

    ListeyiYazdir(pListe);

    return 0;
}

/*	Ekran Çıktısı:

Listenin elemanlari : 5 4 3 2 1

*/