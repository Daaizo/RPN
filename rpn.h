#ifndef RPN_H
#define RPN_H
#include <string>
#include <iostream>
#include <stackimplementation.h>
#include <sstream>
using namespace std;
float rpn(string RPN)
{

        MyStack<float> *temp = nullptr;
        float a, b;
        istringstream s(RPN);
        string it;
        while(s>>it)
        {
            //cout << "\nakutalna wartosc "<< it << " jego wartosc to " << float(it[0]);
            if(isdigit(it[0]) ||  (it.size()> 1 &&  isdigit(it[1]) ))
            {
               // cout << "\njest cyfra - " << stoi(it)  ;
                MyStack<float>::Push(temp, stoi(it));
            }
            else if ( it[0] == '+'|| it[0] == '/' || it[0] == '-' || it[0] == '*' || float(it[0])== -98 || it[0] == ':')
            {
            //    cout << " jest operatorem " << it[0] ;
                a = MyStack<float>::Top(temp);
                MyStack<float>::Pop(temp);
                b = MyStack<float>::Top(temp);
                MyStack<float>::Pop(temp);
                // + (43)   - (45)   * (42)   / (47)  × (-98)  : (58)   ascii table value's
                switch(int(it[0]))
                {
                    case 42 :
                    {
                        MyStack<float>::Push(temp , b * a );
                        break;
                    }
                    case -98:
                    {
                        MyStack<float>::Push(temp , b * a );
                        break;
                    }
                    case 43 :
                    {

                        MyStack<float>::Push(temp , b + a );
                        break;
                    }

                    case 45 :
                    {
                        MyStack<float>::Push(temp , b - a );
                        break;
                    }
                    case 58:
                    {
                        MyStack<float>::Push(temp , b / a );
                        break;
                    }
                    case 47 :
                    {
                         MyStack<float>::Push(temp , b / a );
                        break;
                    }
                }
            }
        }
        float result =  MyStack<float>::Top(temp);
       // cout <<"halo " <<  MyStack<float>::Top(temp);
        MyStack<float>::DeleteWholeStack(temp);
        return result ;
  }

string rpn_to_infix(string RPN)
{

    MyStack<string> *stack = nullptr;
   // system("cls");
    //cout << "Podawaj kolejno skladniki wyrazenia ONP po kazdym naciskajac enter, wpisanie 0 i zatwierdzenie enterem konczy wpisywanie\n";
    istringstream s(RPN);
    string var;
    while(s >> var)
    {
        //cout << " \n stos :  " ; MyStack<string>::PrfloatStack(stack);
        //cout << "\nakutalna wartosc " << var ;
        if(isdigit(var[0]) || isdigit(var[1]))
        {

            MyStack<string>::Push(stack, var);

        }
        else if ( var == "+"|| var == "/" || var == "-" || var == "*" || (float)var[0] == -98  || var == ":" )
        {

            //cout << " jest operatorem " << var ;
            //if(var == "/" || var == "*"  ) push(stack, "(");
            string  a = MyStack<string>::Top(stack);
            MyStack<string>::Pop(stack);
            string b = MyStack<string>::Top(stack);
            MyStack<string>::Pop(stack);
             // + (43)   - (45)   * (42)   / (47)  × (-98)  : (58)   ascii table value's
            switch(int(var[0]))
            {
                case 42 :
                {
                    if(a.size() <3 && b.size() < 3)
                    {
                        MyStack<string>::Push(stack , b + "*" + a );
                    }
                    else if(a.size() > b.size() )
                    {
                        MyStack<string>::Push(stack , "(" + a + ")"+ "*" + b   );
                    }
                    else if(a.size() <  b.size())
                    {
                        MyStack<string>::Push(stack ,   a + "*" + "(" + b  + ")" );
                    }
                    else MyStack<string>::Push(stack , "(" + b + ")"+ "*" + a   );
                    break;
                }
                case -98:
                {
                    if(a.size() <3 && b.size() < 3)
                    {
                        MyStack<string>::Push(stack , b + "*" + a );
                    }
                    else if(a.size() > b.size() )
                    {
                        MyStack<string>::Push(stack , "(" + a + ")"+ "*" + b   );
                    }
                    else if(a.size() <  b.size())
                    {
                        MyStack<string>::Push(stack ,   a + "*" + "(" + b  + ")" );
                    }
                    else MyStack<string>::Push(stack , "(" + b + ")"+ "*" + a   );
                    break;

                }
                case 43 :
                {

                    MyStack<string>::Push(stack , b + "+" + a );
                    break;
                }

                case 45 :
                {
                    MyStack<string>::Push(stack , b + "-" + a );
                    break;
                }
                case 58:
                {
                    if(a.size() < 3&& b.size() < 3)
                    {
                        MyStack<string>::Push(stack , b + "/" + a );
                    }
                    else if(a.size() > b.size() )
                    {
                        MyStack<string>::Push(stack , "(" + a + ")"+ "/" + b   );
                    }
                    else if(a.size() <  b.size())
                    {
                        MyStack<string>::Push(stack , "(" + b + ")"+ "/" + a   );
                    }
                    else MyStack<string>::Push(stack , "(" + b + ")"+ "/" + a   );


                    break;

                }
                case 47 :
                {
                   // cout << "rozmiar - >" << top(stack).size() << endl ;
                    if(a.size() < 3&& b.size() < 3)
                    {
                        MyStack<string>::Push(stack , b + "/" + a );
                    }
                    else if(a.size() > b.size() )
                    {
                        MyStack<string>::Push(stack , "(" + a + ")"+ "/" + b   );
                    }
                    else if(a.size() <  b.size())
                    {
                        MyStack<string>::Push(stack , "(" + b + ")"+ "/" + a   );
                    }
                    else MyStack<string>::Push(stack , "(" + b + ")"+ "/" + a   );


                    break;

                }
                default : cout << " haloo";
            }
        }
      //  else { cout << " jedyno z wpisanych wyrazen -- " << var <<" nie jest ani liczba ani operatorem, wychodzenie .. " ; exit(42); }
   // cout << top(stack) << " ROZMIAR " << top(stack).size() << endl;
    }

  //  MyStack<string>::Pop(stack);
    string result = MyStack<string>::Top(stack);
    MyStack<string>::DeleteWholeStack(stack);
    return result;
}

string infix_to_rpn(string expression)
{



}

#endif // RPN_H
