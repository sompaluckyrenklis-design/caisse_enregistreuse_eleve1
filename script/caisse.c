#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    // Génère un prix aléatoire entre 0.05 et 999.95, multiple de 0.05
    int sous = (rand() % 19999 + 1) * 5; // en centimes (sous)
    double prix = sous / 100.0;

    printf("Montant a payer : Rs%.2f\n", prix);

    double paiement;
    do {
        printf("Entrez le montant que vous donnez : Rs");
        scanf("%lf", &paiement);

        if (paiement < prix) {
            printf("Montant insuffisant ! Vous devez donner au moins Rs%.2f\n", prix);
        }
    } while (paiement < prix);

    double monnaie = paiement - prix;
    printf("Monnaie a rendre : Rs%.2f\n", monnaie);

    return 0;
}

