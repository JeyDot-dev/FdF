#include "fdf.h"
int	rgbo_color(int r, int g, int b, int o)
{
	int	color;

	color = 0;
	if (r > 255)
		r = 255;
	if (g > 255)
		g = 255;
	if (b > 255)
		b = 255;
	color |= b;
	color |= g << 8;
	color |= r << 16;
	color |= o << 24;
	return (color);
}
t_line_coordinates scale_pts(t_line_coordinates pts)
{
	int inc = 130;

	pts.x = inc * pts.x;
	pts.y = inc * pts.y;
	pts.z = inc * pts.z;
	pts.x2 = inc * pts.x2;
	pts.y2 = inc * pts.y2;
	pts.z2  = inc * pts.z2;
	return (pts);
}

t_line_coordinates origin_pts(t_line_coordinates pts)
{
	int base_x = 1920 / 2;
	int base_y = 1080 / 2;

	pts.x = base_x + pts.x;
	pts.y = base_y + pts.y;
	pts.x2 = base_x + pts.x2;
	pts.y2 = base_y + pts.y2;
	return (pts);
}

t_line_coordinates base_pt1(int a, int b, int c)
{
	t_line_coordinates	pts;
	pts.x = a;
	pts.y = b;
	pts.z = c;
	return (pts);
}

t_line_coordinates base_pt2(t_line_coordinates pts, int a, int b, int c)
{
	pts.x2 = a;
	pts.y2 = b;
	pts.z2 = c;
	return (pts);
}
void ft_cube(t_imgdata *img)
{
	t_line_coordinates	pts;
	pts = base_pt1(0, 0, 0);
	pts = base_pt2(pts, 1, 0, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 0, 0, 1));
	pts = base_pt1(0, 1, 0);
	pts = base_pt2(pts, 1, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 0, 0, 1));
	pts = base_pt1(0, 0, 0);
	pts = base_pt2(pts, 0, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 255, 0, 1));
	pts = base_pt1(1, 0, 0);
	pts = base_pt2(pts, 1, 1, 0);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(0, 255, 0, 1));
	pts = base_pt1(0, 0, 1);
	pts = base_pt2(pts, 1, 0, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 120, 120, 1));
	pts = base_pt1(0, 1, 1);
	pts = base_pt2(pts, 1, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 120, 120, 1));
	pts = base_pt1(0, 0, 1);
	pts = base_pt2(pts, 0, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(120, 255, 120, 1));
	pts = base_pt1(1, 0, 1);
	pts = base_pt2(pts, 1, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(120, 255, 120, 1));
	pts = base_pt1(0, 0, 0);
	pts = base_pt2(pts, 0, 0, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 255, 255, 1));
	pts = base_pt1(0, 1, 0);
	pts = base_pt2(pts, 0, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 255, 255, 1));
	pts = base_pt1(1, 0, 0);
	pts = base_pt2(pts, 1, 0, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 255, 255, 1));
	pts = base_pt1(1, 1, 0);
	pts = base_pt2(pts, 1, 1, 1);
	pts = base_pts(pts);
	pts = to_isometric(pts);
	pts = origin_pts(pts);
			ft_printf("Line : x=%i, y=%i, x2=%i, y2=%i\n",
					pts.x, pts.y, pts.x2, pts.y2);
	put_line(img, pts, rgbo_color(255, 255, 255, 1));
}
