#include "string.h"

MY_STRING string_init_default(void)
{
    struct my_string *pstring = (struct my_string *)malloc(sizeof(struct my_string));
    if (pstring != NULL)
    {
        pstring->size = 0;
        pstring->capacity = 7;
        pstring->string = (char *)malloc(sizeof(char) * pstring->capacity);
        if (pstring->string == NULL)
        {
            free(pstring);
            return NULL;
        }
    }
    return pstring;
}

void string_destroy(MY_STRING *pString)
{
    struct my_string *pstring = (struct my_string *)*pString;

    free(pstring->string);
    free(pstring);
    *pString = NULL;
}

Status string_assignment(MY_STRING *pLeft, MY_STRING Right)
{
    struct my_string *temp;
    int i;
    int size = string_get_size(Right);
    if (*pLeft == NULL)
    {
        temp = string_init(string_c_str(Right));
        if (temp == NULL)
        {
            exit(1);
        }
        *pLeft = (MY_STRING)temp;
    }
    else
    {
        temp = string_init_default();
        for (i = 0; i <= size; i++)
        {
            string_push_back(temp, *string_at(Right, i));
        }
        *pLeft = (MY_STRING)temp;
    }
    return SUCCESS;
}

MY_STRING string_init(const char *c_string)
{
    struct my_string *pstring = (struct my_string *)malloc(sizeof(struct my_string));
    if (pstring == NULL)
    {
        exit(1);
    }

    int c_string_legnth = 0;
    int i = 0;

    while (c_string[i] != '\0')
    {

        c_string_legnth++;
        i++;
    }

    pstring->capacity = c_string_legnth + 1;

    pstring->size = pstring->capacity - 1;

    pstring->string = malloc(sizeof(char) * pstring->capacity);
    if (pstring->string == NULL)
    {
        exit(1);
    }

    if (c_string == NULL)
    {
        pstring->capacity = pstring->size = 0;
    }

    for (i = 0; i < pstring->capacity; i++)
    {
        pstring->string[i] = c_string[i];
    }

    return pstring;
}

int string_get_capacity(MY_STRING hMy_string)
{
    return ((struct my_string *)hMy_string)->capacity;
}

int string_get_size(MY_STRING hMy_string)
{
    return ((struct my_string *)hMy_string)->size;
}

char *string_c_str(MY_STRING hMy_string)
{
    struct my_string *pstring = (struct my_string *)hMy_string;
    char *temp_var;
    int i;

    if (pstring->string[pstring->size] != '\0')
    {
        temp_var = (char *)malloc(sizeof(char) * 2 * pstring->capacity);
        if (temp_var == NULL)
        {
            free(temp_var);
            return NULL;
        }
        for (i = 0; i < pstring->size; i++)
        {
            temp_var[i] = pstring->string[i];
        }
        temp_var[i] = '\0';
        free(pstring->string);
        pstring->string = temp_var;
        pstring->capacity = pstring->size + 1;
    }
    return pstring->string;
}

char *string_at(MY_STRING hMy_string, int index)
{
    struct my_string *pstring = (struct my_string *)hMy_string;

    if (pstring != NULL && index < pstring->size && index >= 0)
    {
        return &(pstring->string[index]);
    }
    return NULL;
}

Status string_push_back(MY_STRING hMy_string, char item)
{
    int j;

    struct my_string *pstring = (struct my_string *)hMy_string;
    Status status = FAILURE;

    if (pstring != NULL)
    {
        if (pstring->size >= pstring->capacity)
        {
            char *temp_char;
            pstring->capacity *= 2;
            temp_char = (char *)malloc(sizeof(char) * pstring->capacity);

            if (temp_char == NULL)
            {
                pstring->capacity /= 2;
                free(temp_char);
                return FAILURE;
            }

            for (j = 0; j < pstring->size; j++)
            {
                temp_char[j] = pstring->string[j];
            }
            free(pstring->string);
            pstring->string = temp_char;
        }
        pstring->string[pstring->size] = item;
        pstring->size++;

        status = SUCCESS;
    }

    return status;
}

Bool string_empty(MY_STRING hMy_string)
{
    struct my_string *pstring = (struct my_string *)hMy_string;
    if (pstring->size == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

Status string_concat(MY_STRING hResult, MY_STRING hAppend)
{
    struct my_string *presult = (struct my_string *)hResult;
    struct my_string *pappend = (struct my_string *)hAppend;

    char *temp_val;

    int i;
    int capacity;
    int size;

    if (pappend->size == 0)
    {
        return FAILURE;
    }
    else if (presult->size == 0)
    {
        for (i = 0; i < pappend->size; i++)
        {
            presult->string[i] = pappend->string[i];
        }
        presult->size = pappend->size;
        presult->capacity = presult->size + 1;
    }
    else
    {
        size = presult->size + pappend->size;
        capacity = size + 1;
        temp_val = (char *)malloc(sizeof(char) * capacity);
        if (temp_val == NULL)
        {
            free(temp_val);
            return FAILURE;
        }
        for (i = 0; i < presult->size; i++)
        {
            temp_val[i] = presult->string[i];
        }
        for (i = 0; i < pappend->size; i++)
        {
            temp_val[presult->size + i] = pappend->string[i];
        }
        temp_val[presult->size + i] = '\0';
        free(presult->string);
        presult->string = temp_val;
        presult->capacity = capacity;
        presult->size = size;
    }
    return SUCCESS;
}

Status string_pop_back(MY_STRING hMy_string)
{
    struct my_string *pstring = (struct my_string *)hMy_string;

    if (pstring->size <= 0)
    {
        return FAILURE;
    }
    pstring->size--;
    return SUCCESS;
}

int string_compare(MY_STRING hLeft_string, MY_STRING hRight_string)
{
    int length_of_string_1 = string_get_size(hLeft_string);
    int length_of_string_2 = string_get_size(hRight_string);

    int i = 0;

    // make some buffer
    char *string_1 = hLeft_string;
    char *string_2 = hRight_string;

    while (i < length_of_string_1 && i < length_of_string_2)
    {
        if (string_1[i] < string_2[i])
        {
            return -1;
        }
        else if (string_1[i] > string_2[i])
        {
            return 1;
        }
        else
        {
            i++;
        }
    }

    if (length_of_string_1 == length_of_string_2)
    {
        return 0;
    }
    else if (length_of_string_2 > length_of_string_1)
    {
        return -1;
    }
    else
    {

        return 1;
    }
}

int string_find(MY_STRING hLString, MY_STRING hRString) {
    My_string *pLString = (My_string*)hLString;
    My_string *pRString = (My_string*)hRString;

    int lSize = string_get_size(pLString);
    int rSize = string_get_size(pRString);

    for (int i = 0; i <= rSize - lSize; i++) {
        int j;
        for (j = 0; j < lSize; j++) {
            if ( (string_c_str(pRString)[i + j] ) != (string_c_str(pLString)[j]) ) {
                break;
            }
            if (j == lSize) {
                return i;
            }
        }
    }

    return -1;
}
