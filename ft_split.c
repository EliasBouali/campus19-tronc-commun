#include <stdlib.h>

int count_words(char *str, char c)
{
    int count;
    int in_word;

    count = 0;
    in_word = 0;
    while(*str)
    {
        if(*str == c)
            in_word = 0;
        /*cette version de if et else if assure de remettre le compteur a 0 quand on quitte un mot et compter un mot qu'au debut d'un nouveau mot
         * exemple : "salut les gars", s pas un espace donc on passe a else if donc le in_word va passé a 1 et count++ pour les autre letter pas de separateur le in_word reste a un donc on accremete pas jusqu au separateur in_word = 0 et on refait la boucle comme .*/ 
        else if(in_word == 0)
        {
            in_word = 1;
            count++;
        }
        str++;
    }
    return (count);
}

int ft_wordlen(char *str, char c)
{
    int i;

    i = 0;
    while(str[i] && str[i] != c)
        i++;
    return (i);
}
void    free_tab(char **tab, int i)
{
    while (i >= 0) // i represente tous les éléments qui ont été alloués avec succès.
        free(tab[i--]); // cette partie libere mot par mot du tableau .
    free(tab);// une fois que tous les pointeurs individuels ont été libérées,on libère le tableau principal.
}

char    **ft_split(char const *s, char c)
{
    char    **tab;
    int i, j, k, word_len;

    i = 0;
    j = 0;
    tab = malloc(sizeof(char *) * (count_words((char *)s, c) + 1));
    if(!tab)
        return (NULL);
    while(s[i])
    {
        if(s[i] != c)
        {
            word_len = ft_wordlen((char *)&s[i], c);
            tab[j] = malloc(sizeof(char) * (word_len + 1));
            if(!tab[j])
            {
                free_tab(tab, j - 1);
                return (NULL);
            }
            k = 0;
            while( k < word_len)
                tab[j][k++] = s[i++];
            tab[j++][k] = '\0';
        }
        else
            i++;
    }
    tab[j] = NULL;
    return (tab);
}

 #include <stdio.h>
#include <stdlib.h>

void free_tab(char **tab, int i);

// Fonction principale pour tester ft_split()
int main(void)
{
    char **tab;
    int i;

    // Test 1 : Phrase normale
    printf("Test 1 : Phrase normale\n");
    tab = ft_split("Salut les gars comment ça va ?", ' ');
    if (!tab)
        return (1);
    i = 0;
    while (tab[i])
        printf("[%s]\n", tab[i++]);
    free_tab(tab, i - 1);

    // Test 2 : Chaîne avec plusieurs séparateurs successifs
    printf("\nTest 2 : Séparateurs multiples\n");
    tab = ft_split("  Bonjour   les    amis  ", ' ');
    if (!tab)
        return (1);
    i = 0;
    while (tab[i])
        printf("[%s]\n", tab[i++]);
    free_tab(tab, i - 1);

    // Test 3 : Chaîne vide
    printf("\nTest 3 : Chaîne vide\n");
    tab = ft_split("", ' ');
    if (!tab)
        return (1);
    i = 0;
    while (tab[i])
        printf("[%s]\n", tab[i++]);
    free_tab(tab, i - 1);

    // Test 4 : Chaîne sans séparateurs
    printf("\nTest 4 : Chaîne sans séparateurs\n");
    tab = ft_split("Bonjour", ' ');
    if (!tab)
        return (1);
    i = 0;
    while (tab[i])
        printf("[%s]\n", tab[i++]);
    free_tab(tab, i - 1);

    // Test 5 : Chaîne avec uniquement des séparateurs
    printf("\nTest 5 : Uniquement des séparateurs\n");
    tab = ft_split("      ", ' ');
    if (!tab)
        return (1);
    i = 0;
    while (tab[i])
        printf("[%s]\n", tab[i++]);
    free_tab(tab, i - 1);

    // Test 6 : Test d'un séparateur différent
    printf("\nTest 6 : Séparateur différent\n");
    tab = ft_split("Salut-les-gars-comment-ça-va", '-');
    if (!tab)
        return (1);
    i = 0;
    while (tab[i])
        printf("[%s]\n", tab[i++]);
    free_tab(tab, i - 1);

    return (0);
}
