/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: victor <victor@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 22:41:54 by victor            #+#    #+#             */
/*   Updated: 2023/03/29 18:38:15 by victor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    print_win()
{
    printf("\033[0;32m██╗░░░██╗░█████╗░██╗░░░██╗  ░██╗░░░░░░░██╗██╗███╗░░██╗\n╚██╗░██╔╝██╔══██╗██║░░░██║  ░██║░░██╗░░██║██║████╗░██║\n░╚████╔╝░██║░░██║██║░░░██║  ░╚██╗████╗██╔╝██║██╔██╗██║\n░░╚██╔╝░░██║░░██║██║░░░██║  ░░████╔═████║░██║██║╚████║\n░░░██║░░░╚█████╔╝╚██████╔╝  ░░╚██╔╝░╚██╔╝░██║██║░╚███║\n░░░╚═╝░░░░╚════╝░░╚═════╝░  ░░░╚═╝░░░╚═╝░░╚═╝╚═╝░░╚══╝\n\033[0m");
}

void    print_loose()
{
    printf("\033[0;31m██╗░░░██╗░█████╗░██╗░░░██╗  ██╗░░░░░░█████╗░░█████╗░░██████╗███████╗\n╚██╗░██╔╝██╔══██╗██║░░░██║  ██║░░░░░██╔══██╗██╔══██╗██╔════╝██╔════╝\n░╚████╔╝░██║░░██║██║░░░██║  ██║░░░░░██║░░██║██║░░██║╚█████╗░█████╗░░\n░░╚██╔╝░░██║░░██║██║░░░██║  ██║░░░░░██║░░██║██║░░██║░╚═══██╗██╔══╝░░\n░░░██║░░░╚█████╔╝╚██████╔╝  ███████╗╚█████╔╝╚█████╔╝██████╔╝███████╗\n░░░╚═╝░░░░╚════╝░░╚═════╝░  ╚══════╝░╚════╝░░╚════╝░╚═════╝░╚══════╝\n\033[0m");
}

// int main (void)
// {
//     print_win();
//     print_loose();
//     return (0);
// }