#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct stos
{
    int value;
    struct stos *next;
};

void push(stos *&, int );
void pop(stos *&);
//bool IsEmpty(stos *);  ?           ?????????po co ????? mamy 100 % warunek stopu dla kazdej sytuacji sprawdzajac, czy stos == 0
void delete_whole_stack(stos *&);
void show_whole_stack(stos*);
int top(stos *);

int onp();


int main()
{
    /* czesc do testow
    struct stos *stos_nr1 = nullptr;

    cout << stos_nr1 << " <- pierwszy adres" << endl;
    push(stos_nr1, 7);

    cout << "akutalna pierwsza wartosc: " << top(stos_nr1)  << endl;
     push(stos_nr1, 5);

    cout << "akutalna pierwsza wartosc: " << top(stos_nr1)  << endl;

    push(stos_nr1, 75);
    push(stos_nr1, 15);
    push(stos_nr1, 715);
    push(stos_nr1, 7325);
    show_whole_stack(stos_nr1);
    push(stos_nr1, 75);
    push(stos_nr1, 15);
    push(stos_nr1, 715);
    push(stos_nr1, 7325);
    show_whole_stack(stos_nr1);
    show_whole_stack(stos_nr1);
    //delete_whole_stack(stos_nr1);
    pop(stos_nr1);
    cout << "po usunieciu 1 z gory mamy : akutalna pierwsza wartosc: " << top(stos_nr1) << endl;

    //cout << stos_nr1;
    //show_whole_stack(stos_nr1);
    */
    stos *stos = nullptr;
    int menu = 1,value;
    while(menu)
    {
        cout << "\n\n MENU\n1 - Dodanie wartosci na stos\n2 - Usuniecie wartosci ze stosu\n3 - Sprawdzenie jaka wartosc znajduje sie na gorze stosu\n4 - ";
        cout << "Wyswietlnie calego stosu\n5 - Usunienie calego stosu\n6 - ONP\n7 - notacja konwencjonalna na ONP\n0 - Wyjscie z programu\n";
        cin >> menu  ;
        switch(menu)
        {
            case 0 : cout << "wychodzenie ..."; break;
            case 1 :
                {
                    cout << "Podaj warosc do dodania: ";
                    cin >> value ;
                    push(stos, value);
                    break;

                }
            case 2 :
                {
                    cout << "usuwanie wartosci ze stosu ..";
                    pop(stos);
                    break;
                }
            case 3 :
                {

                    if(top(stos)) cout << "aktualna wartosc na szczycie stosu to : " << top(stos);
                    else cout << "nie ma nic do wyswietlania - stos jest pusty!";
                    break;
                }

            case 4 :
                {
                    show_whole_stack(stos);
                    break;
                }
            case 5 :
                {
                    delete_whole_stack(stos);
                    cout << "stos zostal pomyslnie usuniety";
                    break;
                }
            case 6:
                {
                    int result = onp();
                    cout << "Wynik to "<< result ;
                    break;

                }




            default : cout << "podales zly numer ! sprobuj ponownie ... " ;

        }
    }

    return 0;
}


void push(stos *&current_stos, int  valueto_add)
{
    stos *temp = new stos ;
    temp->value = valueto_add;
    temp->next = current_stos;
    current_stos = temp;
}
int top(stos *current_stos)
{

    if(current_stos)
    {
        return current_stos->value ;
    }

    return 0 ;

}
void pop(stos *&current_stos)
{
    if(current_stos) current_stos = current_stos->next;
    else cout << "\nnie ma nic do wyswietlania - stos jest pusty";
}
void delete_whole_stack(stos *&current_stack)
{
    if(current_stack)
    {
        while(current_stack)
        {
            pop(current_stack);

        }
        delete [] current_stack ;

    }
    else cout << "\nstos juz jest usuniety !";

}
void show_whole_stack(stos*current_stack) // wystarczy nie daæ referencji i pracujemy na kopii wiêc mo¿emy usuwaæ z aktualnego stosu i ¿adne zmiany nie zostan¹
{
    if(current_stack)
    {
       // stos * temp = new stos;
        //temp = current_stack;
        cout << "\n stos \n";
        while(current_stack)
        {
           // cout << "adres -> " << current_stack;
            cout << " aktualny element " <<current_stack->value << endl;

            pop(current_stack);

        }
      //  delete [ ] temp ;
    }
    else cout << "\nnie ma nic do wyswietlania - stos jest pusty";

}
int  onp()
{
    cout << "\n**************************************** ONP ****************************************\n";
    string onp;
    stos *temp = nullptr;
    int a, b , result;
    cout << "Podaj wyrazenie do policzenia odzielajac liczby i operatory spacja lub podawaj po kolei liczby i operatory wciskajac po kazdym klawisz <enter>\nwcisniecie ? powoduje zakonczenie wpisywania \n" ;
    while(onp!= "?")
    {
        cout << " " ;
        cin >> onp; // dlaczego mozna wpisywac po spacji i dziala ????

        //cout << "\nwpisales  " << onp << endl ;
       // show_whole_stack(temp);
        if(isdigit(onp[0]))
        {
            //cout << " jest cyfra - " << stoi(onp) ;
            push(temp, stoi(onp));
        }
        else if ( onp == "+"|| onp == "/" || onp == "-" || onp == "*"  )
        {

            //cout << " jest operatorem ";

            a = top(temp);
            pop(temp);
            b = top(temp);
            pop(temp);


            // + = 43   - = 45   * = 42   / = 47
            switch(int(onp[0])) // po prostu z tablicy ascii zeby sie nie bawic w 17 ifow ;
            {
                case 42 :
                {
                    push(temp , b * a );
                    break;
                }

                case 43 :
                {
                    push(temp , b + a );
                    break;
                }

                case 45 :
                {
                    push(temp , b - a );
                    break;
                }

                case 47 :
                {
                    push(temp , b / a );
                    break;
                }
            }

        }
        else if (onp == "?")
        {
                cout <<  " zakonczono wpisywanie \n" ;
                b = top(temp);
                delete_whole_stack(temp);
                return b;


        }
        else { cout << " jedyno z wpisanych wyrazen nie jest ani liczba ani operatorem, wychodzenie .. " ; exit(42); }

    }
    return 1 ;
}





