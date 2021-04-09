#include "hashtable.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* 
- localizacão (linha e coluna, esta opcional) ˜
- natureza (literal, variavel, funcão, etc) ˜
- tipo (qual o tipo de dado deste símbolo)
- tamanho (derivado do tipo e se vetor)
- argumentos e seus tipos (no caso de funções) ˜
- dados do valor do token pelo yylval (veja E3)
*/


unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval; // do wikipedia essa
    return hashval % HASHSIZE;
}

HASH_TBL *lookup(HASH_TBL *hashtab[], char *s)
{
    HASH_TBL *entry;
    unsigned hashed_value = hash(s);
    for (entry = hashtab[hashed_value]; entry != NULL; entry = entry->next)
        if (strcmp(s, entry->name) == 0)
            return entry; /* found */

    return NULL; /* not found */
}

void add_to_table(HASH_TBL *hashtab[], char *name, void *content)
{
    HASH_TBL *new_entry;
    HASH_TBL *aux_entry;
    unsigned hashval;
    hashval = hash(name);

    new_entry = malloc(sizeof(HASH_TBL *));
    new_entry->content = content;
    new_entry->next = NULL;
    new_entry->name = strdup(name); // ou só name? ponteiros diferentes evita double free

    aux_entry = hashtab[hashval];

    if (aux_entry == NULL)
    {
        hashtab[hashval] = new_entry;
    }
    else
    {
        while (aux_entry->next != NULL)
        {
            aux_entry = aux_entry->next;
        }
        aux_entry->next = new_entry;
    }
}

void free_entry(HASH_TBL *entry)
{
    if (entry->name != NULL)
    {
        free(entry->name);
    }
    if (entry->content != NULL)
    {   
        free_token(entry->content->valor);
        
        LIST* aux;
        LIST* next = (LIST*) entry->content->argumentos;
        
        while(next != NULL) {
            aux = next;
            next = next->next;
            free(aux->label);
            free(aux);
        }

        free(entry->content); // isso vai ter que ser refatorado provavelmente
    }
    if (entry != NULL)
        free(entry);
}

void clear_table(HASH_TBL *hashtab[], int hash_tab_size)
{
    HASH_TBL *next_aux;
    for (int i = 0; i < hash_tab_size; i++)
    {
        if (hashtab[i] != NULL)
        {   
            HASH_TBL *aux = hashtab[i]->next;
            while (aux != NULL)
            {
                next_aux = aux->next;
                free_entry(aux);
                aux = next_aux;
            }
            
            free_entry(hashtab[i]);
        }
    }
}
/*
int main()
{
    HASH_TBL* hashtab[100];
    for (int i = 0; i < 100; i++)
    {
        hashtab[i] = NULL;
    }

    char *names[] = {"diego", "dimer", "rodrigues", "no_aguardo", "de", "hash", "repetido"};

    for (int i = 0; i < 7; i++)
    {
        add_to_table(hashtab, names[i], NULL);
    }
    for (int i = 0; i < 7; i++)
    {
        HASH_TBL *l = lookup(hashtab, names[i]);
    }

    printf("liberando tabela: \n");
    clear_table(hashtab, 100);
}
*/
