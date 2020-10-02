//
// Created by Rusakova Veronika on 21.09.2020.
//

#include "rtv1.h"
//todo реализовать парсер
/*
 * Функции mock -временные

static void		mock_sphere(t_sph *sph)
{
	sph->center.x = 0.0f;
	sph->center.y = -1.0f;
	sph->center.z = 3.0f;

	sph->color.r = 255;
	sph->color.g = 0;
	sph->color.b = 0;

	sph->rad = 1.0f;

}

static void		mock_cylinder(t_cylindr *cylinder)
{
	cylinder->center.x = 0.0f;
	cylinder->center.y = 0.0f;
	cylinder->center.z = 4.0f;

	cylinder->color.r = 114;
	cylinder->color.g = 255;
	cylinder->color.b = 255;

	cylinder->rotation.x = 1.0f;
	cylinder->rotation.y = 1.0f;
	cylinder->rotation.z = 0.0f;

	cylinder->rotation = normal_vector((t_coord){1.0, 1.0, 0.0});

	cylinder->rad = 1.0f;

}

static void		mock_cone(t_cone *cone)
{
	cone->center.x = 0.0f;
	cone->center.y = 0.0f;
	cone->center.z = 4.0f;

	cone->color.r = 255;
	cone->color.g = 0;
	cone->color.b = 225;

	cone->rotation.x = 1.0f;
	cone->rotation.y = 0.0f;
	cone->rotation.z = 0.0f;
	cone->rotation = normal_vector((t_coord){-1.5, 1.0, 0.0});

	cone->angle = 10;

}

static void		mock_plane(t_plane *plane)
{
	plane->center.x = -2.0f;
	plane->center.y = -1.0f;
	plane->center.z = 10.0f;

	plane->color.r = 255;
	plane->color.g = 225;
	plane->color.b = 0;

	plane->rotation.x = -1.0f;
	plane->rotation.y = 1.0f;
	plane->rotation.z = 1.0f;
	plane->rotation = normal_vector((t_coord){1.0, 0.0, 0.0});

}

static void		mock_camera(t_object *object)
{
	object->camera.x = 0.0f;
	object->camera.y = 0.0f;
	object->camera.z = 0.0f;

	object->rot_cam = normal_vector((t_coord){1.0, 0.0, 1.0});
}

static void mock_light(t_light *pLight, int i)
{
	if (i == 0)
	{
		pLight->intensity = 0.2f;
		pLight->type = AMBIENT;
	}
	else if (i == 1)
	{
		pLight->type = POINT;
		pLight->intensity = 0.6f;
		pLight->pos_or_dir.x = 2.0;
		pLight->pos_or_dir.y = -1.0;
		pLight->pos_or_dir.z = 0.0;
	}
	else
	{
		pLight->type = DIRECTIONAL;
		pLight->intensity = 0.4f;
		pLight->pos_or_dir.x = 1.0;
		pLight->pos_or_dir.y = 4.0;
		pLight->pos_or_dir.z = 4.0;
	}
}

void		read_setups(t_object *object, char *name)
{
//	validate_inside()
	object->num_cylns = 0;
	object->num_sphs = 0;
	object->num_l_src = 0;
	object->num_cons = 0;
	object->num_plans = 0;

	mock_sphere(object->sph_objs);
	object->num_sphs++;

	mock_cylinder(object->cyln_objs);
	object->num_cylns++;

	mock_cone(object->cone_objs);
	object->cone_objs++;

	mock_plane(object->plane_objs);
	object->plane_objs++;

	while (object->num_l_src < 3)
	{
		mock_light(&object->light_srcs[object->num_l_src], object->num_l_src);
		object->num_l_src++;
	}

	mock_camera(object);

	(void)name;
}
 */