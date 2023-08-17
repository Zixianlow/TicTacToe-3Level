/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzi-xian <lzi-xian@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 19:29:12 by lzi-xian          #+#    #+#             */
/*   Updated: 2023/08/17 19:33:11 by lzi-xian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tictactoe.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to reverse a string
void reverse(char str[], int length) {
    int start = 0;
    int end = length - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Integer to ASCII (itoa) function
char* itoa(int num, char* str, int base) {
    if (base < 2 || base > 36) {
        return NULL; // Unsupported base
    }

    int isNegative = 0;
    if (num < 0) {
        isNegative = 1;
        num = -num;
    }

    int i = 0;
    while (num) {
        int rem = num % base;
        str[i++] = (rem < 10) ? (rem + '0') : (rem + 'a' - 10);
        num = num / base;
    }

    if (i == 0) {
        str[i++] = '0';
    }

    if (isNegative) {
        str[i++] = '-';
    }

    str[i] = '\0'; // Null-terminate the string

    reverse(str, i);

    return str;
}
