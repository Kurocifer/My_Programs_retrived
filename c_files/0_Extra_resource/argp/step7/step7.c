/* An argp-enabled program, that accepts arguements */
#include <argp.h>
#include <stdio.h>
#include <stdlib.h>

static int parse_opt(int key, char *arg, struct argp_state *state)
{
    int *arg_count = state->input;
    switch(key) {
        case 'd':
            unsigned int i;
            for(i = 0; i < atoi(arg); i++)
                printf(".");
            printf("\n");
            break;
        
        case 777:
            parse_opt('d', "3", state);
        
        case ARGP_KEY_ARG:
            (*arg_count)--;
            if(*arg_count >= 0)
                printf(" %s", arg);
            break;
        
        case ARGP_KEY_END:
            printf("\n");
            if(*arg_count >= 4)
                argp_failure(state, 1, 0, "too few arguements");
            if(*arg_count < 0)
                argp_failure(state, 1, 0, "too many arguements");
            break;
    }

    return 0;
}

int main(int argc, char **argv)
{
    struct argp_option options[] =
    {
        {"dot", 'd', "NUM", OPTION_ARG_OPTIONAL, "show some dots on the screen"},
        {"period", 0, "NOT IMPORTANT", OPTION_ALIAS, "NOT IMPORTANT"},
        {0}
    };

    int arg_count = 4;
    struct argp argp = {options, parse_opt, "WORD[WORD[WORD[WORD]]]"};

    return argp_parse(&argp, argc, argv, 0, 0, &arg_count);
}