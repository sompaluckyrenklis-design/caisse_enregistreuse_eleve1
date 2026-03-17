#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NB_COUPURES 14

int valeurs[] = {200000, 100000, 50000, 20000, 10000, 5000, 2500, 2000, 1000, 500, 100, 50, 20, 5};
char *noms[] = {"Rs2000", "Rs1000", "Rs500", "Rs200", "Rs100", "Rs50", "Rs25", "Rs20", "Rs10", "Rs5", "Rs1", "50 sous", "20 sous", "5 sous"};

void calcule_monnaie(int monnaie_sous) {
    printf("\nMonnaie a rendre : Rs%.2f\n", monnaie_sous / 100.0);
    printf("%-12s | %s\n", "Coupure", "Quantite");

    for (int i = 0; i < NB_COUPURES; i++) {
        int nb = monnaie_sous / valeurs[i];
        if (nb > 0) {
            printf("%-12s | %d\n", noms[i], nb);
            monnaie_sous -= nb * valeurs[i];
        }
    }
}

int main() {
    srand(time(NULL));

    int sous = (rand() % 19999 + 1) * 5;
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

    int monnaie_sous = (int)((paiement - prix) * 100 + 0.5); // arrondi
    calcule_monnaie(monnaie_sous);

    return 0;
}
