#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int valeur(int couleur)
{
    if (couleur == 1)
    {
        printf("rouge");
    }
    else if (couleur == 2)
    {
        printf("bleu");
    }
    else if (couleur == 3)
    {
        printf("vert");
    }
    else if (couleur == 4)
    {
        printf("jaune");
    }
    else if (couleur == 5)
    {
        printf("orange");
    }
    else if (couleur == 6)
    {
        printf("violet");
    }
    else
    {
        printf("couleur invalide");
    }
}

int main()
{
    srand(time(NULL));

   int code[4];
    printf("Code secret : ");
    for (int i = 0; i < 4; i++)
    {
    int couleur;
    do
    {
        couleur = rand() % 6 + 1;
    } while (couleur == code[0] || couleur == code[1] || couleur == code[2] || couleur == code[3]);
    code[i] = couleur;
    printf("%d ", code[i]);
    }
    printf("\n");

    int tentatives = 0;
    while (tentatives < 10)
    {
        int tentative[4];
        printf("Entrez votre tentative (4 chiffres de 1 a 6), 1 = rouge, 2 = bleu, 3 = vert, 4 = jaune, 5 = orange, 6 = violet : ");
        scanf("%d%d%d%d", &tentative[0], &tentative[1], &tentative[2], &tentative[3]);
        

        int correctes = 0;
        int proches = 0;
        int faux[6] = {0};
        int nbrTentatives[6] = {0};
        for (int i = 0; i < 4; i++){
            if (tentative[i] == code[i])
            {
                correctes++;
            }
            else
            {
                faux[code[i] - 1]++;
                nbrTentatives[tentative[i] - 1]++;
            }
        }
        for (int i = 0; i < 6; i++)
        {
            proches += (faux[i] < nbrTentatives[i]) ? faux[i] : nbrTentatives[i];
        }
        proches -= correctes;

        for (int i = 0; i < correctes; i++)
        {
            printf("w");
        }
        for (int i = 0; i < proches; i++)
        {
            printf("r");
        }
        for (int i = 0; i < 4 - correctes - proches; i++)
        {
            printf(".");
        }
        printf("\n");

        if (correctes == 4)
        {
            printf("Bravo, vous avez trouvé le code secret en %d tentatives !\n", tentatives + 1);
            system("pause");
            return 0;
        }
        tentatives++;
    }

    printf("Perdu,\nLe code secret était : ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d ", code[i]);
    }
    printf("\n");
    system("pause");
    return 0;
}