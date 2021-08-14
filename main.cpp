#include <iostream>

using namespace std;
struct elemt{ int info;
            elemt *suiv;
            };
struct pile{ elemt *sommet;
            };
bool si_vide(pile *f)
{   bool out=false;
    if(f==NULL)
        out=true;
    else{
        if(f->sommet==NULL)
            out=true;
        }
    return out;
}
int long_pile(pile *f)
{  elemt *e=NULL;
   int nbe=0;
   if(si_vide(f)==false)
   { e=f->sommet;
   while(e!=NULL)
   {
       nbe++;
       e=e->suiv;
   }
    }
    return nbe;
}
void empiler(pile *&f,int val)
{ elemt *nov;
  if(f==NULL)
  {
      f= new pile;
      f->sommet=NULL;
  }
  nov=new elemt;
  nov->info=val;
  nov->suiv=f->sommet;
  f->sommet=nov;

}
void depiler(pile *&f)
{  elemt *p;
    if(si_vide(f)==false)
      {p=f->sommet;
       f->sommet=f->sommet->suiv;
       delete p;
      }

}
int val_tete(pile *f)
{
    if(si_vide(f)==false)
        return f->sommet->info;
    else
        return -1;
}
void cree_pile(pile *&f,int tai)
 {  int valeur;
     for(int i=0;i<tai;i++)
     { cout<<"donner la valeur de "<<i+1<<" element:";
       cin>>valeur;
       empiler(f,valeur);
     }
 }
void supprimer(pile *&f)
{ if(si_vide(f))
     cout<<"la pile est vide!!!!\n";
  else{
    while(f->sommet!=NULL)
       depiler(f);
    cout<<"la pile a ete supprimer!!!!\n";
    }
}
void affich_pile(pile *f)
{   cout<<"-------------AFFICHAGE-------------------\n";
    if(si_vide(f)==false)
    {
        elemt *e;
        e=f->sommet;
        while(e!=NULL)
        {   cout<<e->info<<endl;
            e=e->suiv;
        }
    }
    else
        cout<<"la pile est vide,rien a affiche!!!!!\n";
    cout<<"----------------------------------------\n";
}

int main()
{ pile *f=NULL;
    int tai;int choix;
    cout<<"donner le nombre des elements de la pile:\n";
    cin>>tai;
    cree_pile(f,tai);
    cout<<"|--------------------MENU------------------------|\n";
    cout<<"|1.savoir si la pile est vide.                   |\n";
    cout<<"|2.la longueur de la pile.                       |\n";
    cout<<"|3.empiler un element.                           |\n";
    cout<<"|4.depiler un element.                           |\n";
    cout<<"|5.supprimer une pile.                           |\n";
    cout<<"|6.affichage des elements de la pile.            |\n";
    cout<<"|7.Quiter.                                       |\n";
    cout<<"|------------------------------------------------|\n";
    do{
    cout<<"donner votre choix:\n";
    cin>>choix;
    switch(choix)
    {
        case 1:{
            if(si_vide(f))
                cout<<"la pile est vide!!!!\n";
            else
                cout<<"la pile n est pas vide!!!!\n";
            };break;
        case 2:{
            cout<<"--------------------------------\n";
            cout<<"la longueur de la pile est:"<<long_pile(f)<<endl;
            cout<<"--------------------------------\n";
                };break;
        case 3:{
            int valeur;
            cout<<"donner la valeur a empiler:\n";
            cin>>valeur;
            empiler(f,valeur);
                };break;
        case 4:{depiler(f);
                cout<<"--------------------------------\n";
                cout<<"l element a ete depiler!!!!!\n";
                cout<<"--------------------------------\n";
                };break;
        case 5:supprimer(f);break;
        case 6:affich_pile(f);break;
        case 7:{supprimer(f);
               cout<<"fin de programme a bientot\n";
                }break;
    }
    }while(choix!=7);



    return 0;
}
