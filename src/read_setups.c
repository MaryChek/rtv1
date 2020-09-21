//
// Created by Rusakova Veronika on 21.09.2020.
//

#include "rtv1.h"
//todo реализовать парсер
/*
 * Функции mock -временные
 * */
static void		mock_sphere(t_sph *sph)
{
	sph->center.x = 0.0;
	sph->center.y = 0.0;
	sph->center.z = 220.0;

	sph->color.r = 255;
	sph->color.g = 0;
	sph->color.b = 0;

	sph->rad = 200;

}

static void		mock_cylinder(t_cylindr *cylinder)
{
	cylinder->center.x = 0.0;
	cylinder->center.y = 0.0;
	cylinder->center.z = 210.0;

	cylinder->color.r = 0;
	cylinder->color.g = 255;
	cylinder->color.b = 0;

	cylinder->rotation.x = 1.0;
	cylinder->rotation.y = 1.0;
	cylinder->rotation.z = 0.0;

	normal_rotation(&cylinder->rotation);

	cylinder->rad = 50;

}

static void		mock_camera(t_object *object)
{
	object->camera.x = 0.0;
	object->camera.y = 0.0;
	object->camera.z = 0.0;
}

void		read_setups(t_object *object, char *name)
{
//	validate_inside()
	object->num_cylns = 0;
	object->num_sphs = 0;

	mock_sphere(object->sph_objs);
	object->num_sphs++;

	mock_cylinder(object->cyln_objs);
	object->num_cylns++;

	mock_camera(object);

	(void)name;
}