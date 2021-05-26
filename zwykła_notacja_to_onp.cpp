







#include <iostream>
#include <string>
using namespace std;




struct stos
{
    string value;
    struct stos *next;
};

void push(stos *&, string );
void pop(stos *&);
//bool IsEmpty(stos *);  ?           ?????????po co ????? mamy 100 % warunek stopu dla kazdej sytuacji sprawdzajac, czy stos == 0
void delete_whole_stack(stos *&);
void show_whole_stack(stos*);
string top(stos *);
string onp_to_n();
void n_to_onp();

int main()
{
    stos *stos = nullptr;
    int menu = 1;
    string value;
    while(menu)
    {
        cout << "\n\n MENU\n1 - Dodanie wartosci na stos\n2 - Usuniecie wartosci ze stosu\n3 - Sprawdzenie jaka wartosc znajduje sie na gorze stosu\n4 - ";
        cout << "Wyswietlnie calego stosu\n5 - Usunienie calego stosu\n6 - ONP\n7 - ONP -> notacja konwencjonalna  \n0 - Wyjscie z programu\n";
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

                    //if(stoi(top(stos)) != 0)
                    cout << "aktualna wartosc na szczycie stosu to : " << top(stos);
                   // else cout << "nie ma nic do wyswietlania - stos jest pusty!";
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
            case 7:
                {
                    string res = onp_to_n();
                    cout << "\n onp na zwykla notajce to : " <<  res ;
                    break;
                }
            case 8:
                {
                    n_to_onp();
                    break;
                }




            default : cout << "podales zly numer ! sprobuj ponownie ... " ;

        }
    }

    return 0;
}


void push(stos *&current_stos, string  valueto_add)
{
    stos *temp = new stos ;
    temp->value = valueto_add;
    temp->next = current_stos;
    current_stos = temp;
}
string top(stos *current_stos)
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
void show_whole_stack(stos*current_stack) // wystarczy nie daæ referencji i pracujemy na kopii wiêc mo¿emy usuwaæ z aktualnego stosu i zadne zmiany nie zostana
{
    if(current_stack)
    {
       // stos * temp = new stos;
        //temp = current_stack;
        cout << "\n stos \n";
        while(current_stack)
        {
            cout << "adres -> " << current_stack;
            cout << " aktualny element " <<current_stack->value << endl;

            pop(current_stack);

        }
      //  delete [ ] temp ;
    }
    else cout << "\nnie ma nic do wyswietlania - stos jest pusty";

}
string onp_to_n()
{
    stos *stack = nullptr;
    system("cls");
    cout << "\n*************** ONP NA ODWROTNA NOTACJE ***************\n";
    cout << "Podawaj kolejno skladniki wyrazenia ONP po kazdym naciskajac enter, wpisanie 0 i zatwierdzenie enterem konczy wpisywanie\n";
    string var = " ";
    while(var != "0")
    {
        cin >> var;
        if(isdigit(var[0]))
        {
            //cout << " jest cyfra - " << stoi(onp) ;
            push(stack, var);
        }
        else if ( var == "+"|| var == "/" || var == "-" || var == "*"  )
        {

            //cout << " jest operatorem ";
            //if(var == "/" || var == "*"  ) push(stack, "(");
            string  a = top(stack);
            pop(stack);
            string b = top(stack);
            pop(stack);


            // + = 43   - = 45   * = 42   / = 47
            switch(int(var[0])) // po prostu z tablicy ascii zeby sie nie bawic w 17 ifow ;
            {
                case 42 :
                {
                    if(a.size() <3 && b.size() < 3)
                    {
                        push(stack , b + "*" + a );
                    }
                    else if(a.size() > b.size() )
                    {
                        push(stack , "(" + a + ")"+ "*" + b   );
                    }
                    else if(a.size() <  b.size())
                    {
                        push(stack ,   a + "*" + "(" + b  + ")" );
                    }
                    else push(stack , "(" + b + ")"+ "*" + a   );
                    break;
                }

                case 43 :
                {
                    push(stack , b + "+" + a );
                    break;
                }

                case 45 :
                {
                    push(stack , b + "-" + a );
                    break;
                }

                case 47 :
                {
                   // cout << "rozmiar - >" << top(stack).size() << endl ;
                    if(a.size() < 3&& b.size() < 3)
                    {
                        push(stack , b + "/" + a );
                    }
                    else if(a.size() > b.size() )
                    {
                        push(stack , "(" + a + ")"+ "/" + b   );
                    }
                    else if(a.size() <  b.size())
                    {
                        push(stack , "(" + b + ")"+ "/" + a   );
                    }
                    else push(stack , "(" + b + ")"+ "/" + a   );


                    break;

                }
            }

        }
        else { cout << " jedyno z wpisanych wyrazen nie jest ani liczba ani operatorem, wychodzenie .. " ; exit(42); }
   // cout << top(stack) << " ROZMIAR " << top(stack).size() << endl;
    }

    pop(stack);
    string result = top(stack);
    delete_whole_stack(stack);
    return result;
}void n_to_onp()
{
    string var;
    cout << " Wprowadz zwykle wyrazenie do zamiany na onp : \n";
    getline(cin, var);
    getline(cin, var);
    for(char i : var)
    {
        cout << i  << " " ;
    }



}
