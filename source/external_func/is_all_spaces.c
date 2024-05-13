# include <stdbool.h>

bool is_all_spaces(const char *s)
{
    int i;

    i = 0;
    while (s[i] && s[i] == ' ')
        i++;
    if (!s[i])
        return (true);
    return (false);
}