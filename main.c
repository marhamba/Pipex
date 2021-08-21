/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tumolabs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:57:26 by tumolabs          #+#    #+#             */
/*   Updated: 2021/08/18 17:27:30 by tumolabs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_pipex.h"

int main(int argc, char **argv)
{
    if (argc != 5)
        ft_exit("Wrong number of arguments!");
    else
    {
        // printf("hello");
        ft_pipex(argc, argv);
    }

    return (0);
}
