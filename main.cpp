#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define NR_CARTI_MANA 5
#define NR_CARTI_PACHET 52
#define FORME 4
#define RANGURI 13
struct carte{
    int rang; //0-13 (2,3,...,10,J,Q,K,A)
    int forma;//0-3  (0=R(romb), 1=I(inima), 2=F(frunza), 3=T(trefla))
};
void creaza_pachet(struct carte*);
void amesteca_pachet(struct carte*);
void imparte_carti(struct carte*, struct carte*, struct carte*); //doar pentru un jucator
void afiseaza_o_carte(struct carte *,int i);
void afiseaza_pachet(struct carte *Pachet);
int main()
{
    struct carte *Pachet=malloc(NR_CARTI_PACHET*sizeof(struct carte));
    creaza_pachet(Pachet);
    amesteca_pachet(Pachet);
    afiseaza_pachet(Pachet);
    struct carte *J1=malloc(NR_CARTI_MANA*sizeof(struct carte));
    struct carte *J2=malloc(NR_CARTI_MANA*sizeof(struct carte));
    imparte_carti(J1,J2,Pachet);
}
// cream pachetul neamestecat
void creaza_pachet(struct carte *Pachet)
{
    int i,j;
    for(i=0;i<FORME;i++)
        for(j=0;j<RANGURI;j++)
        {
            Pachet[RANGURI*i+j].rang=j;
            Pachet[RANGURI*i+j].forma=i;
        }
}
void afiseaza_o_carte(struct carte *p,int i)
{
    FILE *f=fopen("fisier.txt","w");
    if(p[i].rang<=8)
        {
            fprintf(f,"%d",p[i].rang+2);
        }
        else
        {
            switch(p[i].rang)
            {
                case 9:  fputc('J',f);
                break;
                case 10: fputc('Q',f);
                break;
                case 11: fputc('K',f);
                break;
                case 12: fputc('A',f);
                break;
            }
        }
        //afisare forma
        switch(p[i].forma)
        {
            case 0: fputc('R',f);
            break;
            case 1: fputc('I',f);
            break;
            case 2: fputc('F',f);
            break;
            case 3: fputc('T',f);
            break;
        }
        fputc(' ',f);
    fclose(f);
}
void afiseaza_pachet(struct carte *Pachet)
{
    FILE *f=fopen("fisier.txt","w");
    int i;
    for(i=0;i<NR_CARTI_PACHET;i++)
    {
        afiseaza_o_carte(Pachet,i);
        if(i==12||i==25||i==38)
        fputc('\n',f);
    }
    fclose(f);
}
void amesteca_pachet(struct carte *Pachet)
{
    int i,j;
    struct carte aux;
    srand(time(NULL));
    for(i=0;i<NR_CARTI_PACHET;i++)
    {
        j=rand()%51;
        aux=Pachet[i];
        Pachet[i]=Pachet[j];
        Pachet[j]=aux;
    }
}
void imparte_carti(struct carte *J1, struct carte *J2, struct carte *Pachet)
{
    int i;
    for(i=0;i<NR_CARTI_MANA;i++)
    {
        J1[i]=Pachet[i];
        J2[i]=Pachet[NR_CARTI_MANA+i];
    }
}
void afisare_maini(struct carte *J1,struct carte*J2)
{
    int i;
    for(i=0;i<NR_CARTI_MANA;i++)
    {
    }
}
