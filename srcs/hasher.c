/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hasher.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lmittie <lmittie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 20:09:06 by lmittie           #+#    #+#             */
/*   Updated: 2020/09/30 20:09:06 by lmittie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		hasher(const char *name)
{
	int hash;

	hash = 53;
	while (*name)
	{
		hash = hash * 33 + hash + (int)(*name);
		name++;
	}
	if (hash < 0)
		hash *= -1;
	hash %= HASH_TABLE_SIZE;
	return (hash);
}
