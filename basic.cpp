// #include<iostream>
// using namespace std;
// int main()
// {
//     cout<<"Hridoy";
//     cout<<endl;
//     cout<<"Hawladar \nstyding in \nCSE";
//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     int x;
//     cin>>x;
//     cout<<x-1;

//     return 0;
// }

// #include<iostream>
// using namespace std;
// int main()
// {
//     int x;
//     cout<<"Enter a number: ";
//     cin>>x;
//     if(x%2==0)
//     cout<<"Even Number \n";
//     else
//     cout<<"Odd Number \n";
//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     int x;
//     cout<<"Enter a number: ";
//     cin>>x;

//     if (x>0)
//     {
//         cout<<"Positive Number \n";
//     }
//     else if (x<0)
//     {
//         cout<<"Negative Number \n";
//     }
//     else
//     {
//         cout<<"Zero \n";
//     }

//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     int x;
//     x = 5;
//     cout<<"Enter a number: ";
//     int y;
//     cin>>y;
//     if (y % x == 0)
//     {
//         cout<<"Divisible \n";
//     }
//     else
//     {
//         cout<<"Not Divisible \n";
//     }
//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     int x;
//     cin>>x;
//     (x>=0)?cout<<"Poisitive Number\n" : cout<<-x;
//     return 0;

// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     for (int i = 1; i <= 10; i++)
//     {
//         cout<<i<<endl;
//     }

// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     int x;
//     cout<<"Enter a number: ";
//     cin>>x;
//     for (int i = 1; i<=10; i++)
//     {
//         cout<<x++<<endl;
//     }
// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     for (int i = 1; i <= 100; i++)
//     {
//         cout<<i<<",";
//     }

//     return 0;
// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     for (int i = 1; i <= 100; i++)
//     {
//         if (i%2!=0)
//         {
//             cout<<i<<",";
//         }

//     }

// }
// #include<iostream>
// using namespace std;
// int main()
// {
//     int x=19;
//     for (int i = 1; i <= 10; i++)
//     {
//         cout<<x<<"*"<<i<<"="<<x*i<<endl;
//     }

// }
//   #include<iostream>
//     using namespace std;
//     int main()
//     {
//         int x=1;
//         while (x<=10)
//         {
//             cout<<x<<endl;
//             x++;
//         }

//     }
// #include<iostream>
// using namespace std;
// int main()
// {
//     int x=1;
//     do
//     {
//     cout<<x<<endl;
//     x++;
//     } while (x<=10);

// }
// #include<iostream>
// using namespace std;
// int main()
//  {
//     for (int i = 0; i <= 5; i++)
//     {
//         int x=5;
//         while (0<=x-i)
//         {
//             cout << "*";
//             x--;
//         }
//         cout << endl;

//     }

//     return 0;
//  }
// #include <iostream>
// using namespace std;
// int main()
// {
//     int x;
//     for (int i = 65; i <= 69; i++)
//     {
//         for (int j = 1; j <= (70 - i); j++)
//         {
//             cout << char(i);
//         }
//         cout << endl;
//     }

//     return 0;
// }
// #include <iostream>
// using namespace std;
// int main()
// {
//     int x = 0;
//     for (int i = 0; i <= 3; i++)
//     {
//         for (int j = 0; j <= i; j++)
//         {
//             cout << x++;
//         }
//         cout << endl;
//     }

// }
// #include <iostream>
// using namespace std;
// int main()
// {
//     for (int i = 1; i < 6; i++)
//     {

//         for (int j = 1; j <= i; j++)
//         {
//             if ((i+j )% 2 == 0)
//             {
//                 cout << 1;
//             }
//             else
//             {
//                 cout << 0;
//             }
//         }
//         cout << endl;
//     }

// }
// #include <iostream>
// using namespace std;
// int main ()
// {
//     for (int i = 0; i <= 6; i++)
//     {
//         for (int j = 0; j <=6; j++)
//         {
//             if (i==3 || j==3)
//             {
//                 cout << "*";
//             }
//             else
//             {
//                 cout << " ";
//             }

//         }
//         cout << endl;
//     }
//     return 0;
// }
// #include <iostream>
// using namespace std;
// int main()
// {
//     for (int i = 0; i <= 6; i++)
//     {
//         for (int j = 0; j <= 6; j++)
//         {
//             if (i == 0 || j == 0 || i == 6 || j == 6)
//             {
//                 cout << "* ";
//             }
//             else
//             {
//                 cout << "  ";
//             }
//         }
//         cout << endl;
//     }
//     return 0;
// }
// #include <iostream>
// using namespace std;
// int hello()
// {
//     cout << "Hello World";
//     return 2;
// }
// int main()
// {
//     int x = hello();
//     cout << endl;
//     cout << x;
//     return 0;
// }
// #include <iostream>
// using namespace std;
// int factorial(int n){
//     int fact = 1;
//     for (int i = 1; i <= n; i++)
//     {
//        fact *= i;
//     }

//     return fact;
// }
// int main(){
//     cout<<"Enter a number: ";
//     int x;
//     cin>>x;
//     cout<<"Factorial of "<<x<<" is "<<factorial(x);
//     return 0;
// }
// #include <iostream>
// using namespace std;
// int factorial(int n){
//     int fact = 1;
//     for (int i = 1; i <= n; i++)
//     {
//        fact *= i;
//     }

//     return fact;
// }
// int main(){
//     cout<<"Enter a number: ";
//     int x;
//     cin>>x;
//     cout<<"Factorial of "<<x<<" is "<<factorial(x);
//     return 0;
// }
// #include <iostream>
// using namespace std;
// int factorial(int n){
//     int fact = 1;
//     for (int i = 1; i <= n; i++)
//     {
//        fact *= i;
//     }

//     return fact;
// }
// int main(){
//     cout<<"Enter a number: ";
//     int x;
//     cin>>x;
//     cout<<"Factorial of "<<x<<" is "<<factorial(x);
//     return 0;
// }