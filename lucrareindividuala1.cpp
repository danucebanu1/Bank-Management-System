#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    // Declararea Variabilelor
    double b, beta,alpha,alphaRad,betaRad,c,S,Si,R,r,P,a;
    // Citirea catetei b si unghiului beta
    cout << "Introduceti lungimea catetei b: ";
    cin >> b;
    cout << "Introduceti unghiul beta (in grade): ";
    cin >> beta;
    // Unghiul Alpha
    alpha = 90 - beta;
    // Unghiurile in Radiani
    alphaRad = alpha * M_PI / 180.0;
    betaRad = beta * M_PI / 180.0;
    // Calcularea laturilor
    a = b * tan(alphaRad);
    c = sqrt(pow(a, 2) + pow(b, 2));
    // Calcularea ariei
    S = 0.5 * a * b;
    // Calcularea ariei cercului inscris
    Si = S / (a + b + c) * c;
    // Calcularea razei circumferintei circumscrise
    R = c / 2;
    // Calcularea razei circumferintei inscrise
    r = Si / S * R;
    // Calcularea perimetrului 
    P = a + b + c;
    // Afișarea rezultatelor
    cout << "Unghiul alpha (in grade): " << alpha << endl;
    cout << "Cateta a: " << a << endl;
    cout << "Ipotenuza c: " << c << endl;
    cout << "Aria S: " << S << endl;
    cout << "Perimetrul P: " << P << endl;
    cout << "Aria cercului inscris Si: " << Si << endl;
    cout << "Raza circumferintei circumscrise R: " << R << endl;
    cout << "Raza cercului inscris r: " << r << endl;
}