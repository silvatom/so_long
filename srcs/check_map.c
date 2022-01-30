#include "so_long.h"

int check_arg(int argc, char *argv)
{
    if (argc != 2)
    {
        error_msg("Wrong number of arguments!");
        return (TRUE);
    }
    if (ft_extcheck(argv, ".ber"))
    {
        error_msg("File extension invalid!");
        return (TRUE);
    }
    return (FALSE);
}

void error_msg(char *errstr)
{
    ft_putstr("Error: ");
    ft_putstr(errstr);
    ft_putstr("\n");
}