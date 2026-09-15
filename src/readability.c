#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// initialisation de la fonction de comptage de lettres
int count_letters(string texte);
// initialisation de la fonction de comptage de mots
int count_words(string texte);
// initialisation de la fonction de comptage de phrases
int count_sentences(string texte);

int main(void)
{
    // entrées de l'utilisateur
    string texte = get_string("text: ");

    // comptage du nombre de lettres
    count_letters(texte);
    // comptage du nombre de mots
    count_words(texte);
    // comptage du nombre de phrases
    count_sentences(texte);

    // assigner les sorties des fonctions aux variables pour les utiliser
    int lettres = count_letters(texte);
    int mots = count_words(texte);
    int phrases = count_sentences(texte);

    // calcul de l'indice de Coleman-Liau
    int L = ((float) lettres / mots) * 100;
    int S = ((float) phrases / mots) * 100;
    // printf("%d %d\n", L, S);
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    // printf("%i\n", index);

    // attribution de grade

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

// la fonction de comptage de lettres
int count_letters(string texte)
{
    int lettres = 0;
    for (int i = 0, n = strlen(texte); i < n; i++)
    {
        if (isalpha(texte[i]))
        {
            lettres += 1;
        }
    }
    return lettres;
}

// la fonction de comptage de mots
int count_words(string texte)
{
    int mots = 1; // si je veux je pouvais mettre en bas ajouter 1 avant de retourner
    for (int i = 0, n = strlen(texte); i < n; i++)
    {
        if (texte[i] == ' ') // isblank() ou texte[i] == ' '
        {
            mots += 1;
        }
    }
    return mots;
}

// initialisation de la fonction de comptage de phrases
int count_sentences(string texte)
{
    int phrases = 0;
    for (int i = 0, n = strlen(texte); i < n; i++)
    {
        if (texte[i] == '.' || texte[i] == '?' || texte[i] == '!')
        {
            phrases += 1;
        }
    }
    return phrases;
}
