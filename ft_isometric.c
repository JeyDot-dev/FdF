#include "fdf.h"
void	to_isometric(t_pts_coordinates *pts)
{
	double a = 0.43;
	double b = 2.0;

	if (!pts)
		return ;
//	pts.x = round(pts.x + cos(b) * pts.z);
//	pts.y = round(pts.y + sin(b) * pts.z);
//	pts.x2 = round(pts.x2 + cos(b) * pts.z2);
//	pts.y2 = round(pts.y2 + sin(b) * pts.z2);

//	pts.x = (pts.x - pts.y) * cos(a);
//   pts.y = ((-1) * pts.z + (pts.x + pts.y)) * sin(a);
//	pts.x2 = (pts.x2 - pts.y2) * cos(a);
//	pts.y2 = ((-1) * pts.z2 + (pts.x2 + pts.y2)) * sin(a);
//	
	while (pts)
	{
		pts->x  = pts->x * cos(a) + pts->y * cos(a+b) + pts->z * cos(a-b);
		pts->y  = pts->x * sin(a) + pts->y * sin(a+b) + pts->z * sin(a-b);
		pts = pts->next;
	}
//	pts.x = pts.x * cos(a) + pts.x * cos(a + b) + pts.z * cos(a - b);
//	pts.y = pts.y * sin(a) + pts.x * sin(a + b) + pts.z * sin(a - b);
//	pts.x2 = pts.x2 * cos(a) + pts.x2 * cos(a + b) + pts.z2 * cos(a - b);
//	pts.y2 = pts.y2 * sin(a) + pts.x2 * sin(a + b) + pts.z2 * sin(a - b);
	
//	pts.x = (pts.x - pts.z) / sqrt(2);
//	pts.y = (pts.x + pts.y * 2 + pts.z) / sqrt(6);
//	pts.x2 = (pts.x2 - pts.z2) / sqrt(2);
//	pts.y2 = (pts.x2 + pts.y2 * 2 + pts.z2) / sqrt(6);
}
