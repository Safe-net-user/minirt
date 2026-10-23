# Phong Reflection Model

## Definition
Le model de reflection de Phong décrit le moyen pour qu'une surface réflechisse la lumière avec la somme  de 3 types de féflexion
- Ambient: contribution ambiante, qui represente approximativement l'éclairage indirect.
- Diffuse: réflexion diffuse, dépendant de l'orientation de la surface par rapport à la lumière.
- Specular: reflet brillant, dépendant notamment de la direction de vue.


  ![phong_reflection_model](../image/phong_reflection_model.png)

## Modele mathematique

### Ambient Shading
Formule de la lumière ambiente $I_{amb} = I_a k_a$

- $I_a$: intensité de la lumière ambiente
- $k_a$: coefficient de la réflexion ambiente du materiaux, 0 ~ 1

### Diffuse Lighting

![lambert's Law](../image/lambert_law.webp)

Nous pouvons voir que depuis la loi du cosinus de Lambert, l'intensité de la lumière est réduite par un facteur de $cos(θ)$

Formule de la diffusion de la lumière 

$$I_{diff} = I_p k_d(N \cdot V_L)$$


![light and normal vectors](../image/light_normal_vector.webp)

- $I_p$: point light intensity
- $k_d$: diffuse reflection coef 0 ~ 1
- $θ$ : angle: 0° ~ 90°
- $V_L$: direction to the light source
- $N$: Surface normal

Nous pouvons dissequer l'équation en remplacant le produit scalaire avec cette expression.

$$I_{diff} = I_p k_d ||N||||V_L||cos(θ)$$

Nous pouvons également supposer que nous travaillons avec des vectors unitaires etant donné que les vecteurs ci dessus indiquent une direction et ne devraient pas influencer l'intensité lumineuse.

$$I_{diff} = I_p k_d cos(θ)$$

### Source d'attenuation de la lumière
Il s'agit d'additionner les equations ci-dessus et d'ajouter un facteur d'atténuation à l'eclairage diffus.   
$$I_{diff} = I_a k_a + f_{att} I_p k_d (N \cdot V_L)$$

Si la source de la lumière est un point, le coeficient prend la forme:

$$f_{att} = \frac {1} {d_L²}$$

C'est du à la loi en carré inverse relative à l'intensité lumineuse.

### Réflexion spéculaire
N/A

## Architecure

### Données entrantes
Voici des données type de départ d'un fichier .rt (modifié pour n'avoir que ce qui nous interesses) rentré au début du programme:
```text
#type   #ratio_amb_light    #coords         #ratio_luminosité       # RGB color                 
A       0.2                                                         255,255,255         # lumière ambiente
L                           -40,0,30        0.7                     255,255,255         # lumière
sp                          150,150,0                               255,100,100         # objet sphere
```

### Calcule de la lumière
Pour obtenir la couleur ambiante, nous devons calculer $I_a$

$I_a = (\frac {r}{255}, \frac {g}{255}, \frac {b}{255})x_{ratio}$

$I_a = (\frac {255}{255}, \frac {255}{255}, \frac {255}{255})0.2$

$I_a = (1, 1, 1)0.2$

$I_a = (0.2, 0.2, 0.2)$

Ensuite pour finaliser le caclul de la couleur ambiente $I_{amb}$

$I_{amb} = I_a k_a$

$I_{amb} = (0.2, 0.2, 0.2) (255, 100, 100)$

$I_{amb} = (51, 20, 20)$             # 0x331414

Il est temps de calculer la suite du rendu avec la lumière diffuse $I_{diff}$

## Implémentation
Dans le fichier header *minirt/src/physic/light.h* on retrouve le prototype suivant:
```c
lighting(type arg1, type arg2, ...);
```
Et dans le fichier *minirt/src/physic/light.c* le modèle de reflection de Phong y est implementé.
```c++
int	lighting_sphere(const t_sphere *sp, const size_t id, const t_amb_light al, const t_light light, const t_light_data d)
{
	//int		object_color;
	t_vec4		ambient;
	int		material_color;
	//int		ambient_color;
	//int		diffuse;
	/*float	reflect_dot_eye;*/
	//float	light_dot_normal;
	//t_vec4	l;
	//t_vec4	r;

	(void)d;
	(void)al;
	// no compute emissive
	// compute ambient lighting
	(void)light;
	ambient = compute_ambient(al);
	material_color =	((int)(((uint8_t *)sp->sr.r->buffer)[id] * ambient.x) << 16) |
				((int)(((uint8_t *)sp->sr.g->buffer)[id] * ambient.y) << 8) |
				(int)(((uint8_t *)sp->sr.b->buffer)[id] * ambient.z);
	/*
	ambient_color = ((((int)(((uint8_t *)sp->sr.r->buffer)[id] * al.ratio / al.r)) << 16)
	| (((int)(((uint8_t *)sp->sr.g->buffer)[id] * al.ratio / al.g)) << 8)
	| ((int)(((uint8_t *)sp->sr.b->buffer)[id] * al.ratio / al.b)));*/
	/*l = normalize_vector(
		sub_points(
			set_point(
				((float *)sp->st.x->buffer)[id],
				((float *)sp->st.y->buffer)[id],
				((float *)sp->st.z->buffer)[id]
				),
				d.p),
				compute_magnitude(sub_points(
			set_point(
				((float *)sp->st.x->buffer)[id],
				((float *)sp->st.y->buffer)[id],
				((float *)sp->st.z->buffer)[id]
				),
				d.p)));
	light_dot_normal = compute_dot(l, d.n);
	if (light_dot_normal < 0)
		return (ambient_color);
	//diffuse = ambient_color * light_dot_normal;
	//r = reflect_at(negate_vector(l), d.n);*/
	return (material_color);
}
```

## Références
https://medium.com/@leo6150631016/a-breif-note-about-phong-reflection-model-derivation-of-its-formula-different-approach-to-7711936cd231
https://www.oreilly.com/library/view/real-time-3d-graphics/9781788629690/e08d3981-4690-45d5-b2c0-8cd6158b11d7.xhtml