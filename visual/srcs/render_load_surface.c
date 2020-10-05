/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_load_surface.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarlett <acarlett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:58:09 by acarlett          #+#    #+#             */
/*   Updated: 2020/10/05 14:03:06 by acarlett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void		render_surface(t_map_data *data, t_visual *vis)
{
	vis->render_flags = SDL_RENDERER_ACCELERATED |
			SDL_RENDERER_PRESENTVSYNC | SDL_TEXTUREMODULATE_ALPHA;
	if ((vis->rend = SDL_CreateRenderer(vis->win, -1,
					vis->render_flags)) == NULL)
		get_error_free_data(data, CREATE_RENDER, "SDL_CreateRender error: ");
	if ((vis->surface = IMG_Load("images/back_gradient3.png")) == NULL)
		get_error_free_data(data, CREATE_SURFACE, "SDL_CreateSurface error: ");
	if ((vis->back = SDL_CreateTextureFromSurface(vis->rend,
					vis->surface)) == NULL)
		get_error_free_data(data, CREATE_TEXTURE, "SDL_CreateTexture error: ");
	SDL_FreeSurface(vis->surface);
	if ((vis->surface = IMG_Load("images/21_logo.png")) == NULL)
		get_error_free_data(data, CREATE_SURFACE, "SDL_CreateSurface error: ");
	if ((vis->logo_21 = SDL_CreateTextureFromSurface(vis->rend,
					vis->surface)) == NULL)
		get_error_free_data(data, CREATE_TEXTURE, "SDL_CreateTexture error: ");
	SDL_FreeSurface(vis->surface);
	vis->run = true;
}
