/*
** EPITECH PROJECT, 2021
** my_putnbr
** File description:
** cast string to integer
*/

static void sign_check(int *sign, char const *str, int *range)
{
    for (int i = 0; str[i] == '-' || str[i] == '+'; i++) {
        if (str[i] == '-') {
            *sign *= -1;
        }
        *range = i + 1;
    }
}

static int nbr_check(char const *str, int *range, int *sign)
{
    int my_number = 0;
    for (int i = *range; str[i] >= '0' && str[i] <= '9'; i++) {
        if (my_number > (2147483648 - (str[i] - 48)) / 10) {
            return (-2);
        }
        if (*sign == 1 && my_number > (2147483647 - (str[i] - 48)) / 10) {
            return (-2);
        }
        my_number = (my_number * 10) + (str[i] - 48);
    }
    my_number *= *sign;
    return (my_number);
}

int my_getnbr(char const *str)
{
    int sign = 1;
    int range = 0;
    sign_check(&sign, str, &range);
    return nbr_check(str, &range, &sign);
}

void int_swap(int *a, int j)
{
    int temp = a[j + 1];

    if (a[j] < a[j + 1])
        return;
    a[j + 1] = a[j];
    a[j] = temp;
}

void sort_int_array(int *a, int size)
{
    for (int i = 0; i < size - 1; ++i)
        for (int j = 0; j < size - 1 - i; ++j )
            int_swap(a, j);
}
