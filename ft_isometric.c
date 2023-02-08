#include "fdf.h"
t_coordinate to_isometric(t_coordinate pts)
{
//	pts.x = round(pts.x + cos(120) * pts.z);
//	pts.y = round(pts.y + sin(120) * pts.z);
//	pts.x2 = round(pts.x2 + cos(120) * pts.z2);
//	pts.y2 = round(pts.y2 + sin(120) * pts.z2);

	pts.x = (pts.x - pts.y) * cos(0.523599);
    pts.y = ((-1) * pts.z + (pts.x + pts.y)) * sin(0.523599);
	pts.x2 = (pts.x2 - pts.y2) * cos(0.523599);
	pts.y2 = ((-1) * pts.z2 + (pts.x2 + pts.y2)) * sin(0.523599);
 //
//	pts.x = round(pts.x * cos(120) + pts.x * cos(120 + 2) + pts.z * cos(120 - 2));
//	pts.y = round(pts.y * sin(120) + pts.x * sin(120 + 2) + pts.z * sin(120 - 2));
//	pts.x2 = round(pts.x2 * cos(120) + pts.x2 * cos(120 + 2) + pts.z2 * cos(120 - 2));
//	pts.y2 = round(pts.y2 * sin(120) + pts.x2 * sin(120 + 2) + pts.z2 * sin(120 - 2));
	
//	pts.x = (pts.x - pts.z) / sqrt(2);
//	pts.y = (pts.x + pts.y * 2 + pts.z) / sqrt(6);
//	pts.x2 = (pts.x2 - pts.z2) / sqrt(2);
//	pts.y2 = (pts.x2 + pts.y2 * 2 + pts.z2) / sqrt(6);
	return (pts);
}
