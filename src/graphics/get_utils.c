/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtacos <rtacos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 19:54:06 by rtacos            #+#    #+#             */
/*   Updated: 2020/12/16 18:02:16 by rtacos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

// t_color		get_obj_color(t_scene objs, int type, int index)
// {
// 	if (type == SPH)
// 		return (objs.sph_objs[index].color);
// 	else if (type == CYLINDER)
// 		return (objs.cyln_objs[index].color);
// 	else if (type == CONE)
// 		return (objs.cone_objs[index].color);
// 	else
// 		return (objs.plane_objs[index].color);
// }
// t_coord		sph_coord_conversion(t_coord begin, t_coord point)
// {
// 	t_coord  p;

	
// 	return (p);
// }

//
// Created by Hugor Chau on 12/4/20.
//

// static int		is_png(FILE **fp, t_parser *parser)
// {
// 	png_byte	header[8];
// 	int			is_png;
// ​
// 	*fp = fopen(parser->texture->filename, "rb");
// 	if (!*fp)
// 		return (rt_err("can\'t open file"));
// 	fread(header, sizeof(png_byte), 8, *fp);
// 	is_png = png_sig_cmp(header, 0, 8);
// 	if (is_png)
// 	{
// 		fclose(*fp);
// 		return (rt_err("not png"));
// 	}
// 	return (0);
// }
// ​
// static int		prepare_pnglib_structs(png_structp *png_ptr, png_infop *info_ptr, png_infop *end_info)
// {
// 	*png_ptr = png_create_read_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
// 	if (!*png_ptr)
// 		return (rt_err("not png"));
// 	png_set_user_limits(*png_ptr, 4000, 4000);
// 	*info_ptr = png_create_info_struct(*png_ptr);
// 	*end_info = png_create_info_struct(*png_ptr);
// 	if (!*info_ptr || !*end_info)
// 	{
// 		png_destroy_read_struct(png_ptr, (png_infopp) NULL, (png_infopp) NULL);
// 		return (rt_err("no end_info"));
// 	}
// 	if (setjmp(png_jmpbuf(*png_ptr)))
// 	{
// 		png_destroy_read_struct(png_ptr, info_ptr, end_info);
// 		return (rt_err("setjmp() error"));
// 	}
// 	return (0);
// }
// ​
// static int		txr_png_read_rows(png_structp png_ptr, t_parser *parser, png_byte *image_data)
// {
// 	png_bytepp		row_pointers;
// 	size_t			i;
// ​
// 	i = 0;
// 	row_pointers = (png_bytepp) malloc( parser->texture->height * sizeof(png_bytep) );
// 	if ( !row_pointers )
// 	{
// 		free(image_data);
// 		return (rt_err("malloc error"));
// 	}
// 	while (i < parser->texture->height)
// 	{
// 		row_pointers[i] = image_data + i * parser->texture->stride;
// 		i++;
// 	}
// 	png_read_image(png_ptr, row_pointers);
// //	if (parser->texture->content)
// //		ft_memdel((void **)&parser->texture->content);
// 	parser->texture->content = (char *)image_data;
// //	ft_free(row_pointers);
// 	return (0);
// }
// ​
// static int		png_read_buf(png_structp png_ptr, png_infop info_ptr, png_infop end_info, t_parser *parser)
// {
// 	png_byte		*image_data;
// ​
// 	image_data = (png_bytep) malloc(parser->texture->stride * parser->texture->height * sizeof(png_byte));
// 	if (!image_data)
// 	{
// 		png_destroy_read_struct( &png_ptr, &info_ptr, &end_info );
// 		return (rt_err("malloc error"));
// 	}
// 	if (txr_png_read_rows(png_ptr, parser, image_data))
// 	{
// 		png_destroy_read_struct( &png_ptr, &info_ptr, &end_info );
// 		return (rt_err("png_read_buf(): error"));
// 	}
// 	return (0);
// }
// ​
// static int		check_type(png_structp png_ptr, png_infop info_ptr, t_parser *parser)
// {
// 	int				color_type;
// ​
// 	png_get_IHDR(png_ptr, info_ptr, NULL, NULL, NULL, &color_type, NULL, NULL, NULL);
// 	if (color_type == PNG_COLOR_TYPE_RGBA)
// 	{
// 		if (parser->texture->type != TXR_RGBA_8)
// 			return (rt_err("expected another color type"));
// 		return (0);
// 	}
// 	if (color_type == PNG_COLOR_TYPE_RGB)
// 	{
// 		if (parser->texture->type != TXR_RGB_8)
// 			return (rt_err("expected another color type"));
// 		return (0);
// 	}
// 	if (color_type == PNG_COLOR_TYPE_GRAY)
// 	{
// 		if (parser->texture->type != TXR_BW_8)
// 			return (rt_err("expected another color type"));
// 		return (0);
// 	}
// 	return (rt_err("unknown texture type"));
// }
// ​
// static int		png_get_size(png_structp png_ptr, png_infop info_ptr, t_parser *parser)
// {
// 	png_uint_32		t_width;
// 	png_uint_32		t_height;
// 	int				bit_depth;
// 	int				color_type;
// ​
// 	png_set_sig_bytes(png_ptr, 8);
// 	png_read_info(png_ptr, info_ptr);
// 	png_get_IHDR(png_ptr, info_ptr,
// 				 &t_width, &t_height,
// 				 &bit_depth, &color_type, NULL, NULL, NULL);
// 	parser->texture->width = t_width;
// 	parser->texture->height = t_height;
// 	png_read_update_info(png_ptr, info_ptr);
// 	parser->texture->stride = png_get_rowbytes(png_ptr, info_ptr);
// 	return (0);
// }
// ​
// int		cmd_read_png(t_parser *parser)
// {
// 	FILE			*fp;
// 	png_structp		png_ptr;
// 	png_infop		info_ptr;
// 	png_infop		end_info;
// ​
// 	if (is_png(&fp, parser))
// 		return (rt_err("cmd_read_png(): given file is not png"));
// 	if (prepare_pnglib_structs(&png_ptr, &info_ptr, &end_info))
// 	{
// 		fclose(fp);
// 		return (rt_err("cmd_read_png(): can\'t prepare png structs"));
// 	}
// 	png_init_io(png_ptr, fp);
// 	if (png_get_size(png_ptr, info_ptr, parser))
// 	{
// 		fclose(fp);
// 		png_destroy_read_struct( &png_ptr, &info_ptr, &end_info );
// 		return (rt_err("png size error"));
// 	}
// 	if (check_type(png_ptr, info_ptr, parser))
// 	{
// 		fclose(fp);
// 		png_destroy_read_struct( &png_ptr, &info_ptr, &end_info );
// 		return (rt_err("check_type(): type error"));
// 	}
// 	if (png_read_buf(png_ptr, info_ptr, end_info, parser))
// 	{
// 		fclose(fp);
// 		png_destroy_read_struct( &png_ptr, &info_ptr, &end_info );
// 		return (rt_err("check_type(): png_read_buf error"));
// 	}
// 	fclose(fp);
// 	png_destroy_read_struct( &png_ptr, &info_ptr, &end_info );
// 	return (0);
// }

typedef struct	s_textur
{
	t_color		color_1;
	t_color		color_2;
	float		width;
	float		height;
}				t_textur;

t_textur	creat_uv_checker(float w, float h, t_color col1, t_color col2)
{
	t_textur map;

	map.width = w;
	map.height = h;
	map.color_1 = col1;
	map.color_2 = col2;
	return (map);
}

t_color		uv_pattern_at(t_textur checkers, float u, float v)
{
	int		u2;
	int		v2;

	u2 = (int)floorf(u * checkers.width);
	v2 = (int)floorf(v * checkers.height);
	if (((u2 + v2) % 2) == 0)
		return (checkers.color_1);
	else
		return (checkers.color_2);
}

t_2d_map	spherical_map(t_coord p)
{
	t_2d_map res;

	float teta = atan2f((float)p.x, (float)p.z);
	float rad = (float)vctr_len(p);
	float phi = acosf((float)p.y / rad);
	float raw_u = teta / (2.0f * (float)M_PI);
	res.u = 1.0f - (raw_u + 0.5f);
	res.v = 1.0f - (phi / (float)M_PI);
	return (res);
}

// vec3 computePrimaryTexDir(vec3 normal)
// {
//     vec3 a = cross(normal, vec3(1, 0, 0));
//     vec3 b = cross(normal, vec3(0, 1, 0));

//     vec3 max_ab = dot(a, a) < dot(b, b) ? b : a;

//     vec3 c = cross(normal, vec3(0, 0, 1));

//     return normalize(dot(max_ab, max_ab) < dot(c, c) ? c : max_ab);
// }

//   …

//     vec3 u = computePrimaryTexDir(normal);
//     vec3 v = cross(n, u);

//	   h.u = u.dot( h.coordinates );
//	   h.v = v.dot( h.coordinates );


t_coord		vctr_cross(t_coord vec_1, t_coord vec_2)
{
	t_coord		vec_new;

	vec_new.x = vec_1.y * vec_2.z - vec_1.z * vec_2.y;
	vec_new.y = -(vec_1.x * vec_2.z - vec_1.z * vec_2.x);
	vec_new.z = vec_1.x * vec_2.y - vec_1.y * vec_2.x;
   return (vec_new);
}

t_2d_map	planlar_map(t_coord p, t_coord normal)
{
	t_2d_map	res;
	t_coord a, b, c, max_ab, vec_u, vec_v;

	a = vctr_cross(normal, (t_coord){1, 0, 0});
	b = vctr_cross(normal, (t_coord){0, 1, 0});
	
	max_ab = vctr_dot(a, a) < vctr_dot(b, b) ? b : a;
	c = vctr_cross(normal, (t_coord){0, 0, 1});
	vec_u = vctr_normal(vctr_dot(max_ab, max_ab) < vctr_dot(c, c) ? c : max_ab);
	vec_v = vctr_cross(normal, vec_u);
	res.u = vctr_dot(vec_u, p);
	res.v = vctr_dot(vec_v, p);
	// float		u2;
	// float		v2;

	// u2 = floorf((float)p.z);
	// v2 = floorf((float)p.y);
	// if ((res.u = (float)(((float)p.z - u2))) < 0.00000f)
	// 	res.u += 1.00000f;
	// if ((res.v = (float)(((float)p.y - v2))) < 0.00000f)
	// 	res.v += 1.00000f;
	return (res);
}

	static t_coord              projection(t_coord point_a, t_coord point_b, t_coord  direction_bc)
{
    float             cosine;
    t_coord           projection;
   	float             hypotenuse;
	t_coord			  hypotenuse_vec;
    t_coord           cathet_bc;
    t_coord           ba;
    ba = vctr_sub(point_b, point_a);
    hypotenuse = vctr_len(ba);
	hypotenuse_vec = (t_coord){hypotenuse, hypotenuse, hypotenuse};
    cosine = vctr_dot(direction_bc, vctr_normal(ba));
    cathet_bc = vctr_mult(hypotenuse_vec, cosine);
    projection = vctr_sum(point_b, vctr_cross(direction_bc, cathet_bc));
    return(projection);
}

static void                local_default(t_coord *top, t_coord *bottom, t_coord *intersection)
{
    *top = vctr_sub(*top, *bottom);
    *intersection = vctr_sub(*intersection, *bottom);
    *bottom = vctr_sub(*bottom, *bottom);
}
t_2d_map	cylindrical_map(t_coord p, t_cylinder_cap cyln)
{
	t_2d_map res;
	// (void)cyln;
	// float theta = atan2f((float)p.x, (float)p.z);
	// float raw_u = theta / (2.0f * (float)M_PI);
	// res.u = 1.0f - (raw_u + 0.5f);
	// float	v2 = floorf((float)p.y);
	// if ((res.v = ((float)p.y - v2)) < 0.00000f)
	// 	res.v += 1.00000f;
	// return (res);
    t_coord           normal;
    t_coord           top;
	t_coord				t_h;
    local_default(&cyln.head, &cyln.tail, &p);
    top = projection(p, cyln.tail, cyln.direction);
    normal = vctr_normal(vctr_sub(top, p));
	t_h = vctr_sub(cyln.tail, cyln.head);
    if (t_h.y == 0.0)
        res.u = 0.5 + atan2(normal.y, normal.z) / (2 * M_PI);
    else
        res.u = 0.5 + atan2(normal.z, normal.x) / (2 * M_PI);
    if (vctr_dot(vctr_normal(vctr_sub(p, cyln.tail)), cyln.direction) >= -0.00001
        && vctr_dot(vctr_normal(vctr_sub(p, cyln.tail)), cyln.direction) <= 0.00001)
        res.v = vctr_len(vctr_sub(cyln.tail, p)) / vctr_len(vctr_sub(cyln.tail, cyln.head));
    else if (vctr_dot(vctr_normal(vctr_sub(p, cyln.head)), cyln.direction) >= -0.00001
        && vctr_dot(vctr_normal(vctr_sub(p, cyln.head)), cyln.direction) <= 0.00001)
        res.v = 1 - vctr_len(vctr_sub(cyln.head, p)) / vctr_len(vctr_sub(cyln.tail, cyln.head));
    else
        res.v = 1 - (cyln.rad + vctr_len(vctr_sub(cyln.tail, top))) / vctr_len(vctr_sub(cyln.tail, cyln.head));
	return (res);
}

void		test_checker(t_coord normal)
{
	t_coord p;
	// t_color color;
	// float u, v;

	p = (t_coord){0.25 , 0 , 0.5};
	t_2d_map map = planlar_map(p, normal);
	printf("%f ; %f\n", map.u, map.v);
	p = (t_coord){0.25 , 0 , -0.25};
	map = planlar_map(p, normal);
	printf("%f ; %f\n", map.u, map.v);
	p = (t_coord){0.25 , 0.5 , - 0.25};
	map = planlar_map(p, normal);
	printf("%f ; %f\n", map.u, map.v);
	p = (t_coord){1.25 , 0 , 0.5};
	map = planlar_map(p, normal);
	printf("%f ; %f\n", map.u, map.v);
	p = (t_coord){0.25 , 0 , -1.75};
	map = planlar_map(p, normal);
	printf("%f ; %f\n", map.u, map.v);
	p = (t_coord){1 , 0 , - 1};
	map = planlar_map(p, normal);
	printf("%f ; %f\n", map.u, map.v);
	p = (t_coord){0 , 0 , 0};
	map = planlar_map(p, normal);
	printf("%f ; %f\n", map.u, map.v);
	// | точка ( 0,25 , 0 , 0,5 )      |  0,25  |  0,5   | 
    // |  точка ( 0,25 , 0 , - 0,25 )    |  0,25  |  0,75  | 
    // |  точка ( 0,25 , 0,5 , - 0,25 )  |  0,25  |  0,75  | 
    // | точка ( 1,25 , 0 , 0,5 )      |  0,25  |  0,5   | 
    // |  точка ( 0,25 , 0 , - 1,75 )    |  0,25  |  0,25  | 
    // |  точка ( 1 , 0 , - 1 )          |  0,0   |  0,0   | 
    // |  точка ( 0 , 0 , 0 )           |  0,0   |  0,0   |
	// | point(0, 0, -1)      | 0.0  | 0.5  |
    // | point(1, 0, 0)       | 0.25 | 0.5  |
    // | point(0, 0, 1)       | 0.5  | 0.5  |
    // | point(-1, 0, 0)      | 0.75 | 0.5  |
    // | point(0, 1, 0)       | 0.5  | 1.0  |
    // | point(0, -1, 0)      | 0.5  | 0.0  |
    // | point(√2/2, √2/2, 0) | 0.25 | 0.75 |
	// t_textur checkers = creat_uv_checker(16, 8, GREEN, WHITE);
	// p = (t_coord) {0.4315, 0.4670, 0.7719};
	// t_2d_map map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
	// p = (t_coord) {-0.9654, 0.2552, -0.0534};
	// map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
	// p = (t_coord) {0.1039, 0.7090, 0.6975};
	// map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
	// p = (t_coord) {-0.4986, -0.7856, -0.3663};
	// map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
	// p = (t_coord) {-0.0317, -0.9395, 0.3411};
	// map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
	// p = (t_coord) {0.4809, -0.7721, 0.4154};
	// map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
	// p = (t_coord) {0.0285, -0.9612, -0.2745};
	// map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
	// p = (t_coord) {-0.5734, -0.2162, -0.7903};
	// map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
	// p = (t_coord) {0.7688, -0.1470, 0.6223};
	// map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
	// p = (t_coord) {-0.7652, 0.2175, 0.6060};
	// map = spherical_map(p);
	// color = uv_pattern_at(checkers, map.u, map.v);
	// if (color.r == 0)
	// 	printf("black\n");
	// else
	// 	printf("white\n");
}

t_coord		newdir(t_coord point, t_obj_info near)
{
	t_quat	axis;

	axis = rot((t_quat){1, near.st_cent}, 1);
	point = vctr_rotation(point, axis);
	return (point);
}

t_color		get_color_pix(t_scene objs, t_obj_info near)
{
	t_coord		p;
	t_2d_map	map;

	// if (near.fl == 1)
	// 	test_checker(near.normal);
	if (near.type == SPH)
	{
		p = vctr_sub(objs.sph_objs[near.index].center, near.point);
		map = spherical_map(p);
		return (uv_pattern_at(creat_uv_checker(10.0f, 5, WHITE, GREEN), map.u, map.v));
	}
	else if (near.type == CYLINDER)
	{
		p = vctr_sub(objs.cyln_objs[near.index].center, near.point);
		map = cylindrical_map(p, objs.cyln_cap_objs[near.index]);
		return (uv_pattern_at(creat_uv_checker(10.0f, 5, WHITE, GREEN), map.u, map.v));
	}
		// return (objs.cyln_objs[near.index].color);
	else if (near.type == CONE)
	{
		p = vctr_sub(objs.cone_objs[near.index].center, near.point);
		map = cylindrical_map(p, objs.cyln_cap_objs[near.index]);
		return (uv_pattern_at(creat_uv_checker(100.0f, 50, WHITE, GREEN), map.u, map.v));
	}
	else if (near.type == CAP_CYLN)
	{
		// p = vctr_sub(objs.cyln_cap_objs[near.index].tail, near.point);
		// p = newdir(p, near);
		map = cylindrical_map(near.point, objs.cyln_cap_objs[near.index]);
		return (uv_pattern_at(creat_uv_checker(100.0f, 50, WHITE, GREEN), map.u, map.v));
		// return (objs.cyln_cap_objs[near.index].color);
	}
	else
	{
		p = vctr_sub(objs.plane_objs[near.index].center, near.point);
		map = planlar_map(p, near.normal);
		return (uv_pattern_at(creat_uv_checker(10.0f, 10, WHITE, GREEN), map.u, map.v));
	}
		// return (objs.plane_objs[near.index].color);
}

int			get_specul_obj(t_scene objs, int type, int index)
{
	if (type == SPH)
		return (objs.sph_objs[index].specular);
	else if (type == CYLINDER)
		return (objs.cyln_objs[index].specular);
	else if (type == CONE)
		return (objs.cone_objs[index].specular);
	else if (type == CAP_CYLN)
		return (objs.cyln_cap_objs[index].specular);
	else
		return (objs.plane_objs[index].specular);
}

t_coord		get_direction(t_vector camera, int x, int y)
{
	t_coord		direction;
	t_coord		point;

	point = (t_coord){x - (WIN_WID / 2), (WIN_HIG / 2) - y, WIN_DIST};
	point = vctr_rotation(point, camera.roter);
	direction = vctr_normal(vctr_sub(camera.point, point));
	return (direction);
}
