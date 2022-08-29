#include "mlx.h"

int main()
{

void	*mlx_pointer;
void	*window;
int		width;
int		height;
char	*name;

	mlx_pointer = mlx_init();
	window = mlx_new_window(mlx_pointer, 1080, 1920, "mywindow");
	usleep(10);
}
