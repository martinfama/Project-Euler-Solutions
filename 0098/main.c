#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <uthash.h>

typedef struct
{
    uint8_t c_counts[26]; // Count of each character in the word, use this as key
    uint64_t count;       // Count of occurrences of this character combination
    char **words;         // The actual words that match this character combination
    UT_hash_handle hh;    // Makes this structure hashable
} WordCount;

void load_words(char ***words, size_t *count)
{
    // This function should load words from a file or other source.
    // For simplicity, we will use a static array here.
    // static char *static_words[] = {"HELLO", "WORLD", "TEST", "EXAMPLE", "HELLO", "POO", "LLOEH"};
    // *words = static_words;
    // *count = sizeof(static_words) / sizeof(static_words[0]);
    // open 0098_words.txt, which has one word per line
    FILE *file = fopen("0098_words.txt", "r");
    if (file == NULL)
    {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }
    char **temp_words = NULL;
    size_t temp_count = 0;
    char buffer[256];
    while (fgets(buffer, sizeof(buffer), file))
    {
        // Remove newline character if present
        size_t len = strlen(buffer);
        if (len > 0 && buffer[len - 1] == '\n')
            buffer[len - 1] = '\0';

        // Allocate memory for the new word
        temp_words = realloc(temp_words, sizeof(char *) * (temp_count + 1));
        temp_words[temp_count] = strdup(buffer);
        temp_count++;
    }
    fclose(file);
    *words = temp_words;
    *count = temp_count;
}

int main(int argc, char *argv[])
{

    char **words = NULL;
    size_t word_count = 0;
    load_words(&words, &word_count);

    WordCount *word_counts = NULL;

    uint32_t distinct_anagrams = 0;
    for (size_t i = 0; i < word_count; i++)
    {
        char *w1 = words[i];
        if (w1 == NULL || w1[0] == '\0')
            continue;

        uint8_t temp[26] = {0};
        for (int i = 0; w1[i] != '\0'; i++)
        {
            temp[w1[i] - 'A']++;
        }
        // if not found, create a new entry
        WordCount *wc;
        HASH_FIND(hh, word_counts, temp, sizeof(temp), wc);
        if (wc == NULL)
        {
            wc = (WordCount *)malloc(sizeof(WordCount));
            for (int i = 0; i < 26; i++)
                wc->c_counts[i] = temp[i];
            wc->count = 1;
            HASH_ADD(hh, word_counts, c_counts, sizeof(wc->c_counts), wc);
            wc->words = NULL; // Initialize words to NULL
            wc->words = (char **)malloc(sizeof(char *));
            wc->words[0] = strdup(w1); // Store the first word
            wc->words[1] = NULL;       // Null-terminate the array of words

            distinct_anagrams++;
        }
        else
        {
            wc->count++;
            // add word, assume it is not already in the list
            size_t word_index = 0;
            while (wc->words[word_index] != NULL)
            {
                if (strcmp(wc->words[word_index], w1) == 0)
                    break; // Word already exists, no need to add
                word_index++;
            }
            if (wc->words[word_index] == NULL) // If we reached the end of the list
            {
                wc->words = realloc(wc->words, sizeof(char *) * (word_index + 2)); // +1 for new word, +1 for NULL terminator
                wc->words[word_index] = strdup(w1);
                wc->words[word_index + 1] = NULL; // Null-terminate the array of words
            }
        }
    }

    printf("Distinct anagrams: %u\n", distinct_anagrams);
    // iterate over the hash table and print the counts
    WordCount *current_word_count, *tmp;
    HASH_ITER(hh, word_counts, current_word_count, tmp)
    {
        if (current_word_count->count < 2)
            continue;
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < current_word_count->c_counts[i]; j++)
            {
                printf("%c", 'A' + i);
            }
        }
        // print the words
        printf(" -> ");
        for (int i = 0; current_word_count->words[i] != NULL; i++)
        {
            printf("%s", current_word_count->words[i]);
            if (current_word_count->words[i + 1] != NULL)
                printf(", ");
        }
        printf("   | Count: %lu\n", current_word_count->count);
        HASH_DEL(word_counts, current_word_count);
        free(current_word_count);
    }
}